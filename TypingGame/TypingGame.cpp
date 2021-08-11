#include <iostream>
#include "TypingGame.h"

#define wordCount 150 // �ܾ� ����
#define wordTime 20000 // �ܾ� �ߴ� �ӵ�

time_t startTime = 0, endTime = 0; // ���� �ð� ����
int user_time; // ���� �ð�

void wordPrint();
void wordScan();


string words[] = { "include", "print", "game", "music", "rain", "link", "book", "mouse","word", "phone",
"august", "season", "studio", "listen", "jaw", "ear", "saddle", "ska", "as","reward",
"reader", "lad", "upland", "sky", "bet", "thief", "hungry", "nothing", "language","finish",
"each", "several", "lock", "silence", "save", "choir", "zerosum", "icefall","step", "problem",
"center", "upmost", "fake", "keek", "safe", "lass", "reason", "dawm","since", "net",
"computer", "plan", "animal", "icon", "engineer", "assent", "runaway", "jump", "alarm", "fence",
"company", "member", "score", "often", "club", "pocket", "arrive", "collection", "keycase", "visitor",
"vanish", "jazz", "close", "everybody", "advice", "which", "twice", "cut", "rubberize", "clue",
"camera", "headache", "prize", "wealthy", "holiday", "throw", "south", "fight", "earhole", "enough",
"journey", "baby", "loudly", "label", "know", "vagrancy", "meat", "song", "neathouse", "teenager",
"lightning", "Olympic", "prison", "machine", "windy", "natalist", "rest", "news", "break", "fast",
"age", "attent", "half", "gangle", "kennel", "wash", "sand", "new", "continue", "script",
"live", "share", "short", "long", "accept", "submit", "report", "react", "rise", "proceed",
"double", "open", "position", "tourists", "receive", "product", "refund", "follow", "session", "discuss",
"quick", "duties", "price", "recent", "visit", "decline", "need", "difficult", "very", "develop"
};

int wordc[150]; // �ܾ� �ߺ� ����
int user_score = 0;
int bestScore = 0;
int level = 1; // �� 3�ܰ�
int color[3] = { 1, 2, 4 };
int remember[wordCount][3] = { 0, }; // ����üũ
char scan[20]; // �ܾ� �Է¹ޱ�

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

void Play() {
	screen();

	gotoxy(40, 23); cout << "3�� �� ����!";	
	Sleep(1000);
	gotoxy(40, 23); cout << "2�� �� ����!";
	Sleep(1000);
	gotoxy(40, 23); cout << "1�� �� ����!";
	Sleep(1000);

	system("cls"); screen();

	while (true) {
		wordPrint(); // �ܾ����
		wordScan(); // �ܾ� �Է�
	}

}

void wordPrint() {

	srand((unsigned)time(0));

	int check = wordCount;
	int x = rand() % 80 + 3;
	int y = rand() % 33 + 3;
	int w = rand() % wordCount;
	int c = rand() % 3;

	if (wordc[w] != 1) { // �ߺ�üũ
		wordc[w] = 1; 
		check--;

		gotoxy(x, y);
		for (int i = 0; i < 3; i++) {
			switch (i) {
			case 0: remember[w][i] = x; break;
			case 1: remember[w][i] = y; break;
			case 2: remember[w][i] = c; break;
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[c]);
		cout << words[w]; // �ܾ� ���
		
	}

}

void wordScan() {
	//gotoxy(30, 40); cout << "�Է� : ";
}
