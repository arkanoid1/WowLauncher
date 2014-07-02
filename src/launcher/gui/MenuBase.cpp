
#include "MenuBase.hpp"

namespace gui {

    MenuBase::MenuBase() {
    }

    MenuBase::~MenuBase() {
    }

    HMENU MenuBase::getHandle() const {
        return this->menuHandler.hMenu;
    }
}
