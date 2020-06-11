#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <graphics.h>

void init(int width, int height);
void close();
void drawBlock(int x, int y);
void drawBorder(int left, int top, int right, int bottom);
bool isOverlap(int x, int y, int x2, int y2);
void setBlockSize(int size);
void clearBlock(int x, int y);
#endif // !GRAPHICS_H

