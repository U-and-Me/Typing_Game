#include "TypingGame.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


                                   

void logo() {
	system("cls");
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	/*
	for (int i = 16; i <= 79; i++) {
		gotoxy(i, 6); cout << "□";
		gotoxy(i, 20); cout << "□";
	}
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

	gotoxy(19, 4); cout << "O))) O))))))O))      O))O)))))))  O))O)))     O))   O)))) ";
	gotoxy(22, 5); cout << "	O))     O))    O)) O))    O))O))O) O))   O)) O)    O))";
	gotoxy(22, 6); cout << "	O))      O)) O))   O))    O))O))O)) O))  O))O))";
	gotoxy(22, 7); cout << "	O))        O))     O)))))))  O))O))  O)) O))O))";
	gotoxy(22, 8); cout << "	O))        O))     O))       O))O))   O) O))O))   O))))";
	gotoxy(22, 9); cout << "	O))        O))     O))       O))O))    O) )) O))    O)";
	gotoxy(22, 10); cout << "	O))        O))     O))       O))O))      O))  O)))))";
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

	gotoxy(26, 13); cout << "   O))))         O)       O))       O))O))))))))";
	gotoxy(26, 14); cout << " O)    O))      O) ))     O) O))   O)))O))";
	gotoxy(26, 15); cout << "O))            O)  O))    O)) O)) O O))O))";
	gotoxy(26, 16); cout << "O))           O))   O))   O))  O))  O))O))))))";
	gotoxy(26, 17); cout << "O))   O))))  O)))))) O))  O))   O)  O))O))";
	gotoxy(26, 18); cout << " O))    O)  O))       O)) O))       O))O))";
	gotoxy(26, 19); cout << "  O)))))   O))         O))O))       O))O))))))))";



	/*
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
	*/
}

void Menu() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(14, 28); cout << "1. 게임 시작";
	gotoxy(34, 28); cout << "2. 도움말";
	gotoxy(54, 28); cout << "3. 랭킹보기";
	gotoxy(74, 28); cout << "4. 종료하기";

}
