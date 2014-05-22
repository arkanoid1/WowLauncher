
#ifndef __GUI_DIALOG_HPP__
#define __GUI_DIALOG_HPP__

#include "Widget.hpp"

namespace gui {
    class Dialog : public Widget {
    public:
        Dialog(Widget *parent);
    };
}

#endif  //__GUI_DIALOG_HPP__
