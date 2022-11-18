#include "date.h"


void nhapNgay(date& x)
{
nhap:
	do
	{
		cout << "\nNgay: ";
		cin >> x.ngay;
		cout << "\nThang: ";
		cin >> x.thang;
		cout << "\nNam: ";
		cin >> x.nam;
	} while (x.ngay <= 0 || x.thang <= 0 || x.thang > 12 || x.nam <= 0);
	switch (x.thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (x.ngay > 31)
		{
			goto nhap;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (x.ngay > 30)
		{
			goto nhap;
		}
		break;
	case 2:
		if ((x.nam % 4 == 0 && x.nam % 100 != 0) || (x.nam % 400 == 0))
		{
			if (x.ngay > 29)
			{
				goto nhap;
			}
		}
		else
		{
			if (x.ngay > 28)
			{
				goto nhap;
			}
		}
		break;
	default:
		break;
	}
}


void xuatNgay(date x)
{
	cout << x.ngay << "/" << x.thang << "/" << x.nam;
}


bool soSanhNgay(date x1, date x2)
{
	if (x1.nam == x2.nam)
	{
		if (x1.thang == x2.thang)
		{
			if (x1.ngay <= x2.ngay)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (x1.thang < x2.thang)
		{
			return true;
		}
		else
		{
			false;
		}
	}
	else if (x1.nam < x2.nam)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int quyDoi(date x)
{
	if (x.thang < 3)
	{
		x.nam--;
		x.thang += 12;
	}
	return 365 * x.nam + x.nam / 4 - x.nam / 100 + x.nam / 400 + (153 * x.thang - 457) / 5 + x.ngay - 306;
}

//15-12-2022 = 738501
//7-1-2023 = 738566