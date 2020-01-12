#include "pch.h"
#include "DFS.h"
#include <iostream> 
using namespace std;

DFS::DFS(Map * _map) {
	this->clearStacks();
	this->map = _map;
	Tile *tile = new Tile();
	tile->x = _map->getCharacter()->posx;
	tile->y = _map->getCharacter()->posy;
	tile->parent = NULL;
	this->tileVisiting.push(*tile);
	this->tileAll.push(*tile);
	this->ifsearched = false;
}

DFS::~DFS() {
	// this->clearStacks();
}

void DFS::clearStacks() {
	while (this->tileVisiting.size() != 0) {
		this->tileVisiting.pop();
	}
	while (this->tileAll.size() != 0) {
		Tile *tile = &(this->tileAll.top());
		this->tileAll.pop();
		delete tile;
	}
}

bool DFS::ifNoway() {
	if (this->tileVisiting.size() == 0) {
		return true;
	}
	return false;
}

void DFS::visitATile() {
	// 从队列中取出一个头部节点
	Tile tile = this->tileVisiting.top();
	this->tileVisiting.pop();
	// 修改被访问节点的状态
	int tilestate = this->map->getState(tile.x, tile.y);
	if (tilestate == FromLeft) {
		this->map->setState(tile.x, tile.y, LeftBack);
	}
	if (tilestate == FromRight) {
		this->map->setState(tile.x, tile.y, RightBack);
	}
	if (tilestate == FromUp) {
		this->map->setState(tile.x, tile.y, UpBack);
	}
	if (tilestate == FromDown) {
		this->map->setState(tile.x, tile.y, DownBack);
	}
	// 将角色置于取出的头部节点上
	this->map->getCharacter()->setPos(tile.y, tile.x);

	// 判断该角色的上下左右四个方向是否可访问
	if (this->map->ifCanVisited(tile.x - 1, tile.y)) {
		Tile * newtile = new Tile();
		newtile->x = tile.x - 1;
		newtile->y = tile.y;
		newtile->parent = &tile;
		this->tileVisiting.push(*newtile);
		this->tileAll.push(*newtile);
		if (this->map->getState(newtile->x, newtile->y) == End) {
			ifsearched = true;
		}
		this->map->setState(newtile->x, newtile->y, FromRight);
	}
	if (this->map->ifCanVisited(tile.x + 1, tile.y)) {
		Tile * newtile = new Tile();
		newtile->x = tile.x + 1;
		newtile->y = tile.y;
		newtile->parent = &tile;
		this->tileVisiting.push(*newtile);
		this->tileAll.push(*newtile);
		if (this->map->getState(newtile->x, newtile->y) == End) {
			ifsearched = true;
		}
		this->map->setState(newtile->x, newtile->y, FromLeft);
	}
	if (this->map->ifCanVisited(tile.x, tile.y - 1)) {
		Tile * newtile = new Tile();
		newtile->x = tile.x;
		newtile->y = tile.y - 1;
		newtile->parent = &tile;
		this->tileVisiting.push(*newtile);
		this->tileAll.push(*newtile);
		if (this->map->getState(newtile->x, newtile->y) == End) {
			ifsearched = true;
		}
		this->map->setState(newtile->x, newtile->y, FromDown);
	}
	if (this->map->ifCanVisited(tile.x, tile.y + 1)) {
		Tile * newtile = new Tile();
		newtile->x = tile.x;
		newtile->y = tile.y + 1;
		newtile->parent = &tile;
		this->tileVisiting.push(*newtile);
		this->tileAll.push(*newtile);
		if (this->map->getState(newtile->x, newtile->y) == End) {
			ifsearched = true;
		}
		this->map->setState(newtile->x, newtile->y, FromDown);
	}
}

bool DFS::ifSearched() {
	return ifsearched;
}