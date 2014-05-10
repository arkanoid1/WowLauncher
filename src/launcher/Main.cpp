
#include <Windows.h>

#include "WindowsError.hpp"
#include "gui/Widget.hpp"

namespace gui {

	class WindowClass {
	public:
		WindowClass(const std::wstring &className_) : className(className_) {
			WNDCLASS wc = { 0 };
			wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
			wc.hIcon = ::LoadIcon(NULL, IDI_WINLOGO);
			wc.lpfnWndProc = DefWindowProc;
			wc.hbrBackground = (HBRUSH)COLOR_3DFACE;
			wc.hInstance = ::GetModuleHandle(NULL);
			wc.lpszClassName = className.c_str();

			::RegisterClass(&wc);
		}

		~WindowClass() {
			::UnregisterClass(className.c_str(), ::GetModuleHandle(NULL));
		}

	private:
		const std::wstring &className;
	};

	class Frame : public WindowClass, public Widget {
	public:
		Frame(const std::wstring &className, const std::wstring &title) : WindowClass(className) {
			hWnd = ::CreateWindow ( 
				className.c_str(), title.c_str(),
				WS_OVERLAPPEDWINDOW, 
				CW_USEDEFAULT, CW_USEDEFAULT, 
				200, 200, 
				NULL, NULL, 
				::GetModuleHandle(NULL), NULL
			);

			::SetWindowLong(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG>(WndProc));
			::SetWindowLong(hWnd, GWL_USERDATA, reinterpret_cast<LONG>(this));

			if (hWnd == NULL) {
				throw launcher::WindowsError(::GetLastError());
			}
		}

		bool doEvents() {
			MSG msg = { 0 };

			// Procesa todos los mensajes pendientes
			while (::PeekMessage(&msg, hWnd, 0, 0, PM_REMOVE)) {
				if (msg.message == WM_QUIT) {
					::MessageBox(NULL, L"WM_QUIT", L"Mensaje", MB_OK | MB_ICONINFORMATION);
					return false;
				} else {
					::TranslateMessage(&msg);
					::DispatchMessage(&msg);
					return true;
				}
			}

			return true;
		}

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			if (msg == WM_DESTROY) {
				::MessageBox(NULL, L"WM_DESTROY", L"Mensaje", MB_OK | MB_ICONINFORMATION);
				::PostMessage(hWnd, WM_QUIT, 0, 0);

				return 0;
			}

			return ::DefWindowProc(hWnd, msg, wParam, lParam);
		}
	};
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	gui::Frame frame1(L"gui::Frame", L"Majong!!");

	frame1.setVisible(true);

	while (frame1.doEvents()) {}

	return 0;
}
