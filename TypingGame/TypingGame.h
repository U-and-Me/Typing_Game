#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void gotoxy(int x, int y);
void CursorView();
int main();
void logo();
void Menu();
void Play(); // 게임시작
void screen();
void game_help(); // 도움말
void Rank(); // 랭킹
void Word();

extern int Wcount;
extern vector<string> wordList;