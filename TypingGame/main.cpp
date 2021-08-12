#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h"

int main() {
	// 기본 설정
	system("mode con: cols=96 lines=46"); // 가로 : cols  세로 : lines
	CursorView();

	int User_ans; // 사용자 입력



	while (1) {
		logo();
		Menu();
		gotoxy(18, 35); cout << "**** 번호를 입력하세요 ****";
		gotoxy(55, 35); cin >> User_ans; // 입력받기
		system("cls");

		switch (User_ans) {
		case 1: // 게임 시작
			Play();
			break;
		case 2: // 도움말
			game_help();
			break;
		case 3: // 랭킹보기

			break;
		case 4: // 종료하기 => 게임 종료화면으로 다시 돌아감
			return 0; break;
		default:
			gotoxy(30, 20); ; cout << "해당 번호는 존재하지 않습니다!";
			Sleep(1000);


		}



	} // End of While


}

