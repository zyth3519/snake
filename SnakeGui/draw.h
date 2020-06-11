#pragma once
#ifndef DRAW_H
#define DRAW_H
#include "bean.h"

void createMap();
void createFood();
void createSnake(MoveKey key, int x, int y);
void createSnake(Snake* snake, MoveKey key, int x, int y);
bool moveSnake(Snake* snake);
void gameOver();
void eatFood(Snake* snake);
void grade();
void topic();
#endif // !DRAW_H
