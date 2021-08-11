#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h" // 메인화면 구현

int main() {
	// 기본 설정
	system("mode con: cols=96 lines=46"); // 가로 : cols  세로 : lines
	CursorView();

	int User_ans; // 사용자 입력

	logo();
	Menu();

	while (1) {

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
		case 4: // 종료하기
			return 0;
			break;
		default:
			cout << "해당 번호는 존재하지 않습니다!";
			break;
		}

	} // End of While


}

