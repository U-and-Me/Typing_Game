#include <iostream>
#include "TypingGame.h"

void game_help() {

	char key;

	screen();
	gotoxy(40, 7); cout << "**** 도움말 ****";
	gotoxy(14, 12); cout << "1. 화면에 뜨는 단어를 입력하세요" << endl;
	gotoxy(14, 13); cout << " ▷ 총 3단계로 단계마다 25초씩 게임이 진행됩니다.";
	gotoxy(14, 14); cout << " ▷ 단계가 높아질수록 나타나고 사라지는 속도가 빨라집니다.";
	gotoxy(14, 15); cout << " ▷ 랜덤으로 정해진 시간이 되면 단어색이 바뀌니 조심하세요!!";
	gotoxy(14, 16); cout << " ▷ 점수가 올라갈 수도 있고 내려갈 수도 있습니다";
	gotoxy(14, 19); cout << "2. 단어 색깔에 따라 점수 배점이 달라집니다." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	gotoxy(14, 20); cout << " ▷ 파란색 : 100점" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	gotoxy(14, 21); cout << " ▷ 초록색 : 150점" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(14, 22); cout << " ▷ 빨간색 : 200점" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(14, 25); cout << "3. 중간 종료하고 싶다면 end를 입력해주세요";
	gotoxy(14, 28); cout << "** 메인 메뉴로 돌아가려면 아무키나 누르세요 **";

	key = _getch(); // 키보드 입력

	if (_kbhit) { // 키보드가 눌렸는지 확인
		logo();
		Menu();
	}

}