#include <time.h>
#include <atlstr.h>
#include <conio.h>
#include <iostream>
#include "core.h"
#include "graphics.h"
#include "util.h"
#include "bean.h"

void createMap()
{
	// 设置边框颜色
	setlinecolor(GREEN);
	drawBorder(MAPLEFT - 1, MAPTOP - 1, MAPRIGHT + 1, MAPBOTTOM + 1);
	drawBorder(MAPLEFT, MAPTOP, MAPRIGHT, MAPBOTTOM);

}

void createFood()
{
	srand((unsigned)time(NULL));
	// 随机生成坐标
	food.x = rand() % 47 + 2;
	food.y = rand() % 36 + 2;

	// 判断是否生成蛇上
	while (true)
	{
		for (int i = 0; i < snakes.size(); i++)
		{
			Snake* snake = snakes[i];
			for (int a = 0; a < snake->len; a++)
			{
				if (isOverlap(food.x, food.y, snake->x[i], snake->y[i]))
				{
					food.x = rand() % 47 + 2;
					food.y = rand() % 36 + 2;
					break;
				}
			}
		}
		break;
	}

	// 绘制食物
	drawBlock(food.x, food.y);
}

// 通过坐标，生成蛇
void createSnake(Snake* snake, MoveKey key, int x, int y)
{
	// 案件绑定
	snake->key = key;
	snake->direction = key.left;

	snake->x[0] = x;
	snake->y[0] = y;
	// 蛇头
	drawBlock(x, y);

	for (int i = 1; i < snake->len; i++)
	{
		// 向末尾添加数据
		snake->x[i] = snake->x[i - 1] + 1;
		snake->y[i] = snake->y[i - 1];

		drawBlock(snake->x[i], snake->y[i]);
	}
	// 注册
	snakes.push_back(snake);
}

bool moveSnake(Snake* snake)
{
	// 通过指针来操作
	// 蛇尾位置
	int x = snake->x[snake->len - 1];
	int y = snake->y[snake->len - 1];

	for (int i = snake->len - 1; i > 0; i--)
	{
		snake->x[i] = snake->x[i - 1];
		snake->y[i] = snake->y[i - 1];
	}

	// 方向
	char key = snake->direction;

	if (key == snake->key.up)
	{
		snake->y[0]--;
	} else if (key == snake->key.down)
	{
		snake->y[0]++;
	} else if (key == snake->key.left)
	{
		snake->x[0]--;
	} else if (key == snake->key.right)
	{
		snake->x[0]++;
	}

	// 绘制头
	drawBlock(snake->x[0], snake->y[0]);
	// 吃食物
	eatFood(snake);

	// 是否碰到墙或身体
	if (hitBody(snake, snake->x[0], snake->y[0]) || hitWall(snake))
	{
		return true;
	}
	// 清楚末尾
	clearBlock(x, y);

	return false;
}

void eatFood(Snake* snake)
{
	if (isOverlap(snake->x[0], snake->y[0], food.x, food.y))
	{
		createFood();
		// 蛇的长度一
		snake->len++;
	}
}

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
