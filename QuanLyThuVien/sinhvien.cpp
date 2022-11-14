#include "sinhvien.h"


SV::SV()
{
	this->mssv = ' ';
	this->hoTen = ' ';
	this->lop = ' ';
	this->ngayHHT.setNgay(0);
	this->ngayHHT.setThang(0);
	this->ngayHHT.setNam(0);
}


SV::~SV()
{

}


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


string SV::checkCard(date x)
{
	if (ngayHHT.getNam() == x.getNam())
	{
		if (ngayHHT.getThang() == x.getThang())
		{
			if (ngayHHT.getNgay() < x.getNgay())
			{
				return "Da Khoa";
			}
			else
			{
				return "Dang hoat dong";
			}
		}
		else if (ngayHHT.getThang() < x.getThang())
		{
			return "Da Khoa";
		}
		else
		{
			return "Dang hoat dong";
		}
	}
	else if (ngayHHT.getNam() < x.getNam())
	{
		return "Da khoa";
	}
	else
	{
		return "Dang hoat dong";
	}
}

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
	int ngay;
	cin >> ngay;
	ngayHHT.setNgay(ngay);
	int thang;
	cin >> thang;
	ngayHHT.setThang(thang);
	int nam;
	cin >> nam;
	ngayHHT.setNam(nam);
}

void SV::xuatSV()
{
	fflush(stdin);
	cout << left << setw(2) << "|" << left << setw(15) << mssv << left << setw(2) << "|" << left << setw(25) << hoTen << left << setw(2) << "|" << left << setw(15) << lop << left << setw(2) << "|" << right << setw(2) << ngayHHT.getNgay() << "/" << right << setw(2) << ngayHHT.getThang() << "/" << left << setw(14) << ngayHHT.getNam() << left << setw(2) << "|";
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
	getline(filein, mssv, ',');
	filein.seekg(1, 1);
	getline(filein, hoTen, ',');
	filein.seekg(1, 1);
	getline(filein, lop, ',');
	filein.seekg(1, 1);
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

	string temp;
	getline(filein, temp);
}

void SV::ghi_file(fstream& filein)
{
	filein.open("SinhVien.txt", ios::app);
	filein << mssv << ", " << hoTen << ", " << lop << ", " << ngayHHT.getNgay() << "/" << ngayHHT.getThang() << "/" << ngayHHT.getNam() << endl;
	filein.close();
}

date SV::capNhap(int a, int b, int c)
{
	ngayHHT.setNgay(a);
	ngayHHT.setThang(b);
	ngayHHT.setNam(c);
	return ngayHHT;
}