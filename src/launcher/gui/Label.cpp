
#include "Label.hpp"

namespace gui {
	Label::Label(Widget *parent) {
		Widget::create(NULL, L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_LEFT, 0, 0, 100, 35, parent->getHandle(), NULL);
	}
}
