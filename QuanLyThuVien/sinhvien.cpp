#include "sinhvien.h"
#include <string>



void SV::setMssv(string x)
{
	this->mssv = mssv;
}

string SV::getMssv()
{
	return mssv;
}

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
	cin.ignore(1);
	getline(cin, mssv);
	cout << "\nNhap ho ten: ";
	cin.ignore(0);
	getline(cin, hoTen);
	cout << "\nLop: ";
	cin.ignore(0);
	getline(cin, lop);
	cout << "\nNhap ngay het han the: ";
	nhapNgay(ngayHHT);
	fstream filein;
	ghi_file(filein);
}

void SV::xuatSV()
{
	cout << "\n";
	cout << left << setw(15) << mssv << left << setw(25) << hoTen << left << setw(10) << lop;
	xuatNgay(ngayHHT);
}

void SV::xoaSV()
{
	
}

bool SV::timKiemSV(string x)
{
	if (x == mssv)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SV::doc_file(fstream& filein)
{
	filein.open("SinhVien.txt", ios::in);
	while (!filein.eof())
	{
		getline(filein, mssv, ',');
		filein.seekg(1, 1);
		getline(filein, hoTen, ',');
		filein.seekg(1, 1);
		getline(filein, lop, ',');
		filein.seekg(1, 1);
		filein >> ngayHHT.ngay;
		filein.seekg(1, 1);
		filein >> ngayHHT.thang;
		filein.seekg(1, 1);
		filein >> ngayHHT.nam;
	}
	filein.close();
}

void SV::ghi_file(fstream& filein)
{
	filein.open("SinhVien.txt", ios::app);
	filein << mssv << ", " << hoTen << ", " << lop << ", " << ngayHHT.ngay << "/" << ngayHHT.thang << "/" << ngayHHT.nam << endl;
	filein.close();
}