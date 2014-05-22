
#ifndef __WINDOWSERROR_HPP__
#define __WINDOWSERROR_HPP__

#include <stdexcept>

class WindowsError : public std::runtime_error {
public:
	WindowsError(unsigned long errCode);
	virtual const char* what() const;

private:
	std::string msg;
};


#endif	//__WINDOWSERROR_HPP__
