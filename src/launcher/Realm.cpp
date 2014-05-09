
#include "Realm.hpp"

namespace launcher {
	Realm::Realm() {}

	Realm::Realm(const std::string &name, const std::string &address) {
		this->setName(name);
		this->setAddress(address);
	}

	bool Realm::isValid() const {
		return true;
	}

	std::string Realm::getName() const {
		return this->name;
	}

	std::string Realm::getAddress() const {
		return this->address;
	}

	void Realm::setName(const std::string &name) {
		this->name = name;
	}

	void Realm::setAddress(const std::string &address) {
		this->address = address;
	}
}
