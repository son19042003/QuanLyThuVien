#include "sinhvien.h"
#include "sach.h"
#include "muonTra.h"
#include <conio.h>
#include <stdio.h>

/*
Nhom 23 - CQ.62.CNTT:
	Pham Tu Thanh (Nhom truong) - 6251071091
	Pham Thanh Son - 6251071083
	Le Cong Tuan - 6251071112
	Pham Nhat Tan - 6251071086
*/

//Sinh Vien

void themSV(SV sv[], int &n, SV svn[], int &a)
{
	string x;
	do
	{
		cout << "\nNhap so luong sinh vien can them: ";
		cin >> a;
	} while (n <= 0);
	cin.ignore();
	for (int i = 0; i < a; i++)
	{
	nhap:
		cout << "\nNhap ma sinh vien: ";
		getline(cin, x);
		if (x.size() != 8)
		{
			cout << "\nMa sinh vien phai la 8 ky tu!";
			goto nhap;
		}
		for (int j = 0; j < n; j++)
		{
			if (x == sv[j].getMssv())
			{
				cout << "\nMa sinh vien nay da ton tai!";
				goto nhap;
			}
		}
		svn[i].nhapMSSV(x);
		svn[i].themSV();
	}
}


void luuSVdaThem(SV sv[], fstream &f, int n)
{
	for (int i = 0; i < n; i++)
	{
		sv[i].ghi_file(f);
	}
}


void doc_file_SV(SV sv[], int &n)
{
	fstream filein;
	filein.open("SinhVien.txt", ios::in);
	int dem=0;
	while (filein.eof() == false)
	{
		string line;
		getline(filein, line);
		dem++;
	}
	filein.close();
	n = dem - 1;
	filein.open("SinhVien.txt", ios::in);
	for (int i = 0; i < n; i++)
	{
		sv[i].doc_file(filein);
	}
	filein.close();
}


void xuatDSSV(SV sv[], int n)
{
	cout << "\n\n";
	cout << left << setw(2) << "|" << left << setw(15) << "Ma sinh vien" << left << setw(2) << "|" << left << setw(25) << "Ho va ten" << left << setw(2) << "|" << left << setw(15) << "Lop" << left << setw(2) << "|" << left << setw(20) << "Ngay het han the" << left << setw(2) << "|" << endl;
	for (int i = 0; i < n; i++)
	{
		sv[i].xuatSV();
		cout << "\n";
	}
}


void checkCard_ds(SV sv[], int n)
{
	date x;
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	x.nam = 1900 + ltm.tm_year;
	x.thang = 1 + ltm.tm_mon;
	x.ngay = ltm.tm_mday;
	cout << "\nNgay kiem tra: " << x.ngay << "/" << x.thang << "/" << x.nam;
	cout << "\n\n";
	cout << left << setw(2) << "|" << left << setw(15) << "Ma sinh vien" << left << setw(2) << "|" << left << setw(25) << "Ho va ten" << left << setw(2) << "|" << left << setw(15) << "Lop" << left << setw(2) << "|" << left << setw(20) << "Ngay het han the" << left << setw(2) << "|" << left << setw(20) << "Tinh trang the" << setw(1) << "|" << endl;
	for (int i = 0; i < n-1; i++)
	{
		sv[i].xuatSV();
		cout << left << setw(20) << sv[i].checkCard(x) << setw(1) << "|";
		cout << "\n";
	}
}

void timKiem_ds(SV sv[], int n)
{
	string x;
	cout << "\nNhap ma sinh vien can tim: ";
	cin >> x;
	cout << left << setw(2) << "|" << left << setw(15) << "Ma sinh vien" << left << setw(2) << "|" << left << setw(25) << "Ho va ten" << left << setw(2) << "|" << left << setw(15) << "Lop" << left << setw(2) << "|" << left << setw(20) << "Ngay het han the" << left << setw(2) << "|" << endl;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].timKiemSV(x) == true)
		{
			sv[i].xuatSV();
		}
	}
}

void updateSV(SV sv[], int n)
{
	fstream tmpf, f;
	tmpf.open("SinhVien.txt", ios::in);
	f.open("SinhVien_new.txt", ios::app);
	for (int i = 0; i < n; i++)
	{
		f << sv[i].getMssv() << ", " << sv[i].getHoten() << ", " << sv[i].getLop() << ", " << sv[i].getNgayHHT().ngay << "/" << sv[i].getNgayHHT().thang << "/" << sv[i].getNgayHHT().nam << endl;
	}
	tmpf.close();
	f.close();

	remove("SinhVien.txt");
	rename("SinhVien_new.txt", "SinhVien.txt");
}

