#pragma once

class Clock {

private:
	long int m_previous_time;

public:
	Clock();

	long int delta();

	long int split();

	void testClock();

};
