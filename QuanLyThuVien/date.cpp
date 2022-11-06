#include "date.h"


//void nhapNgay(date& x)
//{
//nhap:
//	do
//	{
//		cout << "\nNgay: ";
//		cin >> x.ngay;
//		cout << "\nThang: ";
//		cin >> x.thang;
//		cout << "\nNam: ";
//		cin >> x.nam;
//	} while (x.ngay <= 0 || x.thang <= 0 || x.thang > 12 || x.nam <= 0);
//	switch (x.thang)
//	{
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//		if (x.ngay > 31)
//		{
//			goto nhap;
//		}
//		break;
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		if (x.ngay > 30)
//		{
//			goto nhap;
//		}
//		break;
//	case 2:
//		if ((x.nam % 4 == 0 && x.nam % 100 != 0) || (x.nam % 400 == 0))
//		{
//			if (x.ngay > 29)
//			{
//				goto nhap;
//			}
//		}
//		else
//		{
//			if (x.ngay > 28)
//			{
//				goto nhap;
//			}
//		}
//		break;
//	default:
//		break;
//	}
//}
//
//
//void xuatNgay(date x)
//{
//	cout << x.ngay << "/" << x.thang << "/" << x.nam;
//}
//
//
//bool soSanhNgay(date x1, date x2)
//{
//	if (x2.nam > x1.nam)
//	{
//		return false;
//	}
//	else if (x2.nam < x1.nam)
//	{
//		return true;
//	}
//	else
//	{
//		if (x2.thang > x1.thang)
//		{
//			return false;
//		}
//		else if (x2.thang < x1.thang)
//		{
//			return true;
//		}
//		else
//		{
//			if (x2.ngay > x1.ngay)
//			{
//				return false;
//			}
//			else
//			{
//				return true;
//			}
//		}
//	}
//}

void date::setNgay(int ngay)
{
	this->ngay = ngay;
}

int date::getNgay()
{
	return ngay;
}

void date::setThang(int thang)
{
	this->thang = thang;
}

int date::getThang()
{
	return thang;
}

void date::setNam(int nam)
{
	this->nam = nam;
}

int date::getNam()
{
	return nam;
}