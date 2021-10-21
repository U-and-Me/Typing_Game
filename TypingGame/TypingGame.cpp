#define HAVE_STRUCT_TIMESPEC
#include <iostream>
#include <thread>
#include <mutex>
#include "TypingGame.h"

std::mutex mu1, mu2, mu3;

time_t startTime = 0, endTime = 0, cur_time = 0, pass_time = 0; // 게임 시간 제한
double user_time; // 사용자 게임 시간
int word_speed = 2000; // 단어 뜨는 속도
int remove_speed = 4000; // 없어지는 속도

void wordPrint(); // 단어 출력
void wordScan();  // 단어 입력
void wordRemove(); // 단어 지우기
void GameTime();  // 게임 시간
void Score();     // 점수
void saveScore(); // 점수 저장
void Start_Game();
void timer();
void Info();

//int wordc[150]; // 단어 중복 방지
vector<int> wordc(150);
int level = 1; // 총 3단계
int color[3] = { 1, 2, 4 }; // 파, 초, 빨
int Changec[3] = { 11, 13, 14 }; // 하늘, 보라, 노랑
//int remem_W[count][3] = { 0, }; // 점수체크
vector<int> remem_X(150);
vector<int> remem_Y(150);
vector<int> remem_C(150);

string scan; // 단어 입력받기
int ChangeColor; // 바뀔 단어색 정하기
int Sign[3]; // 0 : 음수, 1 : 양수
int ChangeScore[3] = { 0, 0, 0 }; // 각 색의 바뀐 점수
int Csign; // 부호 정하는 변수
int Cscore; // 점수 정하는 변수
char name[10]; // 사용자 이름
int user_score = 0; // 사용자 점수
//int Rcount[count] = { 0, }; // 단어 지우는 배열
vector<int> Rcount(150);
int ind1 = 0; // wordPrint() 에서 사용
int ind2 = 0;

int ip = 1, op = 1, wr = 1;

void saveScore() {
	ofstream fout("rank.txt", ios::app);
	fout << name << "\t" << user_score << endl;
	fout.close();
}

void screen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

	system("cls");
	srand((unsigned)time(0)); // 단어색 바뀔 시간 정하기
	ChangeColor = rand() % 17 + 3; // 3초에서 19초 사이

	screen();

	if (level == 1) {
		gotoxy(30, 20); cout << "이름을 입력해주세요 : ";
		cin >> name;
		system("cls"); screen();
	}

	gotoxy(43, 20); cout << "3초 후 시작!";	
	Sleep(1000);
	gotoxy(43, 20); cout << "2초 후 시작!";
	Sleep(1000);
	gotoxy(43, 20); cout << "1초 후 시작!";
	Sleep(1000);

	system("cls"); screen();

	startTime = clock(); 
	Info();
	Start_Game();

}

void Start_Game() {
	
	ip = 1; op = 1; wr = 1;

	thread t1(timer);

	thread t2(wordPrint);
	thread t3(wordRemove);
	thread t4(GameTime);
	thread t5(wordScan);

	t1.join();

	t2.join();
	t5.join();
	t3.join();
	t4.join();
	

	
}

void timer() {
	int tt = 25;
	while (tt != 0) {
		mu1.lock();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoxy(94, 2); cout << tt << " ";
		gotoxy(38, 40); //cout << scan;
		mu1.unlock();
		Sleep(1000); tt--;
		//cout << "실행중  " << tt ;
	}
}

void Info() {
	gotoxy(3, 2); cout << "Level : " << level;
	gotoxy(3, 3); cout << "현재 점수 : " << user_score;
	gotoxy(82, 2); cout << "게임 시간 : 25";
	gotoxy(30, 40); cout << "입력 : ";
}

void wordPrint() {
		srand((unsigned)time(0));
		while (op) {
			int x = rand() % 80 + 3; // 3 ~ 82
			int y = rand() % 32 + 5; // 5 ~ 36
			int w = rand() % Wcount; // 0 ~ 149
			int c = rand() % 3; // 0 ~ 2


			if (wordc[w] != 1 || wordc[w] != 2) { // 중복체크
				wordc[w] = 1; // 중복
				remem_X[w] = x;
				remem_Y[w] = y;
				remem_C[w] = c;

				Rcount[ind1++] = w;

				if (user_time >= ChangeColor + 6) {
					for (int i = 0; i < Wcount; i++) {
						if (remem_C[i] > 2) {
							int x = remem_X[i];
							int y = remem_Y[i];
							remem_C[i] = 100;

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
				//mu2.lock();
				if (user_time >= ChangeColor && user_time <= ChangeColor + 5) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					//gotoxy(30, 43); cout << "5초동안 글자색이 바뀌어 나옵니다.";
					gotoxy(x, y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Changec[c]);
					cout << wordList.at(w); // 단어 출력
					remem_C[w] = c + 3;
					Rcount.push_back(w);
				}
				else {
					gotoxy(30, 43); cout << "                                       ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[c]);
					gotoxy(x, y);
					cout << wordList.at(w); // 단어 출력
				}
				//gotoxy(38, 40); //cout << scan;
				//mu2.unlock();
			}
			Sleep(word_speed); // 단어 뜨는 속도 조절
		}

}

void wordScan() {
		while (ip) {
			//gotoxy(2, 0); cout << "                                  ";
			if (_kbhit()) {
				mu3.lock();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoxy(37, 40);  cin >> scan;
				gotoxy(37, 40); cout << "                                  ";

				for (int i = 0; i < Wcount; i++) {
					if (scan == wordList.at(i)) { // 입력한 단어가 맞을 때
						wordc[i] = 2; // 단어 맞췄을 때
						int x = remem_X[i];
						int y = remem_Y[i];
						int color = remem_C[i];

						gotoxy(x, y); cout << "         "; // 단어 지우기
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
						default: break;
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						gotoxy(15, 3); cout << user_score << "  ";
					}


				}
				mu3.unlock();
			} // end of if
			//scan = "";
			
		}
}

void wordRemove() {
	while (wr) {
		Sleep(remove_speed);

		int index = Rcount.at(ind2++);
		int x = remem_X[index];
		int y = remem_Y[index];
		gotoxy(x, y); cout << "         ";
		remem_C[index] = 100; // 점수 오르는거 방지
	}
}

void GameTime() {
	while (true) {
		endTime = clock();
		user_time = (double)(endTime - startTime) / (CLOCKS_PER_SEC);

		if (user_time > 25) {
			ip = 0; op = 0; wr = 0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			system("cls"); screen();
			Score();
			Sleep(3000);
			system("cls");
			if (level == 1) {
				gotoxy(37, 20); cout << "2단계로 올라갑니다!!";
				Sleep(1500);
				system("cls");
				level++; // 2단계
				user_time = 0; startTime = 0; endTime = 0; word_speed = 1000; remove_speed = 2000;
				for (int i = 0; i < Wcount; i++)
					wordc[i] = 0;
				Play();

			}
			else if (level == 2) {
				gotoxy(37, 20); cout << "3단계로 올라갑니다!!";
				Sleep(1500);
				system("cls");
				level++; // 3단계
				user_time = 0; startTime = 0; endTime = 0; word_speed = 800; remove_speed = 1300;
				for (int i = 0; i < Wcount; i++)
					wordc[i] = 0;
				Play();
			}
			else {
				level = 1;
				saveScore();
				gotoxy(37, 20); cout << "*** 게 임 종 료 ***";
				Sleep(1500);
				gotoxy(30, 20); cout << "2초 후 자동으로 메인으로 넘어갑니다.";
				Sleep(2000);
				system("cls");
				main();
			}

		}
	}
}

void Score() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

