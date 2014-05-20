
add_definitions(-DUNICODE -D_UNICODE)

add_executable(Launcher WIN32 
	Manifest.cpp
	Main.hpp 			Main.cpp
	MainWindow.hpp 		MainWindow.cpp
	Process.hpp 		Process.cpp
	Realm.hpp 			Realm.cpp
	RealmList.hpp 		RealmList.cpp
	WindowsError.hpp 	WindowsError.cpp

	gui/Widget.hpp 		gui/Widget.cpp
	gui/Label.hpp 		gui/Label.cpp
	gui/ComboBox.hpp 	gui/ComboBox.cpp
	gui/Frame.hpp 		gui/Frame.cpp
	gui/Button.hpp 		gui/Button.cpp
	gui/Image.hpp 		gui/Image.cpp
)

target_link_libraries(Launcher vaca)
