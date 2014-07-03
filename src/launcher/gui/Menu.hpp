#ifndef __GUI_MENU_HPP__
#define __GUI_MENU_HPP__

#include <string>
#include <memory>
#include <Windows.h>

#include "MenuBase.hpp"
#include <list>

namespace gui {
	class MenuItem;
	class MenuBar;

	class Menu : public MenuBase {
	public:
        Menu();
		Menu(const MenuBar &menuBar, const std::wstring &text);
		~Menu();

        void addMenu(Menu &menu);
        void addItem(MenuItem &menuItem);
        void addSeparator();

	public:
        std::wstring getText() const;
        void setText(const std::wstring &text);

	private:
        std::list<Menu> menus;
        std::list<MenuItem> items;
	};
}

#endif	//__GUI_MENU_HPP__
