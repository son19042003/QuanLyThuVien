
#include "draw_line.h"


void drawLine()
{
	cout << "____________________________________________________________________________________" << endl;
	cout << left << setw(2) << "|";
	setColor(0, 11);
	cout << left << setw(8) << "Ma Sach";
	setColor(0, 7);
	cout << left << setw(11) << "|";
	setColor(0, 11);
	cout << left << setw(33) << "Ten Sach";
	setColor(0, 7);
	cout << left << setw(5) << "|";
	setColor(0, 11);
	cout << left << setw(13) << "The loai";
	setColor(0, 7);
	cout << left << setw(2) <<  "|";
	setColor(0, 11);
	cout << left << setw(9) << "So Luong";
	setColor(0, 7);
	cout << "|" << endl;
	cout << "____________________________________________________________________________________" << endl;
}