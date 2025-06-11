#include "2048.h"

//ham hien thong bao dang ki hoac dang nhap
void SignIn_Up(Game2048& myGame) {
	myGame.log = true;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(40, 0);
	SetConsoleTextAttribute(h, 4);
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
	SetConsoleTextAttribute(h, 2);
	gotoxy(0, 7);
	cout << "\t\t\t\t\t~*_________________________________*~"<<endl;
	cout << "\t\t\t\t\t~|         WELCOME TO 2048         |~" << endl;
	cout << "\t\t\t\t\t~*_________________________________*~"<<endl;
	SetConsoleTextAttribute(h, 12);
	cout << "\t\t\t\t\t\t     ||        ||     " << endl;
	SetConsoleTextAttribute(h, 6);
	cout << "\t\t\t\t\t\t*____________________*" << endl;
	cout << "\t\t\t\t\t\t|   1. LOG IN [1]    |"<< endl;
	cout << "\t\t\t\t\t\t*____________________*"<<endl;
	SetConsoleTextAttribute(h, 12);
	cout << "\t\t\t\t\t\t     ||        ||     " << endl;
	SetConsoleTextAttribute(h, 6);
	cout << "\t\t\t\t\t\t*____________________*" << endl;
	cout << "\t\t\t\t\t\t|   2. SIGN UP [2]   |" << endl;
	cout << "\t\t\t\t\t\t*____________________*" << endl;
	
	SetConsoleTextAttribute(h, 8);
	bool check = true;
	while (check) {
		char c;
		c = _getch();
		int t = (int)c;
		if (t == 49) {
			system("cls");
			cout << "Nhap exit de thoat!" << endl;
			SetConsoleTextAttribute(h, 6);
			cout << "1. LOG IN" << endl;
			SetConsoleTextAttribute(h, 14);
			cout << "Nhap ten dang nhap (khong dau cach): ";
			SetConsoleTextAttribute(h, 10);
			getline(cin, myGame.Name);
			if (myGame.Name == "exit" || myGame.Name == "EXIT") {
				system("cls");
				SignIn_Up(myGame);
			}
			SetConsoleTextAttribute(h, 14);
			cout << "Nhap mat khau (khong dau cach):";
			SetConsoleTextAttribute(h, 10);
			getline(cin, myGame.Pass);
			if (myGame.Pass == "exit" || myGame.Pass == "EXIT") {
				system("cls");
				SignIn_Up(myGame);
			}
			bool checkP = false;
			for (int i = 0; i < myGame.NOP; i++) {
				if (myGame.playerList[i].Name == myGame.Name && myGame.playerList[i].Pass == myGame.Pass) {
					checkP = true;
					myGame.stt = i;
					break;
				}
			}
			while (checkP == false) {
				system("cls");
				SetConsoleTextAttribute(h, 4);
				cout << "Ten dang nhap hoac mat khau sai, vui long dang nhap lai!" << endl;
				cout << "Nhap exit de thoat!" << endl;
				SetConsoleTextAttribute(h, 6);
				cout << "1. LOG IN" << endl;
				SetConsoleTextAttribute(h, 14);
				cout << "Nhap ten dang nhap (khong dau cach): ";
				SetConsoleTextAttribute(h, 10);
				getline(cin, myGame.Name);
				if (myGame.Name == "exit" || myGame.Name == "EXIT") {
					system("cls");
					SignIn_Up(myGame);
				}
				SetConsoleTextAttribute(h, 14);
				cout << "Nhap mat khau (khong dau cach): ";
				SetConsoleTextAttribute(h, 10);
				getline(cin, myGame.Pass);
				if (myGame.Pass == "exit" || myGame.Pass == "EXIT") {
					system("cls");
					SignIn_Up(myGame);
				}
				for (int k = 0; k < myGame.NOP; k++) {
					if (myGame.playerList[k].Name == myGame.Name && myGame.playerList[k].Pass == myGame.Pass) {
						checkP = true;
						myGame.stt = k;
						break;
					}
				}
			}
			check = false;
			system("cls");
		}
		else if (t == 50) {
			system("cls");
			string Pass2 = " ";
			cout << "Nhap exit de thoat!" << endl;
			SetConsoleTextAttribute(h, 6);
			cout << "2. SIGN UP:" << endl;
			SetConsoleTextAttribute(h, 14);
			cout << "Nhap ten dang nhap (khong dau cach): ";
			SetConsoleTextAttribute(h, 10);
			getline(cin, myGame.Name);
			bool checkK = false;
			for (int i = 0; i < myGame.NOP; i++) {
				if (myGame.playerList[i].Name == myGame.Name) {
					checkK = true;
					break;
				}
			}
			if (myGame.Name == "exit" || myGame.Name == "EXIT") {
				system("cls");
				SignIn_Up(myGame);
			}
			while (wordCheck(myGame.Name) == false||checkK==true) {
				system("cls");
				SetConsoleTextAttribute(h, 4);
				cout << "Ten dang nhap bi trung hoac khong hop le, hay nhap lai..." << endl;
				SetConsoleTextAttribute(h, 8);
				cout << "Nhap exit de thoat!" << endl;
				SetConsoleTextAttribute(h, 6);
				cout << "2. SIGN UP:" << endl;
				SetConsoleTextAttribute(h, 14);
				cout << "Nhap ten dang nhap (khong dau cach): ";
				SetConsoleTextAttribute(h, 10);
				getline(cin, myGame.Name);
				if (myGame.Name == "exit" || myGame.Name == "EXIT") {
					system("cls");
					SignIn_Up(myGame);
				}
				for (int i = 0; i < myGame.NOP; i++) {
					if (myGame.playerList[i].Name == myGame.Name) {
						checkK = true;
						break;
					}
					checkK = false;
				}
			}
			while (myGame.Pass != Pass2 || wordCheck(Pass2) != true) {
				SetConsoleTextAttribute(h, 14);
				cout << "Nhap mat khau (khong dau cach): ";
				SetConsoleTextAttribute(h, 10);
				getline(cin, myGame.Pass);
				if (myGame.Pass == "exit" || myGame.Pass == "EXIT") {
					system("cls");
					SignIn_Up(myGame);
				}
				SetConsoleTextAttribute(h, 14);
				cout << "Nhap lai mat khau (khong dau cach): ";
				SetConsoleTextAttribute(h, 10);
				getline(cin, Pass2);
				if (Pass2 == "exit" ||Pass2 == "EXIT") {
					system("cls");
					SignIn_Up(myGame);
				}
				SetConsoleTextAttribute(h, 4);
				if (myGame.Pass != Pass2 || wordCheck(Pass2) != true) {
					cout << "Mat khau khong trung khop hoac khong hop le hay nhap lai..." << endl;
				}

			}
			myGame.NOP++;
			SavePlayer(myGame.Name, myGame.Pass);
			ofstream fileP("Point.bin", ios::binary|ios::app);
			int diem = 0;
			fileP.write((char*)&diem, sizeof(int));
			fileP.close();
			readPlayer(myGame);
			if (myGame.NOP <= 5) {
				SavePlayerPoint(myGame);
			}
			system("cls");
			SetConsoleTextAttribute(h, 8);
			cout << "Dang ki thanh cong, dang nhap de choi..." << endl;
			SignIn_Up(myGame);
			check = false;
			system("cls");
		}
	}
	myGame.log_exit = true;
	SavePlayerPoint(myGame);
	SaveTime(myGame);
	myGame.log = false;
	Main_Dis(myGame);
}
//ham check ten 
bool wordCheck(string t) {
	bool check = false;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == ' ') {
			check = true;
			break;
		}
	}
	if (check == false) {
		return true;
	}
	else {
		return false;
	}
}

