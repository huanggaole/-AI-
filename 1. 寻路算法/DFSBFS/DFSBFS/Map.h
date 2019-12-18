#pragma once
#include "stdio.h"
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
private:
	int width;
	int height;
	int posx;
	int posy;
	int ** MapArray;
	void drawTile(int type);
	
};