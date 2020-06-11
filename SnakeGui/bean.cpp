#include "bean.h"
#include "util.h"

vector<Snake*> snakes;
Food food;
// 蛇颜色
COLORREF snakeColor = randColor();

int speed = 100;