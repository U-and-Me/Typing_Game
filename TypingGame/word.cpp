#define _CRT_SECURE_NO_WARNINGS
#include "TypingGame.h"
#include <iostream>


void Word(); // 단어 읽어오기

int Wcount = 0;

void Word() {

	ifstream read;
	read.open("word.txt", ios::in);
	if (read.is_open()) cout << "파일 열림" << endl;
	//Sleep(5000);

	string temp;
	while (!read.eof()) {
		if (getline(read, temp, ',')) {
			Wcount++;
		}
	}

	cout << Wcount << endl;

	Sleep(4000);
}

void sortWord() {
	ifstream fin1;
	fin1.open("word.txt", ios::in);



}


