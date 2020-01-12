#include"pch.h"
#include "Character.h"
#include <iostream> 
using namespace std;
Character::Character(int x, int y) {
	this->posx = x;
	this->posy = y;
}

void Character::drawChar() {
	COORD point = { (short)posx * 2, (short)posy };
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
	SetConsoleCursorPosition(HOutput, point);//设置光标位置
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN);
	std::wcout << L"☻";
}

void Character::setPos(int _x, int _y) {
	this->posx = _x;
	this->posy = _y;
}

void Character::goLeft() {
	posx -= 1;
}

void Character::goUp() {
	posy -= 1;
}

void Character::goRight() {
	posx += 1;
}

void Character::goDown() {
	posy += 1;
}