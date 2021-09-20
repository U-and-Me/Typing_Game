#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TypingGame.h"

using namespace std;

void rank_logo();

int len = 0; // ���Ͽ� �ִ� ������ ����
string users[100];
int scores[100];
int x1[3] = { 17, 46, 77 };
int x2[3] = { 18, 47, 78 };


void Rank() {

    char key;

    rank_logo();

    ifstream fin1;
    fin1.open("rank.txt");

    // ������ ����
    string temp;
    while (!fin1.eof()) {
        if (getline(fin1, temp)) {
            len++;
        }
    }
    fin1.close();

    // ���� �б�
    ifstream fin2;
    fin2.open("rank.txt");

    if (fin2.is_open()) {
        for (int i = 0; i < len; i++) {
            fin2 >> users[i];
            fin2 >> scores[i];
        }
    }
    else {
        gotoxy(2, 40);
        cout << "������ ã�� �� �����ϴ�." << endl;
    }
    
    fin2.close();

    // �������� ����
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            if (scores[j] < scores[j+1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
                string temp2 = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp2;
            }
        }
    }


    for (int i = 0; i < 3; i++) {
        if (users[i] == " " || scores[i] == 0) continue;
        gotoxy(x1[i], 26);
        cout << users[i];
        gotoxy(x2[i], 27);
        cout << scores[i];

    }


    gotoxy(2, 42); cout << "** ���� �޴��� ���ư����� �ƹ�Ű�� �������� **";

    key = _getch(); // Ű���� �Է�

    if (_kbhit) { // Ű���尡 ���ȴ��� Ȯ��
        logo();
        Menu();
    }

}


void rank_logo() {
	
    gotoxy(26, 5);
    cout << "8888888b.         d8888 888b    888 888    d8P ";
    gotoxy(26, 6);
    cout << "888   Y88b       d88888 8888b   888 888   d8P  ";
    gotoxy(26, 7);
    cout << "888    888      d88P888 88888b  888 888  d8P    ";
    gotoxy(26, 8);
    cout << "888   d88P     d88P 888 888Y88b 888 888d88K     ";
    gotoxy(26, 9);
    cout << "8888888PP     d88P  888 888 Y88b888 8888888b ";
    gotoxy(26, 10);
    cout << "888 T88b     d88P   888 888  Y88888 888  Y88b   ";
    gotoxy(26, 11);
    cout << "888  T88b   d8888888888 888   Y8888 888   Y88b  ";
    gotoxy(26, 12);
    cout << "888   T88b d88P     888 888    Y888 888    Y88b ";

    
    gotoxy(16, 19);
    cout << "  ###";
    gotoxy(16, 20);
    cout << "   ##";
    gotoxy(16, 21);
    cout << "   ##";
    gotoxy(16, 22);
    cout << "   ##";
    gotoxy(16, 23);
    cout << " ######";


    gotoxy(45, 19);
    cout << "#######";
    gotoxy(45, 20);
    cout << "     ##";
    gotoxy(45, 21);
    cout << "#######";
    gotoxy(45, 22);
    cout << "##";
    gotoxy(45, 23);
    cout << "#######";

    gotoxy(76, 19);
    cout << "#######";
    gotoxy(76, 20);
    cout << "     ##";
    gotoxy(76, 21);
    cout << "   ####";
    gotoxy(76, 22);
    cout << "     ##";
    gotoxy(76, 23);
    cout << "#######";
                                             

}
