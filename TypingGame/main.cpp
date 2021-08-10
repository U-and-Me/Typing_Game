#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h" // ����ȭ�� ����

using namespace std;

void CursorView(); // Ŀ�� �����
void Menu(); // �޴�
void Play(); // ���� ����
void screen(); // ���� ���� ȭ��
void game_help(); // ����

int main() {
	// �⺻ ����
	system("mode con: cols=96 lines=46"); // ���� : cols  ���� : lines


	int User_ans; // ����� �Է�

	logo();
	Menu();

	while (1) {

		gotoxy(55, 35); cin >> User_ans; // �Է¹ޱ�
		system("cls");

		switch (User_ans) {
		case 1: // ���� ����
			Play();
			break;
		case 2: // ����
			game_help();
			break;
		case 3: // ��ŷ����

			break;
		case 4: // �����ϱ�
			return 0;
			break;
		default:
			cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�!";
			break;
		}

	} // End of While


}

void Menu() {
	gotoxy(11, 30); cout << "1. ���� ����";
	gotoxy(31, 30); cout << "2. ����";
	gotoxy(51, 30); cout << "3. ��ŷ����";
	gotoxy(71, 30); cout << "4. �����ϱ�";

	gotoxy(18, 35); cout << "**** ��ȣ�� �Է��ϼ��� ****";
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

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}