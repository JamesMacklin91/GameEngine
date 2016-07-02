#ifndef _WINMAIN_H
#define _WINMAIN_H

//C Runtime header files
#ifndef _WINDOW
#include <Windows.h>
#endif

int _tmain(int argc, char* argv[]);//used for debugging will display console window
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

#endif// _WINMAIN_H