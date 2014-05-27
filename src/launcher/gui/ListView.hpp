
#ifndef __GUI_LISTVIEW_HPP__
#define __GUI_LISTVIEW_HPP__

#include "Widget.hpp"
#include <vector>

namespace gui {
	class ListView;
	class ListViewRow {
		friend class ListView;

	protected:
		ListViewRow(ListView *listView);

	public:
		ListView* getListView();
		const ListView* getListView() const;

		void setValue(const int columnIndex, const std::wstring &value);
		std::wstring getValue(const int columnIndex) const;

	private:
		ListView *listView;
	};

	class ListView : public Widget {
	public:
		ListView(Widget *parent, const std::vector<std::wstring> &columns);

		int getColumnCount() const;

		int getRowCount() const;
		const ListViewRow* getRow(int rowIndex) const;

		void setValue(const int rowIndex, const int columnIndex, const std::wstring &value);
		std::wstring getValue(const int rowIndex, const int columnIndex) const;

		ListViewRow* getRow(int rowIndex);
		ListViewRow* addRow(int rowIndex);

        ListViewRow* addRow();
        ListViewRow* addRow(const std::vector<std::wstring> &values);

	private:
		int columnCount;
	};
}

#endif	//__GUI_LISTVIEW_HPP__
