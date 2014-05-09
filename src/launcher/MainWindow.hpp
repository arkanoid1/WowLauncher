
#ifndef __LAUNCHER_MAINWINDOW_HPP__
#define __LAUNCHER_MAINWINDOW_HPP__

#include <memory>
#include <string>

namespace launcher {
	class MainWindow {
	public:
		MainWindow();
		virtual ~MainWindow();

		void doEvents();

	private:
		struct Impl;
		std::unique_ptr<Impl> impl;
	};
}

#endif	// __LAUNCHER_MAINWINDOW_HPP__
