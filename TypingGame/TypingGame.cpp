#include <iostream>
#include <thread>
#include "TypingGame.h"
#define HAVE_STRUCT_TIMESPEC

#define wordCount 150 // 단어 개수

time_t startTime = 0, endTime = 0; // 게임 시간 제한
double user_time; // 게임 시간
int word_speed = 10000; // 단어 뜨

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

int wordc[150]; // 단어 중복 방지
int user_score = 0; // 사용자 점수
int bestScore = 0; // 최고 점수
int level = 1; // 총 3단계
int color[3] = { 1, 2, 4 }; // 파, 초, 빨
int Changec[3] = { 11, 13, 14 }; // 하늘, 보라, 노랑
int remember[wordCount][3] = { 0, }; // 점수체크
char scan[20]; // 단어 입력받기
char name[10]; // 사용자 이름
int ChangeColor; // 바뀔 단어색 정하기
int Sign[3]; // 0 : 음수, 1 : 양수
int ChangeScore[3] = { 0, 0, 0 }; // 각 색의 바뀐 점수
int Csign; // 부호 정하는 변수
int Cscore; // 점수 정하는 변수

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

	srand((unsigned)time(0)); // 단어색 바뀔 시간 정하기
	ChangeColor = rand() % 17 + 3; // 3초에서 19초 사이

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
		
		wordPrint();// 단어출력
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
		wordc[w] = 1; // 중복
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

					gotoxy(x, y); cout << "          "; // 단어 지우기
				}
			}
		}
		if (user_time <= ChangeColor) {
			for (int i = 0; i < 3; i++) {
				Csign = rand() % 2;
				Cscore = rand() % 451 + 50; // 50 ~ 500점 사이
				Sign[i] = Csign;
				ChangeScore[i] = Cscore;
			}
	
		}
		if (user_time >= ChangeColor && user_time <= ChangeColor + 5 ) {
			gotoxy(30, 43); cout << "5초동안 글자색이 바껴서 나옵니다.";
			gotoxy(x, y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Changec[c]);
			cout << words[w]; // 단어 출력
			remember[w][2] = c + 3;
		}
		else {
			gotoxy(30, 43); cout << "                                       ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[c]);
			gotoxy(x, y);
			cout << words[w]; // 단어 출력
		}
	}

}

void wordScan() {
	int sec = 0;
	GameTime();

	gotoxy(30, 40); cout << "입력 : ";

	while (sec < word_speed) {
		sec++;

		if (_kbhit()) {
			gotoxy(37, 40);  cin >> scan;
			gotoxy(37, 40); cout << "                                  ";

			for (int i = 0; i < 2; i++) {
				if (strcmp(scan, End[i]) == 0) {
					system("cls"); screen();
					gotoxy(30, 20); cout << "정말 게임을 종료하시겠습니까?(y, n) ";
					char ans; cin >> ans;
					if (ans == 'y' || ans == 'Y') {
						gotoxy(30, 20); cout << "                                             ";
						gotoxy(39, 20); cout << "*** 게 임 종 료 ***";
						Sleep(1500);
						gotoxy(32, 20); cout << "2초 후 자동으로 메인으로 넘어갑니다.";
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
				if (strcmp(scan, words[i]) == 0) { // 입력한 단어가 맞을 때
					wordc[i] = 2; // 단어 맞췄을 때
					int x = remember[i][0];
					int y = remember[i][1];
					int color = remember[i][2];

					gotoxy(x, y); cout << "          "; // 단어 지우기

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
					gotoxy(2, 3); cout << "현재 점수 : " << user_score;

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
			gotoxy(37, 20); cout << "2단계로 올라갑니다!!";
			Sleep(1500);
			system("cls");
			level++; // 2단계
			user_time = 0; startTime = 0; endTime = 0; word_speed = 7000;
			for (int i = 0; i < wordCount; i++)
				wordc[i] = 0;
			Play();

		}else if (level == 2) {
			gotoxy(37, 20); cout << "3단계로 올라갑니다!!";
			Sleep(1500);
			system("cls");
			level++; // 3단계
			user_time = 0; startTime = 0; endTime = 0; word_speed = 4000;
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

