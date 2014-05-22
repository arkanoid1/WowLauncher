
#include "../WindowsError.hpp"
#include "ComboBox.hpp"
#include <CommCtrl.h>

namespace gui {
	ComboBox::ComboBox(Widget *parent) {
		if (parent == nullptr) {
			throw WindowsError( ::GetLastError() );
		}

		HWND parentHandle = parent->getHandle();

		Widget::create(NULL, L"COMBOBOX", L"", CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_VISIBLE, 0, 0, 50, 50, parentHandle, NULL);
	}

	int ComboBox::getItemCount() const {
		return ::SendMessage(hWnd, (UINT)CB_GETCOUNT, (WPARAM)0, (LPARAM)0);
	}

	std::wstring ComboBox::getItem(int index) const {
        if (index<0 || index>=this->getItemCount()) {
            throw std::logic_error("ComboBox::getItem: Index out of bounds.");
        }

        wchar_t itemText[1024] = {0};
        ::SendMessage(hWnd, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)itemText);

		return itemText;
	}

	void ComboBox::setItem(int index, const std::wstring &item) {
        ::SendMessage(hWnd, (UINT)CB_ADDSTRING, index, (LPARAM)item.c_str());
	}

	void ComboBox::addItem(const std::wstring &item) {
		::SendMessage(hWnd, (UINT)CB_ADDSTRING, 0, (LPARAM)item.c_str());
	}

    void ComboBox::clearItems() {
        ::SendMessage(hWnd, (UINT)CB_RESETCONTENT, 0, 0);
    }

    int ComboBox::getSelectedItemIndex() const {
        return ::SendMessage(hWnd, (UINT)CB_GETCURSEL, 0, 0);
    }

    void ComboBox::setSelectedItemIndex(int itemIndex) {
        ::SendMessage(hWnd, (UINT)CB_SETCURSEL, itemIndex, 0);
    }
}
