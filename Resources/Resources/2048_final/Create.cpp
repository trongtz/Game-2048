#include "2048.h"
//khoi tao cac gia tri ma tran =0
void TaoMaTran(Game2048& myGame) {
	for (int i = 0; i < (myGame.sizeOfMatrix); i++) {
		for (int j = 0; j < (myGame.sizeOfMatrix); j++) {
			myGame.Matrix[i][j] = 0;
		}
	}
}

// radom so theo ti le 20 duoc so 4
int TaoSo() {
	srand(time(0));
	int a = rand() % 20;
	if (a) return 2;
	return 4;
}

//khoi tao 2 gia tri
void KhoiTao(Game2048& myGame) {
	srand(time(0));
	int x, y, x1, y1;
	x = rand() % (myGame.sizeOfMatrix);
	y = rand() % (myGame.sizeOfMatrix);
	myGame.Matrix[x][y] = TaoSo();
	do {
		x1 = rand() % (myGame.sizeOfMatrix);
		y1 = rand() % (myGame.sizeOfMatrix);
	} while (x1 == x || y1 == y);
	myGame.Matrix[x1][y1] = TaoSo();

}

//them so 2 hoac 4 moi khi di chuyen 
void ThemSo(Game2048& myGame) {
	int i, j;
	do {
		i = rand() % (myGame.sizeOfMatrix);
		j = rand() % (myGame.sizeOfMatrix);
	} while (myGame.Matrix[i][j]);
	myGame.Matrix[i][j] = TaoSo();
}

//ham in ma tran
void Inmatran(Game2048& myGame) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(0, 0);
	DrawMatrix(myGame.sizeOfMatrix);
	

	for (int j = 0; j < (myGame.sizeOfMatrix); j++) {
		for (int i = 0; i < (myGame.sizeOfMatrix); i++) {
			gotoxy(4 + j * 8 , 2 + i * 4);
			if (myGame.Matrix[i][j] == 2) {
				SetConsoleTextAttribute(h, 14);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 4) {
				SetConsoleTextAttribute(h, 6);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 8) {
				SetConsoleTextAttribute(h, 12);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 16) {
				SetConsoleTextAttribute(h, 11);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 32) {
				SetConsoleTextAttribute(h, 10);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 64) {
				SetConsoleTextAttribute(h, 9);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 128) {
				SetConsoleTextAttribute(h, 8);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 256) {
				SetConsoleTextAttribute(h, 7);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 512) {
				SetConsoleTextAttribute(h, 13);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 1024) {
				SetConsoleTextAttribute(h, 5);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 2048) {
				SetConsoleTextAttribute(h, 4);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 4096) {
				SetConsoleTextAttribute(h, 3);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 8192) {
				SetConsoleTextAttribute(h, 2);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 16384) {
				SetConsoleTextAttribute(h, 4);
				printf("%d", myGame.Matrix[i][j]);
			}
			else if (myGame.Matrix[i][j] == 32768) {
				SetConsoleTextAttribute(h, 4);
				printf("%d", myGame.Matrix[i][j]);
			}
		}
	}

	if (myGame.Diemcao < myGame.Diem) {
		myGame.Diemcao = myGame.Diem;
	}
	if (myGame.Diemcao > myGame.playerList[myGame.stt].Max_Point) {
		myGame.playerList[myGame.stt].Max_Point = myGame.Diemcao;
	}

	SetConsoleTextAttribute(h, 14);
	gotoxy(82, 0);
	cout << "|Player: ";
	SetConsoleTextAttribute(h, 10);
	gotoxy(91,0);
	cout << myGame.Name;
	gotoxy(82, 2);
	SetConsoleTextAttribute(h, 14);
	cout << "|Score: ";
	SetConsoleTextAttribute(h, 2);
	cout << myGame.Diem <<"       "<< endl;
	gotoxy(82, 3);
	SetConsoleTextAttribute(h, 14);
	cout << "|Best: ";
	SetConsoleTextAttribute(h, 2);
	cout<< myGame.playerList[myGame.stt].Max_Point<<endl;
	gotoxy(82, 4);
	SetConsoleTextAttribute(h, 4);
	int best = myGame.playerList[0].Max_Point;
	for (int i = 1; i < myGame.NOP; i++) {
		if (myGame.playerList[i].Max_Point > best) {
			best = myGame.playerList[i].Max_Point;
		}
	}
	cout << "|Top 1: " << best << "   " << endl; //cap nhat top1 
	if (myGame.undo_redo == true) {
		gotoxy(82, 6);
		SetConsoleTextAttribute(h, 14);
		cout << "|UNDO: ";
		SetConsoleTextAttribute(h, 8);
		cout << "[ U ]                  ";
		gotoxy(82, 7);
		SetConsoleTextAttribute(h, 14);
		cout << "|REDO: ";
		SetConsoleTextAttribute(h, 8);
		cout << "[ R ]                  ";
	}
	gotoxy(82, 9);
	SetConsoleTextAttribute(h, 8);
	cout << "|EXIT AND SAVE: ";
	cout << "[ E ].";
}