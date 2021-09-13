#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TypingGame.h"

void rank_logo();
void rank_insert(); // 사용자 이름, 점수 저장


void Rank() {

    char key;

    rank_logo();


    gotoxy(2, 42); cout << "** 메인 메뉴로 돌아가려면 아무키나 누르세요 **";

    key = _getch(); // 키보드 입력

    if (_kbhit) { // 키보드가 눌렸는지 확인
        logo();
        Menu();
    }

}

void rank_insert() {

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
