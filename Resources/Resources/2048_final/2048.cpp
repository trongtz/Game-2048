#include "2048.h"

int main() {
	noneCursorType(false); // ham xoa dau nhay trong console
	Game2048 myGame; //tao game
	readPlayer(myGame); //duyet danh sach cac tai khoan truoc khi dang nhap
	Resume(myGame); //hien resume 5 tai khoan
	SignIn_Up(myGame); //dang nhap

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 8);
	return 0;
}