
#include "Main.hpp"
#include "MainWindow.hpp"

namespace launcher {
	int main(int argc, char **argv) {
		return 0;
	}
}

#if defined(_CONSOLE)
int main(int argc, char **argv) {
	return launcher::main(0, nullptr);
}
#else 

#include <Windows.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	return launcher::main(0, nullptr);
}

#endif
