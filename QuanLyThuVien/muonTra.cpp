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

//MuonTra::MuonTra()
//{
//	this->ngayM.ngay = 1;
//	this->ngayM.thang = 1;
//	this->ngayM.nam = 1;
//	this->ngayHT.ngay = 1;
//	this->ngayHT.thang = 1;
//	this->ngayHT.nam = 1;
//	this->ngayT.ngay = 1;
//	this->ngayT.thang = 1;
//	this->ngayT.nam = 1;
//}
//
//MuonTra::~MuonTra()
//{
//
//}
//
//
//void MuonTra::them()
//{
//	cout << "\nMa sinh vien: ";
//	cin.ignore();
//	getline(cin, mssv);
//	cout << "\nHo ten nguoi muon: ";
//	cin.ignore();
//	getline(cin, hoTen);
//	cout << "\nLop: ";
//	cin.ignore();
//	getline(cin, lop);
//	cout << "\nMa sach muon: ";
//	cin.ignore();
//	getline(cin, maS);
//	cout << "\nTen sach muon: ";
//	cin.ignore();
//	getline(cin, tenS);
//	cout << "\nThe loai: ";
//	cin.ignore();
//	getline(cin, theLoai);
//	cout << "\nNgay muon: ";
//	cin >> ngayM.ngay >> ngayM.thang >> ngayM.nam;
//	cout << "\nNgay hen tra: ";
//	cin >> ngayHT.ngay >> ngayHT.thang >> ngayHT.nam;
//}
//
//void MuonTra::xoa()
//{
//
//}
//
//void MuonTra::xuat()
//{
//	cout << left << setw(15) << mssv << left << setw(20) << hoTen << left << setw(10) << lop << left << setw(10) << maS << left << setw(15) << tenS << left << setw(15) << theLoai;
//	//xuatNgay(ngayM);
//	cout << "\t";
//	//xuatNgay(ngayHT);
//}
//
//void MuonTra::sua(string x)
//{
//	cout << "\nNgay tra: ";
//	cin >> ngayT.ngay >> ngayT.thang >> ngayT.nam;
//}