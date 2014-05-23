
#include "MenuBar.hpp"
#include "../WindowsError.hpp"

namespace gui {
	MenuBar::MenuBar(Frame *parent_) : parent(parent_), hMenu(NULL) {
		hMenu = ::CreateMenu();
		if (!hMenu) {
			throw WindowsError(::GetLastError());
		}

		if (::SetMenu(parent->getHandle(), this->hMenu) == FALSE) {
			throw WindowsError(::GetLastError());
		}
	}

	MenuBar::~MenuBar() {
		if (hMenu) {
			::DestroyMenu(hMenu);
		}
	}

	Frame* MenuBar::getParent() {
		return parent;
	}

	const Frame* MenuBar::getParent() const {
		return parent;
	}

	MenuHandle MenuBar::getHandle() const {
		return hMenu;
	}

	Menu* MenuBar::addMenu(const std::wstring &text) {
		return nullptr;
	}
}
