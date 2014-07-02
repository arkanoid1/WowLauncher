

#ifndef __GUI_MENUHANDLER_HPP__
#define __GUI_MENUHANDLER_HPP__

#include <Windows.h>

namespace gui {
    struct MenuHandler {
        HMENU hMenu;

        MenuHandler(HMENU hMenu);
        MenuHandler();
        ~MenuHandler();

        //! Transfiere propiedad del handler interno entre objetos MenuHandler
        MenuHandler& operator= (MenuHandler &other);
    };
}
#endif  //__GUI_MENUHANDLER_HPP__
