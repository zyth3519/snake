#include <conio.h>
#include <graphics.h>
#include "draw.h"
#include "bean.h"

int main(void)
{
	// 窗口大小
	initgraph(600, 400);
	topic();
	createMap();
	createSnake();
	createFood();
	while (moveSnake())
	{
		grade();
	}
	gameOver();
	_getch();
	closegraph();
	return 0;
}


