
#ifndef __LAUNCHER_PROCESS_HPP__
#define __LAUNCHER_PROCESS_HPP__

#include <Windows.h>

#include <string>
#include <list>

namespace launcher {
	class Process {
	public:
		Process();
		Process(const std::wstring &name);
		Process(const std::wstring &name, const std::wstring &cmdLine);

		~Process();

		void open(const std::wstring &name);
		void open(const std::wstring &name, const std::wstring &cmdLine);
		void close();

		void start();
		void wait();

		void terminate();

		int getExitCode() const;

	private:
		PROCESS_INFORMATION processInfo;
	};
}

#endif	// __LAUNCHER_PROCESS_HPP__
