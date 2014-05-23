
#ifndef __GUI_MENUITEM_HPP__
#define __GUI_MENUITEM_HPP__

#include "Widget.hpp"

namespace gui {

	class Menu;

	class MenuItem {
	public:
		Signal commandSignal;

	public:
		MenuItem(Menu *parentMenu, const std::wstring &text);
		~MenuItem();

	private:
		Menu *parentMenu;
		int menuId;

	private:
		static int menuItemCount;
	};
}

#endif	//__GUI_MENUITEM_HPP__
