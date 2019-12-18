#include"pch.h"
#include "Map.h"
#include <iostream> 
using namespace std;
Map::Map() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	this->width = 8;
	this->height = 8;

	int TempMap[8][8] = {
		{Wall,				Wall,					Wall,					Wall,					Wall,					Wall,					Wall,					Wall	},
		{Wall,				Start,		NeverSteped,	NeverSteped,	NeverSteped,	NeverSteped,	NeverSteped,			Wall	},
		{Wall,		NeverSteped,			Wall,			NeverSteped,			Wall,			NeverSteped,			Wall,					Wall	},
		{Wall,		NeverSteped,			Wall,			NeverSteped,			Wall,			NeverSteped,	NeverSteped,			Wall	},
		{Wall,		NeverSteped,	NeverSteped,	NeverSteped,			Wall,					Wall,			NeverSteped,			Wall	},
		{Wall,				Wall,					Wall,			NeverSteped,	NeverSteped,	NeverSteped,	NeverSteped,			Wall	},
		{Wall,				End,			NeverSteped,	NeverSteped,			Wall,			NeverSteped,	NeverSteped,			Wall	},
		{Wall,				Wall,					Wall,					Wall,					Wall,					Wall,					Wall,					Wall	},
	};

	this->MapArray = new int * [8];
	for (int i = 0; i < 8; i++) {
		this->MapArray[i] = new int[8];
		for (int j = 0; j < 8; j++) {
			this->MapArray[i][j] = TempMap[i][j];
			if (TempMap[i][j] == Start) {
				this->posx = i;
				this->posy = j;
				this->MapArray[i][j] = NeverSteped;
			}
		}
	}
	
}

Map::~Map() {
	for (int i = 0; i < this->height; i++) {
		delete this->MapArray[i];
	}
	delete this->MapArray;
}

void Map::drawMap() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			this->drawTile(this->MapArray[i][j]);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
		std::wcout << i << L"\n";
	}
	for (int j = 0; j < 8; j++) {
		std::wcout << j << L" ";
	}
}

void Map::drawChar() {
	COORD point = { (short)posx * 2, (short)posy};
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);//使用GetStdHandle(STD_OUTPUT_HANDLE)来获取标准输出的句柄
	SetConsoleCursorPosition(HOutput, point);//设置光标位置
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN|FOREGROUND_RED | FOREGROUND_GREEN);
	std::wcout << L"☻";

	COORD point2 = { 0, (short)this->height + 2 };
	SetConsoleCursorPosition(HOutput, point2);//设置光标位置
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void Map::drawTile(int type) {
	switch (type)
	{
	case Wall:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		std::wcout << L"▓";
		break;
	case End:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		std::wcout << L"❐";
		break;
	default:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED| BACKGROUND_BLUE| BACKGROUND_GREEN);
		std::wcout << L"  ";
		break;
	}
}