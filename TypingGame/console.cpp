#include "TypingGame.h"

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
          
void logo() {
	system("cls");

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

}

void Menu() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(14, 28); cout << "1. 게임 시작";
	gotoxy(34, 28); cout << "2. 도움말";
	gotoxy(54, 28); cout << "3. 랭킹보기";
	gotoxy(74, 28); cout << "4. 종료하기";
}
