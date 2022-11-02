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

void SV::setNgayHHT(string ngayHHT)
{
	this->ngayHHT = ngayHHT;
}

string SV::getNgayHHT()
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


bool SV::checkCard(string x)
{
	return true;
}

void SV::themSV()
{
	cout << "\nNhap ho ten: ";
	cin.ignore(1);
	getline(cin, hoTen);
}

void SV::xuatSV()
{
	cout << "\nHo va ten: " << hoTen << "\n";
}