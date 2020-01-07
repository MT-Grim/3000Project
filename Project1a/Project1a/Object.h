#pragma once

#include <string>
#include "Vector.h"
#include "Event.h"

namespace df {

	class Object {

	private:
		int m_id;
		std::string m_type;
		Vector m_position;

	public:
		Object();

		virtual ~Object();

		void setId(int new_id);

		int getId() const;

		void setType(std::string new_type);

		std::string getType() const;

		void setPosition(Vector new_pos);

		Vector getPosition() const;

		virtual int eventHandler(const Event* p_e);

		void testObject();
	};

}
