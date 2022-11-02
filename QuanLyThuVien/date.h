#pragma once
#include "base.h"

typedef struct Date
{
	int ngay;
	int thang;
	int nam;
}date;


void nhapNgay(date &x);

void xuatNgay(date x);

bool soSanhNgay(date x1, date x2);