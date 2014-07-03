
#ifndef __GUI_FRAME_HPP__
#define __GUI_FRAME_HPP__

#include <Windows.h>
#include <string>
#include "Widget.hpp"
#include "MenuBar.hpp"

namespace gui {

    class MenuBar;
	class WindowClass {
	public:
		WindowClass(const std::wstring &className_);
		~WindowClass();

	private:
		std::wstring className;
	};

	class Frame : public WindowClass, public Widget {
	public:
		Frame(const std::wstring &className, const std::wstring &title);
		
        void setMenuBar(MenuBar &menuBar);
        MenuBar& getMenuBar();
        const MenuBar& getMenuBar() const;

    private:
        MenuBar menuBar;

	private:
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	};
}

#endif	//__GUI_FRAME_HPP__
