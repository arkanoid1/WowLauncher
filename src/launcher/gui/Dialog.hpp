
#ifndef __GUI_DIALOG_HPP__
#define __GUI_DIALOG_HPP__

#include "Widget.hpp"

namespace gui {
    struct DialogResult {
        enum Enum {
            Cancel = 0,
            OK = 1
        };
    };

    class Dialog : public Widget {
    public:
        Dialog(Widget *parent);
        virtual ~Dialog() = 0;

        DialogResult::Enum show();
    };
}

#endif  //__GUI_DIALOG_HPP__
