#pragma once
#include "Struct_Stack.h";

//cac ham thuc hien chuc nang logic trong game
void ProcessLeft(Game2048& myGame);
void ProcessRight(Game2048& myGame);
void ProcessUp(Game2048& myGame);
void ProcessDown(Game2048& myGame);
void GameProcess(Game2048& myGame);
void EndGame(Game2048& myGame); //ham check end game
void winGame(Game2048& myGame); //ham check win game