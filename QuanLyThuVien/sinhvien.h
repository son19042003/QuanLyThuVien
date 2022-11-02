#pragma once
#include "maSo.h"
#include "date.h"


class SV:private MaSo
{
private:
	string hoTen;
	date ngayHHT;
	string lop;
public:
	void setHoten(string hoTen);
	string getHoten();
	void setNgayHHT(date ngayHHT);
	date getNgayHHT();
	void setLop(string lop);
	string getLop();
	bool checkCard(date x);
	void themSV(SV sv);
	void xoaSV(SV sv);
	void xuatSV(SV sv);
	void suaSV(SV sv);
	SV timKiemSV(string x);
};

