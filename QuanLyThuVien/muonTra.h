#pragma once
#include "maSo.h"
#include "date.h"


class MuonTra:private MaSo
{
private:
	date ngayM;
	date ngayHT;
	date ngayT;
public:
	void setNgayM(date ngayM);
	date getNgayM();
	void setNgayHT(date ngayHT);
	date getNgayHT();
	void setNgayT(date ngayT);
	date getNgayT();
	void them();
	void xoa();
	void xuat();
	void sua();
};