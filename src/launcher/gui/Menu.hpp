
#ifndef __GUI_MENU_HPP__
#define __GUI_MENU_HPP__

#include <string>
#include <memory>
#include <Windows.h>

#include "MenuBase.hpp"

namespace gui {
	class MenuItem;
	class MenuBar;

	class Menu : public MenuBase {
	public:
		Menu(MenuBar *menuBar, const std::wstring &text);
		~Menu();

	public:
        std::wstring getText() const;
        void setText(std::wstring &text);

	private:
		MenuBar *menuBar;
	};
}

#endif	//__GUI_MENU_HPP__
