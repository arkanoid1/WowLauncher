
#ifndef __LAUNCHER_WINDOWSERROR_HPP__
#define __LAUNCHER_WINDOWSERROR_HPP__

#include <stdexcept>

namespace launcher {
	class WindowsError : public std::runtime_error {
	public:
		WindowsError(unsigned long errCode);
		virtual const char* what() const;

	private:
		std::string msg;
	};
}

#endif	//__LAUNCHER_WINDOWSERROR_HPP__
