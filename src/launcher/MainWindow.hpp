
#ifndef __launcher_mainwindow_hpp__
#define __launcher_mainwindow_hpp__

#include <memory>
#include <string>

class MainWindow {
public:
	MainWindow();
	virtual ~MainWindow();

private:
	struct Impl;
	std::unique_ptr<Impl> impl;
};

#endif	// __launcher_mainwindow_hpp__
