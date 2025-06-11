#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
struct Stack {
    Node* head;
    int size;

    Stack() : head(nullptr), size(0) {} // Khoi tao head và size

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void pop() {
        if (empty()) {
            cout << "Ngan xep rong!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int top() {
        if (empty()) {
            cout << "Ngan xep rong!" << endl;
            return -1;
        }

        return head->data;
    }

    bool empty() {
        return size == 0;
    }

    //tu dong duoc goi de giai phong bo nho 
    ~Stack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};


//strcuct nguoi choi
struct Player {
    string Name; //ten
    string Pass; // mat khau
    int Max_Point; //diem cao nhat
    int Current_Point; //diem gan nhat
    int time; //buoc di nhieu nhat
    string R_Matrix;

    Player() {
        Name = "", Pass = "", Max_Point = 0, Current_Point = 0, time = 0, R_Matrix = "";
    }
};

//stuct ca game bao gom ma tran, danh sach nguoi choi....
struct Game2048 {
    int sizeOfMatrix;
    int** Matrix;
    int NOP; //so thu tu cua nguoi choi hien tai trong file
    Player* playerList;
    int Duocphep;
    int Diem, Diemcao;
    int luot; //bien ho tro undo redo
    int redo; //so lan co the redo
    bool undo_redo; //bien check xem co duoc phep dung undo/redo khong
    bool resume; //bien de check nguoi choi dung resume
    bool log_exit;
    bool log; //bien check xem truoc do cai phai dang nhap hay khong
    bool win; // bien de check xem co dat 2048 diem chua
    string Name; //bien luu ten dang nhap
    string Pass; //bien luu mat khau
    int stt; //bien luu so thu tu trong playerlist
    int stt_InList; //bien luu so thu tu 1 trong 5 tai khoan duoc sao luu
    Stack und; //stack dung cho undo
    Stack red; //stack dung cho redo
    int time; //bien luu step
    //khoi tao cac gia tri cho game
    Game2048() {
        int numPlayers = 1000;
        stt = 0;
        Diem = 0;
        Diemcao = 0;
        Duocphep = 0;
        resume = false;
        undo_redo = false;
        log_exit = false;
        log = false;
        luot = 0;
        redo = 0;
        stt_InList = 0;
        NOP = 0;
        win = false;
        time = 0;
        // Cấp phát động cho playerList
        playerList = new Player[numPlayers];
    }

    // Destructor tự được gọi để giải phóng bộ nhớ khi kết thúc chương trình
    ~Game2048() {
        // Giải phóng bộ nhớ cho Matrix
        if (Matrix != nullptr) {
            for (int i = 0; i < sizeOfMatrix; ++i) {
                delete[] Matrix[i];
            }
            delete[] Matrix;
        }

        // Giải phóng bộ nhớ cho playerList
        delete[] playerList;

    }

    //cấp phát cho ma trận khi có size của ma trận
    void createM() {
        Matrix = new int* [sizeOfMatrix];
        for (int i = 0; i < sizeOfMatrix; ++i) {
            Matrix[i] = new int[sizeOfMatrix] {};
        }
    }
};