#include "muonTra.h"


MuonTra::MuonTra()
{
	this->ngayM.setNgay(0);
	this->ngayM.setThang(0);
	this->ngayM.setNam(0);
	this->ngayHT.setNgay(0);
	this->ngayHT.setThang(0);
	this->ngayHT.setNam(0);
	this->ngayT.setNgay(0);
	this->ngayT.setThang(0);
	this->ngayT.setNam(0);
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


void MuonTra::them()
{
	cout << "\nMa sinh vien: ";
	cin.ignore();
	getline(cin, mssv);
	cout << "\nHo ten nguoi muon: ";
	getline(cin, hoTen);
	cout << "\nLop: ";
	getline(cin, lop);
	cout << "\nMa sach muon: ";
	getline(cin, maS);
	cout << "\nTen sach muon: ";
	getline(cin, tenS);
	cout << "\nThe loai: ";
	getline(cin, theLoai);
	cout << "\nNgay muon: ";
	int nn, tm, nm;
	cin >> nn >> tm >> nm;
	ngayM.setNgay(nn); ngayM.setThang(tm); ngayM.setNam(nm);
	cout << "\nNgay hen tra: ";
	int nnht, tht, nht;
	cin >> nnht >> tht >> nht;
	ngayHT.setNgay(nnht); ngayHT.setThang(tht); ngayHT.setNam(nht);
	cout << "\nSo luong muon: ";
	cin >> sl;
}

void MuonTra::xoa()
{

}

void MuonTra::xuat()
{
	cout << left << setw(2) << "|" << left << setw(13) << mssv << left << setw(2) << "|" << left << setw(22) << hoTen << left << setw(2) << "|" << left << setw(12) << lop << left << setw(2) << "|" << left << setw(10) << maS << left << setw(2) << "|" << left << setw(15) << tenS << left << setw(2) << "|" << left << setw(15) << theLoai << left << setw(2) << "|" << right << setw(2) << ngayM.getNgay() << "/" << right << setw(2) << ngayM.getThang() << "/" << left << setw(8) << ngayM.getNam() << left << setw(2) << "|" << right << setw(2) << ngayHT.getNgay() << "/" << right << setw(2) << ngayHT.getThang() << "/" << left << setw(8) << ngayHT.getNam() << left << setw(2) << "|" << right << setw(2) << ngayT.getNgay() << "/" << right << setw(2) << ngayT.getThang() << "/" << left << setw(6) << ngayT.getNam() << left << setw(2) << "|" << left << setw(8) << sl << left << setw(2) << "|";
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
	int nnm;
	f >> nnm;
	ngayM.setNgay(nnm);
	f.seekg(1, 1);
	int tm;
	f >> tm;
	ngayM.setThang(tm);
	f.seekg(1, 1);
	int nm;
	f >> nm;
	ngayM.setNam(nm);
	f.seekg(2, 1);
	int nnht;
	f >> nnht;
	ngayHT.setNgay(nnht);
	f.seekg(1, 1);
	int tht;
	f >> tht;
	ngayHT.setThang(tht);
	f.seekg(1, 1);
	int nht;
	f >> nht;
	ngayHT.setNam(nht);
	f.seekg(2, 1);
	int nnt;
	f >> nnt;
	ngayT.setNgay(nnt);
	f.seekg(1, 1);
	int tt;
	f >> tt;
	ngayT.setThang(tt);
	f.seekg(1, 1);
	int nt;
	f >> nt;
	ngayT.setNam(nt);
	f.seekg(1, 1);
	f >> sl;

	string temp;
	getline(f, temp);
}

void MuonTra::ghifileMT(fstream& f)
{
	f.open("MuonTra.txt", ios::app);
	f << mssv << ", " << hoTen << ", " << lop << ", " << maS << ", " << tenS << ", " << theLoai << ", " << ngayM.getNgay() << "/" << ngayM.getThang() << "/" << ngayM.getNam() << ", " << ngayHT.getNgay() << "/" << ngayHT.getThang() << "/" << ngayHT.getNam() << ", " << ngayT.getNgay() << "/" << ngayT.getThang() << "/" << ngayT.getNam() << ", " << sl << endl;
	f.close();
}

int MuonTra::tinhSL()
{
	if (ngayT.getNgay() == 0)
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
	if (ngayT.getNgay() != 0)
	{
		if (ngayT.getNam() == ngayHT.getNam())
		{
			if (ngayT.getThang() == ngayHT.getThang())
			{
				if (ngayT.getNgay() <= ngayHT.getNgay())
				{
					return "Da tra";
				}
				else
				{
					return "Tra muon";
				}
			}
			else if (ngayT.getThang() < ngayHT.getThang())
			{
				return "Da tra";
			}
			else
			{
				return "Tra muon";
			}
		}
		else if (ngayT.getNam() < ngayHT.getNam())
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
		if (x.getNam() == ngayHT.getNam())
		{
			if (ngayHT.getThang() == x.getThang())
			{
				if (ngayHT.getNgay() < x.getNgay())
				{
					return "Qua han";
				}
				else
				{
					return "Con han";
				}
			}
			else if (ngayHT.getThang() < x.getThang())
			{
				return "Qua han";
			}
			else
			{
				return "Con han";
			}
		}
		else if (ngayHT.getNam() < x.getNam())
		{
			return "Qua han";
		}
		else
		{
			return "Con han";
		}
	}
}

date MuonTra::suaTT(int a, int b, int c)
{
	ngayT.setNgay(a);
	ngayT.setThang(b);
	ngayT.setNam(c);
	return ngayT;
}