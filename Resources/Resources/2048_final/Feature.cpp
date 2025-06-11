#include "2048.h"

//ham xoa dau nhay trong console
void noneCursorType(bool cursor) {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = cursor;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//ham luu ma tran de undo
void SaveMatrixU(Game2048& myGame) {
	for (int j = myGame.sizeOfMatrix-1; j >= 0; j--) {
		for (int i = myGame.sizeOfMatrix - 1; i >= 0; i--) {
			myGame.und.push(myGame.Matrix[j][i]);
		}
	}
	myGame.und.push(myGame.Diem);
}
//ham luu ma tran de redo
void SaveMatrixR(Game2048& myGame) {
	for (int j = myGame.sizeOfMatrix-1; j >= 0; j--) {
		for (int i = myGame.sizeOfMatrix-1; i >= 0; i--) {
			myGame.red.push(myGame.Matrix[j][i]);
		}
	}
	myGame.red.push(myGame.Diem);
}

void Undo(Game2048& myGame) {
	myGame.Diem = myGame.und.top();
	myGame.und.pop();
	for (int j = 0; j < myGame.sizeOfMatrix; j++) {
		for (int i = 0; i < myGame.sizeOfMatrix; i++) {
			myGame.Matrix[j][i] = myGame.und.top();
			myGame.und.pop();
		}
	}
	myGame.luot--;
	myGame.redo++;
	Inmatran(myGame);
}

void Redo(Game2048& myGame) {
	myGame.Diem = myGame.red.top();
	myGame.red.pop();
	for (int j = 0; j < myGame.sizeOfMatrix; j++) {
		for (int i = 0; i < myGame.sizeOfMatrix; i++) {
			myGame.Matrix[j][i] = myGame.red.top();
			myGame.red.pop();
		}
	}
	myGame.luot++;
	myGame.redo--;
	Inmatran(myGame);
}
