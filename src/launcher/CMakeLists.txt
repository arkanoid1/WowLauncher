
add_executable(Launcher WIN32 
	Main.hpp 			Main.cpp
	MainWindow.hpp 		MainWindow.cpp
	Process.hpp 		Process.cpp
	RealmList.hpp 		RealmList.cpp
	
	win32/MainWindowWin32.hpp	win32/MainWindowWin32.cpp
	win32/ProcessWin32.hpp 		win32/ProcessWin32.cpp
)
