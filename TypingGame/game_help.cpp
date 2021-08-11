#include <iostream>
#include "TypingGame.h"

void game_help() {

	char key;

	screen();
	gotoxy(37, 10); cout << "**** 도움말 ****";
	gotoxy(21, 15); cout << "1. 화면에 뜨는 단어를 입력하세요" << endl;
	gotoxy(21, 16); cout << " ▷ 총 3단계로 단계가 높아질수록 화면에 뜨는 속도가 빨라집니다.";
	gotoxy(21, 19); cout << "2. 단어 색깔에 따라 점수 배점이 달라집니다." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	gotoxy(21, 20); cout << " ▷ 파란색 : 100점" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	gotoxy(21, 21); cout << " ▷ 초록색 : 150점" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(21, 22); cout << " ▷ 빨간색 : 200점" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(21, 25); cout << "** 메인 메뉴로 돌아가려면 아무키나 누르세요 **";

	key = _getch(); // 키보드 입력

	if (_kbhit) { // 키보드가 눌렸는지 확인
		logo();
		Menu();
	}

}