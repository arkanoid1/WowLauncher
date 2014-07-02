
#ifndef __GUI_MENUITEM_HPP__
#define __GUI_MENUITEM_HPP__

#include "Menu.hpp"

namespace gui {
	class MenuItem {
	public:
		MenuItem(Menu *parentMenu, const std::wstring &text);
		~MenuItem();

        const int getId() const;
        Menu* getParentMenu() const;

        void setText(const std::wstring &text);
        std::wstring getText() const;

	private:
		Menu *parentMenu;
		const int menuId;
        std::wstring text;

	private:
		static int menuItemCount;
	};
}

#endif	//__GUI_MENUITEM_HPP__
