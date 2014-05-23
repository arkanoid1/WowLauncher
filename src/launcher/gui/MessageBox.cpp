
#include "MessageBox.hpp"



namespace gui {

	UINT mapIconFlags(MessageBoxIcon::Enum iconFlags) {
		switch (iconFlags) {
		case MessageBoxIcon::Question: return MB_ICONQUESTION;
		case MessageBoxIcon::Information: return MB_ICONINFORMATION;
		case MessageBoxIcon::Error: return MB_ICONERROR;
		case MessageBoxIcon::Exclamation: return MB_ICONEXCLAMATION;
		}

		return MB_OK;
	}

	UINT mapButtonFlags(MessageBoxButton::Enum iconFlags) {
		return MB_OK;
	}

	UINT mapFlags(MessageBoxIcon::Enum iconFlags, MessageBoxButton::Enum buttonFlags) {
		return mapIconFlags(iconFlags) | mapButtonFlags(buttonFlags);
	}

	MessageBoxButton::Enum unmapFlags(UINT msgboxResult) {
		return MessageBoxButton::OK;
	}

	int MessageBox::show(const std::wstring &msg, const std::wstring &title) {
		return unmapFlags(::MessageBoxW(NULL, msg.c_str(), title.c_str(), mapFlags(MessageBoxIcon::Information, MessageBoxButton::OK)));
	}

	int MessageBox::show(const std::wstring &msg, const std::wstring &title, MessageBoxIcon::Enum icons) {
		return unmapFlags(::MessageBoxW(NULL, msg.c_str(), title.c_str(), mapFlags(icons, MessageBoxButton::OK)));
	}

	int MessageBox::show(const std::wstring &msg, const std::wstring &title, MessageBoxIcon::Enum icons, MessageBoxButton::Enum buttons) {
		return unmapFlags(::MessageBoxW(NULL, msg.c_str(), title.c_str(), mapFlags(icons, buttons)));
	}
}
