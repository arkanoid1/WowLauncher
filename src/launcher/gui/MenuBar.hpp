
#ifndef __GUI_MENUBAR_HPP__
#define __GUI_MENUBAR_HPP__

#include "Frame.hpp"
#include "Menu.hpp"

namespace gui {
	typedef HMENU MenuHandle;

	class Menu;
	class MenuBar {
	public:
		MenuBar(Frame *parent);
		~MenuBar();

		Frame* getParent();
		const Frame* getParent() const;

		MenuHandle getHandle() const;

		Menu* addMenu(const std::wstring &text);

	private:
		Frame *parent;
		HMENU hMenu;
	};
}

#endif	//__GUI_MENUBAR_HPP__
