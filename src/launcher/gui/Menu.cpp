
#include "Menu.hpp"
#include "MenuItem.hpp"
#include "MenuBar.hpp"

#include "../WindowsError.hpp"

namespace gui {
    Menu::Menu(MenuBar *menuBar, const std::wstring &text) : menuBar(NULL) {
        if (menuBar == nullptr) {
            throw std::runtime_error("Menu::Menu: Menubar pointer can't be null.");
        }

        MenuHandler menuHandler;

        if (::AppendMenu(menuBar->getHandle(), MF_POPUP | MF_ENABLED | MF_STRING, (UINT_PTR)menuHandler.hMenu, text.c_str()) == FALSE) {
            throw WindowsError(::GetLastError());
        }

        this->menuHandler = menuHandler;
	}

	Menu::~Menu() {}
}
