#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <atlstr.h>
#include "bean.h"
#include "util.h"

// 判断是否碰到身体,不判断蛇头
bool hitBody(Square square)
{
	for (int i = 1; i < snake.len; i++)
	{
		if (hit(snake.body[i], square))
		{
			return true;
		}
	}
	return false;
}

/*
画有边框的填充正方形
square 正方形
fill 填充颜色，默认绿色
border 边框颜色，默认绿色
*/
void drawSquare(Square square, COLORREF fill, COLORREF border)
{
	setlinecolor(border);
	setfillcolor(fill);
	fillrectangle(square.left, square.top, square.right, square.bottom);
}

// 随机生成颜色
COLORREF randColor()
{
	srand((unsigned)time(0));
	int r = rand() % 256;
	int g = rand() % 256;
	int b = rand() % 256;

	return RGB(r, g, b);
}

/*
获取一个边长为10的正方形
x,y 坐标
*square 正方形的指针,保证操作的是同一个变量
*/
void getSquare(int x, int y, Square* square)
{
	square->top = y - 5;
	square->bottom = y + 5;
	square->left = x - 5;
	square->right = x + 5;
}

/*
判断是否相交
*/
bool hit(Square s1, Square s2)
{
	//return !(((s1.right < s2.left) || (s1.bottom > s2.top)) ||
			 //((s2.right < s1.left) || (s2.bottom > s1.top)));

	if (s1.bottom == s2.bottom && s1.left == s2.left && s1.top == s2.top && s1.right == s2.right)
	{
		return true;
	}
	return false;
}

void keyDown()
{
	if (_kbhit())
	{
		char key = _getch();
		switch (key)
		{
		case UP:
			if (snake.direction != DOWN)
				snake.direction = key;
			break;
		case DOWN:
			if (snake.direction != UP)
				snake.direction = key;
			break;
		case LEFT:
			if (snake.direction != RIGHT)
				snake.direction = key;
			break;
		case RIGHT:
			if (snake.direction != LEFT)
				snake.direction = key;
			break;
		}
	}
}

bool hitWall()
{
	if (((snake.body[0].top <= 20) || (snake.body[0].bottom >= 380)) ||
		((snake.body[0].left <= 20) || (snake.body[0].right >= 490)))
	{
		return true;
	}
	return false;
}

LPCTSTR intTOLPCTSTR(int i)
{
	CString t;
	t.Format(_T("%d"), i);
	return t;
}
