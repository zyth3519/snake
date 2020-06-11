#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <atlstr.h>
#include "graphics.h"
#include "bean.h"
#include "util.h"

// 判断是否碰到蛇的身体
bool hitBody(Snake* snake, int x, int y)
{
	// 所有蛇
	for (int i = 0; i < snakes.size(); i++)
	{
		Snake* s = snakes[i];

		// 如果判断的是当前蛇，那就不判断蛇头
		int a = 0;
		if (s == snake)
		{
			a++;
		}
		for (; a < snake->len; a++)
		{
			if (isOverlap(x, y, s->x[a], s->y[a]))
			{
				return true;
			}
		}
	}
	return false;
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

// 检测按键
void keyDown()
{
	if (_kbhit())
	{
		char key = _getch();
		// 判断案件与谁绑定
		for (int i = 0; i < snakes.size(); i++)
		{
			Snake* snake = snakes[i];
			if (key == snake->key.up)
			{
				if (snake->direction != snake->key.down)
					snake->direction = key;
				return;

			}
			if (key == snake->key.down)
			{
				if (snake->direction != snake->key.up)
					snake->direction = key;
				return;

			}
			if (key == snake->key.left)
			{
				if (snake->direction != snake->key.right)
					snake->direction = key;
				return;

			}
			if (key == snake->key.right)
			{
				if (snake->direction != snake->key.left)
					snake->direction = key;
				return;

			}
		}
	}
}

// 是否撞墙
bool hitWall(Snake* snake)
{
	// 判断四周
	if (((snake->y[0] <= MAPTOP) || (snake->y[0] >= MAPBOTTOM)) ||
		((snake->x[0] <= MAPLEFT) || (snake->x[0] >= MAPRIGHT)))
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
