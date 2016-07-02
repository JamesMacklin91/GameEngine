#include "WinMain.h"

//Additional include files
#include "Engine.h"

#ifndef _STRING_H
	#include "string.h"
#endif
#ifndef _IOSTREAM_H
	#include "iostream.h"
#endif

#ifndef _DELETEMACRO_H
	#include "deletemacros.h"
#endif

#if defined (DEBUG)|| defined(_DEBUG)
int _tmain(int argc, char* argv[])
{
	//unreferenced paramter means the variables will not be used
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	//logger::Log("Starting the program");

	//run winmain function
	WinMain((HINSTANCE)GetModuleHandle(NULL), 0, 0, SW_SHOW);
}
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//shows again the variables will not be used
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

#if defined(DEBUG)||defined(_DEBUG)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	//enable runtime memory leak check for debug builds
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(0);//memory leak id goes into function when debugging
#endif

	//Create the engine
	Engine* pEngine = new Engine();

	//kick off the game
	int result = pEngine->RunLoop();

	//Delete the engine
	SafeDelete(pEngine);

	return result;

	
}
