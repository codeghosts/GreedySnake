#include "HEAD.h"


//定义光标位置
void Init_cursor(int x, int y)
{
	COORD pos;
	HANDLE output;
	pos.X = x;
	pos.Y = y;
	output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

//画出地图
void Creat_Map()
{
	int i = 0;
	for ( i = 0; i < 55; i+=2)
	{
		Init_cursor(i, 0);
		printf("□");
		Init_cursor(i, 23);
		printf("□");
	}
	for ( i = 1; i < 23; i++)
	{
		Init_cursor(0, i);
		printf("□");
		Init_cursor(54, i);
		printf("□");
	}
}