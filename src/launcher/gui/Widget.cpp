
#include "Widget.hpp"
#include "../WindowsError.hpp"

namespace gui {

	Widget::Widget() : hWnd(NULL) {
	}

	Widget::~Widget() {
		if (hWnd) {
			::CloseWindow(hWnd);
			this->hWnd = NULL;
		}
	}

	void Widget::setVisible(bool visible) {
		::ShowWindow(hWnd, SW_SHOWDEFAULT);
	}

	bool Widget::getVisible() const {
		return ::IsWindowVisible(hWnd)!=FALSE;
	}

	HWND Widget::getHandle() const {
		return hWnd;
	}

	void Widget::setBounds(const Rect &rect) {
		DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);

		if (::SetWindowPos(hWnd, NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_FRAMECHANGED) == FALSE) {
			throw launcher::WindowsError(::GetLastError());
		}
	}

	Rect Widget::getBounds() const {
		RECT rect = { 0 };

		if (::GetWindowRect(hWnd, &rect) == FALSE) {
			throw launcher::WindowsError(::GetLastError());
		} else {
			return Rect(rect.left, rect.top, rect.right, rect.bottom);
		}
	}

	void Widget::setClientBounds(const Rect &rect) {
		DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);
		
		if (::SetWindowPos(hWnd, NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_FRAMECHANGED) == FALSE) {
			throw launcher::WindowsError(::GetLastError());
		}
	}

	Rect Widget::getClientBounds() const {
		RECT rect = { 0 };

		if (::GetClientRect(hWnd, &rect) == FALSE) {
			throw launcher::WindowsError(::GetLastError());
		} else {
			return Rect(rect.left, rect.top, rect.right, rect.bottom);
		}
	}
}
