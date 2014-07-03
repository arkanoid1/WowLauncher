
#ifndef __GUI_MENUITEM_HPP__
#define __GUI_MENUITEM_HPP__

#include "Menu.hpp"

namespace gui {
    struct MenuItemType {
        enum Enum {
            Item,
            Separator
        };
    };

	class MenuItem {
	public:
        MenuItem(const Menu &parentMenu, const MenuItemType::Enum menuItemType);
		MenuItem(const Menu &parentMenu, const MenuItemType::Enum menuItemType, const std::wstring &text);
		~MenuItem();

        const int getId() const;
        const Menu& getParentMenu() const;

        void setText(const std::wstring &text);
        std::wstring getText() const;

    private:
        void init(const Menu &parentMenu, const MenuItemType::Enum menuItemType, const std::wstring &text);

	private:
		const Menu &parentMenu;
		const int menuId;
        const MenuItemType::Enum type;
        std::wstring text;

	private:
		static int menuItemCount;
	};
}

#endif	//__GUI_MENUITEM_HPP__
