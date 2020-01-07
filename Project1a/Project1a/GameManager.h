#pragma once

#include "Manager.h"
#include "LogManager.h"

const int FRAME_TIME_DEFAULT = 33;

#define GM df::GameManager::getInstance()

namespace df {

	class GameManager : public Manager {

	private:
		GameManager();
		GameManager(GameManager const&);
		void operator=(GameManager const&);
		bool game_over;
		int frame_time;

	public:
		static GameManager& getInstance();

		int startUp();

		void shutDown();

		void run();

		void setGameOver(bool new_game_over = true);

		bool getGameOver() const;

		int getFrameTime();

		void runTests(bool run);

	};

}
