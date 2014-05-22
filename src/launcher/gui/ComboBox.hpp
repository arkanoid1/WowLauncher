
#ifndef __GUI_COMBOBOX_HPP__
#define __GUI_COMBOBOX_HPP__

#include "Widget.hpp"

namespace gui {
	class ComboBox : public Widget {
	public:
		ComboBox(Widget *parent);

        void clearItems();

		int getItemCount() const;
		std::wstring getItem(int index) const;

		void setItem(int index, const std::wstring &item);
		void addItem(const std::wstring &item);

        int getSelectedItemIndex() const;
        void setSelectedItemIndex(int itemIndex);
	};
}

#endif	// __GUI_COMBOBOX_HPP__
