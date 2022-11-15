#include "muonTra.h"


MuonTra::MuonTra()
{
	this->ngayM.ngay = 0;
	this->ngayM.thang = 0;
	this->ngayM.nam = 0;
	this->ngayHT.ngay = 0;
	this->ngayHT.thang = 0;
	this->ngayHT.nam = 0;
	this->ngayT.ngay = 0;
	this->ngayT.thang = 0;
	this->ngayT.nam = 0;
}

MuonTra::~MuonTra()
{

}

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

void MuonTra::setSL(int sl)
{
	this->sl = sl;
}

int MuonTra::getSL()
{
	return sl;
}


//void MuonTra::them()
//{
//	cout << "\nMa sinh vien: ";
//	cin.ignore();
//	getline(cin, mssv);
//	cout << "\nHo ten nguoi muon: ";
//	getline(cin, hoTen);
//	cout << "\nLop: ";
//	getline(cin, lop);
//	cout << "\nMa sach muon: ";
//	getline(cin, maS);
//	cout << "\nTen sach muon: ";
//	getline(cin, tenS);
//	cout << "\nThe loai: ";
//	getline(cin, theLoai);
//	cout << "\nNgay muon: ";
//	nhapNgay(ngayM);
//	/*int nn, tm, nm;
//	cin >> nn >> tm >> nm;
//	ngayM.setNgay(nn); ngayM.setThang(tm); ngayM.setNam(nm);*/
//	cout << "\nNgay hen tra: ";
//	nhapNgay(ngayHT);
//	/*int nnht, tht, nht;
//	cin >> nnht >> tht >> nht;
//	ngayHT.setNgay(nnht); ngayHT.setThang(tht); ngayHT.setNam(nht);*/
//	cout << "\nSo luong muon: ";
//	cin >> sl;
//}

void MuonTra::xuat()
{
	cout << left << setw(2) << "|" << left << setw(13) << mssv << left << setw(2) << "|" << left << setw(22) << hoTen << left << setw(2) << "|" << left << setw(12) << lop << left << setw(2) << "|" << left << setw(10) << maS << left << setw(2) << "|" << left << setw(15) << tenS << left << setw(2) << "|" << left << setw(15) << theLoai << left << setw(2) << "|" << right << setw(2) << ngayM.ngay << "/" << right << setw(2) << ngayM.thang << "/" << left << setw(8) << ngayM.nam << left << setw(2) << "|" << right << setw(2) << ngayHT.ngay << "/" << right << setw(2) << ngayHT.thang << "/" << left << setw(8) << ngayHT.nam << left << setw(2) << "|" << right << setw(2) << ngayT.ngay << "/" << right << setw(2) << ngayT.thang << "/" << left << setw(6) << ngayT.nam << left << setw(2) << "|" << left << setw(8) << sl << left << setw(2) << "|";
}

void MuonTra::docfileMT(fstream& f)
{
	getline(f, mssv, ',');
	f.seekg(1, 1);
	getline(f, hoTen, ',');
	f.seekg(1, 1);
	getline(f, lop, ',');
	f.seekg(1, 1);
	getline(f, maS, ',');
	f.seekg(1, 1);
	getline(f, tenS, ',');
	f.seekg(1, 1);
	getline(f, theLoai, ',');
	f.seekg(1, 1);
	//int nnm;
	f >> ngayM.ngay;
	//ngayM.setNgay(nnm);
	f.seekg(1, 1);
	//int tm;
	f >> ngayM.thang;
	//ngayM.setThang(tm);
	f.seekg(1, 1);
	//int nm;
	f >> ngayM.nam;
	//ngayM.setNam(nm);
	f.seekg(2, 1);
	//int nnht;
	f >> ngayHT.ngay;
	//ngayHT.setNgay(nnht);
	f.seekg(1, 1);
	//int tht;
	f >> ngayHT.thang;
	//ngayHT.setThang(tht);
	f.seekg(1, 1);
	//int nht;
	f >> ngayHT.nam;
	//ngayHT.setNam(nht);
	f.seekg(2, 1);
	//int nnt;
	f >> ngayT.ngay;
	//ngayT.setNgay(nnt);
	f.seekg(1, 1);
	//int tt;
	f >> ngayT.thang;
	//ngayT.setThang(tt);
	f.seekg(1, 1);
	//int nt;
	f >> ngayT.nam;
	//ngayT.setNam(nt);
	f.seekg(1, 1);
	f >> sl;

	string temp;
	getline(f, temp);
}

void MuonTra::ghifileMT(fstream& f)
{
	f.open("MuonTra.txt", ios::app);
	f << mssv << ", " << hoTen << ", " << lop << ", " << maS << ", " << tenS << ", " << theLoai << ", " << ngayM.ngay << "/" << ngayM.thang << "/" << ngayM.nam << ", " << ngayHT.ngay << "/" << ngayHT.thang << "/" << ngayHT.nam << ", " << ngayT.ngay << "/" << ngayT.thang << "/" << ngayT.nam << ", " << sl << endl;
	f.close();
}

int MuonTra::tinhSL()
{
	if (ngayT.ngay == 0)
	{
		return sl;
	}
	else
	{
		return 0;
	}
}

string MuonTra::kiemTraMT(date x)
{
	if (ngayT.ngay != 0)
	{
		if (ngayT.nam == ngayHT.nam)
		{
			if (ngayT.thang == ngayHT.thang)
			{
				if (ngayT.ngay <= ngayHT.ngay)
				{
					return "Da tra";
				}
				else
				{
					return "Tra muon";
				}
			}
			else if (ngayT.thang < ngayHT.thang)
			{
				return "Da tra";
			}
			else
			{
				return "Tra muon";
			}
		}
		else if (ngayT.nam < ngayHT.nam)
		{
			return "Da tra";
		}
		else
		{
			return "Tra muon";
		}
	}
	else
	{
		if (x.nam == ngayHT.nam)
		{
			if (ngayHT.thang == x.thang)
			{
				if (ngayHT.ngay < x.ngay)
				{
					return "Qua han";
				}
				else
				{
					return "Con han";
				}
			}
			else if (ngayHT.thang < x.thang)
			{
				return "Qua han";
			}
			else
			{
				return "Con han";
			}
		}
		else if (ngayHT.nam < x.nam)
		{
			return "Qua han";
		}
		else
		{
			return "Con han";
		}
	}
}

date MuonTra::suaTT()
{
	nhapNgay(ngayT);
	return ngayT;
}