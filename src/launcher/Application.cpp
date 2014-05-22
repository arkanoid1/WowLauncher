
#include "Application.hpp"

bool Application::doEvents() {
	MSG msg = { 0 };

	while (BOOL result = ::GetMessage(&msg, NULL, 0, 0)) {
		if (msg.message == WM_QUIT) {
			return false;
		} else {
			if (result == 0 || result == -1) {
				return false;
			} else {
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);

				return true;
			}
		}
	}
}

void Application::run() {
	while (this->doEvents()) {}
}
