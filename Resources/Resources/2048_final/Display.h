#pragma once
#include "Struct_Stack.h";
//cac ham hien giao dien, ve khung, man hinh chinh, va cac muc trong man hinh chinh
void gotoxy(int x, int y); // ham di den toa do (x,y)
void DrawMatrix(int size); //ham ve ma tran n x n
void Main_Dis(Game2048& myGame); //ham ve giao dien chinh

//cac ham thao tach trong man hinh chinh
void NewGame(Game2048& myGame);
void Continue(Game2048& myGame);
void Guide(Game2048& myGame);
void Setting(Game2048& myGame);
void Top20(Game2048& myGame);
