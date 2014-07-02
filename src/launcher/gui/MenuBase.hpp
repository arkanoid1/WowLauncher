
#ifndef __GUI_MENUBASE_HPP__
#define __GUI_MENUBASE_HPP__

#include "MenuHandler.hpp"

namespace gui {
    class MenuBase {
    public:
        MenuBase();
        MenuBase(HMENU hMenu);
        ~MenuBase();

        HMENU getHandle() const;

    protected:
        MenuHandler menuHandler;
    };
}

#endif  //__GUI_MENUBASE_HPP__
