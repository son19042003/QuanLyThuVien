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

void SV::themSV()
{
	cout << "\nNhap ma sinh vien: ";
	cin >> mssv;
	cout << "\nNhap ho ten: ";
	cin.ignore(0);
	getline(cin, hoTen);
	cout << "\nNhap ngay het han the: ";
	nhapNgay(ngayHHT);
	cout << "\nLop: ";
	cin.ignore(0);
	getline(cin, lop);
}

void SV::xuatSV()
{
	
}

void SV::xoaSV()
{

}

void SV::suaSV()
{

}

SV SV::timKiemSV()
{

}