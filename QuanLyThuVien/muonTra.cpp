#include "muonTra.h"


void MuonTra::setNgayM(date ngayM)
{
	this->ngayM = ngayM;
}

date MuonTra::getNgayM()
{
	return ngayM;
}

void MuonTra::setNgayHT(date ngayHT)
{
	this->ngayHT = ngayHT;
}

date MuonTra::getNgayHT()
{
	return ngayHT;
}

void MuonTra::setNgayT(date ngayT)
{
	this->ngayT = ngayT;
}

date MuonTra::getNgayT()
{
	return ngayT;
}

MuonTra::MuonTra()
{
	this->ngayM.ngay = 1;
	this->ngayM.thang = 1;
	this->ngayM.nam = 1;
	this->ngayHT.ngay = 1;
	this->ngayHT.thang = 1;
	this->ngayHT.nam = 1;
	this->ngayT.ngay = 1;
	this->ngayT.thang = 1;
	this->ngayT.nam = 1;
}

MuonTra::~MuonTra()
{

}


void MuonTra::them(MuonTra mt)
{
	cout << "\nNgay muon: ";
	nhapNgay(mt.ngayM);
	cout << "\nNgay hen tra: ";
	nhapNgay(mt.ngayHT);
}

void MuonTra::xoa(MuonTra mt)
{

}

void MuonTra::xuat(MuonTra mt)
{
	cout << left << setw(15) << mt.maS;
	cout << left << setw(15) << mt.mssv;
	cout << left << setw(15);
	xuatNgay(mt.ngayM);
	cout << left << setw(15);
	xuatNgay(mt.ngayHT);
	cout << left << setw(15);
	xuatNgay(mt.ngayT);
}

void MuonTra::sua(MuonTra mt)
{
	cout << "\nNgay hen tra: ";
	nhapNgay(mt.ngayHT);
	cout << "\nNgay tra: ";
	nhapNgay(mt.ngayT);
}