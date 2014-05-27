
#ifndef __LAUNCHER_MAINWINDOW_HPP__
#define __LAUNCHER_MAINWINDOW_HPP__

#include <memory>
#include <string>

#include "gui/Widget.hpp"
#include "gui/Frame.hpp"
#include "gui/Button.hpp"
#include "gui/ComboBox.hpp"
#include "gui/TextBox.hpp"
#include "gui/Label.hpp"
#include "gui/MessageBox.hpp"
#include "gui/ListView.hpp"

class MainFrame : public gui::Frame {
public:
	MainFrame(const std::wstring &title);

private:
	gui::ListView listView;
};

#endif	// __LAUNCHER_MAINWINDOW_HPP__
