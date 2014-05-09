
add_definitions(-DUNICODE -D_UNICODE)

add_executable(Launcher WIN32 
	Main.hpp 			Main.cpp
	MainWindow.hpp 		MainWindow.cpp
	Process.hpp 		Process.cpp
	Realm.hpp 			Realm.cpp
	RealmList.hpp 		RealmList.cpp
	WindowsError.hpp 	WindowsError.cpp
)

target_link_libraries(Launcher vaca)
