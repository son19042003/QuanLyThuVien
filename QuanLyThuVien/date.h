#pragma once
#include "base.h"

//struct Date
//{
//	int ngay;
//	int thang;
//	int nam;
//};
//
//typedef Date date;
//
//void nhapNgay(date& x);
//
//void xuatNgay(date x);
//
//bool soSanhNgay(date x1, date x2);

class date
{
private:
	int ngay;
	int thang;
	int nam;
public:
	void setNgay(int ngay);
	int getNgay();
	void setThang(int thang);
	int getThang();
	void setNam(int nam);
	int getNam();
};