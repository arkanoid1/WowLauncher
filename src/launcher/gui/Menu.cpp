
#include "Menu.hpp"

#include "MenuItem.hpp"
#include "MenuBar.hpp"
#include <Windows.h>

namespace gui {

	int Menu::count = 0;

	Menu::Menu(MenuBar *menuBar, const std::wstring &text) {

	}

	Menu::~Menu() {

	}

	MenuItem* Menu::addMenuItem(const std::wstring &text) {
		return nullptr;
	}
}
