#pragma once
#include "windows.h"
#include <io.h>
#include <fcntl.h>
class Character {
public:
	Character(int x, int y);
	~Character();
	void drawChar();
	void setPos(int _x, int _y);
	void goLeft();
	void goUp();
	void goRight();
	void goDown();
	int posx;
	int posy;
};