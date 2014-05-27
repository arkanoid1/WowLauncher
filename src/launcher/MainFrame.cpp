
#include "MainFrame.hpp"

using namespace gui;

std::ostream& operator<< (std::ostream &os, const Size &size) {
    os << size.width << ", " << size.height;
    return os;
}

MainFrame::MainFrame(const std::wstring &title) : Frame(L"MainFrame", title), listView(this, {L"Col 1", L"Col 2", L"Col 3"}) {
	setBounds(gui::Rect(0, 0, 300, 400));
	setVisible(true);
}
