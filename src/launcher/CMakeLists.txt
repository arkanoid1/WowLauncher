
add_definitions(-DUNICODE -D_UNICODE)

set (BASE_SOURCES 
	Manifest.cpp
	Main.hpp 			Main.cpp
	MainWindow.hpp 		MainWindow.cpp
	Process.hpp 		Process.cpp
	Realm.hpp 			Realm.cpp
	RealmList.hpp 		RealmList.cpp
	WindowsError.hpp 	WindowsError.cpp
	Application.hpp 	Application.cpp)

set (GUI_SOURCES
	gui/MessageBox.hpp 	gui/MessageBox.cpp
	gui/Frame.hpp 		gui/Frame.cpp
	gui/Dialog.hpp 		gui/Dialog.cpp
	gui/Widget.hpp 		gui/Widget.cpp
	gui/Label.hpp 		gui/Label.cpp
	gui/ComboBox.hpp 	gui/ComboBox.cpp
	gui/TextBox.hpp 	gui/TextBox.cpp
	gui/Button.hpp 		gui/Button.cpp
	gui/Image.hpp 		gui/Image.cpp
)

source_group("\\" FILES ${BASE_SOURCES})
source_group("\\gui" FILES ${GUI_SOURCES})

add_executable(WowLauncher WIN32 ${BASE_SOURCES} ${GUI_SOURCES})
