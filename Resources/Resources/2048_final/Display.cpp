#include "2048.h"

//ham di den toa do (x,y)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

//ve ma tran theo do lon
void DrawMatrix(int size) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < size; ++i) {
        cout << "+";
        for (int j = 0; j < 7; ++j) { 
            cout << "-";
        }
    }
    cout << "+\n";
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < 3; ++k) {
            for (int j = 0; j < size; ++j) {
                cout << "|";
                for (int l = 0; l < 7; ++l) {
                    cout << " ";
                }
            }
            cout << "|\n";
        }
        for (int j = 0; j < size; ++j) {
            cout << "+";
            for (int l = 0; l < 7; ++l) {
                cout << "-";
            }
        }
        cout << "+\n";
    }
}

//ham in man hinh chinh
void Main_Dis(Game2048& myGame) {
    system("cls");
    readPlayerPoint(myGame, myGame.stt_InList);
    readPlayer(myGame);
    myGame.resume = false;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 4);
    gotoxy(40, 0);
    cout << "  2222     0000       4     8888  *   " << std::endl;
    gotoxy(40, 1);
    SetConsoleTextAttribute(h, 12);
    cout << "     2    0    0     4 4   8    8 * *  *" << std::endl;
    gotoxy(40, 2);
    SetConsoleTextAttribute(h, 4);
    cout << "    2    0      0   4  4   8    8  *  *    *  *  *  *" << std::endl;
    gotoxy(40, 3);
    SetConsoleTextAttribute(h, 12);
    cout << "   2     0      0  444444   8888  * *  *  *   *" << std::endl;
    gotoxy(40, 4);
    SetConsoleTextAttribute(h, 4);
    cout << "  2      0      0      4   8    8 *  * *  *" << std::endl;
    gotoxy(40, 5);
    SetConsoleTextAttribute(h, 12);
    cout << " 2        0    0       4   8    8  *  *" << std::endl;
    gotoxy(40, 6);
    SetConsoleTextAttribute(h, 4);
    cout << " 22222     0000        4    8888 * " << std::endl;
    cout << '\n' << '\n' ;
    SetConsoleTextAttribute(h, 15);
    
    cout << "\t\t\t\t\t\t     |PLAYER: " << myGame.playerList[myGame.stt].Name << "\n";
    cout << "\t\t\t\t\t\t     |HIGHSCORE: " << myGame.playerList[myGame.stt].Max_Point << "\n";
    SetConsoleTextAttribute(h, 13);
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    cout << "\t\t\t\t\t\t   |   1.NEW GAME    |" << endl;
    cout << "\t\t\t\t\t\t   ._________________." << endl;

    if (myGame.Diem == 0) {
        SetConsoleTextAttribute(h, 8);
        cout << "\t\t\t\t\t\t   ._________________." << endl;
        cout << "\t\t\t\t\t\t   |   2.CONTINUE    |" << endl;
        cout << "\t\t\t\t\t\t   ._________________." << endl;
        SetConsoleTextAttribute(h, 13);
    }
    else {
        cout << "\t\t\t\t\t\t   ._________________." << endl;
        cout << "\t\t\t\t\t\t   |   2.CONTINUE    |" << endl;
        cout << "\t\t\t\t\t\t   ._________________." << endl;
    }
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    cout << "\t\t\t\t\t\t   |     3.GUIDE     |" << endl;
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    cout << "\t\t\t\t\t\t   |    4.SETTING    |" << endl;
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    cout << "\t\t\t\t\t\t   |    5.LOGOUT     |" << endl;
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    cout << "\t\t\t\t\t\t   | 6.TOP 20 PLAYER |" << endl;
    cout << "\t\t\t\t\t\t   ._________________." << endl;
    SetConsoleTextAttribute(h, 0);
    bool check = true;
    while (check) {
        char c;
        c = _getch();
        int t = (int)c;
        if (t == 49) {
            NewGame(myGame);
            check = false;
        }
        else if (t == 50&&myGame.Diem!=0) {
            myGame.resume = true;
            Continue(myGame);
            check = false;
        }
        else if (t == 51) {
            Guide(myGame);
            check = false;
        }
        else if (t == 52) {
            Setting(myGame);
            check = false;
        }
        else if (t == 53) {
            system("cls");
            myGame.Diemcao = 0;
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 8);
            cout << "Dang xuat thanh cong..." << endl;
            myGame.time = 0;
            myGame.stt_InList = 0;
            SignIn_Up(myGame);
            check = false;
        }
        else if (t == 54) {
            Top20(myGame);
        }
    }
}