void xoaSV_ID(SV sv[], int &n)
{
	fstream f;
	string found;
	cout << "\nNhap vao ma sinh vien cua sinh vien can xoa: ";
	cin.ignore();
	getline(cin, found);
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].getMssv() == found)
		{
			tmp = 1;
			for (int j = i; j < n; j++)
			{
				sv[j] = sv[j + 1];
			}
			break;
		}
	}
	if (tmp == 0)
	{
		cout << "\nSinh vien co mssv nay khong ton tai";
	}
	else
	{
		cout << "\nDa xoa sinh vien nay!";
		n--;
	}
}

void capNhap_SV(SV sv[], int n)
{
	int a = 0, b = 0, c = 0, tmp = 0;
	string x;
	cout << "\nNhap mssv cua sinh vien can gia han the: ";
	cin.ignore();
	getline(cin, x);
	for (int i = 0; i < n; i++)
	{
		if (sv[i].getMssv() == x)
		{
			cout << "\nNhap ngay het han moi: ";
			sv[i].capNhap();
			tmp++;
		}
	}
	if (tmp != 0)
	{
		cout << "\nCap nhap thanh cong cho sinh vien nay!";
	}
	else
	{
		cout << "\nSinh vien nay khong ton tai";
	}
}

void sapXep_SV(SV sv[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		SV min = sv[i];
		int pmin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (min.getMssv() > sv[j].getMssv())
			{
				min = sv[j];
				pmin = j;
			}
		}
		if (i != pmin)
		{
			SV tmp;
			tmp = sv[i];
			sv[i] = sv[pmin];
			sv[pmin] = tmp;
		}
	}
}

//Sach

void update_S(Sach s[], int p)
{
	fstream f, tmpf;
	tmpf.open("Sach.txt", ios::in);
	f.open("Sach_new.txt", ios::app);
	for (int i = 0; i < p; i++)
	{
		f << s[i].getMaS() << ", " << s[i].getTenS() << ", " << s[i].getTheLoai() << ", " << s[i].getTacGia() << ", " << s[i].getNamXB() << ", " << s[i].getSL() << endl;
	}
	tmpf.close();
	f.close();

	remove("Sach.txt");
	rename("Sach_new.txt", "Sach.txt");
}

void them_S(Sach s[], int& p, Sach sn[], int &q)
{
	string x;
	int tmp;
	do
	{
		cout << "So luong sach can them (so luong >= 1): ";
		cin >> q;
	} while (q <= 0);
	for (int i = 0; i < q; i++)
	{
	nhapS:
		int c = 0;
		cout << "\nNhap ma sach: ";
		cin.ignore();
		getline(cin, x);
		if (x.size() != 3)
		{
			cout << "\nMa sach phai la 3 ky tu!";
			goto nhapS;
		}
		for (int j = 0; j < p; j++)
		{
			if (x == s[j].getMaS())
			{
				cout << "\nSach nay da co trong thu vien, nhap so luong sach tang len: ";
				cin >> tmp;
				s[j].setSL(s[j].getSL() + tmp);
				if (i != (q - 1))
				{
					q--;
					c++;
					update_S(s, p);
					goto nhapS;
				}
				else
				{
					q--;
					update_S(s, p);
					goto end;
				}
			}
		}
		sn[i].nhapMS(x);
		sn[i].themS();
		if (c != 0)
		{
			q--;
		}
	}
end:
	return;
}

void luu_S(Sach s[], int p, fstream& f)
{
	for (int i = 0; i < p; i++)
	{
		s[i].ghiFileS(f);
	}
}

void doc_file_s(Sach s[], int& p)
{
	fstream f;
	f.open("Sach.txt", ios::in);
	int dem = 0;
	while (f.eof() == false)
	{
		string line;
		getline(f, line);
		dem++;
	}
	f.close();
	p = dem - 1;
	f.open("Sach.txt", ios::in);
	for (int i = 0; i < p; i++)
	{
		s[i].docFileS(f);
	}
	f.close();
}

