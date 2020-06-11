#pragma once
#ifndef UTIL_H
#define UTIL_H

bool hitBody(Snake* snake, int x, int y);
COLORREF randColor();
void keyDown();
bool hitWall(Snake* snake);
LPCTSTR intTOLPCTSTR(int i);
#endif // !UTIL_H
