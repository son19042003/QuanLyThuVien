#pragma once
#include "sach.h"
#include "sinhvien.h"
#include "date.h"
#include "base.h"


class MuonTra:private SV, private Sach
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
	void them();
	void xoa();
	void xuat();
	void sua(string x);
	void docfileMT(fstream& f);
	void ghifileMT(fstream& f);
	int tinhSL();
	int tinhSL_ten(string x);
	~MuonTra();
};