#include <conio.h>
#include "graphics.h"
#include "draw.h"
#include "bean.h"
#include "util.h"

int main(void)
{
	init(60, 40);
	topic();
	cleardevice();
	createMap();

	MoveKey key;
	MoveKey key2;

	key.up = 'w';
	key.left = 'a';
	key.down = 's';
	key.right = 'd';
	Snake snake;

	key2.up = 'k';
	key2.left = 'h';
	key2.down = 'j';
	key2.right = 'l';
	Snake snake2;

	createSnake(&snake, key, 19, 10);
	createSnake(&snake2, key2, 19, 30);

	createFood();

	int flag = 0;
	while (true)
	{
		keyDown();
		for (int i = 0; i < snakes.size(); i++)
		{
			if (moveSnake(snakes[i]))
			{
				flag = 1;
				break;
			}
		}
		grade();
		if (flag == 1)
		{
			break;
		}
		Sleep(speed);
	}
	gameOver();
	_getch();
	close();
	return 0;
}
