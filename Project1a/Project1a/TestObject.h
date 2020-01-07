#pragma once

#include "Object.h"
#include "Vector.h"


class TestObject : public df::Object {

public:
	TestObject();
	df::Vector m_pos;
	void EventHandler(const df::Event* p_e);
	void setPos(df::Vector v);
	void setPos(int X, int Y);
	df::Vector getPos() const;
};

