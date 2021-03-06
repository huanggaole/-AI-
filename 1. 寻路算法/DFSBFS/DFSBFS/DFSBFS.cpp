// DFSBFS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include "Map.h"
#include "Character.h"
#include "DFS.h"
#include <iostream> 
using namespace std;
int main()
{
	Map map;
	map.drawMap();
	map.drawChar();
	Character * character = map.getCharacter();
	DFS dfs(&map);
	// 将起点赋值给dfs
	
	while (true){
		Sleep(500);
		dfs.visitATile();
		map.drawMap();
		map.drawChar();
		if (dfs.ifNoway()) {
			std::wcout << L"没有找到路径";
			break;
		}
		if (dfs.ifSearched()) {
			std::wcout << L"找到了路径！";
			break;
		}
	}
	/*
	
	_setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << L"▓▓▓▓▓❐⇐⇑⇒⇓ ⇍ ⇏⇞⇟ ←↑→↓↙↘↖↗↰↱↲↳↴↵↶↺↻↷\n";
	std::wcout << L"▓  ▓☺☺ ☻♧♡♂♀♠♣♥❤☜☞☎☏☃⊙◎ ☺☻☼▧▨♨◐◑↔↕▪ ? ◊◦▣▤▥ ▦▩◘ ◈◇\1\1\u0001☺\u9787\n";
	std::wcout << L"▓▓▓▓▓\n";
	*/

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
