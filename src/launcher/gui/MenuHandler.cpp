
#include "MenuHandler.hpp"
#include "../WindowsError.hpp"

namespace gui {
    MenuHandler::MenuHandler() : hMenu(NULL) {
        this->hMenu = ::CreateMenu();
        if (this->hMenu == NULL) {
            throw WindowsError();
        }
    }

    MenuHandler::MenuHandler(HMENU hMenu) : hMenu(NULL) {
        this->hMenu = hMenu;
    }

    MenuHandler::~MenuHandler() {
        if (this->hMenu) {
            ::DestroyMenu(hMenu);
        }
    }

    MenuHandler& MenuHandler::operator= (MenuHandler &other) {
        if (this != &other) {
            this->hMenu = other.hMenu;
            other.hMenu = NULL;
        } 

        return *this;
    }
}
