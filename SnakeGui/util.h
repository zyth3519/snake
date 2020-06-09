#pragma once
#ifndef UTIL_H
#define UTIL_H

COLORREF randColor();
bool hitBody(Square square);
void getSquare(int x, int y, Square* square);
bool hit(Square s1, Square s2);
void keyDown();
bool hitWall();
LPCTSTR intTOLPCTSTR(int i);
void drawSquare(Square square, COLORREF fill = GREEN, COLORREF border = GREEN);
#endif // !UTIL_H
