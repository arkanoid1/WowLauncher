
#include <vaca/Vaca.h>

using namespace Vaca;

class MainFrame : public Frame {
public:
	MainFrame() : Frame(L"WoW Launcher"), realmComboBox(this) {
		setLayout(new BoxLayout(Orientation::Vertical, false));

		realmComboBox.addItem(L"LALA");

		setSize(getPreferredSize());
		center();
	}

private:
	ComboBox realmComboBox;
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	using namespace Vaca;

	Application app;

	MainFrame mainFrame;
	mainFrame.setVisible(true);

	app.run();

	return 0;
} 
