#pragma once

#include "Manager.h"
#include "Object.h"
#include <vector>

#define WM df::WorldManager::getInstance()

namespace df {

	class WorldManager : public Manager {

	private:
		WorldManager();
		WorldManager(WorldManager const&);
		void operator=(WorldManager const&);

		std::vector<Object*> m_updates;
		std::vector<Object*> m_deletions;

	public:
		static WorldManager& getInstance();

		int startUp();

		void shutDown();

		int insertObject(Object* p_o);

		int removeObject(Object* p_o);

		std::vector<Object*> getAllObjects() const;

		std::vector<Object*> objectsOfType(std::string type) const;

		void update();

		int markForDelete(Object* p_o);

		void testWorldManager();

	};
}
