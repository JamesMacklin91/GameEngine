#include "Engine.h"

//Additional include files
//ifndef in the header files stops system.h being included more than once
#include "System.h"
#include "Game.h"

#ifndef _DELETEMACRO_H
#include "deletemacros.h"
#endif
#ifndef _STRING_H
#include "string.h"
#endif

//when nothing has happened the engine state is invalid
EngineState Engine::m_EngineState = EngineState::Invalid;

Engine::Engine()
{
	m_EngineState = EngineState::Constructing;
}

Engine::~Engine()
{
	m_EngineState = EngineState::Destroying;
}

//Public Methods
#pragma region Public Methods
int Engine::RunLoop()
{

}
#pragma endregion

//Private Methods
#pragma region Private Methods
int Engine::Initialize()
{
	m_EngineState = EngineState::Initializing;

	Game* game = CreateGame();

	if (!game)
		return false;

	//Add some systems


	return true;
}
int Engine::Draw()
{

}
int Engine::Update()
{

}
int Engine::ShutDown()
{
	m_EngineState = EngineState::ShuttingDown;

	//for every system in our map we delete the system
	for (std::pair<SystemType, System*> psys : m_mapSystems)
	{
		//if (!psys.second->ShutDown())
		//{
			//Log::Logger("Failed to shutdown system " + psys->GetSystemType());
			continue;
		//}

		SafeDelete(psys.second);
	}

	//when every system is deleted return true
	return true;
}

//Add a core system to the engine
int AddSystem(System* psys)
{
	//auto element = m_mapSystems.insert(std::make_pair(psys->GetType(), psys));
	//if (element.second)
		//return true;

	return false;
}

//Create the game instance
Game* Engine::CreateGame()
{
	if (!AddSystem(new Game(GameData())))
		return nullptr;

	//if system did not return a valid game pointer return a nullptr
	Game* game = GetSystem<Game>(SystemType::Sys_Game);
	if (!game)
		return nullptr;

	//initialise if successful
	if (!game->Initialize())
		return nullptr;

	//if everything is successful return game
	return game;
}
#pragma endregion