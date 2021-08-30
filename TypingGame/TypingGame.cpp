#include <iostream>
#include <thread>
#include "TypingGame.h"
#define HAVE_STRUCT_TIMESPEC

#define wordCount 150 // �ܾ� ����

time_t startTime = 0, endTime = 0; // ���� �ð� ����
double user_time; // ���� �ð�
int word_speed = 10000; // �ܾ� ��

void wordPrint();
void wordScan();
void GameTime();
void Score();

char words[][150] = { "include", "print", "game", "music", "rain", "link", "book", "mouse","word", "phone",
"august", "season", "studio", "listen", "jaw", "ear", "saddle", "ska", "as","reward",
"reader", "lad", "upland", "sky", "bet", "thief", "hungry", "nothing", "language","finish",
"each", "several", "lock", "silence", "save", "choir", "zerosum", "icefall","step", "problem",
"center", "upmost", "fake", "keek", "safe", "lass", "reason", "dawn","since", "net",
"computer", "plan", "animal", "icon", "engineer", "assent", "runaway", "jump", "alarm", "fence",
"company", "member", "score", "often", "club", "pocket", "arrive", "collection", "keycase", "visitor",
"vanish", "jazz", "close", "everybody", "advice", "which", "twice", "cut", "rubberize", "clue",
"camera", "headache", "prize", "wealthy", "holiday", "throw", "south", "fight", "earhole", "enough",
"journey", "baby", "loudly", "label", "know", "vagrancy", "meat", "song", "neathouse", "teenager",
"lighting", "Olympic", "prison", "machine", "windy", "natalist", "rest", "news", "break", "fast",
"age", "attent", "half", "gangle", "kennel", "wash", "sand", "new", "continue", "script",
"live", "share", "short", "long", "accept", "submit", "report", "react", "rise", "proceed",
"double", "open", "position", "tourists", "receive", "product", "refund", "follow", "session", "discuss",
"quick", "duties", "price", "recent", "visit", "decline", "need", "difficult", "very", "develop"
};
const char End[][4] = { "end", "END" };

int wordc[150]; // �ܾ� �ߺ� ����
int user_score = 0; // ����� ����
int bestScore = 0; // �ְ� ����
int level = 1; // �� 3�ܰ�
int color[3] = { 1, 2, 4 }; // ��, ��, ��
int Changec[3] = { 11, 13, 14 }; // �ϴ�, ����, ���
int remember[wordCount][3] = { 0, }; // ����üũ
char scan[20]; // �ܾ� �Է¹ޱ�
char name[10]; // ����� �̸�
int ChangeColor; // �ٲ� �ܾ�� ���ϱ�
int Sign[3]; // 0 : ����, 1 : ���
int ChangeScore[3] = { 0, 0, 0 }; // �� ���� �ٲ� ����
int Csign; // ��ȣ ���ϴ� ����
int Cscore; // ���� ���ϴ� ����

void screen() {
	for (int i = 1; i < 44; i++) {
		gotoxy(1, i); cout << "|";
		gotoxy(98, i); cout << "|";
	}
	for (int i = 1; i < 99; i++) {
		gotoxy(i, 1); cout << "-";
		gotoxy(i, 37); cout << "-";
		gotoxy(i, 44); cout << "-";
	}

}

void Play() {

	srand((unsigned)time(0)); // �ܾ�� �ٲ� �ð� ���ϱ�
	ChangeColor = rand() % 17 + 3; // 3�ʿ��� 19�� ����

	screen();

	if (level == 1) {
		gotoxy(30, 20); cout << "�̸��� �Է����ּ��� : ";
		cin >> name;
		system("cls"); screen();
	}
	

	gotoxy(40, 20); cout << "3�� �� ����!";	
	Sleep(1000);
	gotoxy(40, 20); cout << "2�� �� ����!";
	Sleep(1000);
	gotoxy(40, 20); cout << "1�� �� ����!";
	Sleep(1000);

	system("cls"); screen();

	startTime = clock();

	while (true) {
		
		wordPrint();// �ܾ����
		wordScan(); // �ܾ� �Է�
		

	}

}

void wordPrint() {

	srand((unsigned)time(0));

	int check = wordCount;
	int x = rand() % 80 + 3;
	int y = rand() % 33 + 4;
	int w = rand() % wordCount;
	int c = rand() % 3;

	if (wordc[w] != 1) { // �ߺ�üũ
		wordc[w] = 1; // �ߺ�
		check--;

		for (int i = 0; i < 3; i++) {
			switch (i) {
			case 0: remember[w][i] = x; break;
			case 1: remember[w][i] = y; break;
			case 2: remember[w][i] = c; break;
			}
		}
		if (user_time >= ChangeColor + 6) {
			for (int i = 0; i < wordCount; i++) {
				if (remember[i][2] > 2) {
					int x = remember[i][0];
					int y = remember[i][1];

					gotoxy(x, y); cout << "          "; // �ܾ� �����
				}
			}
		}
		if (user_time <= ChangeColor) {
			for (int i = 0; i < 3; i++) {
				Csign = rand() % 2;
				Cscore = rand() % 451 + 50; // 50 ~ 500�� ����
				Sign[i] = Csign;
				ChangeScore[i] = Cscore;
			}
	
		}
		if (user_time >= ChangeColor && user_time <= ChangeColor + 5 ) {
			gotoxy(30, 43); cout << "5�ʵ��� ���ڻ��� �ٲ��� ���ɴϴ�.";
			gotoxy(x, y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Changec[c]);
			cout << words[w]; // �ܾ� ���
			remember[w][2] = c + 3;
		}
		else {
			gotoxy(30, 43); cout << "                                       ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[c]);
			gotoxy(x, y);
			cout << words[w]; // �ܾ� ���
		}
	}

}

