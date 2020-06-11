#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <atlstr.h>
#include "graphics.h"
#include "bean.h"
#include "util.h"

// 随机生成颜色
COLORREF randColor()
{
	srand((unsigned)time(0));
	int r = rand() % 256;
	int g = rand() % 256;
	int b = rand() % 256;

	return RGB(r, g, b);
}

LPCTSTR intTOLPCTSTR(int i)
{
	CString t;
	t.Format(_T("%d"), i);
	return t;
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
