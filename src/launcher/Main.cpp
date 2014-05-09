
#include "Process.hpp"

#include <Windows.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	using namespace launcher;

	Process process;
	process.open("C:\\Windows\\notepad.exe");
	process.start();
	process.wait();
	
	return 0;
}
