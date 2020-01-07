
#include <iostream>
#include "LogManager.h"
#include "Clock.h"
#include "Object.h"
#include "GameManager.h"

int main(int argc, const char* argv[])
{
	LM.setFlush(true);
	GM.run();

}