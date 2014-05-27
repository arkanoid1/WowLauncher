
#include "Widget.hpp"
#include "../WindowsError.hpp"

namespace gui {
	Widget::Widget() : hWnd(NULL) {}

	Widget::~Widget() {
		this->destroy();
	}

	void Widget::destroy() {
		if (hWnd) {
			::DestroyWindow(hWnd);
			this->hWnd = NULL;
		}
	}

	void Widget::setVisible(bool visible) {
		::ShowWindow(hWnd, SW_SHOWDEFAULT);
	}

	bool Widget::getVisible() const {
		return ::IsWindowVisible(hWnd)!=FALSE;
	}

	Handle Widget::getHandle() const {
		return hWnd;
	}

	void Widget::setBounds(const Rect &rect) {
		DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);
        DWORD dwFlags = 0x00000000;
        
        if (this->getVisible()) {
            dwFlags |= SWP_SHOWWINDOW;
        } else {
            dwFlags |= SWP_HIDEWINDOW;
        }

		if (::SetWindowPos(hWnd, NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, dwFlags) == FALSE) {
			throw WindowsError(::GetLastError());
		}
	}

	Rect Widget::getBounds() const {
		RECT rect = {0};

        if (::GetWindowRect(hWnd, &rect) == FALSE) {
            throw WindowsError(::GetLastError());
        }

        if (this->getParent() == nullptr) {
            return Rect(rect.left, rect.top, rect.right, rect.bottom);
        } else {
            POINT pt = {0};
            pt.x = rect.left;
            pt.y = rect.top;

            if (::ScreenToClient(this->getParent()->getHandle(), &pt) == FALSE) {
                throw WindowsError(::GetLastError());
            }

            int width = rect.right - rect.left;
            int height = rect.bottom - rect.top;

            return Rect(pt.x, pt.y, pt.x + width, pt.y + height);
        }
	}

	void Widget::setClientBounds(const Rect &rect_) {
        DWORD dwFlags = SWP_FRAMECHANGED;
        
        if (this->getVisible()) {
            dwFlags |= SWP_SHOWWINDOW;
        } else {
            dwFlags |= SWP_HIDEWINDOW;
        }

        DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);
        DWORD dwExStyle = ::GetWindowLong(hWnd, GWL_EXSTYLE);

        RECT rect = {0};
        rect.left = rect_.left;
        rect.right = rect_.right;
        rect.top = rect_.top;
        rect.bottom = rect_.bottom;
        ::AdjustWindowRectEx(&rect, dwStyle, FALSE, dwExStyle);

        int x = rect.left, y = rect.top;
        int w = rect.right - rect.left, h = rect.bottom - rect.top;

		if (::SetWindowPos(hWnd, NULL, x, y, w, h, dwFlags) == FALSE) {
			throw WindowsError(::GetLastError());
		}
	}

	Rect Widget::getClientBounds() const {
		RECT rect = { 0 };

		if (::GetClientRect(hWnd, &rect) == FALSE) {
			throw WindowsError(::GetLastError());
		} else {
			return Rect(rect.left, rect.top, rect.right, rect.bottom);
		}
	}

    /*
    void Widget::setSize( const Size &size) {
		if (! ::SetWindowPos(this->hWnd, HWND_NOTOPMOST, 0, 0, size.width, size.height, SWP_NOMOVE)) {
			throw WindowsError( ::GetLastError() );
		}
	}

	Size Widget::getSize() const {
		RECT rect = {0};

		if (! ::GetClientRect(this->hWnd, &rect)) {
			throw WindowsError( ::GetLastError() );
		}

		return Size(rect.right-rect.left, rect.bottom-rect.top);
	}


	void Widget::setPosition( const Position &pos) {
		if (this->getParent() == nullptr) {
			if (! ::SetWindowPos(this->hWnd, HWND_NOTOPMOST, pos.x, pos.y, 0, 0, SWP_NOSIZE)) {
				throw WindowsError( ::GetLastError() );
			}
		} else {

		}
	}


	Position Widget::getPosition() const {
		RECT rc = {0};

		if (! ::GetClientRect(this->hWnd, &rc) ) {
			throw WindowsError( ::GetLastError() );
		}

		return Position(rc.left, rc.top);
	}
    */

	Widget* Widget::getParent() {
		HWND hWndParent = ::GetParent(hWnd);

		if (hWndParent == NULL) {
			return nullptr;
		}
		
		LONG lUserData = ::GetWindowLong(hWndParent, GWL_USERDATA);

		if (lUserData == NULL) {
			return nullptr;
		} 

		return reinterpret_cast<Widget*>(lUserData);
	}

	const Widget* Widget::getParent() const {
		return const_cast<Widget*>(this)->getParent();
	}

	std::wstring Widget::getText() const {
		wchar_t buffer[2048] = {0};

		if (::GetWindowText(hWnd, buffer, sizeof(buffer)) == 0) {
			throw WindowsError(::GetLastError());
		}

		return buffer;
	}

	void Widget::setText(const std::wstring &text) {
		if (::SetWindowText(hWnd, text.c_str()) == 0) {
			throw WindowsError(::GetLastError());
		}
	}

	void Widget::create(DWORD dwExStyle, const wchar_t *lpClassName, const wchar_t *lpWindowName, DWORD dwStyle, int x, int y, int w, int h, HWND hWndParent, HMENU hMenu) {
		hWnd = ::CreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, w, h, hWndParent, hMenu, ::GetModuleHandle(NULL), NULL);

		if (hWnd == NULL) {
			throw WindowsError(::GetLastError());
		}

		::SetWindowLong(hWnd, GWL_USERDATA, reinterpret_cast<LONG>(this));

		NONCLIENTMETRICS ncm;
		ncm.cbSize = sizeof(NONCLIENTMETRICS);
		::SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(NONCLIENTMETRICS), &ncm, 0);
		HFONT hFont = ::CreateFontIndirect(&ncm.lfMessageFont);
		::SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, MAKELPARAM(TRUE, 0));
	}

	void Widget::setEnable(bool enable) {
		::EnableWindow(hWnd, enable ? TRUE : FALSE);
	}

	bool Widget::getEnable() const {
		return ::IsWindowEnabled(hWnd) != 0;
	}

    bool Widget::hasFocus() const {
        return ::GetFocus() == this->getHandle();
    }

    void Widget::setFocus() {
        if (::SetFocus(this->hWnd) == NULL) {
            throw WindowsError(::GetLastError());
        }
    }

    void Widget::tryFocus() {
        ::SetFocus(this->hWnd);
    }
}