void wordScan() {
	int sec = 0;
	GameTime();

	gotoxy(30, 40); cout << "�Է� : ";

	while (sec < word_speed) {
		sec++;

		if (_kbhit()) {
			gotoxy(37, 40);  cin >> scan;
			gotoxy(37, 40); cout << "                                  ";

			for (int i = 0; i < 2; i++) {
				if (strcmp(scan, End[i]) == 0) {
					system("cls"); screen();
					gotoxy(30, 20); cout << "���� ������ �����Ͻðڽ��ϱ�?(y, n) ";
					char ans; cin >> ans;
					if (ans == 'y' || ans == 'Y') {
						gotoxy(30, 20); cout << "                                             ";
						gotoxy(39, 20); cout << "*** �� �� �� �� ***";
						Sleep(1500);
						gotoxy(32, 20); cout << "2�� �� �ڵ����� �������� �Ѿ�ϴ�.";
						Sleep(2000);
						system("cls");
						main();
					}
					else {
						gotoxy(30, 20); cout << "                                             ";
						wordPrint();
					}

					
				}
			}

			for (int i = 0; i < wordCount; i++) {
				if (strcmp(scan, words[i]) == 0) { // �Է��� �ܾ ���� ��
					wordc[i] = 2; // �ܾ� ������ ��
					int x = remember[i][0];
					int y = remember[i][1];
					int color = remember[i][2];

					gotoxy(x, y); cout << "          "; // �ܾ� �����

					switch (color) {
					case 0: user_score += 100; break;
					case 1: user_score += 150; break;
					case 2: user_score += 200; break;
					case 3: if (Sign[0] == 0) user_score -= ChangeScore[0]; 
							else user_score += ChangeScore[0];
							break;			
					case 4:if (Sign[1] == 0) user_score -= ChangeScore[1];
						  else user_score += ChangeScore[1];
							break;
					case 5:if (Sign[2] == 0) user_score -= ChangeScore[2];
						  else user_score += ChangeScore[2];
							break;
					}
					gotoxy(2, 3); cout << "���� ���� : " << user_score;

				}
				
				
			}

		}
	}
}

void GameTime() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	endTime = clock();
	user_time = (double)(endTime - startTime) / (CLOCKS_PER_SEC);

	if (user_time > 25){
		system("cls"); screen();
		Score();
		Sleep(3000);
		system("cls");
		if (level == 1) {
			gotoxy(37, 20); cout << "2�ܰ�� �ö󰩴ϴ�!!";
			Sleep(1500);
			system("cls");
			level++; // 2�ܰ�
			user_time = 0; startTime = 0; endTime = 0; word_speed = 7000;
			for (int i = 0; i < wordCount; i++)
				wordc[i] = 0;
			Play();

		}else if (level == 2) {
			gotoxy(37, 20); cout << "3�ܰ�� �ö󰩴ϴ�!!";
			Sleep(1500);
			system("cls");
			level++; // 3�ܰ�
			user_time = 0; startTime = 0; endTime = 0; word_speed = 4000;
			for (int i = 0; i < wordCount; i++)
				wordc[i] = 0;
			Play();
		}
		else {
			gotoxy(37, 20); cout << "*** �� �� �� �� ***";
			Sleep(1500);
			gotoxy(30, 20); cout << "2�� �� �ڵ����� �������� �Ѿ�ϴ�.";
			Sleep(2000);
			system("cls");
			main();
		}

	}

}

void Score() {
	gotoxy(30, 16); cout << "============= ���� ��� =============";
	gotoxy(30, 17); cout << "==                                 ";
	gotoxy(65, 17); cout << "== ";
	gotoxy(30, 18); cout << "==     ��  ��    : " << name;
	gotoxy(65, 18); cout << "== ";
	gotoxy(30, 19); cout << "==     ���� �ܰ� : Level " << level;
	gotoxy(65, 19); cout << "== ";
	gotoxy(30, 20); cout << "==     �� ����   : " << user_score;
	gotoxy(65, 20); cout << "== ";
	gotoxy(30, 21); cout << "==                                 ";
	gotoxy(65, 21); cout << "== ";
	gotoxy(30, 22); cout << "=====================================";
}

