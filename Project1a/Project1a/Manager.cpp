#include "Manager.h"

namespace df {

	Manager::Manager() {

		setType("Manager");
		m_is_started = false;

	}

	Manager::~Manager() {



	}

	void Manager::setType(std::string type) {

		m_type = type;

	}

	std::string Manager::getType() const {

		return m_type;

	}

	int Manager::startUp() {

		m_is_started = true;

		if (m_is_started == true) {

			return 0;

		}
		else {

			return -1;

		}

	}

	void Manager::shutDown() {

		m_is_started = false;

	}

	bool Manager::isStarted() const {

		if (m_is_started == false) {

			return false;
		}
		else if (m_is_started == true) {

			return true;

		}
	}

}






