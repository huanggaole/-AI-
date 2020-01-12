#pragma once
#include "pch.h"
#include "Map.h"
#include<stack>
using namespace std;

typedef struct Tile {
	int x;
	int y;
	Tile * parent;
};

class DFS {
public:
	DFS(Map * _map);
	~DFS();
	void visitATile();
	void clearStacks();
	bool ifSearched();
	bool ifNoway();
private:
	std::stack<Tile> tileVisiting;
	std::stack<Tile> tileAll;
	Map * map;
	bool ifsearched;
};