#include "sach.h"


void Sach::setTenS(string tenS)
{
	this->tenS = tenS;
}

string Sach::getTenS()
{
	return tenS;
}


void Sach::setTheLoai(string theLoai)
{
	this->theLoai = theLoai;
}

string Sach::getTheLoai()
{
	return theLoai;
}


void Sach::setSL(int soLuong)
{
	this->soLuong = soLuong;
}

int Sach::getSL()
{
	return soLuong;
}


void Sach::themS(Sach s)
{
	cout << "\nMa sach: ";
	cin.ignore(0);
	getline(cin, s.maS);
	cout << "\nTen sach: ";
	cin.ignore(0);
	getline(cin, s.tenS);
	cout << "\nThe loai: ";
	cin.ignore(0);
	getline(cin, s.theLoai);
	cout << "\nSo luong: ";
	cin >> s.soLuong;
}

void Sach::xoaS(Sach s)
{

}

void Sach::suaS(Sach s)
{

}

void Sach::xuatS(Sach s)
{

}

Sach Sach::timS(string x)
{
	cout << "\nNhap vao ma sach, ten sach hoac the loai sach: ";
	cin.ignore(0);
	getline(cin, x);
}

bool Sach::kiemTraSL(int x)
{
	cout << "\nNhap vao so luong sach da dem duoc: ";
	cin >> x;
	if (x == soLuong)
	{
		return true;
	}
	else
	{
		return false;
	}
}