void xuatDS_S(Sach s[], int p)
{
	int tongSL = 0;
	cout << "\n\n";
	cout << left << setw(2) << "|" << left << setw(10) << "Ma sach" << left << setw(2) << "|" << left << setw(20) << "Ten sach" << left << setw(2) << "|" << left << setw(15) << "The loai" << left << setw(2) << "|" << left << setw(20) << "Ten tac gia" << left << setw(2) << "|" << left << setw(17) << "Nam xuat ban" << left << setw(2) << "|" << left << setw(10) << "So luong" << left << setw(2) << "|" << endl;
	for (int i = 0; i < p; i++)
	{
		s[i].xuatS();
		tongSL = tongSL + s[i].getSL();
		cout << "\n";
	}
	cout << "\n";
	cout << right << setw(94) << "Tong: " << tongSL;
}

void tongDSS(Sach s[], int p)
{
	int t = 0;
	for (int i = 0; i < p; i++)
	{
		t = t + s[i].getSL();
	}
	cout << "\nTong sach hien co trong thu vien: " << t;
}

void traCuu_sach(Sach s[], int p, MuonTra mt[], int m)
{
	string x;
	cout << "\nNhap ma sach can tim: ";
	cin.ignore();
	getline(cin, x);
	for (int i = 0; i < p; i++)
	{
		if (s[i].timS(x) == true)
		{
			for (int j = 0; j < m; j++)
			{
				if (s[i].getMaS() == mt[j].getMaS())
				{
					s[i].setSL(s[i].getSL() - mt[j].getSL());
				}
			}
			cout << left << setw(2) << "|" << left << setw(10) << "Ma sach" << left << setw(2) << "|" << left << setw(20) << "Ten sach" << left << setw(2) << "|" << left << setw(15) << "The loai" << left << setw(2) << "|" << left << setw(20) << "Ten tac gia" << left << setw(2) << "|" << left << setw(17) << "Nam xuat ban" << left << setw(2) << "|" << left << setw(8) << "SL con lai" << left << setw(2) << "|" << endl;
			s[i].xuatS();
		}
	}
}

void capNhap_S(Sach s[], int p)
{
	int tmp = 0;
	string x;
	cout << "\nNhap ma sach can tim: ";
	cin.ignore();
	getline(cin, x);
	for (int i = 0; i < p; i++)
	{
		if (x == s[i].getMaS())
		{
			int k;
			cout << "\nNhap so luong moi: ";
			cin >> k;
			s[i].setSL(k);
			tmp++;
		}
	}
	if (tmp != 0)
	{
		cout << "\nDa cap nhap so luong moi!";
		update_S(s, p);
	}
	else
	{
		cout << "\nMa sach nay khong ton tai!";
	}
}

void sapxep_S(Sach s[], int p)
{
	for (int i = 0; i < p - 1; i++)
	{
		Sach min = s[i];
		int pmin = i;
		for (int j = i + 1; j < p; j++)
		{
			if (min.getMaS() > s[j].getMaS())
			{
				min = s[j];
				pmin = j;
			}
		}
		if (i != pmin)
		{
			Sach tmp;
			tmp = s[i];
			s[i] = s[pmin];
			s[pmin] = tmp;
		}
	}
	fstream f, tmpf;
	tmpf.open("Sach.txt", ios::in);
	f.open("Sach_new.txt", ios::app);
	for (int i = 0; i < p; i++)
	{
		f << s[i].getMaS() << ", " << s[i].getTenS() << ", " << s[i].getTheLoai() << ", " << s[i].getTacGia() << ", " << s[i].getNamXB() << ", " << s[i].getSL() << endl;
	}
	tmpf.close();
	f.close();

	remove("Sach.txt");
	rename("Sach_new.txt", "Sach.txt");
}

