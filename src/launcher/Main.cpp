
#include <Windows.h>

#include "WindowsError.hpp"
#include "gui/Widget.hpp"
#include "gui/Frame.hpp"
#include "gui/Button.hpp"

using namespace gui;

class MainFrame : public Frame {
public:
	MainFrame(const std::wstring &title) : Frame(L"MainFrame", title), button(this)  {
		this->setBounds(Rect(0, 0, 300, 400));
		this->setVisible(true);

		button.setText(L"Hello, world!");
		button.setBounds(Rect(10, 10, 100, 35));

		button.clickSignal.connect(std::bind([]() {
			::MessageBox(NULL, L"Click Bar", L"Message", MB_OK | MB_ICONINFORMATION);
		}));

		button.clickSignal.connect(std::bind([]() {
			::MessageBox(NULL, L"Click Foo", L"Message", MB_OK | MB_ICONINFORMATION);
		}));
	}

private:
	Button button;
};

class Application {
public:
	Application() {
	}

	void run(Frame &frame) {
		while (frame.doEvents()) {}
	}
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MainFrame frame1(L"Hola!");
	Application app;

	app.run(frame1);

	return 0;
}

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
