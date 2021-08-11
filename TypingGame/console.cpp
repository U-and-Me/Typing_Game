#include "TypingGame.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void logo() {
	system("cls");

	for (int i = 16; i <= 76; i++) {
		gotoxy(i, 6); cout << "-";
		gotoxy(i, 20); cout << "-";
	}

	// T
	for (int i = 21; i <= 32; i++) {
		gotoxy(i, 8); cout << "#";
	}
	for (int i = 9; i <= 16; i++) {
		gotoxy(26, i); cout << "#";
		gotoxy(27, i); cout << "#";
	}
	// y
	gotoxy(31, 11); cout << "#";
	gotoxy(32, 11); cout << "#";
	gotoxy(39, 11); cout << "#";
	gotoxy(40, 11); cout << "#";

	gotoxy(32, 12); cout << "#";
	gotoxy(33, 12); cout << "#";
	gotoxy(38, 12); cout << "#";
	gotoxy(39, 12); cout << "#";

	gotoxy(33, 13); cout << "#";
	gotoxy(34, 13); cout << "#";
	gotoxy(37, 13); cout << "#";
	gotoxy(38, 13); cout << "#";

	gotoxy(34, 14); cout << "#";
	gotoxy(35, 14); cout << "#";
	gotoxy(36, 14); cout << "#";
	gotoxy(37, 14); cout << "#";

	gotoxy(35, 15); cout << "#";
	gotoxy(36, 15); cout << "#";

	gotoxy(34, 16); cout << "#";
	gotoxy(35, 16); cout << "#";

	gotoxy(33, 17); cout << "#";
	gotoxy(34, 17); cout << "#";

	gotoxy(32, 18); cout << "#";
	gotoxy(33, 18); cout << "#";

	// p
	for (int i = 11; i <= 18; i++) {
		gotoxy(43, i); cout << "#";
		gotoxy(44, i); cout << "#";
	}
	for (int i = 11; i <= 14; i++) {
		switch (i) {
		case 11: case 14:
			gotoxy(45, i); cout << "#";
			gotoxy(46, i); cout << "#";
			gotoxy(47, i); cout << "#";
			gotoxy(48, i); cout << "#"; break;
		case 12: case 13:
			gotoxy(48, i); cout << "#";
			gotoxy(49, i); cout << "#"; break;
		}
	}

	// i
	gotoxy(52, 9); cout << "#";
	gotoxy(53, 9); cout << "#";
	for (int i = 11; i <= 15; i++) {
		gotoxy(52, i); cout << "#";
		gotoxy(53, i); cout << "#";
	}

	// n
	for (int i = 12; i <= 15; i++) {
		gotoxy(56, i); cout << "#";
		gotoxy(57, i); cout << "#";
		gotoxy(61, i); cout << "#";
		gotoxy(62, i); cout << "#";
	}

	for (int i = 57; i <= 61; i++) {
		gotoxy(i, 11); cout << "#";
	}

	// g
	for (int i = 11; i <= 18; i++) {
		gotoxy(70, i); cout << "#";
		gotoxy(71, i); cout << "#";
	}
	for (int i = 11; i <= 14; i++) {
		switch (i) {
		case 11: case 14:
			gotoxy(66, i); cout << "#";
			gotoxy(67, i); cout << "#";
			gotoxy(68, i); cout << "#";
			gotoxy(69, i); cout << "#"; break;
		case 12: case 13:
			gotoxy(65, i); cout << "#";
			gotoxy(66, i); cout << "#"; break;
		}
	}
	gotoxy(66, 17); cout << "#";
	gotoxy(67, 17); cout << "#";

	gotoxy(67, 18); cout << "#";
	gotoxy(68, 18); cout << "#";
	gotoxy(69, 18); cout << "#";
	gotoxy(71, 18); cout << " ";
}

void Menu() {
	gotoxy(11, 30); cout << "1. 게임 시작";
	gotoxy(31, 30); cout << "2. 도움말";
	gotoxy(51, 30); cout << "3. 랭킹보기";
	gotoxy(71, 30); cout << "4. 종료하기";

	gotoxy(18, 35); cout << "**** 번호를 입력하세요 ****";
}
