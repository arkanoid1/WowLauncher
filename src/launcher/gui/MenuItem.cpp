
#include "MenuItem.hpp"
#include "../WindowsError.hpp"
#include <Windows.h>

namespace gui {
	int MenuItem::menuItemCount = 1000;

    void MenuItem::init(const Menu &parentMenu, const MenuItemType::Enum menuItemType, const std::wstring &text) {
        DWORD dwFlags = 0L;

        dwFlags = (type==MenuItemType::Separator) ? MF_SEPARATOR : MF_STRING|MF_ENABLED;

        if (!::AppendMenu(parentMenu.getHandle(), dwFlags, (UINT_PTR)this->menuId, text.c_str())) {
            throw WindowsError();
        }

        this->text = text;
    }

    MenuItem::MenuItem(const Menu &parentMenu_, const MenuItemType::Enum type_) :   
        parentMenu(parentMenu_), 
        type(type_), 
        menuId(++MenuItem::menuItemCount) 
    {
        this->init(parentMenu_, type_, L"");
    }

    MenuItem::MenuItem(const Menu &parentMenu_, const MenuItemType::Enum type_, const std::wstring &text) :   
        parentMenu(parentMenu_), 
        type(type_), 
        menuId(++MenuItem::menuItemCount) 
    {
        this->init(parentMenu_, type_, text);
	}

    const int MenuItem::getId() const {
        return this->menuId;
    }

    const Menu& MenuItem::getParentMenu() const {
        return this->parentMenu;
    }

	MenuItem::~MenuItem() {
        ::RemoveMenu(this->parentMenu.getHandle(), this->menuId, MF_BYCOMMAND);
    }

    void MenuItem::setText(const std::wstring &text) {
        if (::ModifyMenu(this->getParentMenu().getHandle(), this->getId(), MF_BYCOMMAND | MF_STRING, this->getId(), text.c_str()) == FALSE) {
            throw WindowsError();
        }

        this->text = text;
    }

    std::wstring MenuItem::getText() const {
        return this->text;
    }
}
