#pragma once
#include "base.h"
#include "date.h"


class SV
{
protected:
	string mssv;
	string hoTen;
	date ngayHHT;
	string lop;
public:
	SV();
	void setMssv(string mssv);
	string getMssv();
	void setHoten(string hoTen);
	string getHoten();
	void setNgayHHT(date ngayHHT);
	date getNgayHHT();
	void setLop(string lop);
	string getLop();
	string checkCard(date x);
	bool checkID(string x);
	//void nhapMSSV();
	void themSV();
	void xuatSV();
	bool timKiemSV(string x);
	void doc_file(fstream& filein);
	void ghi_file(fstream& filein);
	date capNhap();
	~SV();
};