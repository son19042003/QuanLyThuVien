#include "sinhvien.h"




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


//bool SV::checkCard(date x)
//{
//	if (soSanhNgay(ngayHHT, x) == true)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

void SV::themSV()
{
	cout << "\nNhap ma sinh vien: ";
	cin.ignore();
	getline(cin, mssv);
	cout << "\nNhap ho ten: ";
	//cin.ignore();
	getline(cin, hoTen);
	cout << "\nLop: ";
	//cin.ignore();
	getline(cin, lop);
	cout << "\nNhap ngay het han the: ";
	//nhapNgay(ngayHHT);
	int ngay;
	cin >> ngay;
	ngayHHT.setNgay(ngay);
	int thang;
	cin >> thang;
	ngayHHT.setThang(thang);
	int nam;
	cin >> nam;
	ngayHHT.setNam(nam);
	fstream filein;
	ghi_file(filein);
}

void SV::xuatSV()
{
	fflush(stdin);
	cout << left << setw(15) << mssv << left << setw(25) << hoTen << left << setw(10) << lop << "\n";
	//xuatNgay(ngayHHT);
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
	getline(filein, mssv);
	getline(filein, hoTen);
	getline(filein, lop);
	/*filein.seekg(1, 1);
	filein >> ngayHHT.ngay;
	filein.seekg(1, 1);
	filein >> ngayHHT.thang;
	filein.seekg(1, 1);
	filein >> ngayHHT.nam;*/
	int ngay;
	filein >> ngay;
	ngayHHT.setNgay(ngay);
	filein.seekg(1, 1);
	int thang;
	filein >> thang;
	ngayHHT.setThang(thang);
	filein.seekg(1, 1);
	int nam;
	filein >> nam;
	ngayHHT.setNam(nam);
}

void SV::ghi_file(fstream& filein)
{
	filein.open("SinhVien.txt", ios::app);
	filein << mssv << "\n" << hoTen << "\n" << lop << "\n" << ngayHHT.getNgay() << "/" << ngayHHT.getThang() << "/" << ngayHHT.getNam() << endl;
	filein.close();
}