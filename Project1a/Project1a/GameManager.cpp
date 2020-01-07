#include "GameManager.h"
#include "LogManager.h"
#include "Windows.h"
#include "Clock.h"
#include "Object.h"
#include "Vector.h"
#include "WorldManager.h"
#include "EventStep.h"

#include "TestObject.h"


namespace df {

	GameManager::GameManager() {
	
		setType("GameManager");

		game_over = true;

		frame_time = FRAME_TIME_DEFAULT;
	
	}

	GameManager& GameManager::getInstance() {
		
		static GameManager instance;
		return instance;
	
	}

	//call all the manager startups
	int GameManager::startUp() {
	
		if (LM.startUp()) {
			printf("LM failed to start\n");
			return -1;
		}

		LM.setFlush();
		
		if (WM.startUp()) {
			LM.writeLog("WorldManager failed to start.");
			return -1;
		}

		Object *p_oa = new Object;

		timeBeginPeriod(1);

		setGameOver(false);

		runTests(false);

		return 0;

	}

	void GameManager::shutDown() {
	
		setGameOver(true);

		timeEndPeriod(1);

		WM.shutDown();

		//logmanager goes last 
		LM.shutDown();

	}

	void GameManager::run() {
	
		startUp();

		Clock c;

		int loop_count = 0;

		int loop_time = 0;

		while (game_over == false) {

			c.delta();
			LM.writeLog("1");
			//game code goes here

			std::vector<Object*> all_objects = WM.getAllObjects();
			LM.writeLog("2");
			EventStep s(loop_count);
			LM.writeLog("3");
			std::vector<Object*>::iterator li = all_objects.begin();
			LM.writeLog("4");
			while (li != all_objects.end()) {
				LM.writeLog("5");
				(*li)->eventHandler(&s);
				LM.writeLog("6");
				li++;
			}
			LM.writeLog("7");
			loop_time = c.split();
			LM.writeLog("8");
			if (frame_time - loop_time <= 0) {
				Sleep(0);
			}
			else {
				Sleep(frame_time - loop_time);
			}
			LM.writeLog("9");
			loop_count++;
			LM.writeLog("10");
			LM.writeLog("loop_count in loop = %d", loop_count);
			LM.writeLog("11");
			LM.writeLog("Before check to break out of loop");
			LM.writeLog("12");
			if (loop_count == 100) {
				LM.writeLog("loop_count at shutdown = %d", loop_count);
				LM.writeLog("in shutdown if");
				setGameOver(true);
			}
			

		}

		shutDown();
	
	}

	void GameManager::setGameOver(bool new_game_over) {
	
		game_over = new_game_over;

	}

	bool GameManager::getGameOver() const {
	
		return game_over;

	}

	int GameManager::getFrameTime() {
	
		return frame_time;
	
	}

	void GameManager::runTests(bool run) {

		if (run == true) {

			LM.writeLog("");
			LM.writeLog("*******");

			Clock c;

			c.testClock();

			df::Object l;

			l.testObject();

			df::Vector g;

			g.testVector();

			WM.testWorldManager();

		}

	}

}