//Muon tra
void themNM(MuonTra mt[], int& m, SV sv[], int n, Sach s[], int p)
{
	string tmp1, tmp2;
	date tmpM, tmpHT;
	int t;
	do
	{
		cout << "\nNhap so luong nguoi muon muon them: ";
		cin >> m;
	} while (m <= 0);
	for (int i = 0; i < m; i++)
	{
		cout << "\nNhap ma sinh vien: ";
		cin.ignore();
		getline(cin, tmp1);
		mt[i].setMssv(tmp1);
		for (int j = 0; j < n; j++)
		{
			if (tmp1 == sv[j].getMssv())
			{
				mt[i].setHoten(sv[j].getHoten());
				mt[i].setLop(sv[j].getLop());
			}
		}
		cout << "\nNhap ma sach muon: ";
		getline(cin, tmp2);
		mt[i].setMaS(tmp2);
		for (int j = 0; j < p; j++)
		{
			if (tmp2 == s[j].getMaS())
			{
				mt[i].setTenS(s[j].getTenS());
				mt[i].setTheLoai(s[j].getTheLoai());
				do
				{
					cout << "\nNhap so luong sach: ";
					cin >> t;
					mt[i].setSL(t);
				} while (t <= 0 && t > s[j].getSL());
			}
		}
		cout << "\nNhap ngay muon: ";
		nhapNgay(tmpM);
		mt[i].setNgayM(tmpM);
		cout << "\nNhap ngay hen tra: ";
		nhapNgay(tmpHT);
		mt[i].setNgayHT(tmpHT);
	}
}

void luuNM(MuonTra mt[], int m, fstream &f)
{
	for (int i = 0; i < m; i++)
	{
		mt[i].ghifileMT(f);
	}
}

void doc_file_MT(MuonTra mt[], int& m)
{
	fstream f;
	f.open("MuonTra.txt", ios::in);
	int dem = 0;
	while (f.eof() == false)
	{
		string line;
		getline(f, line);
		dem++;
	}
	f.close();
	m = dem - 1;
	f.open("MuonTra.txt", ios::in);
	for (int i = 0; i < m; i++)
	{
		mt[i].docfileMT(f);
	}
	f.close();
}

void xuatDSMT(MuonTra mt[], int m)
{
	cout << "\n\n";
	cout << left << setw(2) << "|" << left << setw(13) << "Ma sinh vien" << left << setw(2) << "|" << left << setw(22) << "Ho va ten" << left << setw(2) << "|" << left << setw(12) << "Lop" << left << setw(2) << "|" << left << setw(10) << "Ma sach" << left << setw(2) << "|" << left << setw(15) << "Ten sach" << left << setw(2) << "|" << left << setw(15) << "The loai" << left << setw(2) << "|" << left << setw(14) << "Ngay muon" << left << setw(2) << "|" << left << setw(14) << "Ngay hen tra" << left << setw(2) << "|" << left << setw(12) << "Ngay tra" << left << setw(2) << "|" << left << setw(8) << "So Luong" << left << setw(2) << "|" << endl;
	for (int i = 0; i < m; i++)
	{
		mt[i].xuat();
		cout << "\n";
	}
}

void tongSachM(MuonTra mt[], int m)
{
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		s = s + mt[i].tinhSL();
	}
	cout << "\nTong sach duoc muon: " << s;
}

void tongSachM_ten(MuonTra mt[], int m)
{
	int s = 0;
	string x;
	cout << "\nTen sach hoac the loai can tra cuu: ";
	cin.ignore();
	getline(cin, x);
	for (int i = 0; i < m; i++)
	{
		if ((x == mt[i].getTenS() && mt[i].getNgayT().ngay == 0) || (x == mt[i].getTheLoai() && mt[i].getNgayT().ngay == 0))
		{
			s = s + mt[i].getSL();
		}
	}
	cout << "\nTong so luong sach dang tim da muon: " << s;
}

void kiemTraHanMT(MuonTra mt[], int m)
{
	date x;
	cout << "\nNhap ngay kiem tra han tra sach: ";
	nhapNgay(x);
	cout << "\n\n";
	cout << left << setw(2) << "|" << left << setw(13) << "Ma sinh vien" << left << setw(2) << "|" << left << setw(22) << "Ho va ten" << left << setw(2) << "|" << left << setw(12) << "Lop" << left << setw(2) << "|" << left << setw(10) << "Ma sach" << left << setw(2) << "|" << left << setw(15) << "Ten sach" << left << setw(2) << "|" << left << setw(15) << "The loai" << left << setw(2) << "|" << left << setw(14) << "Ngay muon" << left << setw(2) << "|" << left << setw(14) << "Ngay hen tra" << left << setw(2) << "|" << left << setw(12) << "Ngay tra" << left << setw(2) << "|" << left << setw(8) << "So Luong" << left << setw(2) << "|" << left << setw(12) << "Trang thai" << setw(1) << "|" << endl;
	for (int i = 0; i < m; i++)
	{
		mt[i].xuat();
		cout << left << setw(12) << mt[i].kiemTraMT(x) << setw(1) << "|";
		cout << "\n";
	}
}

