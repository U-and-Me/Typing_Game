#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h" // ����ȭ�� ����

int main() {
	// �⺻ ����
	system("mode con: cols=96 lines=46"); // ���� : cols  ���� : lines
	CursorView();

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

