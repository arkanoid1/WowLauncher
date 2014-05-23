
#include "MenuItem.hpp"

#include <Windows.h>

namespace gui {

	int MenuItem::menuItemCount = 0;

	MenuItem::MenuItem(Menu *parentMenu_, const std::wstring &text) : parentMenu(nullptr), menuId(0) {

		int menuId = ++MenuItem::menuItemCount;

//		::AppendMenu()
	}

	MenuItem::~MenuItem() {

	}
}
