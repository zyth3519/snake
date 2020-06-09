#include <graphics.h>
#include <time.h>
#include <atlstr.h>
#include <conio.h>
#include "bean.h"
#include "util.h"
#include "draw.h"

void createMap()
{
	// ���ñ߿���ɫ
	setlinecolor(GREEN);
	rectangle(10, 10, 500, 390);
	rectangle(20, 20, 490, 380);
}

void createFood()
{
	srand((unsigned)time(NULL));
	// �����������
	int x = rand() % 46 + 3;
	int y = rand() % 35 + 3;
	// ���ɱ�����10�ı�����Ҫ��Ȼ�Բ���
	x = x * 10;
	y = y * 10;

	getSquare(x, y, &food);

	// �ж��Ƿ���������,hitBody���ж���ͷ
	while (hit(food, snake.body[0]) && hitBody(food))
	{
		int x = rand() % 46 + 3;
		int y = rand() % 35 + 3;
		x = x * 10;
		y = y * 10;
		getSquare(x, y, &food);
	}

	// һ���뾶Ϊ5��Բ
	drawSquare(food);
}
void createSnake()
{
	// ��ʼ����
	int x = 250;
	int y = 190;

	// ������ͷ
	getSquare(x, y, &snake.body[0]);
	drawSquare(snake.body[0], snakeColor, snakeColor);
	Sleep(100);

	for (int i = 1; i < snake.len; i++)
	{

		// �Ҳ���д̫��
		Square* body1 = &snake.body[i];
		Square* body2 = &snake.body[i - 1];

		body1->left = body2->left + 10;
		body1->right = body2->right + 10;

		// ����βû�иı�
		body1->top = body2->top;
		body1->bottom = body2->bottom;

		drawSquare(snake.body[i], randColor());
	}
}

bool moveSnake()
{
	// ���ں�������᲻����
	keyDown();

	// �ߵ�ĩλֵ
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
	LPCTSTR  end = L"��Ϸ����";
	cleardevice();
	settextstyle(84, 0, L"��������");
	outtextxy(132, 50, end);
	settextstyle(24, 0, L"����");
	settextcolor(COLORREF RGB(144, 236, 194));
	outtextxy(220, 285, L"���ⰴ���ر�");
};

void eatFood()
{
	if (hit(snake.body[0], food))
	{
		createFood();
		snake.len += 1;
	}
}

// ��ʾ����
void grade()
{

	settextstyle(16, 0, L"����");
	LPCTSTR grade = L"����: ";
	CString str1 = CString(grade) + CString(intTOLPCTSTR(snake.len - 3));
	outtextxy(510, 30, str1);

	LPCTSTR speed = L"�ٶ�: ";
	CString str2 = CString(speed) + CString(intTOLPCTSTR(snake.speed));
	outtextxy(510, 50, str2);

}


//��ʾ���漰��������,�ұ��˵�
void topic()
{
	settextstyle(84, 0, L"��������");
	settextcolor(COLORREF RGB(134, 235, 246));
	outtextxy(80, 125, L"̰��������");
	settextstyle(24, 0, L"����");
	settextcolor(COLORREF RGB(144, 236, 194));
	outtextxy(220, 285, L"���ⰴ����ʼ");
	_getch();
	cleardevice();
}
