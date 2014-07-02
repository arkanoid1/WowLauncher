
#include "MenuBar.hpp"
#include "../WindowsError.hpp"

namespace gui {
    MenuBar::MenuBar(Frame* parentFrame) {
        ::SetMenu(parentFrame->getHandle(), this->getHandle());
	}

	MenuBar::~MenuBar() {}
}
