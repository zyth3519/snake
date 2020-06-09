#include <graphics.h>
#include <time.h>
#include <atlstr.h>
#include <conio.h>
#include "bean.h"
#include "util.h"
#include "draw.h"

void createMap()
{
	// 设置边框颜色
	setlinecolor(GREEN);
	rectangle(10, 10, 500, 390);
	rectangle(20, 20, 490, 380);
}

void createFood()
{
	srand((unsigned)time(NULL));
	// 随机生成坐标
	int x = rand() % 46 + 3;
	int y = rand() % 35 + 3;
	// 生成必须是10的倍数，要不然对不起
	x = x * 10;
	y = y * 10;

	getSquare(x, y, &food);

	// 判断是否生成蛇上,hitBody不判断蛇头
	while (hit(food, snake.body[0]) && hitBody(food))
	{
		int x = rand() % 46 + 3;
		int y = rand() % 35 + 3;
		x = x * 10;
		y = y * 10;
		getSquare(x, y, &food);
	}

	// 一个半径为5的圆
	drawSquare(food);
}
void createSnake()
{
	// 初始坐标
	int x = 250;
	int y = 190;

	// 生成蛇头
	getSquare(x, y, &snake.body[0]);
	drawSquare(snake.body[0], snakeColor, snakeColor);
	Sleep(100);

	for (int i = 1; i < snake.len; i++)
	{

		// 我不想写太长
		Square* body1 = &snake.body[i];
		Square* body2 = &snake.body[i - 1];

		body1->left = body2->left + 10;
		body1->right = body2->right + 10;

		// 顶和尾没有改变
		body1->top = body2->top;
		body1->bottom = body2->bottom;

		drawSquare(snake.body[i], randColor());
	}
}

bool moveSnake()
{
	// 放在后面操作会不流畅
	keyDown();

	// 蛇的末位值
	Square s = snake.body[snake.len - 1];

	for (int i = snake.len - 1; i > 0; i--)
	{
		snake.body[i] = snake.body[i - 1];
	}

	switch (snake.direction)
	{
	case UP:
		snake.body[0].top -= 10;
		snake.body[0].bottom -= 10;
		break;
	case DOWN:
		snake.body[0].top += 10;
		snake.body[0].bottom += 10;
		break;
	case LEFT:
		snake.body[0].left -= 10;
		snake.body[0].right -= 10;
		break;
	case RIGHT:
		snake.body[0].left += 10;
		snake.body[0].right += 10;
		break;
	}

	drawSquare(snake.body[0], randColor());

	eatFood();

	if (hitBody(snake.body[0]) || hitWall())
	{
		return false;
	}

	clearrectangle(s.left, s.top, s.right, s.bottom);

	Sleep(snake.speed);

	return true;
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

void eatFood()
{
	if (hit(snake.body[0], food))
	{
		createFood();
		snake.len += 1;
	}
}

// 显示分数
void grade()
{

	settextstyle(16, 0, L"楷体");
	LPCTSTR grade = L"分数: ";
	CString str1 = CString(grade) + CString(intTOLPCTSTR(snake.len - 3));
	outtextxy(510, 30, str1);

	LPCTSTR speed = L"速度: ";
	CString str2 = CString(speed) + CString(intTOLPCTSTR(snake.speed));
	outtextxy(510, 50, str2);

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
