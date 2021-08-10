#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h" // 메인화면 구현

using namespace std;

void CursorView(); // 커서 지우기
void Menu(); // 메뉴
void Play(); // 게임 시작
void screen(); // 게임 시작 화면
void game_help(); // 도움말

int main() {
	// 기본 설정
	system("mode con: cols=96 lines=46"); // 가로 : cols  세로 : lines


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

void Menu() {
	gotoxy(11, 30); cout << "1. 게임 시작";
	gotoxy(31, 30); cout << "2. 도움말";
	gotoxy(51, 30); cout << "3. 랭킹보기";
	gotoxy(71, 30); cout << "4. 종료하기";

	gotoxy(18, 35); cout << "**** 번호를 입력하세요 ****";
}

void screen() {
	for (int i = 1; i < 44; i++) {
		gotoxy(1, i); cout << "|";
		gotoxy(94, i); cout << "|";
	}
	for (int i = 1; i < 95; i++) {
		gotoxy(i, 1); cout << "-";
		gotoxy(i, 37); cout << "-";
		gotoxy(i, 44); cout << "-";
	}

}

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

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}