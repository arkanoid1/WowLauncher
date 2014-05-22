
#include <Windows.h>

#include "Application.hpp"
#include "WindowsError.hpp"
#include "gui/Widget.hpp"
#include "gui/Frame.hpp"
#include "gui/Button.hpp"
#include "gui/ComboBox.hpp"
#include "gui/TextBox.hpp"
#include "gui/Label.hpp"

using namespace gui;

class MainFrame : public Frame {
public:
	MainFrame(const std::wstring &title) : Frame(L"MainFrame", title), button(this), comboBox(this), textBox(this), label(this) {
		this->setBounds(Rect(0, 0, 300, 400));
		this->setVisible(true);

		comboBox.setBounds(Rect(150, 10, 250, 45));
		comboBox.addItem(L"Probando 1 2 3");
        comboBox.setItem(0, L"Hola");
        comboBox.setSelectedItemIndex(0);

		textBox.setBounds(Rect(10, 10, 100, 45));
		textBox.setText(L"Hola, mundo!");

		button.setText(L"Hello, world!");
		button.setBounds(Rect(10, 60, 100, 135));

		button.commandSignal.connect(std::bind([]() {
			::MessageBox(NULL, L"Click Bar", L"Message", MB_OK | MB_ICONINFORMATION);
		}));

		button.commandSignal.connect(std::bind([]() {
			::MessageBox(NULL, L"Click Foo", L"Message", MB_OK | MB_ICONINFORMATION);
		}));

		label.setBounds(Rect(100, 200, 200, 235));
		label.setText(L"Hallo!");

        button.setFocus();
	}

private:
	Button button;
	ComboBox comboBox;
	TextBox textBox;
	Label label;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    try {
	    MainFrame frame1(L"Hola!");
	    Application app;

	    app.run();
    } catch (const std::exception &exp) {
        wchar_t exceptionMsg[1024] = {0};

        ::mbstowcs(exceptionMsg, exp.what(), ::strlen(exp.what()));
        ::MessageBox(NULL, exceptionMsg, L"Whooops!, runtime exception!", MB_OK | MB_ICONERROR);
    }

    return 0;
}