void tongSachMuon_1SV(MuonTra mt[], int m)
{
	int s = 0;
	int tmp1 = 0, tmp2;
	string x;
	cout << "\nNhap ma so sinh vien cua sinh vien can tra cuu: ";
	cin.ignore();
	getline(cin, x);
	for (int i = 0; i < m; i++)
	{
		if (x == mt[i].getMssv() && mt[i].getNgayT().ngay == 0)
		{
			s = s + mt[i].getSL();
			tmp1++;
		}
	}
	if (tmp1 == 0)
	{
		cout << "\nKhong co sinh vien nay!";
	}
	else
	{
		cout << "\nTong so luong sach sinh vien nay da muon la: " << s;
	}
	if (s != 0)
	{
		cout << "\nChi tiet? (Bam 1) ";
		cin >> tmp2;
		if (tmp2 != 1)
		{
			return;
		}
		else
		{
			cout << left << setw(2) << "|" << left << setw(13) << "Ma sinh vien" << left << setw(2) << "|" << left << setw(22) << "Ho va ten" << left << setw(2) << "|" << left << setw(12) << "Lop" << left << setw(2) << "|" << left << setw(10) << "Ma sach" << left << setw(2) << "|" << left << setw(15) << "Ten sach" << left << setw(2) << "|" << left << setw(15) << "The loai" << left << setw(2) << "|" << left << setw(14) << "Ngay muon" << left << setw(2) << "|" << left << setw(14) << "Ngay hen tra" << left << setw(2) << "|" << left << setw(12) << "Ngay tra" << left << setw(2) << "|" << left << setw(8) << "So Luong" << left << setw(2) << "|" << endl;
			for (int i = 0; i < m; i++)
			{
				if (x == mt[i].getMssv() && mt[i].getNgayT().ngay == 0)
				{
					mt[i].xuat();
					cout << "\n";
				}
			}
		}
	}
}

void capNhapMT(MuonTra mt[], int m)
{
	int a = 0, b = 0, c = 0, tmp = 0;
	string x, y;
	cout << "\nNhap ma sinh vien can sua: ";
	cin.ignore();
	getline(cin, x);
	cout << "\nNhap ma sach sinh vien do da muon: ";
	getline(cin, y);
	for (int i = 0; i < m; i++)
	{
		if (mt[i].getMssv() == x && mt[i].getMaS() == y && mt[i].getNgayT().ngay == 0)
		{
			cout << "\nNhap ngay tra: ";
			mt[i].suaTT();
			tmp++;
		}
	}
	if (tmp != 0)
	{
		cout << "\nSinh vien nay vua tra sach!";
		fstream tmpf, f;
		tmpf.open("MuonTra.txt", ios::in);
		f.open("MuonTra_new.txt", ios::app);
		for (int i = 0; i < m; i++)
		{
			f << mt[i].getMssv() << ", " << mt[i].getHoten() << ", " << mt[i].getLop() << ", " << mt[i].getMaS() << ", " << mt[i].getTenS() << ", " << mt[i].getTheLoai() << ", " << mt[i].getNgayM().ngay << "/" << mt[i].getNgayM().thang << "/" << mt[i].getNgayM().nam << ", " << mt[i].getNgayHT().ngay << "/" << mt[i].getNgayHT().thang << "/" << mt[i].getNgayHT().nam << ", " << mt[i].getNgayT().ngay << "/" << mt[i].getNgayT().thang << "/" << mt[i].getNgayT().nam << ", " << mt[i].getSL() << endl;
		}
		tmpf.close();
		f.close();

		remove("MuonTra.txt");
		rename("MuonTra_new.txt", "MuonTra.txt");
	}
	else
	{
		cout << "\nSinh vien nay chua muon hoac da tra sach roi!";
	}
}

//Xu ly
void pressAnyKey() {
	printf("\n\nChon phim bat ky de tiep tuc");
	_getch();
	system("cls");
}

