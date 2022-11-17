#include "sinhvien.h"


SV::SV()
{
	this->mssv = ' ';
	this->hoTen = ' ';
	this->lop = ' ';
	this->ngayHHT.ngay = 0;
	this->ngayHHT.thang = 0;
	this->ngayHHT.nam = 0;
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
	if (ngayHHT.nam == x.nam)
	{
		if (ngayHHT.thang == x.thang)
		{
			if (ngayHHT.ngay < x.ngay)
			{
				return "Da Khoa";
			}
			else
			{
				return "Dang hoat dong";
			}
		}
		else if (ngayHHT.thang < x.thang)
		{
			return "Da Khoa";
		}
		else
		{
			return "Dang hoat dong";
		}
	}
	else if (ngayHHT.nam < x.nam)
	{
		return "Da khoa";
	}
	else
	{
		return "Dang hoat dong";
	}
}

void SV::nhapMSSV(string x)
{
	mssv = x;
}

void SV::themSV()
{
	cout << "\nNhap ho ten: ";
	getline(cin, hoTen);
label:
	cout << "\nLop: ";
	getline(cin, lop);
	if (lop != "CNTT K60" && lop != "CNTT K61" && lop != "CNTT K62" && lop != "CNTT K63"
		&& lop != "KTTH K60" && lop != "KTTH K61" && lop != "KTTH K62" && lop != "KTTH K63"
		&& lop != "QTKD K60" && lop != "QTKD K61" && lop != "QTKD K62" && lop != "QTKD K63"
		&& lop != "KTCDT K60" && lop != "KTCDT K61" && lop != "KTCDT K62" && lop != "KTCDT K63"
		&& lop != "KTOTO K60" && lop != "KTOTO K61" && lop != "KTOTO K62" && lop != "KTOTO K63")
	{
		cout << "\nLop nay khong ton tai!";
		goto label;
	}
	cout << "\nNhap ngay het han the: ";
	nhapNgay(ngayHHT);
}

void SV::xuatSV()
{
	fflush(stdin);
	cout << left << setw(2) << "|" << left << setw(15) << mssv << left << setw(2) << "|" << left << setw(25) << hoTen << left << setw(2) << "|" << left << setw(15) << lop << left << setw(2) << "|" << right << setw(2) << ngayHHT.ngay << "/" << right << setw(2) << ngayHHT.thang << "/" << left << setw(14) << ngayHHT.nam << left << setw(2) << "|";
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
	//int ngay;
	filein >> ngayHHT.ngay;
	//ngayHHT.setNgay(ngay);
	filein.seekg(1, 1);
	//int thang;
	filein >> ngayHHT.thang;
	//ngayHHT.setThang(thang);
	filein.seekg(1, 1);
	//int nam;
	filein >> ngayHHT.nam;
	//ngayHHT.setNam(nam);

	string temp;
	getline(filein, temp);
}

void SV::ghi_file(fstream& filein)
{
	filein.open("SinhVien.txt", ios::app);
	filein << mssv << ", " << hoTen << ", " << lop << ", " << ngayHHT.ngay << "/" << ngayHHT.thang << "/" << ngayHHT.nam << endl;
	filein.close();
}

date SV::capNhap()
{
	date x;
nhap:
	nhapNgay(x);
	if (soSanhNgay(ngayHHT, x) == true)
	{
		ngayHHT = x;
		return ngayHHT;
	}
	else
	{
		cout << "\nNgay het han moi phai lon hon ngay het han cu";
		goto nhap;
	}
}