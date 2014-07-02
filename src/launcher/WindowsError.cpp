
#include "WindowsError.hpp"
#include <Windows.h>

// Create a string with last error message
// source: http://www.codeproject.com/Tips/479880/GetLastError-as-std-string
static std::string ErrorCodeToString(DWORD error) {
	if (error) {
		LPVOID lpMsgBuf;
		DWORD bufLen = FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			error,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&lpMsgBuf,
			0, NULL);

		if (bufLen) {
			LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
			std::string result(lpMsgStr, lpMsgStr + bufLen);
			LocalFree(lpMsgBuf);
			return result;
		}
	}
	return std::string();
}

WindowsError::WindowsError() : std::runtime_error("") {
    this->initMsg("", ::GetLastError());
}

WindowsError::WindowsError(unsigned long errCode) : std::runtime_error(""), msg("") {
    this->initMsg("", errCode);
}

WindowsError::WindowsError(const std::string &baseMsg) : std::runtime_error("") {
    this->initMsg(baseMsg, ::GetLastError());
}

WindowsError::WindowsError(const std::string &baseMsg, unsigned long errCode) : std::runtime_error("") {
    this->initMsg(baseMsg, errCode);
}

void WindowsError::initMsg(const std::string &baseMsg, unsigned long errCode) {
    this->msg = baseMsg + ErrorCodeToString(errCode);
}

const char* WindowsError::what() const {
	return this->msg.c_str();
}
