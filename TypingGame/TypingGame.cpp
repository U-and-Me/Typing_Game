#include <iostream>
#include "TypingGame.h"

#define wordCount 150 // 단어 개수

time_t startTime = 0, endTime = 0; // 게임 시간 제한
double user_time; // 게임 시간
int word_speed = 1500;

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

int wordc[150]; // 단어 중복 방지
int user_score = 0;
int bestScore = 0;
int level = 1; // 총 3단계
int color[3] = { 1, 2, 4 }; // 파, 초, 빨
int Changec[3] = { 11, 13, 14 }; // 하늘, 보라, 노랑
int remember[wordCount][3] = { 0, }; // 점수체크
char scan[20]; // 단어 입력받기
char name[10];
int speed = 1500;
int ChangeColor;

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

	srand((unsigned)time(0)); // 단어색 바뀔 시간 정하기
	ChangeColor = rand() % 17 + 3; // 3초에서 20초 사이

	screen();

	if (level == 1) {
		gotoxy(30, 20); cout << "이름을 입력해주세요 : ";
		cin >> name;
		system("cls"); screen();
	}
	

	gotoxy(40, 20); cout << "3초 후 시작!";	
	Sleep(1000);
	gotoxy(40, 20); cout << "2초 후 시작!";
	Sleep(1000);
	gotoxy(40, 20); cout << "1초 후 시작!";
	Sleep(1000);

	system("cls"); screen();

	startTime = clock();

	while (true) {
		wordPrint(); // 단어출력
		wordScan(); // 단어 입력
	}

}

void wordPrint() {

	srand((unsigned)time(0));

	int check = wordCount;
	int x = rand() % 80 + 3;
	int y = rand() % 33 + 4;
	int w = rand() % wordCount;
	int c = rand() % 3;

	if (wordc[w] != 1) { // 중복체크
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
		
		if (user_time >= ChangeColor && user_time <= ChangeColor +5 ) {
			gotoxy(30, 43); cout << "5초동안 글자색이 바껴서 나옵니다.";
			gotoxy(x, y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Changec[c]);
			cout << words[w]; // 단어 출력
			remember[w][2] = c + 3;
		}
		else {
			gotoxy(30, 43); cout << "                                       ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[c]);
			cout << words[w]; // 단어 출력
		}


		
	}

}

void wordScan() {
		GameTime();

		gotoxy(30, 40); cout << "입력 : ";

		if (_kbhit()) {
			char scan[20];
			gotoxy(37, 40);  cin >> scan;
			gotoxy(37, 40); cout << "                                  ";

			for (int i = 0; i < wordCount; i++) {
				if (strcmp(scan, words[i]) == 0) { // 입력한 단어가 맞을 때
					int x = remember[i][0];
					int y = remember[i][1];
					int color = remember[i][2];

					gotoxy(x, y); cout << "          "; // 단어 지우기

					switch (color) {
					case 0: user_score += 100; break;
					case 1: user_score += 150; break;
					case 2: user_score += 200; break;
					case 3: user_score -= 50; break;
					case 4: user_score += 130; break;
					case 5: user_score -= 100; break;
					}

				}
				gotoxy(2, 3); cout << "현재 점수 : " << user_score;
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
			gotoxy(37, 20); cout << "2단계로 올라갑니다!!";
			Sleep(1500);
			system("cls");
			level++; // 2단계
			user_time = 0; startTime = 0; endTime = 0; word_speed = 2000;
			for (int i = 0; i < wordCount; i++)
				wordc[i] = 0;
			Play();

		}else if (level == 2) {
			gotoxy(37, 20); cout << "3단계로 올라갑니다!!";
			Sleep(1500);
			system("cls");
			level++; // 3단계
			user_time = 0; startTime = 0; endTime = 0; word_speed = 1000;
			for (int i = 0; i < wordCount; i++)
				wordc[i] = 0;
			Play();
		}
		else {
			gotoxy(37, 20); cout << "*** 게 임 종 료 ***";
			Sleep(1500);
			gotoxy(30, 20); cout << "2초 후 자동으로 메인으로 넘어갑니다.";
			Sleep(2000);
			system("cls");
			main();
		}

	}

}

void Score() {
	gotoxy(30, 16); cout << "============= 게임 결과 =============";
	gotoxy(30, 17); cout << "==                                 ";
	gotoxy(65, 17); cout << "== ";
	gotoxy(30, 18); cout << "==     이  름    : " << name;
	gotoxy(65, 18); cout << "== ";
	gotoxy(30, 19); cout << "==     현재 단계 : Level " << level;
	gotoxy(65, 19); cout << "== ";
	gotoxy(30, 20); cout << "==     총 점수   : " << user_score;
	gotoxy(65, 20); cout << "== ";
	gotoxy(30, 21); cout << "==                                 ";
	gotoxy(65, 21); cout << "== ";
	gotoxy(30, 22); cout << "=====================================";
}
