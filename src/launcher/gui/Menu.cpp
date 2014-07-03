
#include "Menu.hpp"
#include "MenuItem.hpp"
#include "MenuBar.hpp"

#include "../WindowsError.hpp"

namespace gui {
    Menu::Menu(const MenuBar &menuBar_, const std::wstring &text) : menuBar(menuBar_) {
        MenuHandler menuHandler;

        if (::AppendMenu(menuBar.getHandle(), MF_POPUP | MF_ENABLED | MF_STRING, (UINT_PTR)menuHandler.hMenu, text.c_str()) == FALSE) {
            throw WindowsError(::GetLastError());
        }

        this->menuHandler = menuHandler;
	}

	Menu::~Menu() {}
}
