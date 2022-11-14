#pragma once
#include "sach.h"
#include "sinhvien.h"
#include "date.h"
#include "base.h"


class MuonTra:public SV, public Sach
{
private:
	date ngayM;
	date ngayHT;
	date ngayT;
	int sl;
public:
	MuonTra();
	void setNgayM(date ngayM);
	date getNgayM();
	void setNgayHT(date ngayHT);
	date getNgayHT();
	void setNgayT(date ngayT);
	date getNgayT();
	void setSL(int sl);
	int getSL();
	void them();
	void xoa();
	void xuat();
	void docfileMT(fstream& f);
	void ghifileMT(fstream& f);
	int tinhSL();
	~MuonTra();
	string kiemTraMT(date x);
	date suaTT(int a, int b, int c);
};