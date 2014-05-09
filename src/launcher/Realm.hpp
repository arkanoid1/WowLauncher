
#ifndef __LAUNCHER_REALM_HPP__
#define __LAUNCHER_REALM_HPP__

#include <string>

namespace launcher {
	class Realm {
	public:
		Realm();
		Realm(const std::string &name, const std::string &address);

		bool isValid() const;

		std::string getName() const;
		void setName(const std::string &name);

		void setAddress(const std::string &address);
		std::string getAddress() const;

	private:
		std::string name;
		std::string address;
	};
}

#endif	//__LAUNCHER_REALMLIST_HPP__
