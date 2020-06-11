#include <time.h>
#include <atlstr.h>
#include <conio.h>
#include <iostream>
#include "draw.h"
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
void gameOver()
{
	LPCTSTR  end = L"游戏结束";
	cleardevice();
	settextstyle(84, 0, L"华文琥珀");
	outtextxy(132, 50, end);
	settextstyle(24, 0, L"楷体");
	settextcolor(COLORREF RGB(144, 236, 194));
	outtextxy(220, 285, L"任意按键关闭");
};

void eatFood(Snake* snake)
{
	if (isOverlap(snake->x[0], snake->y[0], food.x, food.y))
	{
		createFood();
		// 蛇的长度一
		snake->len++;
	}
}

// 显示分数
void grade()
{
	settextstyle(16, 0, L"楷体");

	int y = 30;
	for (int i = 0; i < snakes.size(); i++)
	{
		CString str;
		str.Format(L"%d", i + 1);
		CString user = CString(L"玩家") + str;
		outtextxy(510, y, user);

		CString str2;
		str2.Format(L"%d", snakes[i]->len - 3);
		CString grade = CString(L"分数: ") + str2;
		outtextxy(510, y + 20, grade);
		y += 80;
	}

	CString str;
	str.Format(L"%d", speed);
	CString speedStr = CString(L"速度") + str;
	outtextxy(510, 200, speedStr);

}


//显示封面及设置字体,找别人的
void topic()
{
	settextstyle(84, 0, L"华文琥珀");
	settextcolor(COLORREF RGB(134, 235, 246));
	outtextxy(80, 125, L"贪吃龙物语");
	settextstyle(24, 0, L"楷体");
	settextcolor(COLORREF RGB(144, 236, 194));
	outtextxy(220, 285, L"任意按键开始");
	_getch();
	cleardevice();
}
