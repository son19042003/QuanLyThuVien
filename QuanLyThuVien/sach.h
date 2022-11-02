#pragma once
#include "maSo.h"


class Sach:private MaSo
{
private:
	string tenS;
	string theLoai;
	int soLuong;
public:
	void setTenS(string tenS);
	string getTenS();
	void setTheLoai(string theLoai);
	string getTheLoai();
	void setSL(int soLuong);
	int getSL();
	void themS();
	void xoaS();
	void suaS();
	void xuatS();
	Sach timS();
	bool kiemTraS();
};