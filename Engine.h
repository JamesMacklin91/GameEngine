#ifndef _ENGINE_H
#define _ENGINE_H

//C Runtime header files
#ifndef _WINDOWS_
#include<Windows.h>
#endif
#ifndef _MAP_
#include<map>
#endif

//Forward declaration
enum SystemType;

class System;
class Game;

//Enumaration
enum EngineState
{
	Invalid,//When something is wrong
	Constructing,//when everything is getting created
	Initializing,//when its initialising
	Running,//when your going to the main build
	ShuttingDown,//when the engine is shutting down
	Destroying//when the engine is destroying everything created
};

class Engine
{
public:
	Engine();
	~Engine();

	int RunLoop();

	//void* operator new(size_t size);
	//void operator delete(void* pdelete);

	static EngineState GetEngineState(){ return m_EngineState; }

private:

	//returns an int as when something goes wrong we have a value for debugging purposes
	int Initialize();
	int Draw();
	int Update();
	int ShutDown();

	//Add a core system to the engine
	int AddSystem(System* psys);

	//Retrieve a core system from the engine
	//this looks for a system in the engine if it cant find the system its looking for it will return a nullptr
	template<typename T>
	T* GetSystem(SystemType systype)
	{
		T* psys = static_cast<T*>(m_mapSystems[systype]);
		if (!psys)
		{
			//Logger::Log("System is not valid");
			return nullptr;
		}

		return psys;
	}

	//Create the game instance
	Game* CreateGame();

	std::map<SystemType, System*> m_mapSystems;
	static EngineState m_EngineState;
};

#endif