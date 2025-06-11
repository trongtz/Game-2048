#pragma once
#include "Struct_Stack.h";

//cac ham check dang nhap va dang ki
void SignIn_Up(Game2048& myGame);
bool wordCheck(string t); //ham kiem tra ten va mat khau hop le
void SavePlayer(string Name, string Pass);
void SavePlayerPoint(Game2048& myGame); //luu thong tin vao 5 tai khoan duoc sao luu
void readPlayer(Game2048& myGame);
void SavePoint(Game2048& myGame); //ham cap nhat diem cao nhat cua cac nguoi choi
void SaveTime(Game2048& myGame); //ham cap nhat thoi gian choi
void readPlayerPoint(Game2048& myGame, int n);  //ham lay thong tin khi dung resume
void showList(Game2048& myGame); //ham show 5 tai khoan duoc resume
void Resume(Game2048& myGame); //ham resume