void QLSV() {
	SV sv[100], svn[100];
	int n, a;
	fstream f;
begin:
	system("cls");
	cout << endl << endl;
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                          QUAN LY SINH VIEN                         ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                  1. Them sinh vien                                 ||";
	cout << "\n\t\t\t\t\t    ||                  2. Xuat thong tin sinh vien                       ||";
	cout << "\n\t\t\t\t\t    ||                  3. Kiem tra tinh trang the                        ||";
	cout << "\n\t\t\t\t\t    ||                  4. Tim kiem sinh vien                             ||";
	cout << "\n\t\t\t\t\t    ||                  5. Xoa sinh vien theo MSSV                        ||";
	cout << "\n\t\t\t\t\t    ||                  6. Gia han the cho sinh vien                      ||";
	cout << "\n\t\t\t\t\t    ||                  7. Tro ve                                         ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung:   ";

	char chon;
	bool key = true;

	do
	{
		if (key == false)
		{
			cout << "ERROR!";
			exit(0);
		}
		else
			cin >> chon;
		key = false;
	} while ((chon < '0') || (chon > '9'));
	doc_file_SV(sv, n);
	switch (chon) {
	case '1':
		themSV(sv, n, svn, a);
		int k;
		do {
			cout << "\nXac nhan luu?";
			cout << "\n\t1. Luu";
			cout << "\n\t2. Khong luu\n";
			cin >> k;
		} while (k != 2 && k != 1);
		if (k == 1)
		{
			luuSVdaThem(svn, f, a);
			cout << "Luu sinh vien thanh cong!";
		}
		if (k == 2)
		{
			cout << "Sinh vien vua nhap khong duoc luu!";
		}
		pressAnyKey();
		break;
	case '2':
		//doc_file_SV(sv, n);
		sapXep_SV(sv, n);
		updateSV(sv, n);
		xuatDSSV(sv, n);
		pressAnyKey();
		break;
	case '3':
		//doc_file_SV(sv, n);
		checkCard_ds(sv, n);
		pressAnyKey();
		break;
	case '4':
		//doc_file_SV(sv, n);
		timKiem_ds(sv, n);
		pressAnyKey();
		break;
	case '5':
		//doc_file_SV(sv, n);
		xoaSV_ID(sv, n);
		updateSV(sv, n);
		pressAnyKey();
		break;
	case '6':
		capNhap_SV(sv, n);
		updateSV(sv, n);
		pressAnyKey();
		break;
	case '7':
		goto end;
		break;
	default:
		cout << "\nKhong hop le!";
		pressAnyKey();
		goto begin;
		break;
	}
	goto begin;
end:;
}

void QLSach() {
	Sach s[100], sn[100];
	int p, q;
	MuonTra mt[100];
	int m;
	fstream f;
begin:
	system("cls");
	cout << endl << endl;
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                          QUAN LY SACH                              ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                 1. Them sach                                       ||";
	cout << "\n\t\t\t\t\t    ||                 2. Xuat danh sach sach hien co                     ||";
	cout << "\n\t\t\t\t\t    ||                 3. Cap nhap thong tin sach                         ||";
	cout << "\n\t\t\t\t\t    ||                 4. Tra cuu thong tin 1 sach bat ky                 ||";
	cout << "\n\t\t\t\t\t    ||                 5. Tro ve                                          ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung:   ";
	char chon;
	bool k = true;

	do
	{
		if (k == false)
		{
			cout << "ERROR!";
			exit(0);
		}
		else
			cin >> chon;
		k = false;
	} while ((chon < '0') || (chon > '9'));
	switch (chon) {
	case '1':
		doc_file_s(s, p);
		them_S(s, p, sn, q);
		int k;
		do {
			cout << "\nXac nhan luu?";
			cout << "\n\t1. Luu";
			cout << "\n\t2. Khong luu\n";
			cin >> k;
		} while (k != 2 && k != 1);
		if (k == 1)
		{
			luu_S(sn, q, f);
			cout << "Luu sach thanh cong!";
		}
		if (k == 2)
		{
			cout << "Sach vua nhap khong duoc luu!";
		}
		pressAnyKey();
		break;
	case '2':
		doc_file_s(s, p);
		sapxep_S(s, p);
		xuatDS_S(s, p);
		pressAnyKey();
		break;
	case '3':
		doc_file_s(s, p);
		capNhap_S(s, p);
		pressAnyKey();
		break;
	case '4':
		doc_file_MT(mt, m);
		doc_file_s(s, p);
		traCuu_sach(s, p, mt, m);
		pressAnyKey();
		break;
	case '5':
		goto end;
		break;
	default:
		cout << "\nKhong hop le!";
		pressAnyKey();
		goto begin;
		break;
	}
	goto begin;
end:;
}

