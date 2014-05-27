
#include "ListView.hpp"
#include <CommCtrl.h>

namespace gui {

	ListViewRow::ListViewRow(ListView *listView_) : listView(listView_) {}

	ListView* ListViewRow::getListView() {
		return this->listView;
	}

	const ListView* ListViewRow::getListView() const {
		return this->listView;
	}

	void ListViewRow::setValue(const int columnIndex, const std::wstring &value) {
	}

	std::wstring ListViewRow::getValue(const int columnIndex) const {
		return L"";
	}
}


namespace gui {

	ListView::ListView(Widget *parent, const std::vector<std::wstring> &columns) {
        DWORD dwExStyle = WS_EX_CLIENTEDGE;
		DWORD dwStyle = WS_CHILD | LVS_REPORT | LVS_EDITLABELS | WS_VISIBLE | LVS_SINGLESEL | LVS_SHOWSELALWAYS;
        
		Widget::create(dwExStyle, WC_LISTVIEW, L"", dwStyle, 0, 0, 50, 50, parent->getHandle(), NULL);

        ListView_SetExtendedListViewStyleEx(hWnd, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT);

		// Agregar las columnas
		LVCOLUMN lvc = { 0 };
		lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;

		for (int i=0; i<(int)columns.size() ; ++i) {
			std::wstring column = columns[i];

			lvc.iSubItem = i;
			lvc.pszText = L"HOLA";
			lvc.fmt = LVCFMT_LEFT;
			lvc.cx = 50;

			ListView_InsertColumn(hWnd, i, &lvc);
		}

		this->columnCount = columns.size();
	}

	int ListView::getColumnCount() const {
		return this->columnCount;
	}

	int ListView::getRowCount() const {
		return 0;
	}

	const ListViewRow* ListView::getRow(int rowIndex) const {
		return nullptr;
	}

	void ListView::setValue(const int rowIndex, const int columnIndex, const std::wstring &value)  {
	}

	std::wstring ListView::getValue(const int rowIndex, const int columnIndex) const {
		return L"";
	}

	ListViewRow* ListView::getRow(int rowIndex) {
		return nullptr;
	}

	ListViewRow* ListView::addRow() {
		LVITEM lvItem = {0};

		lvItem.mask = LVIF_TEXT;
		lvItem.pszText = L"Tanteando...";
		::SendMessage(hWnd, LVM_INSERTITEM, 0, (LPARAM)&lvItem);

		for (int i = 1; i<this->columnCount; ++i) {
			lvItem.pszText = L"TanteandXX...";
			lvItem.iSubItem = i;
			::SendMessage(hWnd, LVM_SETITEM, 0, (LPARAM)&lvItem);
		}

		return nullptr;
	}

	ListViewRow* ListView::addRow(int rowIndex) {
		return nullptr;
	}

    ListViewRow* ListView::addRow(const std::vector<std::wstring> &values) {
		LVITEM lvItem = {0};
        
		lvItem.mask = LVIF_TEXT;
		lvItem.pszText = const_cast<LPWSTR>(values[0].c_str());
		::SendMessage(hWnd, LVM_INSERTITEM, 0, (LPARAM)&lvItem);

		for (int i = 1; i<this->columnCount; ++i) {
			lvItem.pszText = const_cast<LPWSTR>(values[i].c_str());
			lvItem.iSubItem = i;
			::SendMessage(hWnd, LVM_SETITEM, 0, (LPARAM)&lvItem);
		}

		return nullptr;
    }
}
