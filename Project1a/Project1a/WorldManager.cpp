#include "WorldManager.h"
#include "LogManager.h"
#include "Object.h"

#include <vector>

namespace df {

	WorldManager::WorldManager() {

		setType("WorldManager");

	}

	WorldManager& WorldManager::getInstance() {

		static WorldManager instance;
		return instance;

	}

	int WorldManager::startUp() {

		if (Manager::startUp() == 0) {
			return 0;
		}
		else {
			return -1;
		}

	}

	void WorldManager::shutDown() {

		LM.writeLog("m_updates: %d", m_updates.size());

		std::vector<Object*> ol = m_updates;
		std::vector<Object*>::iterator li;

		for (li = ol.begin(); li != ol.end(); li++) {

			LM.writeLog("Hit WM shutdown()");

			delete (*li);

		}

	}

	int WorldManager::insertObject(Object* p_o) {

		int prev_list_size = m_updates.size();

		m_updates.insert(m_updates.end(), p_o);

		int after_list_size = m_updates.size();

		//check if the object at the end of the list has the same type
		//as the object put into the function
		//also check if the size is 1 bigger than before insert
		//
		if(prev_list_size + 1 == after_list_size && m_updates.size() + 1 == prev_list_size) {

			return 0;
			
		}
		else {
			return -1;
			
		}
		
	}

	int WorldManager::removeObject(Object* p_o) {

		for (std::vector<Object*>::iterator li = m_updates.begin(); li != m_updates.end(); li++) {

			if (*li == p_o) {

				m_updates.erase(li);

				return 0;
			}

		}

		return -1;

	}

	std::vector<Object*> WorldManager::getAllObjects() const {

		return m_updates;

	}

	std::vector<Object*> WorldManager::objectsOfType(std::string type) const {

		std::vector<Object*> m_u = m_updates;
		std::vector<Object*> ol;
		std::vector<Object*>::iterator li = m_u.begin();


		for (li; li != m_u.end(); li++) {


			if ((*li)->getType() == type) {

				//       (position, value)
				ol.insert(ol.end(), *li);

			}

		}

		return ol;

	}

	void WorldManager::update() {

		std::vector<Object*>::iterator li = m_deletions.begin();
		while (li != m_deletions.end()) {

			delete (*li);

			li++;

		}

		m_deletions.clear();

	}

	int WorldManager::markForDelete(Object* p_o) {

		std::vector<Object*>::iterator li = m_deletions.begin();

		while (li != m_deletions.end()) {

			if (*li == p_o) {
				return 0;
			}

			li++;

		}

		m_deletions.insert(m_deletions.end(), p_o);

		return 0;
	}

	void WorldManager::testWorldManager() {

		/*
		LM.writeLog("Start WorldManager Tests");

		LM.writeLog("");

		Object c;

		c.setType("WMTest");

		//find better way to test insertObject(). It gets called when the obj is created. 

		if (m_updates.back()->getType() == "WMTest") {
			LM.writeLog("insertObject() test passed");
		}
		else {
			LM.writeLog("insertObject() test failed");
		}

		if (WM.objectsOfType("WMTest").size() == 1) {
			LM.writeLog("objectsOfType() test passed");
		}
		else {
			LM.writeLog("objectsOfType() test failed");
		}

		if (markForDelete(&c) == 0) {
			LM.writeLog("markForDelete() test passed");
		}
		else {
			LM.writeLog("markForDelete() test failed");
		}

		LM.writeLog("");

		LM.writeLog("End WorldManager Tests");

		LM.writeLog("*******");
		*/
	}
}