//ham doc file luu vao playerlist
void readPlayer(Game2048& myGame) {
	const char* filename = "Player.bin";
	ifstream verifyFile(filename, ios::binary);
	
	int count = 0;
	if (verifyFile.is_open()) {
		verifyFile.read(reinterpret_cast<char*>(&count), sizeof(count));
		myGame.NOP = count;
		int i = 0;
		while (verifyFile.peek() != EOF) {
			// doc name
			size_t length;
			verifyFile.read(reinterpret_cast<char*>(&length), sizeof(length));
			char* buffer = new char[length + 1];
			verifyFile.read(buffer, length);
			buffer[length] = '\0';
			string readName = buffer;
			delete[] buffer;

			// doc password
			verifyFile.read(reinterpret_cast<char*>(&length), sizeof(length));
			buffer = new char[length + 1];
			verifyFile.read(buffer, length);
			buffer[length] = '\0';
			string readPassword = buffer;
			delete[] buffer;
			myGame.playerList[i].Name = readName ;
			myGame.playerList[i].Pass = readPassword ;
			i++;
		}
		verifyFile.close();
	}
	else {
		cout << "Cannot open file for reading." << endl;
	}
	ifstream fileP("Point.bin", ios::binary);
	if (fileP.is_open()) {
		int j = 0;
		while (j<myGame.NOP) {
			int mpoint=0;
			fileP.read(reinterpret_cast<char*>(&mpoint), sizeof(int));
			myGame.playerList[j].Max_Point = (mpoint+2)/5;
			j++;
		}
		fileP.close();
	}
	ifstream fileT("Time.bin", ios::binary);
	if (fileT.is_open()) {
		int j = 0;
		while (j < myGame.NOP) {
			int mtime = 0;
			fileT.read(reinterpret_cast<char*>(&mtime), sizeof(int));
			myGame.playerList[j].time = mtime ;
			j++;
		}
		fileT.close();
	}
}

