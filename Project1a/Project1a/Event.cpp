#include "Event.h"
#include "LogManager.h"

namespace df {

	Event::Event() {

		m_event_type = "Event";

	}

	Event::~Event() {

		delete &m_event_type;

	}

	void Event::setType(std::string new_type) {

		m_event_type = new_type;

	}

	std::string Event::getType() const {

		return m_event_type;

	}
}