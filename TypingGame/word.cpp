#define _CRT_SECURE_NO_WARNINGS
#include "TypingGame.h"
#include <iostream>


extern int Wcount = 0;
extern vector<string> wordList(0);

void Word(); // 단어 읽어오기
void bringWords();

void Word() {
	ifstream read;
	read.open("word.txt", ios::in);
	//if (read.is_open()) cout << "파일 열림" << endl;

	string temp;
	while (!read.eof()) {
		if (getline(read, temp)) {
			Wcount++;
		}
	}
	bringWords();
}

void bringWords() {
	ifstream fin1;
	fin1.open("word.txt", ios::in);

	string temp;
	while (!fin1.eof()) {
		if (getline(fin1, temp)) {
			wordList.push_back(temp);
		}
	}

}