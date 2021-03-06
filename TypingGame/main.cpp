#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h"


int main() {
	// 기본 설정
	system("mode con: cols=100 lines=45"); // 가로 : cols  세로 : lines
	system("title TypingGame");
	CursorView();

	char User_ans; // 사용자 입력

	while (1) {
		logo();
		Menu();
		gotoxy(18, 35); cout << "**** 번호를 입력하세요 ****";
		gotoxy(55, 35); cin >> User_ans; // 입력받기
		system("cls");

		Word();

		switch (User_ans) {
		case '1': // 게임 시작
			Play();
			system("pause");
			break;
		case '2': // 도움말
			game_help();
			system("pause");
			break;
		case '3': // 랭킹보기
			Rank();
			system("pause");
			break;
		case '4': // 종료하기
			exit(0); 
		default:
			gotoxy(33, 20); ; cout << "해당 번호는 존재하지 않습니다!";
			Sleep(1000);
			main();

		}
	}

	return 0;
}

