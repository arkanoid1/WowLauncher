
#include "MainWindow.hpp"
#include <Windows.h>

namespace launcher {

	struct MainWindow::Impl {
		HINSTANCE hInstance;
		HWND hWnd;

		Impl() : hInstance(NULL), hWnd(NULL) {
		}
	};
}
