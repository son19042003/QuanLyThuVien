
#include "public_func.h"


void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x;
	position.Y = y;
}


void draw(int a, int b, int c, int d)
{
	gotoXY(a, b);
	for (int i = a; i <= c; i++)
	{
		cout << "_";
	}

	gotoXY(a, d);
	for (int i = a; i <= c; i++)
	{
		cout << "_";
	}

	for (int i = 1; i <= d - b; i++)
	{
		gotoXY(a - 1, b + i);
		cout << "|" << endl;
	}

	for (int i = 1; i <= d - b; i++)
	{
		gotoXY(c + 1, b + i);
		cout << "|" << endl;
	}
}


void setColor(int background_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color = background_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color);
}