void QLMT() {
	MuonTra mt[100];
	int m;
	SV sv[100];
	int n;
	Sach s[100];
	int p;
	fstream f;
begin:
	system("cls");
	cout << endl << endl;
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                          QUAN LY MUON TRA                          ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                   1. Them nguoi muon                               ||";
	cout << "\n\t\t\t\t\t    ||                   2. Xuat nguoi muon                               ||";
	cout << "\n\t\t\t\t\t    ||                   3. Tong sach dang muon                           ||";
	cout << "\n\t\t\t\t\t    ||                   4. Tong loai sach cu the dang muon               ||";
	cout << "\n\t\t\t\t\t    ||                   5. Kiem tra sach qua han                         ||";
	cout << "\n\t\t\t\t\t    ||                   6. Tong sach dang muon cua 1 sinh vien           ||";
	cout << "\n\t\t\t\t\t    ||                   7. Cap nhap thong tin muon tra                   ||";
	cout << "\n\t\t\t\t\t    ||                   8. Tro ve                                        ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung:   ";

	char chon;
	bool k = true;

	do
	{
		if (k == false)
		{
			cout << "ERROR!";
			exit(0);
		}
		else
			cin >> chon;
		k = false;
	} while ((chon < '0') || (chon > '9'));
	switch (chon) {
	case 1:
		doc_file_SV(sv, n);
		doc_file_s(s, p);
		themNM(mt, m, sv, n, s, p);
		int k;
		do {
			cout << "\nXac nhan luu?";
			cout << "\n\t1. Luu";
			cout << "\n\t2. Khong luu\n";
			cin >> k;
		} while (k != 2 && k != 1);
		if (k == 1)
		{
			luuNM(mt, m, f);
			cout << "Luu nguoi muon thanh cong!";
		}
		if (k == 2)
		{
			cout << "Nguoi muon vua nhap khong duoc luu!";
		}
		pressAnyKey();
		break;
	case 2:
		doc_file_MT(mt, m);
		xuatDSMT(mt, m);
		pressAnyKey();
		break;
	case 3:
		doc_file_MT(mt, m);
		tongSachM(mt, m);
		pressAnyKey();
		break;
	case 4:
		doc_file_MT(mt, m);
		tongSachM_ten(mt, m);
		pressAnyKey();
		break;
	case 5:
		doc_file_MT(mt, m);
		kiemTraHanMT(mt, m);
		pressAnyKey();
		break;
	case 6:
		doc_file_MT(mt, m);
		tongSachMuon_1SV(mt, m);
		pressAnyKey();
		break;
	case 7:
		doc_file_MT(mt, m);
		capNhapMT(mt, m);
		pressAnyKey();
		break;
	case 8:
		goto end;
		break;
	default:
		cout << "\nKhong hop le!";
		pressAnyKey();
		goto begin;
		break;
	}
	goto begin;
end:;
}

void Menu()
{
begin:
	system("cls");
	cout << endl << endl;
	cout << "\n\t\t\t\t\t                              CHUONG TRINH QUAN LY THU VIEN ";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                        1. Quan ly sinh vien                        ||";
	cout << "\n\t\t\t\t\t    ||                        2. Quan ly sach                             ||";
	cout << "\n\t\t\t\t\t    ||                        3. Quan ly muon tra                         ||";
	cout << "\n\t\t\t\t\t    ||                        0. Thoat                                    ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung:   ";
	char chon;
	bool k = true;

	do
	{
		if (k == false)
		{
			cout << "ERROR!";
			exit(0);
		}
		else
			cin >> chon;
		k = false;
	} while ((chon < '0') || (chon > '9'));



	switch (chon) {
	case '1':
		system("cls");
		QLSV();
		break;
	case '2':
		system("cls");
		QLSach();
		break;
	case '3':
		system("cls");
		QLMT();
		break;
	case '0':
		goto end;
		break;
	default:
		cout << "\nKhong hop le!";
		pressAnyKey();
		goto begin;
		break;
	}
	goto begin;
end:;
}


int main()
{
	Menu();
	return 0;
}