#pragma once
#ifndef BEAN_H
#define BEAN_H
#include <graphics.h>

// 最大长度
const int MAXSIZE = 999;;

const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';

struct Square
{
	int top;
	int bottom;
	int left;
	int right;
};

// 蛇
struct Snake
{
	Square body[MAXSIZE];
	int len = 3;
	char direction = LEFT;
	int speed = 100;
};

extern Snake snake;
extern Square food;
extern COLORREF snakeColor;
#endif // !BEAN_H

