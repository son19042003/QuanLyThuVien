#pragma once
#include "maSo.h"


class SV:private MaSo
{
private:
	string hoTen;
	string ngayHHT;
	string lop;
public:
	void setHoten(string hoTen);
	string getHoten();
	void setNgayHHT(string ngayHHT);
	string getNgayHHT();
	void setLop(string lop);
	string getLop();
	bool checkCard(string x);
	void themSV();
	void xoaSV();
	void xuatSV();
	void suaSV();
	SV timKiemSV();
};

