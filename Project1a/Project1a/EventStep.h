#pragma once

#include "Event.h"

namespace df {

	const std::string STEP_EVENT = "df::step";

	class EventStep : public Event {

	private:
		int m_step_count;

	public:
		EventStep();

		EventStep(int init_step_count);

		void setStepCount(int new_step_count);

		int getStepCount() const;

	};

}