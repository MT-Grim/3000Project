

#include "TestObject.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include <stdlib.h>

TestObject::TestObject() {

	// random starting location
	float x = rand() % 10 + 1;
	float y = rand() % 10 + 1;

	df::Vector v;
	v.setXY(x, y);

	m_pos = v;

};

void TestObject::EventHandler(const df::Event* p_e) {

	if (p_e->getType() == df::STEP_EVENT) {

		this->setPos(rand() % 10 + 1, rand() % 10 + 1);

	}

}

void TestObject::setPos(df::Vector v) {

	m_pos = v;

}

void TestObject::setPos(int X, int Y) {

	df::Vector v;
	v.setXY(X, Y);

	m_pos = v;

}

df::Vector TestObject::getPos() const {

	return m_pos;

}