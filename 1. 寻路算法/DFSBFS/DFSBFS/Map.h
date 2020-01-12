#pragma once
#include "stdio.h"
#include "Character.h"
#include "windows.h"
#include <io.h>
#include <fcntl.h>
enum TileType {
	Wall,
	Start,
	End,
	NeverSteped,
	FromLeft,
	FromUp,
	FromRight,
	FromDown,
	LeftBack,
	RightBack,
	UpBack,
	DownBack
};

class Map {
public:
	Map();
	~Map();
	void drawMap();
	void drawChar();
	Character * getCharacter();
	bool ifCanVisited(int _x, int _y);
	int getState(int _x, int _y);
	void setState(int _x, int _y, int state);
private:
	int width;
	int height;
	int ** MapArray;
	Character * character;
	void drawTile(int type);
};