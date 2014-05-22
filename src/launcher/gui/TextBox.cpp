
#include "TextBox.hpp"

namespace gui {
	TextBox::TextBox(Widget *parent) {
		Widget::create(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE, 0, 0, 100, 50, parent->getHandle(), NULL);
	}
}