//ham luu ten va mat khau vao file
void SavePlayer(string name,string password) {
	const char* filename = "Player.bin";

	ifstream infile(filename, ios::binary);
	int count = 0;
	string fileContent;
	if (infile.is_open()) {
		infile.read(reinterpret_cast<char*>(&count), sizeof(count));
		stringstream buffer;
		buffer << infile.rdbuf();
		fileContent = buffer.str();
		infile.close();
	}
	count += 1;
	ofstream outFile(filename, ios::binary | ios::trunc);
	if (outFile.is_open()) {
		outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));

		if (!fileContent.empty()) {
			outFile.write(fileContent.c_str(), fileContent.size());
		}

		size_t nameLength = name.length();
		outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
		outFile.write(name.c_str(), nameLength);

		size_t passwordLength = password.length();
		outFile.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
		outFile.write(password.c_str(), passwordLength);

		outFile.close();
	}
	else {
		cout << "Cannot open file for writing." << endl;
		return ;
	}
}
//luu diem cao nhat
void SavePoint(Game2048& myGame) {
		fstream file("Point.bin", ios::binary|ios::in| ios::out);

		if (file.is_open()) {
			int currentValue = myGame.playerList[myGame.stt].Max_Point*5-2;

			file.seekp((myGame.stt) * sizeof(int), ios::beg);
			file.write(reinterpret_cast<char*>(&currentValue), sizeof(int));
			file.close();
		}
}

