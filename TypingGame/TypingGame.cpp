#define HAVE_STRUCT_TIMESPEC
#include <iostream>
#include <thread>
#include <mutex>
#include "TypingGame.h"

std::mutex mu1, mu2, mu3;

time_t startTime = 0, endTime = 0, cur_time = 0, pass_time = 0; // ���� �ð� ����
double user_time; // ����� ���� �ð�
int word_speed = 2000; // �ܾ� �ߴ� �ӵ�
int remove_speed = 4000; // �������� �ӵ�

void wordPrint(); // �ܾ� ���
void wordScan();  // �ܾ� �Է�
void wordRemove(); // �ܾ� �����
void GameTime();  // ���� �ð�
void Score();     // ����
void saveScore(); // ���� ����
void Start_Game();
void timer();
void Info();

//int wordc[150]; // �ܾ� �ߺ� ����
vector<int> wordc(150);
int level = 1; // �� 3�ܰ�
int color[3] = { 1, 2, 4 }; // ��, ��, ��
int Changec[3] = { 11, 13, 14 }; // �ϴ�, ����, ���
//int remem_W[count][3] = { 0, }; // ����üũ
vector<int> remem_X(150);
vector<int> remem_Y(150);
vector<int> remem_C(150);

string scan; // �ܾ� �Է¹ޱ�
int ChangeColor; // �ٲ� �ܾ�� ���ϱ�
int Sign[3]; // 0 : ����, 1 : ���
int ChangeScore[3] = { 0, 0, 0 }; // �� ���� �ٲ� ����
int Csign; // ��ȣ ���ϴ� ����
int Cscore; // ���� ���ϴ� ����
char name[10]; // ����� �̸�
int user_score = 0; // ����� ����
//int Rcount[count] = { 0, }; // �ܾ� ����� �迭
vector<int> Rcount(150);
int ind1 = 0; // wordPrint() ���� ���
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
	srand((unsigned)time(0)); // �ܾ�� �ٲ� �ð� ���ϱ�
	ChangeColor = rand() % 17 + 3; // 3�ʿ��� 19�� ����

	screen();

	if (level == 1) {
		gotoxy(30, 20); cout << "�̸��� �Է����ּ��� : ";
		cin >> name;
		system("cls"); screen();
	}

	gotoxy(43, 20); cout << "3�� �� ����!";	
	Sleep(1000);
	gotoxy(43, 20); cout << "2�� �� ����!";
	Sleep(1000);
	gotoxy(43, 20); cout << "1�� �� ����!";
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
		//cout << "������  " << tt ;
	}
}

void Info() {
	gotoxy(3, 2); cout << "Level : " << level;
	gotoxy(3, 3); cout << "���� ���� : " << user_score;
	gotoxy(82, 2); cout << "���� �ð� : 25";
	gotoxy(30, 40); cout << "�Է� : ";
}

void wordPrint() {
		srand((unsigned)time(0));
		while (op) {
			int x = rand() % 80 + 3; // 3 ~ 82
			int y = rand() % 32 + 5; // 5 ~ 36
			int w = rand() % Wcount; // 0 ~ 149
			int c = rand() % 3; // 0 ~ 2


			if (wordc[w] != 1 || wordc[w] != 2) { // �ߺ�üũ
				wordc[w] = 1; // �ߺ�
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
				//mu2.lock();
				if (user_time >= ChangeColor && user_time <= ChangeColor + 5) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					//gotoxy(30, 43); cout << "5�ʵ��� ���ڻ��� �ٲ�� ���ɴϴ�.";
					gotoxy(x, y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Changec[c]);
					cout << wordList.at(w); // �ܾ� ���
					remem_C[w] = c + 3;
					Rcount.push_back(w);
				}
				else {
					gotoxy(30, 43); cout << "                                       ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[c]);
					gotoxy(x, y);
					cout << wordList.at(w); // �ܾ� ���
				}
				//gotoxy(38, 40); //cout << scan;
				//mu2.unlock();
			}
			Sleep(word_speed); // �ܾ� �ߴ� �ӵ� ����
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
					if (scan == wordList.at(i)) { // �Է��� �ܾ ���� ��
						wordc[i] = 2; // �ܾ� ������ ��
						int x = remem_X[i];
						int y = remem_Y[i];
						int color = remem_C[i];

						gotoxy(x, y); cout << "         "; // �ܾ� �����
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
		remem_C[index] = 100; // ���� �����°� ����
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
				gotoxy(37, 20); cout << "2�ܰ�� �ö󰩴ϴ�!!";
				Sleep(1500);
				system("cls");
				level++; // 2�ܰ�
				user_time = 0; startTime = 0; endTime = 0; word_speed = 1000; remove_speed = 2000;
				for (int i = 0; i < Wcount; i++)
					wordc[i] = 0;
				Play();

			}
			else if (level == 2) {
				gotoxy(37, 20); cout << "3�ܰ�� �ö󰩴ϴ�!!";
				Sleep(1500);
				system("cls");
				level++; // 3�ܰ�
				user_time = 0; startTime = 0; endTime = 0; word_speed = 800; remove_speed = 1300;
				for (int i = 0; i < Wcount; i++)
					wordc[i] = 0;
				Play();
			}
			else {
				level = 1;
				saveScore();
				gotoxy(37, 20); cout << "*** �� �� �� �� ***";
				Sleep(1500);
				gotoxy(30, 20); cout << "2�� �� �ڵ����� �������� �Ѿ�ϴ�.";
				Sleep(2000);
				system("cls");
				main();
			}

		}
	}
}

void Score() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

