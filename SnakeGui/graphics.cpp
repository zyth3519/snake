#include "graphics.h"
#include <graphics.h>

int blockSize = 10;

struct Block
{
	int left;
	int right;
	int top;
	int bottom;
};

Block getBlock(int x, int y);

/*
这个函数用于初始化绘图窗口
大小为参数的blockSize倍
*/
void init(int width, int height)
{
	// EW_SHOWCONSOLE Debug
	initgraph(width * blockSize, height * blockSize);
}

/*
这个函数用于画矩形边框

left 边框左部 x 坐标。
top 边框顶部 y 坐标。
right 边框右部 x 坐标。
bottom 边框底部 y 坐标。
*/
void drawBorder(int left, int top, int right, int bottom)
{
	rectangle(left * blockSize, top * blockSize, right * blockSize, bottom * blockSize);
}

void close()
{
	closegraph();
}


// 绘制块
void drawBlock(int x, int y)
{
	Block b = getBlock(x, y);
	fillrectangle(b.left, b.top, b.right, b.bottom);
}

// 判断两个块是否相交
bool isOverlap(int x, int y, int x2, int y2)
{

	if (x == x2 && y == y2)
	{
		return true;
	}
	return false;
}

// 设置块的大小，默认为10
void setBlockSize(int size)
{
	blockSize = size;
}

Block getBlock(int x, int y)
{
	Block block;
	block.left = x * 10;
	block.top = y * 10;
	block.right = x * 10 + blockSize;
	block.bottom = y * 10 + blockSize;

	return block;
}

// 清楚块
void clearBlock(int x, int y)
{
	Block b = getBlock(x, y);
	clearrectangle(b.left, b.top, b.right, b.bottom);
}
