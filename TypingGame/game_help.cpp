#include <iostream>
#include "TypingGame.h"

void game_help() {

	char key;

	screen();
	gotoxy(37, 10); cout << "**** ���� ****";
	gotoxy(21, 15); cout << "1. ȭ�鿡 �ߴ� �ܾ �Է��ϼ���" << endl;
	gotoxy(21, 16); cout << " �� �� 3�ܰ�� �ܰ谡 ���������� ȭ�鿡 �ߴ� �ӵ��� �������ϴ�.";
	gotoxy(21, 19); cout << "2. �ܾ� ���� ���� ���� ������ �޶����ϴ�." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	gotoxy(21, 20); cout << " �� �Ķ��� : 100��" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	gotoxy(21, 21); cout << " �� �ʷϻ� : 150��" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(21, 22); cout << " �� ������ : 200��" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(21, 25); cout << "** ���� �޴��� ���ư����� �ƹ�Ű�� �������� **";

	key = _getch(); // Ű���� �Է�

	if (_kbhit) { // Ű���尡 ���ȴ��� Ȯ��
		logo();
		Menu();
	}

}