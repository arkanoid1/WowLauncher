
#ifndef __GUI_WIDGET_HPP__
#define __GUI_WIDGET_HPP__

#include <Windows.h>
#include <functional>
#include <map>
#include <vector>
#include <list>
#include <boost/signals2.hpp>

namespace gui {

    struct Position {
        int x, y;

        Position() : x(0), y(0) {}
        Position(int x_, int y_) : x(x_), y(y_) {}
    };

    struct Size {
        int width, height;

        Size() : width(0), height(0) {}
        Size(int w, int h) : width(w), height(h) {}
    };

    struct Rect {
		int left, top;
		int right, bottom;

		Rect() : left(0), top(0), right(0), bottom(0) {}
		Rect(int left_, int top_, int right_, int bottom_) : left(left_), top(top_), right(right_), bottom(bottom_) {}

        Size getSize() const {
            return Size(right - left, bottom - top);
        }

        void setSize(const Size &size) {
            this->right = this->left + size.width;
            this->bottom = this->top + size.height;
        }

        Position getPosition() const {
            return Position(this->left, this->top);
        }

        void setPosition(const Position &pos) {
            int dx = pos.x - this->left;
            int dy = pos.y - this->top;

            this->left += dx;
            this->right += dx;

            this->top += dy;
            this->bottom += dy;
        }
	};

	class Widget;

	typedef std::function<void ()> Slot;
	typedef boost::signals2::signal<void()> Signal;

	class Widget {
	public:
		Signal commandSignal;

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

		void setEnable(bool enable);
		bool getEnable() const;

        bool hasFocus() const;
        void setFocus();
        void tryFocus();

	protected:
		void destroy();
		void create(DWORD dwExStyle, const wchar_t *lpClassName, const wchar_t *lpWindowName, DWORD dwStyle, int x, int y, int w, int h, HWND hWndParent, HMENU hMenu);

	protected:
		HWND hWnd;
	};
}

#endif	//__GUI_WIDGET_HPP__
