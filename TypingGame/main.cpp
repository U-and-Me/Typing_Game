#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h"

int main() {
	// �⺻ ����
	system("mode con: cols=100 lines=45"); // ���� : cols  ���� : lines
	system("title TypingGame");
	CursorView();

	int User_ans; // ����� �Է�



	while (1) {
		logo();
		Menu();
		gotoxy(18, 35); cout << "**** ��ȣ�� �Է��ϼ��� ****";
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
			Rank();
			break;
		case 4: // �����ϱ�
			exit(0); 
		default:
			gotoxy(30, 25); ; cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�!";
			Sleep(1000);
			main();

		}



	} // End of While

	return 0;
}

