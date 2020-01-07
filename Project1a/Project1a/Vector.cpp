#include "Vector.h"
#include "LogManager.h"

namespace df {

	Vector::Vector() {

		m_x = 0;

		m_y = 0;
	}

	Vector::Vector(float init_x, float init_y) {

		m_x = init_x;

		m_y = init_y;
	}

	void Vector::setX(float new_x) {

		m_x = new_x;

	}

	float Vector::getX() const {

		return m_x;

	}

	void Vector::setY(float new_y) {

		m_y = new_y;

	}

	float Vector::getY() const {

		return m_y;

	}

	void Vector::setXY(float new_x, float new_y) {

		m_x = new_x;

		m_y = new_y;


	}

	Vector Vector::operator+(const Vector& other) const {

		Vector v;

		v.m_x = m_x + other.m_x;

		v.m_y = m_y + other.m_y;

		return v;

	}

	float Vector::getMagnitude() const {

		float mag = sqrt(m_x * m_x + m_y * m_y);
		return mag;

	}

	void Vector::normalize() {

		float length = getMagnitude();
		if (length > 0) {

			m_x = m_x / length;

			m_y = m_y / length;

		}

	}

	void Vector::scale(float s) {

		m_x = m_x * s;

		m_y = m_y * s;
	}

	void Vector::testVector() {
		LM.writeLog("Start Vector Tests");

		LM.writeLog("");

		//test default constructor
		Vector v;

		if (v.getX() == 0) {
			LM.writeLog("v getX() test passed");
		}
		else {
			LM.writeLog("v getX() test failed");
		}

		if (v.getY() == 0) {
			LM.writeLog("v getY() test passed");
		}
		else {
			LM.writeLog("v getY() test failed");
		}

		//test constructor with vals
		Vector c(2.0, 2.0);

		if (c.getX() == 2) {
			LM.writeLog("c getX() test passed");
		}
		else {
			LM.writeLog("c getX() test failed");
		}

		if (c.getY() == 2) {
			LM.writeLog("c getY() test passed");
		}
		else {
			LM.writeLog("c getY() test failed");
		}

		//test sets
		c.setX(3.0);
		c.setY(3.0);

		if (c.getX() == 3 && c.getY() == 3) {
			LM.writeLog("c setX() and setY() tests passed");
		}
		else {
			LM.writeLog("c setX() and setY() tests failed");
		}

		//test setXY
		c.setXY(4.0, 4.0);

		if (c.getX() == 4 && c.getY() == 4) {
			LM.writeLog("c setXY() tests passed");
		}
		else {
			LM.writeLog("c setXY() tests failed");
		}

		//test + operator
		Vector a(1.0, 1.0);

		Vector l = c + a;

		if (l.getX() == 5 && l.getY() == 5) {
			LM.writeLog("+ tests passed");
		}
		else {
			LM.writeLog("+ tests failed");
		}

		//test getMagnitude
		Vector magTest(1, 1);

		if (magTest.getMagnitude() == (float)sqrt(2)) {
			LM.writeLog("getMagnitude() test passed");
		}
		else {
			LM.writeLog("getMagnitude() test failed");
		}

		//test normalize
		Vector d(1, 1);

		Vector b(1, 1);

		float dMag = d.getMagnitude();

		d.setX(d.getX() / dMag);
		d.setY(d.getY() / dMag);

		b.normalize();
		
		if (b.getX() == d.getX() && b.getY() == d.getY()) {
			LM.writeLog("normalize() test passed");
		}
		else {
			LM.writeLog("normalize() test failed");
		}

		//test scale vector
		Vector q(1.0, 1.0);

		q.scale(2);

		if (q.getX() == 2 && q.getY() == 2) {
			LM.writeLog("scale() test passed");
		}
		else {
			LM.writeLog("scale() test failed");
		}

		//this stuff goes at the end
		LM.writeLog("");

		LM.writeLog("End Vector Tests");

		LM.writeLog("*******");
	}

	


}