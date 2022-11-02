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
	void themS(Sach s);
	void xoaS(Sach s);
	void suaS(Sach s);
	void xuatS(Sach s);
	Sach timS(string x);
	bool kiemTraSL(int x);
};