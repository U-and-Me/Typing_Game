#include <Windows.h>
#include <conio.h>
#include <iostream>

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

extern char name[10]; // ����� �̸�
extern int user_score; // ����� ����