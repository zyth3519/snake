#pragma once
#ifndef BEAN_H
#define BEAN_H
#include <graphics.h>
#include <vector>

using namespace std;

const int MAPLEFT = 2;
const int MAPTOP = 2;
const int MAPRIGHT = 49;
const int MAPBOTTOM = 38;

const int MAXSIZE = 99;

struct MoveKey
{
	char up;
	char down;
	char left;
	char right;
};

// 蛇
struct Snake
{
	// 使用容器来储存
	int x[MAXSIZE];
	int y[MAXSIZE];
	MoveKey key;
	int len = 3;
	// key默认为空,指定默认值没用
	char direction;
};

struct Food
{
	int x;
	int y;
};

// 每次添加一个条蛇，需要在此注册
extern vector<Snake*> snakes;
extern Food food;
extern COLORREF snakeColor;
extern int speed;
#endif // !BEAN_H

