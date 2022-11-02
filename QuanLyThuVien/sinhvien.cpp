#include "sinhvien.h"
#include <string>

void SV::setHoten(string hoTen)
{
	this->hoTen = hoTen;
}

string SV::getHoten()
{
	return hoTen;
}

void SV::setNgayHHT(date ngayHHT)
{
	this->ngayHHT = ngayHHT;
}

date SV::getNgayHHT()
{
	return ngayHHT;
}

void SV::setLop(string lop)
{
	this->lop = lop;
}

string SV::getLop()
{
	return lop;
}


bool SV::checkCard(date x)
{
	if (soSanhNgay(ngayHHT, x) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SV::themSV(SV sv)
{
	cout << "\nNhap ma sinh vien: ";
	cin >> sv.mssv;
	cout << "\nNhap ho ten: ";
	cin.ignore(0);
	getline(cin, sv.hoTen);
	cout << "\nNhap ngay het han the: ";
	nhapNgay(sv.ngayHHT);
	cout << "\nLop: ";
	cin.ignore(0);
	getline(cin, sv.lop);
}

void SV::xuatSV(SV sv)
{
	
}

void SV::xoaSV(SV sv)
{

}

void SV::suaSV(SV sv)
{

}

SV SV::timKiemSV(string x)
{
	cout << "\nNhap ten hoac mssv can tim: ";
	cin.ignore(0);
	getline(cin, x);

}