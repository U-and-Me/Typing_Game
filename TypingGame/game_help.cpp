#include <iostream>
#include "TypingGame.h"

void game_help() {

	char key;

	screen();
	gotoxy(40, 7); cout << "**** ���� ****";
	gotoxy(14, 12); cout << "1. ȭ�鿡 �ߴ� �ܾ �Է��ϼ���" << endl;
	gotoxy(14, 13); cout << " �� �� 3�ܰ�� �ܰ踶�� 25�ʾ� ������ ����˴ϴ�.";
	gotoxy(14, 14); cout << " �� �ܰ谡 ���������� ��Ÿ���� ������� �ӵ��� �������ϴ�.";
	gotoxy(14, 15); cout << " �� �������� ������ �ð��� �Ǹ� �ܾ���� �ٲ�� �����ϼ���!!";
	gotoxy(14, 16); cout << " �� ������ �ö� ���� �ְ� ������ ���� �ֽ��ϴ�";
	gotoxy(14, 19); cout << "2. �ܾ� ���� ���� ���� ������ �޶����ϴ�." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	gotoxy(14, 20); cout << " �� �Ķ��� : 100��" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	gotoxy(14, 21); cout << " �� �ʷϻ� : 150��" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(14, 22); cout << " �� ������ : 200��" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(14, 25); cout << "3. �߰� �����ϰ� �ʹٸ� end�� �Է����ּ���";
	gotoxy(14, 28); cout << "** ���� �޴��� ���ư����� �ƹ�Ű�� �������� **";

	key = _getch(); // Ű���� �Է�

	if (_kbhit) { // Ű���尡 ���ȴ��� Ȯ��
		logo();
		Menu();
	}

}