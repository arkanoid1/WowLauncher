
#include "Menu.hpp"
#include "MenuItem.hpp"
#include "MenuBar.hpp"

#include "../WindowsError.hpp"

namespace gui {

	int Menu::count = 0;

    Menu::Menu(MenuBar *menuBar, const std::wstring &text) : menuHandler(NULL) {
        if (menuBar == nullptr) {
            throw std::runtime_error("Menu::Menu: Menubar pointer can't be null.");
        }

        MenuHandler menuHandler;

        if (::AppendMenu(menuBar->getHandle(), MF_POPUP | MF_ENABLED | MF_STRING, (UINT_PTR)((HMENU)menuHandler), text.c_str()) == FALSE) {
            throw WindowsError(::GetLastError());
        }

        Menu::count++;
        this->menuHandler = menuHandler;
	}

	Menu::~Menu() {
        if (this->hMenu) {
            ::DestroyMenu(NULL);
        }
	}

	MenuItem* Menu::addMenuItem(const std::wstring &text) {
		return nullptr;
	}
}
