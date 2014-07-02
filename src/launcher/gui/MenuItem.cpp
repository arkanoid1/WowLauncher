
#include "MenuItem.hpp"
#include "../WindowsError.hpp"
#include <Windows.h>

namespace gui {
	int MenuItem::menuItemCount = 1000;

    MenuItem::MenuItem(Menu *parentMenu_, const std::wstring &text) : parentMenu(parentMenu_), menuId(++MenuItem::menuItemCount) {
        if (parentMenu == nullptr) {
            throw std::runtime_error("MenuItem::MenuItem: The parent menu can't be 'nullptr'");
        }

        if (!::AppendMenu(parentMenu->getHandle(), MF_STRING | MF_ENABLED, (UINT_PTR)this->menuId, text.c_str())) {
            throw WindowsError();
        }
	}

    const int MenuItem::getId() const {
        return this->menuId;
    }

    Menu* MenuItem::getParentMenu() const {
        return this->parentMenu;
    }

	MenuItem::~MenuItem() {
        if (this->parentMenu != nullptr && this->menuId != 0) {
            ::RemoveMenu(this->parentMenu->getHandle(), this->menuId, MF_BYCOMMAND);
        }
    }

    void MenuItem::setText(const std::wstring &text) {
        if (::ModifyMenu(this->getParentMenu()->getHandle(), this->getId(), MF_BYCOMMAND | MF_STRING, this->getId(), text.c_str()) == FALSE) {
            throw WindowsError();
        }

        this->text = text;
    }

    std::wstring MenuItem::getText() const {
        return this->text;
    }
}
