#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "TypingGame.h"

int main() {
	// �⺻ ����
	system("mode con: cols=96 lines=46"); // ���� : cols  ���� : lines
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

			break;
		case 4: // �����ϱ� => ���� ����ȭ������ �ٽ� ���ư�
			return 0; break;
		default:
			gotoxy(30, 20); ; cout << "�ش� ��ȣ�� �������� �ʽ��ϴ�!";
			Sleep(1000);


		}



	} // End of While


}

