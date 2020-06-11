#pragma once
#ifndef CORE_H
#define CORE_H
#include "bean.h"

void createMap();
void createFood();
void createSnake(Snake* snake, MoveKey key, int x, int y);
bool moveSnake(Snake* snake);
void eatFood(Snake* snake);
void keyDown();
bool hitWall(Snake* snake);
bool hitBody(Snake* snake, int x, int y);
#endif // !DRAW_H
