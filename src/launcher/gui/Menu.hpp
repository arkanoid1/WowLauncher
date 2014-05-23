
#ifndef __GUI_MENU_HPP__
#define __GUI_MENU_HPP__

#include <string>

namespace gui {
	class MenuItem;
	class MenuBar;

	class Menu {
	protected:
		Menu(MenuBar *menuBar, const std::wstring &text);
		~Menu();

	public:
		MenuItem* addMenuItem(const std::wstring &text);

	private:
		MenuBar *menuBar;

	private:
		static int count;
	};
}

#endif	//__GUI_MENU_HPP__
