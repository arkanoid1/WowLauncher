
#include "Frame.hpp"

namespace gui {
	WindowClass::WindowClass(const std::wstring &className_) : className(className_) {
		WNDCLASS wc = { 0 };
		wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = ::LoadIcon(NULL, IDI_WINLOGO);
		wc.lpfnWndProc = DefWindowProc;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hInstance = ::GetModuleHandle(NULL);
		wc.lpszClassName = className.c_str();

		::RegisterClass(&wc);
	}

	WindowClass::~WindowClass() {
		const wchar_t *lpClassName = className.c_str();

		::UnregisterClass(lpClassName, ::GetModuleHandle(NULL));
	}

	Frame::Frame(const std::wstring &className, const std::wstring &title) : WindowClass(className) {
		Widget::create(NULL,
			className.c_str(), title.c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			200, 200,
			NULL, NULL
			);

		::SetWindowLong(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG>(WndProc));
	}

	LRESULT CALLBACK Frame::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		Widget* windowWidget = reinterpret_cast<Widget*>(::GetWindowLong(hWnd, GWL_USERDATA));

		switch (msg) {
		case WM_CLOSE:
			::PostMessage(hWnd, WM_QUIT, 0, 0);
			return 0;

        case WM_SIZE:
            if (windowWidget) {
                windowWidget->resizeSignal(Size( LOWORD(lParam), HIWORD(lParam) ));
            }
            return 0;

		case WM_COMMAND:
			HWND hWndChild = (HWND)lParam;
			Widget* childWidget = reinterpret_cast<Widget*>(::GetWindowLong(hWndChild, GWL_USERDATA));

			if (childWidget) {
				childWidget->commandSignal();
				return 0;
			}
            break;
		}

		return ::DefWindowProc(hWnd, msg, wParam, lParam);
	}
}
