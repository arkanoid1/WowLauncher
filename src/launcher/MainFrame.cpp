
#include "MainFrame.hpp"

MainFrame::MainFrame(const std::wstring &title) : Frame(L"MainFrame", title), button(this), comboBox(this), textBox(this), label(this), listView(this, {L"Col 1", L"Col 2", L"Col 3"}) {
	this->setBounds(gui::Rect(0, 0, 300, 400));
	this->setVisible(true);

	comboBox.setBounds(gui::Rect(150, 10, 250, 45));
	comboBox.addItem(L"Probando 1 2 3");
	comboBox.setItem(0, L"Hola");
	comboBox.setSelectedItemIndex(0);

	textBox.setBounds(gui::Rect(10, 10, 100, 45));
	textBox.setText(L"Hola, mundo!");

	button.setText(L"Hello, world!");
	button.setBounds(gui::Rect(10, 60, 100, 135));

	button.commandSignal.connect(std::bind([]() {
		gui::MessageBox::show(L"Click 1", L"Message");
	}));

	label.setBounds(gui::Rect(100, 200, 200, 235));
	label.setText(L"Hallo!");

	listView.setBounds(gui::Rect(300, 300, 600, 600));
	listView.addRow();
	listView.addRow();
	listView.addRow();
	listView.addRow();

	button.setFocus();

	HWND hWnd = this->getHandle();

	HMENU hMenu = ::CreateMenu();

	::AppendMenu(hMenu, MF_ENABLED | MF_STRING, 1000, L"File");
	::AppendMenu(hMenu, MF_ENABLED | MF_STRING, 1001, L"Edit");
	
	::SetMenu(hWnd, hMenu);
}
