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
void Play(); // ���ӽ���
void screen();
void game_help(); // ����
void Rank(); // ��ŷ
void Word();

extern int Wcount;
extern vector<string> wordList;