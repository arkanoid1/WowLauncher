
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
			wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
			wc.hInstance = ::GetModuleHandle(NULL);
			wc.lpszClassName = className.c_str();

			::RegisterClass(&wc);
		}

		~WindowClass() {
			const wchar_t *lpClassName = className.c_str();

			::UnregisterClass(lpClassName, ::GetModuleHandle(NULL));
		}

	private:
		std::wstring className;
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
			
			while (BOOL result = ::GetMessage(&msg, this->hWnd, 0, 0)) {
				if (msg.message == WM_QUIT) {
					return 0;
				} else {
					if (result == 0) {
						// app end?
						return false;
					} else if (result == -1) {
						// exit?
						return false;
					} else {
						::TranslateMessage(&msg);
						::DispatchMessage(&msg);
					}
				}
			}

			return true;
		}

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			if (msg == WM_DESTROY) {
				::PostMessage(hWnd, WM_QUIT, 0, 0);
				return 0;
			}

			return ::DefWindowProc(hWnd, msg, wParam, lParam);
		}
	};

	class Button : public Widget {
	public:
		Button(Widget *parent) {
			this->create(parent, L"");
		}

		Button(Widget *parent, const std::wstring &title) {
			this->create(parent, title.c_str());
		}

	protected:
		void create(Widget *parent, const wchar_t *title) {
			if (parent == nullptr) {
				throw std::runtime_error("Button::Button: Parent can't be a null pointer.");
			}

			HWND parentHandle = parent->getHandle();
			this->hWnd = ::CreateWindow(L"BUTTON", title, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 0, 0, 50, 50, parentHandle, NULL, ::GetModuleHandle(NULL), NULL);
		}

	private:

	};
}

using namespace gui;

class MainFrame : public Frame {
public:
	MainFrame(const std::wstring &title) : Frame(L"MainFrame", title) , okButton(this, L"Push Me!")  {
		this->setBounds(Rect(0, 0, 300, 400));
		this->setVisible(true);

		okButton.setBounds(Rect(10, 10, 100, 35));
	}

private:
	Button okButton;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MainFrame frame1(L"Hola!");
	while (frame1.doEvents()) {}

	return 0;
}
