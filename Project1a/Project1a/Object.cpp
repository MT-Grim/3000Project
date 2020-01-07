
#include "Object.h"
#include "LogManager.h"
#include "WorldManager.h"

namespace df {

	

	Object::Object() {

		setType("Object");
		
		static int newestId = 0;

		newestId++;

		m_id = newestId;

		WM.insertObject(this);

	}

	Object::~Object() {

		WM.removeObject(this);

	}

	void Object::setId(int new_id) {

		m_id = new_id;

	}

	int Object::getId() const {

		return m_id;

	}

	void Object::setType(std::string new_type) {

		m_type = new_type;

	}

	std::string Object::getType() const {

		return m_type;

	}

	void Object::setPosition(Vector new_pos){

		m_position = new_pos;

	}

	Vector Object::getPosition() const {

		return m_position;

	}

	int Object::eventHandler(const Event* p_e) {

		return 0;

	}

	void Object::testObject() {
		/*
		LM.writeLog("Start Object Tests");

		LM.writeLog("");

		///tests

		Object o;

		o.setId(2);

		if (o.getId() == 2) {

			LM.writeLog("getId() and setId() tests passed");

		}
		else {
			LM.writeLog("getId() and setId() tests failed");
		}

		o.setType("test");

		if (o.getType() == "test") {

			LM.writeLog("getType() and setType() tests passed");

		}
		else {

			LM.writeLog("getType() and setType() tests failed");

		}

		Vector v;

		v.setXY(1.0, 1.0);

		o.setPosition(v);

		if (o.getPosition().getX() == 1.0 && o.getPosition().getY() == 1.0) {

			LM.writeLog("getPosition() and setPosition() tests passed");

		}
		else {

			LM.writeLog("getPosition() and setPosition() tests failed");

		}

		Object t;

		LM.writeLog("t Id: %d", t.getId());

		Object c;

		LM.writeLog("c Id: %d", c.getId());

		Object z;

		LM.writeLog("z Id: %d", z.getId());

		if (t.getId() == 3 && c.getId() == 4 && z.getId() == 5) {

			LM.writeLog("ID incrementation test passed");

		}
		else {

			LM.writeLog("ID incrementation test failed");

		}

		LM.writeLog("");
		
		LM.writeLog("End Object Tests");

		LM.writeLog("*******");
		*/
	}
}