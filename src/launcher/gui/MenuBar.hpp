
#ifndef __GUI_MENUBAR_HPP__
#define __GUI_MENUBAR_HPP__

#include "Frame.hpp"
#include "MenuBase.hpp"

namespace gui {
	class MenuBar : public MenuBase {
	public:
		MenuBar(Frame* parentFrame);
		~MenuBar();
	};
}

#endif	//__GUI_MENUBAR_HPP__
