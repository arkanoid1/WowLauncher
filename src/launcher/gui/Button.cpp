
#include "Button.hpp"

namespace gui {
	Button::Button(Widget *parent) {
		this->create(parent, L"");
	}

	Button::Button(Widget *parent, const std::wstring &title) {
		this->create(parent, title.c_str());
	}

	void Button::create(Widget *parent, const wchar_t *title) {
		if (parent == nullptr) {
			throw std::runtime_error("Button::Button: Parent can't be a null pointer.");
		}

		HWND parentHandle = parent->getHandle();

		Widget::create(L"BUTTON", title, BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 0, 0, 50, 50, parentHandle, NULL);
	}
}
