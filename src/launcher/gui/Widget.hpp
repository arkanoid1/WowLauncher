
#ifndef __GUI_WIDGET_HPP__
#define __GUI_WIDGET_HPP__

#include <Windows.h>
#include <functional>
#include <map>
#include <vector>
#include <list>
#include <boost/signals2.hpp>

namespace gui {
	struct Rect {
		int left, top;
		int right, bottom;

		Rect() : left(0), top(0), right(0), bottom(0) {}
		Rect(int left_, int top_, int right_, int bottom_) : left(left_), top(top_), right(right_), bottom(bottom_) {}
	};

	class Widget;

	typedef std::function<void ()> Slot;
	typedef boost::signals2::signal<void()> Signal;

	class Widget {
	public:
		Signal clickSignal;

	public:
		Widget();
		virtual ~Widget();

		Widget* getParent();
		const Widget* getParent() const;

		void setVisible(bool visible);
		bool getVisible() const;

		HWND getHandle() const;

		void setBounds(const Rect &rect);
		Rect getBounds() const;

		void setClientBounds(const Rect &rect);
		Rect getClientBounds() const;

		std::wstring getText() const;
		void setText(const std::wstring &text);

	protected:
		void destroy();
		void create(const wchar_t *lpClassName, const wchar_t *lpWindowName, DWORD dwStyle, int x, int y, int w, int h, HWND hWndParent, HMENU hMenu);

	protected:
		HWND hWnd;
	};
}

#endif	//__GUI_WIDGET_HPP__
