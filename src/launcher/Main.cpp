
#include <Windows.h>

#include "Application.hpp"
#include "WindowsError.hpp"
#include "MainFrame.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    try {
	    MainFrame frame1(L"Hola!");
	    Application app;

	    app.run();
    } catch (const std::exception &exp) {
		std::string str(exp.what());

		std::wstring msg;
		msg.assign(str.begin(), str.end());

		gui::MessageBox::show(msg, L"Message");
    }

    return 0;
}
