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
	getline(cin, tenS);
	cout << "\nThe loai: ";
	getline(cin, theLoai);
	cout << "\nTen tac gia: ";
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
	cout << left << setw(10) << maS << left << setw(20) << tenS << left << setw(15) << theLoai << left << setw(20) << tacGia << left << setw(17) << namXB << left << setw(8) << soLuong;
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

void Sach::docFileS(fstream& f) {
	getline(f, maS, ',');
	f.seekg(1, 1);
	getline(f, tenS, ',');
	f.seekg(1, 1);
	getline(f, theLoai, ',');
	f.seekg(1, 1);
	getline(f, tacGia, ',');
	f.seekg(1, 1);
	f >> namXB;
	f.seekg(1, 1);
	f >> soLuong;

	string temp;
	getline(f, temp);
}

void Sach::ghiFileS(fstream& f)
{
	f.open("Sach.txt", ios::app);
	f << maS << ", " << tenS << ", " << theLoai << ", " << tacGia << ", " << namXB << ", " << soLuong << endl;
	f.close();
}