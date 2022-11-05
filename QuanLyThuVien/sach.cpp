#include "sach.h"



void Sach::setMaS(string maS)
{
	this->maS = maS;
}

string Sach::getMaS()
{
	return maS;
}

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

void Sach::setTacGia(string tacGia)
{
	this->tacGia = tacGia;
}

string Sach::getTacGia()
{
	return tacGia;
}

void Sach::setNamXB(int namXB)
{
	this->namXB = namXB;
}

int Sach::getNamXB()
{
	return namXB;
}

void Sach::setSL(int soLuong)
{
	this->soLuong = soLuong;
}

int Sach::getSL()
{
	return soLuong;
}


void Sach::themS()
{
	cout << "\nMa sach: ";
	cin.ignore();
	getline(cin, maS);
	cout << "\nTen sach: ";
	cin.ignore();
	getline(cin, tenS);
	cout << "\nThe loai: ";
	cin.ignore();
	getline(cin, theLoai);
	cout << "\nTen tac gia: ";
	cin.ignore();
	getline(cin, tacGia);
	cout << "\nNam xuat ban: ";
	cin >> namXB;
	cout << "\nSo luong: ";
	cin >> soLuong;
}

void Sach::xoaS()
{
	
}

void Sach::xuatS()
{
	cout << "\n";
	cout << left << setw(15) << maS << left << setw(20) << tenS << left << setw(15) << theLoai << left << setw(20) << tacGia << left << setw(7) << namXB << left << setw(5) << soLuong;
}

bool Sach::timS(string x)
{
	if (x == maS)
	{
		return true;
	}
	else
	{
		return false;
	}
}