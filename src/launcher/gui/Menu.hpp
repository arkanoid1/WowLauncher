
#ifndef __GUI_MENU_HPP__
#define __GUI_MENU_HPP__

#include <string>
#include <memory>
#include <Windows.h>

namespace gui {
	class MenuItem;
	class MenuBar;

    struct MenuHandler {
        HMENU hMenu;

        MenuHandler() : hMenu(NULL) {
            this->hMenu = ::CreateMenu();
        }

        MenuHandler(HMENU hMenu) : hMenu(NULL) {
            this->hMenu = hMenu;
        }

        ~MenuHandler() {
            if (this->hMenu) {
                ::DestroyMenu(hMenu);
            }
        }

        operator HMENU() const {
            return hMenu;
        }


        MenuHandler& operator= (MenuHandler &other) {
            this->hMenu = other.hMenu;
            other.hMenu = NULL;

            return *this;
        }
    };

	class Menu {
	protected:
		Menu(MenuBar *menuBar, const std::wstring &text);
		~Menu();

	public:
		MenuItem* addMenuItem(const std::wstring &text);

        std::wstring getText() const;
        void setText(std::wstring &text);

        int getId() const;

	private:
		MenuBar *menuBar;

	private:
		static int count;
        static const int base = 10000;

    private:
        MenuHandler menuHandler;
	};
}

#endif	//__GUI_MENU_HPP__
