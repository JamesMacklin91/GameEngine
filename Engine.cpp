#include "Engine.h"

//Additional include files
#include "System.h"

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
}
int Engine::Draw()
{

}
int Engine::Update()
{

}
int Engine::ShutDown()
{
	m_EngineState = EngineState::ShuttingDown
}

//Add a core system to the engine
int AddSystem(System* psys)
{

}

//Create the game instance
Game* CreateGame()
{

}
#pragma endregion