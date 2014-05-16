
#include <Windows.h>
#include <functional>
#include <map>
#include <vector>
#include <list>

namespace gui {

	struct Rect {
		int left, top;
		int right, bottom;

		Rect() : left(0), top(0), right(0), bottom(0) {}
		Rect(int left_, int top_, int right_, int bottom_) : left(left_), top(top_), right(right_), bottom(bottom_) {}
	};

	class Widget {
	public:
		typedef std::function<void(Widget*)> Callback;
		typedef std::vector<Callback>  CallbackVector;
		typedef std::map<int, CallbackVector> EventCallbackMap;

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

		void connect(int eventType, const Callback &callback);
		void disconnect(int eventType, const Callback &callback);

		CallbackVector& getEventCallbacks(int eventType);

	protected:
		void destroy();

	private:
		EventCallbackMap events;

	protected:
		HWND hWnd;
	};
}
