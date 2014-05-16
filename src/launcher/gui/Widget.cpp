
#include "Widget.hpp"
#include "../WindowsError.hpp"

namespace gui {

	Widget::Widget() : hWnd(NULL) {
	}

	Widget::~Widget() {
		this->destroy();
	}

	void Widget::destroy() {
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

	void Widget::connect(int eventType, const Callback &callback) {
		events[eventType].push_back(callback);
	}

	void Widget::disconnect(int eventType, const Callback &callback) {
		CallbackVector& callbacks = events[eventType];

		/*
		auto position = std::find(callbacks.begin(), callbacks.end(), callback);

		if (position != std::end(callbacks)) {
			events[eventType].erase(position);
		}
		*/
	}

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
}
