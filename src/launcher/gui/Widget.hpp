
#include <Windows.h>

namespace gui {

	struct Rect {
		int left, top;
		int right, bottom;

		Rect() : left(0), top(0), right(0), bottom(0) {}
		Rect(int left_, int top_, int right_, int bottom_) : left(left_), top(top_), right(right_), bottom(bottom_) {}
	};

	class Widget {
	public:
		Widget();
		virtual ~Widget();

		void setVisible(bool visible);
		bool getVisible() const;

		HWND getHandle() const;

		void setBounds(const Rect &rect);
		Rect getBounds() const;

		void setClientBounds(const Rect &rect);
		Rect getClientBounds() const;

	protected:
		HWND hWnd;
	};
}
