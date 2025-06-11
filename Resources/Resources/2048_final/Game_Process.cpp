#include "2048.h"

void ProcessUp(Game2048& myGame) {
	for (int j = 0; j < myGame.sizeOfMatrix; j++) {
		for (int i = 0; i < myGame.sizeOfMatrix; i++) {
			if (myGame.Matrix[i][j] == 0) {
				for (int h = i + 1; h < myGame.sizeOfMatrix; h++) {
					if (myGame.Matrix[h][j] != 0) {
						myGame.Duocphep = 1;
						myGame.Matrix[i][j] = myGame.Matrix[h][j];
						myGame.Matrix[h][j] = 0;
						i--;

						break;
					}
				}
			}
			else {
				for (int h = i + 1; h < myGame.sizeOfMatrix; h++) {
					if (myGame.Matrix[h][j] != 0) {
						if (myGame.Matrix[i][j] == myGame.Matrix[h][j]) {
							myGame.Duocphep = 1;
							myGame.Matrix[i][j] *= 2;
							myGame.Matrix[h][j] = 0;
							myGame.Diem = myGame.Diem + myGame.Matrix[i][j];

						}
						break;
					}
				}
			}
		}
	}
	if (myGame.Duocphep == 1) {
		ThemSo(myGame);
		myGame.Duocphep = 0;
	}
}
void ProcessDown(Game2048& myGame) {
	for (int j = 0; j < myGame.sizeOfMatrix; j++) {
		for (int i = myGame.sizeOfMatrix-1; i >= 0; i--) {
			if (myGame.Matrix[i][j] == 0) {
				for (int h = i - 1; h >= 0; h--) {
					if (myGame.Matrix[h][j] != 0) {
						myGame.Duocphep = 1;
						myGame.Matrix[i][j] = myGame.Matrix[h][j];
						myGame.Matrix[h][j] = 0;
						i++;
						break;
					}
				}
			}
			else {
				for (int h = i - 1; h >= 0; h--) {
					if (myGame.Matrix[h][j] != 0) {
						if (myGame.Matrix[i][j] == myGame.Matrix[h][j]) {
							myGame.Duocphep = 1;
							myGame.Matrix[i][j] *= 2;
							myGame.Matrix[h][j] = 0;
							myGame.Diem = myGame.Diem + myGame.Matrix[i][j];
						}
						break;
					}
				}
			}
		}
	}
	if (myGame.Duocphep == 1) {
		ThemSo(myGame);
		myGame.Duocphep = 0;
	}
}
void ProcessRight(Game2048& myGame) {
	for (int i = 0; i < myGame.sizeOfMatrix; i++) {
		for (int j = myGame.sizeOfMatrix-1; j >= 0; j--) {
			if (myGame.Matrix[i][j] == 0) {
				for (int h = j - 1; h >= 0; h--) {
					if (myGame.Matrix[i][h] != 0) {
						myGame.Duocphep = 1;
						myGame.Matrix[i][j] = myGame.Matrix[i][h];
						myGame.Matrix[i][h] = 0;
						j++;
						break;
					}
				}
			}
			else {
				for (int h = j - 1; h >= 0; h--) {
					if (myGame.Matrix[i][h] != 0) {
						if (myGame.Matrix[i][j] == myGame.Matrix[i][h]) {
							myGame.Duocphep = 1;
							myGame.Matrix[i][j] *= 2;
							myGame.Matrix[i][h] = 0;
							myGame.Diem = myGame.Diem + myGame.Matrix[i][j];
						}
						break;
					}
				}
			}
		}
	}
	if (myGame.Duocphep == 1) {
		ThemSo(myGame);
		myGame.Duocphep = 0;
	}
}
void ProcessLeft(Game2048& myGame) {
	for (int i = 0; i < myGame.sizeOfMatrix; i++) {
		for (int j = 0; j < myGame.sizeOfMatrix; j++) {
			if (myGame.Matrix[i][j] == 0) {
				for (int h = j + 1; h < myGame.sizeOfMatrix; h++) {
					if (myGame.Matrix[i][h] != 0) {
						myGame.Duocphep = 1;
						myGame.Matrix[i][j] = myGame.Matrix[i][h];
						myGame.Matrix[i][h] = 0;
						j--;
						break;
					}
				}
			}
			else {
				for (int h = j + 1; h < myGame.sizeOfMatrix; h++) {
					if (myGame.Matrix[i][h] != 0) {
						if (myGame.Matrix[i][j] == myGame.Matrix[i][h]) {
							myGame.Duocphep = 1;
							myGame.Matrix[i][j] *= 2;
							myGame.Matrix[i][h] = 0;
							myGame.Diem = myGame.Diem + myGame.Matrix[i][j];
						}
						break;
					}
				}
			}
		}
	}
	if (myGame.Duocphep == 1) {
		ThemSo(myGame);
		myGame.Duocphep = 0;
	}
}
//bat dau choi game
void GameProcess(Game2048& myGame) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (myGame.resume!=true) {
		TaoMaTran(myGame);
		KhoiTao(myGame);
	}

	Inmatran(myGame);
	while (true) {
		char c;
		c = _getch();
		int t = (int)c;
		if (t == -32) {
			SaveMatrixU(myGame);
			myGame.luot++;
			myGame.time++;
			myGame.redo = 0;
			switch (_getch()) {
			case(72):
				ProcessUp(myGame);
				break;
			case(80):
				ProcessDown(myGame);
				break;
			case(75):
				ProcessLeft(myGame);
				break;
			case(77):
				ProcessRight(myGame);
				break;
			}
			Inmatran(myGame);
		}
		else if (t==119||t==97||t==100||t==115) {
			SaveMatrixU(myGame);
			myGame.redo = 0;
			myGame.luot++;
			myGame.time++;
			switch (t) {
			case(119):
				ProcessUp(myGame);
				break;
			case(115):
				ProcessDown(myGame);
				break;
			case(97):
				ProcessLeft(myGame);
				break;
			case(100):
				ProcessRight(myGame);
				break;
			}
			Inmatran(myGame);
		}
		else if (t == 117 && myGame.undo_redo == true) {
			if (myGame.luot > 0) {
				SaveMatrixR(myGame);
				Undo(myGame);
				myGame.time++;
			}
			else {
				gotoxy(88, 6);
				SetConsoleTextAttribute(h, 4);
				cout << " cannot undo.";
			}

		}
		else if (t == 114 && myGame.undo_redo == true) {
			if (myGame.redo > 0) {
				SaveMatrixU(myGame);
				Redo(myGame);
				myGame.time++;
			}
			else {
				gotoxy(88, 7);
				SetConsoleTextAttribute(h, 4);
				cout << " cannot redo.";
			}
		}
		else if (t == 101) {
			gotoxy(78, 11);
			bool sure = true;
			SetConsoleTextAttribute(h, 4);
			cout << "          YOU WANNA LEAVE?" << endl;
			SetConsoleTextAttribute(h, 2);
			gotoxy(78, 12);
			cout << "+_____________+        +______________+" << endl;
			gotoxy(78, 13);
			cout << "|  YES [ 1 ]  |        |   NO [ 2 ]   |" << endl;
			gotoxy(78, 14);
			cout << "+_____________+        +______________+" << endl;
			while (sure) {
				char c;
				c = _getch();
				if (c == '1') {
					SavePlayerPoint(myGame);
					SavePoint(myGame);
					SaveTime(myGame);
					sure = false;
					Main_Dis(myGame);
				}
				if (c == '2') {
					SetConsoleTextAttribute(h, 0);
					sure = false;
					for (int i = 0; i < 10; i++) {
						gotoxy(78, 10+i);
						cout << "                                        ";
					}
				}
			}
		}
		EndGame(myGame);
		winGame(myGame);
	}
}
//ham kiem tra ket thuc game
void EndGame(Game2048& myGame) {
	int d = 0;
	for (int i = 0; i < myGame.sizeOfMatrix; i++) {
		for (int j = 0; j < myGame.sizeOfMatrix; j++) {
			if (myGame.Matrix[i][j] == 0) {
				d = 1;
			}
		}
	}
	int e = 0;
	for (int i = 0; i < myGame.sizeOfMatrix; i++) {
		for (int j = 0; j < myGame.sizeOfMatrix-1; j++) {
			if (myGame.Matrix[i][j] == myGame.Matrix[i][j + 1]) {
				e = 1;
			}
		}
	}
	for (int i = 0; i < myGame.sizeOfMatrix-1; i++) {
		for (int j = 0; j < myGame.sizeOfMatrix; j++) {
			if (myGame.Matrix[i][j] == myGame.Matrix[i + 1][j]) {
				e = 1;
			}
		}
	}
	if (e == 0 && d == 0) {
		cout << "\n\n";
		int a[1000];
		string b[1000];
		int top = 0;
		for (int i = 0; i < myGame.NOP; i++) {
			a[i] = myGame.playerList[i].Max_Point;
		}
		for (int i = 0; i < myGame.NOP; i++) {
			b[i] = myGame.playerList[i].Name;
		}
		for (int i = 0; i < myGame.NOP - 1; i++) {
			for (int j = i; j < myGame.NOP; j++) {
				if (a[i] < a[j]) {
					swap(a[i], a[j]);
					swap(b[i], b[j]);
				}
			}
		}
		for (int i = 0; i < 20; i++) {
			if (b[i] == myGame.Name) {
				top = i + 1;
			}
		}
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 4);
		cout << "\t\t\t\t\t\t|YOU LOSE. GAME OVER!\n" << endl;
		SetConsoleTextAttribute(h, 12);
		if (top > 0 && top <= 20) {
			cout << "\t\t\t\t\t\t*____________________*" << endl;
			cout << "\t\t\t\t\t\t      Hang dat: " << top << endl;
			cout << "\t\t\t\t\t\t*____________________*" << endl;
		}
		SetConsoleTextAttribute(h, 8);
		cout << "\t\t\t\t\t\t*RESTART [ 1 ]." << endl;
		cout << "\t\t\t\t\t\t*MAIN DISPLAY [ 2 ]."<<endl;
		cout << "\t\t\t\t\t\t*CONTINUE BY UNDO [ 3 ].";
		char key;
		bool check = true;
		while (check) {
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case '1':
					SavePlayerPoint(myGame);
					SaveTime(myGame);
					system("cls");
					TaoMaTran(myGame);
					KhoiTao(myGame);
					DrawMatrix(myGame.sizeOfMatrix);
					myGame.Diem = 0;
					myGame.luot = 0;
					check = false;
					GameProcess(myGame);
					break;
				case '2':
					check = false;
					TaoMaTran(myGame);
					SavePlayerPoint(myGame);
					SaveTime(myGame);
					SavePoint(myGame);
					Main_Dis(myGame);
					myGame.luot = 0;
					myGame.Diem = 0;
					break;
				case '3':
						SaveMatrixR(myGame);
						Undo(myGame);
						check = false;
						system("cls");
						Inmatran(myGame);
						break;
				}
			}
		}
	}
}
//ham kiem tra thang game va thong bao thu hang
void winGame(Game2048& myGame) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < myGame.sizeOfMatrix; i++) {
		for (int j = 0; j < myGame.sizeOfMatrix; j++) {
			if (myGame.Matrix[i][j] == 2048 && myGame.win == false) {
				myGame.win = true;
				SetConsoleTextAttribute(h, 11);
				//kiem tra thu hang
				int a[1000];
				string b[1000];
				int top=0;
				for (int i = 0; i < myGame.NOP; i++) {
					a[i] = myGame.playerList[i].Max_Point;
				}
				for (int i = 0; i < myGame.NOP; i++) {
					b[i] = myGame.playerList[i].Name;
				}
				for (int i = 0; i < myGame.NOP - 1; i++) {
					for (int j = i; j < myGame.NOP; j++) {
						if (a[i] < a[j]) {
							swap(a[i], a[j]);
							swap(b[i], b[j]);
						}
					}
				}
				for (int i = 0; i < 20; i++) {
					if (b[i] == myGame.Name) {
						top = i+1;
					}
				}
				cout << "\n\n\n";
				cout << "\t\t\t+______________________________________________________________+" << endl;
				cout << "\t\t\t|     Chuc mung ban da xuat sac chien thang dat 2048 diem!     | " << endl;
				cout << "\t\t\t+______________________________________________________________+" << endl;
				if (top > 0 && top <= 20) {
					cout << "\t\t\t\t\t\t*____________________*" << endl;
					cout << "\t\t\t\t\t\t      Hang dat: "<< top << endl;
					cout << "\t\t\t\t\t\t*____________________*" << endl;
				}
				SetConsoleTextAttribute(h, 6);
				cout << "\t\t\t\t\t\t*____________________*" << endl;
				cout << "\t\t\t\t\t\t|  1. CHOI TIEP [1]  |" << endl;
				cout << "\t\t\t\t\t\t*____________________*" << endl;
				SetConsoleTextAttribute(h, 12);
				cout << "\t\t\t\t\t\t     ||        ||     " << endl;
				SetConsoleTextAttribute(h, 6);
				cout << "\t\t\t\t\t\t*____________________*" << endl;
				cout << "\t\t\t\t\t\t| 2. THOAT GAME [2]  |" << endl;
				cout << "\t\t\t\t\t\t*____________________*" << endl;
				bool check = true;
				while (check) {
					char c;
					c = _getch();
					if (c == '1') {
						system("cls");
						Inmatran(myGame);
						break;
					}
					if (c == '2') {
						Main_Dis(myGame);
					}
				}
			}
		}
	}
}