void SaveTime(Game2048& myGame) {
	fstream file("Time.bin", ios::binary | ios::in | ios::out |ios::app);

	if (file.is_open()) {
		int currentValue = myGame.time;

		file.seekp((myGame.stt) * sizeof(int), ios::beg);
		int value=0;
		file.read(reinterpret_cast<char*>(&value), sizeof(int));
		if (value < myGame.time) {
			file.close();
			fstream file1("Time.bin", ios::binary | ios::in | ios::out);
			file1.seekp((myGame.stt) * sizeof(int), ios::beg);
			file1.write(reinterpret_cast<char*>(&currentValue), sizeof(int));
			file1.close();
		}
		file.close();
	}
}
//luu thong tin vao 1 trong 5 tai khoan duoc resume
void SavePlayerPoint(Game2048& myGame) {
	system("cls");
	bool checkList = true; //bien check xem ten nguoi dang nhap co nam san trong list duoc sap luu chua
	for (int i = 0; i < 5; i++) {
		string t = to_string(i + 1);
		string filename = "PlayerPoint" + t + ".bin";
		ifstream verifyFile(filename, ios::binary);
		if (verifyFile.is_open()&&!verifyFile.eof()) {
			size_t length;
			verifyFile.read(reinterpret_cast<char*>(&length), sizeof(length));

			if (verifyFile.gcount() == sizeof(length) && length > 0) {
				char* buffer = new char[length + 1];
				verifyFile.read(buffer, length);

				if (verifyFile.gcount() == length) {
					buffer[length] = '\0';
					string readName = buffer;
					delete[] buffer;
					verifyFile.close();

					if (myGame.Name == readName) {
						checkList = false;
						myGame.stt_InList = i + 1;
						break;
					}
				}
				else {
					delete[] buffer; 
				}
			}
		}
	}
	if (myGame.NOP <= 5 && checkList == true) {
		myGame.Diem = 0;
		myGame.Diemcao = 0;
		myGame.stt_InList = myGame.NOP;
		myGame.sizeOfMatrix = 4;
		myGame.createM();
		TaoMaTran(myGame);
		KhoiTao(myGame);
	}
	if (myGame.NOP > 5 && checkList==true) {
		myGame.Diem = 0;
		myGame.Diemcao = 0;
		myGame.stt_InList = myGame.NOP;
		myGame.sizeOfMatrix = 4;
		myGame.createM();
		TaoMaTran(myGame);
		KhoiTao(myGame);
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 11);
		cout << "\t\t\t   REACHING THE LIMIT OF BACKED-UP ACCOUNT, CHOOSE ONE AMONG TO REPLACE!" << "\n\n";
		SetConsoleTextAttribute(h, 7);
		showList(myGame);
		SetConsoleTextAttribute(h, 8); 
		cout<<"\t\t\t\t\t      DON'T WANNA SAVE, PRESS [ E ] !";
		char c;
		c = _getch();
		if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5') {
			myGame.stt_InList = c-'0';
		}
		if (c == 'e' || c == 'E') {
			system("cls");
			SavePoint(myGame);
			Main_Dis(myGame);
		}
	}
	if ((myGame.log == false)||(myGame.log==true&&checkList==true)) {
		string m = to_string(myGame.stt_InList);
		string filename = "PlayerPoint" + m + ".bin";
		ofstream outFile(filename, ios::binary | ios::trunc);
		if (outFile.is_open()) {
			int maxP = myGame.Diemcao;
			int CurP = myGame.Diem;
			int size = myGame.sizeOfMatrix;
			// Write the in4 to the binary file
			string name = myGame.Name;
			size_t nameLength = name.length();
			outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
			outFile.write(name.c_str(), nameLength);
			outFile.write((char*)&maxP, sizeof(int));
			outFile.write((char*)&CurP, sizeof(int));
			outFile.write((char*)&size, sizeof(int));
			for (int j = 0; j < size; j++) {
				for (int i = 0; i < size; i++) {
					outFile.write((char*)&myGame.Matrix[i][j], sizeof(int));
				}
			}
			outFile.close();
		}
	}
	else {
		readPlayerPoint(myGame, myGame.stt_InList);
	}
}