//cac ham thao tac
void NewGame(Game2048& myGame) {
    myGame.win = false;
    myGame.Diem = 0;
    myGame.time = 0;
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t\t\t\t\t   +___________________________+" << endl;
    cout << "\t\t\t\t\t\t   |    CHON KICH THUOC....    |" << endl;
    cout << "\t\t\t\t\t\t   +___________________________+" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t|    [1]. 4x4    |" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t|    [2]. 5x5    |" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t|    [3]. 6x6    | " << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t|    [4]. 7x7    |" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t|    [5]. 8x8    |" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t|    [6]. 9x9    |" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    cout << "\t\t\t\t\t\t\t|   [7]. 10x10   |" << endl;
    cout << "\t\t\t\t\t\t\t+________________+" << endl;
    while (true) {
        char c;
        c = _getch();
        if (c == '1') {
            myGame.sizeOfMatrix = 4;
            myGame.luot = 0;
            break;
        }
        else if (c == '2') {
            myGame.sizeOfMatrix = 5;
            myGame.luot = 0;
            break;
        }
        else if (c == '3') {
            myGame.sizeOfMatrix = 6;
            myGame.luot = 0;
            break;
        }
        else if (c == '4') {
            myGame.sizeOfMatrix = 7;
            myGame.luot = 0;
            break;
        }
        else if (c == '5') {
            myGame.sizeOfMatrix = 8;
            myGame.luot = 0;
            break;
        }
        else if (c == '6') {
            myGame.sizeOfMatrix = 9;
            myGame.luot = 0;
            break;
        }
        else if (c == '7') {
            myGame.sizeOfMatrix = 10;
            myGame.luot = 0;
            break;
        }
    }
    myGame.createM();
    system("cls");
    DrawMatrix(myGame.sizeOfMatrix);
    GameProcess(myGame);
}
void Continue(Game2048& myGame) {
    readPlayerPoint(myGame, myGame.stt_InList);
    system("cls");
    DrawMatrix(myGame.sizeOfMatrix);
    GameProcess(myGame);

}
void Guide(Game2048& myGame) {
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 10);
    cout << "CHAO MUNG DEN VOI GAME 2048...." << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "Huong dan:" << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "\t-Su dung cac nut dieu khien de di chuyen tren ban phim:\n";
    SetConsoleTextAttribute(h, 3);
    cout << "\t+Len [ W ]:\t";
    SetConsoleTextAttribute(h, 5);
    cout << " " << (char)24 << endl;
    SetConsoleTextAttribute(h, 3);
    cout << "\t+Xuong [ S ]:\t";
    SetConsoleTextAttribute(h, 5);
    cout << " " << (char)25 << endl;
    SetConsoleTextAttribute(h, 3);
    cout << "\t+Phai [ D ]:\t";
    SetConsoleTextAttribute(h, 5);
    cout << "-->" << endl;
    SetConsoleTextAttribute(h, 3);
    cout << " \t+Trai [ A ]:\t";
    SetConsoleTextAttribute(h, 5);
    cout << "<--" << endl;
    SetConsoleTextAttribute(h, 8);
    cout << "Tro ve giao dien chinh: nhan phim [ E ]." << endl;
    SetConsoleTextAttribute(h, 0);
    while (true) {
        char c;
        c = _getch();
        int t = (int)c;
        if (t == 101) {
            Main_Dis(myGame);
        }
    }
}
void Setting(Game2048& myGame) {
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 6);
    cout << "SETTING:" << endl;
    cout << "-Undo/Redo: ";
    if (myGame.undo_redo == true) {
        gotoxy(12, 1);
        SetConsoleTextAttribute(h, 2);
        cout << "On" << endl;
    }
    else {
        gotoxy(12, 1);
        SetConsoleTextAttribute(h, 4);
        cout << "Off" << endl;
    }
    SetConsoleTextAttribute(h, 14);
    cout << endl;
    cout << "+On: nhan phim [ 1 ]" << endl;
    cout << "+Off: nhan phim [ 0 ]" << endl;
    SetConsoleTextAttribute(h, 8);
    cout << "Tro ve giao dien chinh: nhan phim [ E ]." << endl;
    while (true) {
        char c;
        c = _getch();
        int t = (int)c;
        if (t == 49) {
            gotoxy(12, 1);
            SetConsoleTextAttribute(h, 2);
            cout << "On " << endl;
            myGame.undo_redo = true;
        }
        else if (t == 48) {
            gotoxy(12, 1);
            SetConsoleTextAttribute(h, 4);
            cout << "Off" << endl;
            myGame.undo_redo = false;
        }
        else if (t == 101) {
            Main_Dis(myGame);
        }

    }
}
void Top20(Game2048& myGame) {
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    gotoxy(50, 0);
    cout << "*_____________________* "<<endl;
    gotoxy(50, 1);
    cout << "|   _TOP 20 PLAYER_   |"<<endl;
    gotoxy(50, 2);
    cout << "*_____________________*\n\n" << endl;;
    SetConsoleTextAttribute(h, 10);
    int a[1000]; //luu diem
    string b[1000]; //luu ten
    int c[1000]; //luu time
    for (int i = 0; i < myGame.NOP; i++) {
        a[i] = myGame.playerList[i].Max_Point;
    }
    for (int i = 0; i < myGame.NOP; i++) {
        b[i] = myGame.playerList[i].Name;
    }
    for (int i = 0; i < myGame.NOP; i++) {
        c[i] = myGame.playerList[i].time;
    }
    for (int i = 0; i < myGame.NOP - 1; i++) {
          for (int j = i; j < myGame.NOP ; j++) {
                if (a[i] < a[j]) {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    swap(c[i], c[j]);
                }
          }
    }
    for (int i = 0; i < 20; i++) {
        if (a[i] != 0&& myGame.playerList[i].Max_Point!=0) {
            SetConsoleTextAttribute(h, 10);
            cout << "\t\t\t\t\t    |    " << i + 1 << ". " << b[i] << ", point: " << a[i]<<", step: "<<c[i] << endl;
            SetConsoleTextAttribute(h, 8);
            cout << "\t\t\t\t\t    |____________________________________."<<endl;
        } 
    }
    SetConsoleTextAttribute(h, 8);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t      | Exit [ E ] | ";
    while (true) {
        char c;
        c = _getch();
        if(c=='E'||c=='e') {
            Main_Dis(myGame);
        }
    }
}

