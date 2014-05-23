
#ifndef __GUI_MESSAGEBOX_HPP__
#define __GUI_MESSAGEBOX_HPP__

#include <string>

#include <Windows.h>
#if defined(MessageBox)
#  undef MessageBox
#endif	//MessageBox

namespace gui {
	struct MessageBoxIcon {
		enum Enum {
			Question = 0x01,
			Exclamation = 0x02,
			Information = 0x04,
			Error = 0x08
		};
	};

	struct MessageBoxButton {
		enum Enum {
			OK = 0x01
		};
	};

	class MessageBox {
	public:
		static int show(const std::wstring &msg, const std::wstring &title);
		static int show(const std::wstring &msg, const std::wstring &title, MessageBoxIcon::Enum icons);
		static int show(const std::wstring &msg, const std::wstring &title, MessageBoxIcon::Enum icons, MessageBoxButton::Enum buttons);
	};
}

#endif   // __GUI_MESSAGEBOX_HPP__
