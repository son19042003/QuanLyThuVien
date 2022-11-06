#pragma once
#include "base.h"

class Sach
{
protected:
	string maS;
	string tenS;
	string theLoai;
	string tacGia;
	int namXB;
	int soLuong;
public:
	void setMaS(string maS);
	string getMaS();
	void setTenS(string tenS);
	string getTenS();
	void setTheLoai(string theLoai);
	string getTheLoai();
	void setTacGia(string tacGia);
	string getTacGia();
	void setNamXB(int namXB);
	int getNamXB();
	void setSL(int soLuong);
	int getSL();
	void themS();
	void xoaS();
	void xuatS();
	bool timS(string x);
};