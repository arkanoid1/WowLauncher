
#ifndef __GUI_BUTTON_HPP__
#define __GUI_BUTTON_HPP__

#include "Widget.hpp"

namespace gui {
	class Button : public Widget {
	public:
		Button(Widget *parent);
		Button(Widget *parent, const std::wstring &title);

	protected:
		void create(Widget *parent, const wchar_t *title);
	};
}
#endif	//__GUI_BUTTON_HPP__
