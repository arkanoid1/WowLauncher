
#ifndef __WINDOWSERROR_HPP__
#define __WINDOWSERROR_HPP__

#include <stdexcept>
#include <string>

// #define THROW_WINDOWS_ERROR(Exception) throw Exception("Exception at file " + std::string(__FILE__) + ":" + std::string(__LINE__) + ":";

class WindowsError : public std::runtime_error {
public:
    WindowsError();
    WindowsError(unsigned long errCode);
    WindowsError(const std::string &baseMsg);
    WindowsError(const std::string &baseMsg, unsigned long errCode);

	virtual const char* what() const;

private:
    void initMsg(const std::string &baseMsg, unsigned long errCode);

private:
	std::string msg;
};


#endif	//__WINDOWSERROR_HPP__