//ve list 5 tai khoan reusme
void showList(Game2048& myGame) {
	if (myGame.NOP == 0) {
		system("cls");
		SignIn_Up(myGame);
	}
	else {
		for (int i = 0; i < 5; i++) {
			string t = to_string(i + 1);
			string filename = "PlayerPoint" + t + ".bin";
			ifstream verifyFile(filename, ios::binary);
			if (verifyFile.is_open() && myGame.NOP >= 1) {
				size_t length;
				verifyFile.read(reinterpret_cast<char*>(&length), sizeof(length));
				char* buffer = new char[length + 1];
				verifyFile.read(buffer, length);
				buffer[length] = '\0';
				string readName = buffer;
				delete[] buffer;
				verifyFile.close();
				cout << "\t\t\t\t\t\t   |" << i + 1 << ". " << readName << endl;
				cout << "\t\t\t\t\t\t   +___________________." << endl;
				cout << endl;
			}
			else {
				verifyFile.close();
			}
		}
	}
}
//doc file lay thong tin de resume
void readPlayerPoint(Game2048& myGame,int n) {
	string t = to_string(n);
	string filename = "PlayerPoint" + t + ".bin";
	ifstream verifyFile(filename, ios::binary);
	if (verifyFile.is_open()&&!verifyFile.eof()) {
		//read the name
		size_t length;
		verifyFile.read(reinterpret_cast<char*>(&length), sizeof(length));
		char* buffer = new char[length + 1];
		verifyFile.read(buffer, length);
		buffer[length] = '\0';
		string readName = buffer;
		delete[] buffer;
		myGame.Name = readName;
		int count1;
		verifyFile.read(reinterpret_cast<char*>(&count1), sizeof(count1));
		myGame.Diemcao = count1;
		myGame.playerList[myGame.stt].Max_Point = count1;
		int count2;
		verifyFile.read(reinterpret_cast<char*>(&count2), sizeof(count2));
		myGame.Diem = count2;
		int count3;
		verifyFile.read(reinterpret_cast<char*>(&count3), sizeof(count3));
		myGame.sizeOfMatrix = count3;
		myGame.createM();
		for (int j = 0; j < count3; j++) {
			for (int i = 0; i < count3; i++) {
				int count4;
				verifyFile.read(reinterpret_cast<char*>(&count4), sizeof(count4));
				myGame.Matrix[i][j] = count4;
			}
		}
		verifyFile.close();
	}
}
//ham resume
void Resume(Game2048& myGame) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(37, 0);
	SetConsoleTextAttribute(h, 11);
	cout << "DO YOU WANT TO LOG IN BY THESE BACKED-UP ACCOUNT?"<<endl;
	cout << "\n\n";
	SetConsoleTextAttribute(h,15);
	showList(myGame);
	cout << endl;
	SetConsoleTextAttribute(h, 8);
	cout << "\t\t\t\t\t\t   .___________________." << endl;
	cout << "\t\t\t\t\t\t   |      NO [ E ]     |" << endl;
	cout << "\t\t\t\t\t\t   .___________________." << endl;
	while (true) {
		char c;
		c = _getch();
		if (c == '1'&& myGame.NOP>=1) {
			myGame.stt_InList = 1;
			myGame.log_exit = true;
			myGame.log = false;
			readPlayerPoint(myGame, 1);
			for (int i = 0; i < myGame.NOP; i++) {
				if (myGame.playerList[i].Name == myGame.Name) {
					myGame.stt = i;
					break;
				}
			}
			Main_Dis(myGame);
		}
		if (c == '2' && myGame.NOP >= 2) {
			myGame.stt_InList = 2;
			myGame.log_exit = true;
			myGame.log = false;
			readPlayerPoint(myGame, 2);
			for (int i = 0; i < myGame.NOP; i++) {
				if (myGame.playerList[i].Name == myGame.Name) {
					myGame.stt = i;
					break;
				}
			}
			Main_Dis(myGame);
		}
		if (c == '3' && myGame.NOP >= 3) {
			myGame.stt_InList = 3;
			myGame.log_exit = true;
			myGame.log = false;
			readPlayerPoint(myGame, 3);
			for (int i = 0; i < myGame.NOP; i++) {
				if (myGame.playerList[i].Name == myGame.Name) {
					myGame.stt = i;
					break;
				}
			}
			Main_Dis(myGame);
		}
		if (c == '4' && myGame.NOP >= 4) {
			myGame.stt_InList = 4;
			myGame.log_exit = true;
			myGame.log = false;
			readPlayerPoint(myGame, 4);
			for (int i = 0; i < myGame.NOP; i++) {
				if (myGame.playerList[i].Name == myGame.Name) {
					myGame.stt = i;
					break;
				}
			}
			Main_Dis(myGame);
		}
		if (c == '5' && myGame.NOP >= 5) {
			myGame.stt_InList = 5;
			myGame.log_exit = true;
			myGame.log = false;
			readPlayerPoint(myGame, 5);
			for (int i = 0; i < myGame.NOP; i++) {
				if (myGame.playerList[i].Name == myGame.Name) {
					myGame.stt = i;
					break;
				}
			}
			Main_Dis(myGame);
		}
		else if (c == 'E'||c=='e') {
			system("cls");
			break;
		}
	}
}