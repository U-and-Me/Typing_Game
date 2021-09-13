#include <Windows.h>
#include <conio.h>
#include <iostream>

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

extern char name[10]; // 사용자 이름
extern int user_score; // 사용자 점수