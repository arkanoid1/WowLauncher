
#include "MainFrame.hpp"

using namespace gui;

std::ostream& operator<< (std::ostream &os, const Size &size) {
    os << size.width << ", " << size.height;
    return os;
}

MainFrame::MainFrame(const std::wstring &title) : Frame(L"MainFrame", title), listView(this, {L"Col 1", L"Col 2", L"Col 3"}) {

    MenuBar menuBar;

    Menu fileMenu(menuBar, L"&File");
    MenuItem saveMenuItem(fileMenu, MenuItemType::Item, L"&Save");
    MenuItem exitMenuItem(fileMenu, MenuItemType::Item, L"&Exit");



    this->setBounds(gui::Rect(0, 0, 300, 400));
	this->setVisible(true);
    this->setMenuBar(menuBar);
}
