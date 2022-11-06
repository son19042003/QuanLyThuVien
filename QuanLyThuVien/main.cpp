#include "sinhvien.h"
#include "sach.h"
#include "muonTra.h"
#include <conio.h>

//Sinh Vien
void themSV(SV sv[], int& n)
{
	cout << "\nNhap so luong sinh vien muon them: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		sv[i].themSV();
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
	n = dem-1;
	filein.open("SinhVien.txt", ios::in);
	for (int i = 0; i < n; i++)
	{
		sv[i].doc_file(filein);
	}
	filein.close();
}


void xuatDSSV(SV sv[], int n)
{
	cout << left << setw(15) << "Ma sinh vien" << left << setw(25) << "Ho va ten" << left << setw(15) << "Lop" << left << setw(12) << "Ngay het han the" << endl;
	for (int i = 0; i < n; i++)
	{
		sv[i].xuatSV();
		cout << "\n";
	}
}


void checkCard_ds(SV sv[], int n)
{
	date x;
	int a = 0, b = 0, c = 0;
	cout << "\nNhap ngay kiem tra the: ";
	cin >> a >> b >> c;
	x.setNgay(a); x.setThang(b); x.setNam(c);
	cout << left << setw(15) << "Ma sinh vien" << left << setw(25) << "Ho va ten" << left << setw(15) << "Lop" << left << setw(20) << "Ngay het han the" << left << setw(20) << "Tinh trang the" << endl;
	for (int i = 0; i < n-1; i++)
	{
		sv[i].xuatSV();
		cout << sv[i].checkCard(x);
		cout << "\n";
	}
}

void timKiem_ds(SV sv[], int n)
{
	string x;
	cout << "\nNhap ma sinh vien can tim: ";
	cin >> x;
	cout << left << setw(15) << "Ma sinh vien" << left << setw(25) << "Ho va ten" << left << setw(15) << "Lop" << left << setw(12) << "Ngay het han the" << endl;
	for (int i = 0; i < n; i++)
	{
		if (sv[i].timKiemSV(x) == true)
		{
			sv[i].xuatSV();
		}
	}
}

//Sach
void them_S(Sach s[], int& p)
{
	cout << "So luong sach can them: ";
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		s[i].themS();
	}
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
	cout << left << setw(10) << "Ma sach" << left << setw(20) << "Ten sach" << left << setw(15) << "The loai" << left << setw(20) << "Ten tac gia" << left << setw(17) << "Nam xuat ban" << left << setw(8) << "So luong" << endl;
	for (int i = 0; i < p; i++)
	{
		s[i].xuatS();
		cout << "\n";
	}
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

//Muon tra
void themNM(MuonTra mt[], int& m)
{
	cout << "\nNhap so luong nguoi muon muon them: ";
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		mt[i].them();
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
	cout << left << setw(15) << "Ma sinh vien" << left << setw(25) << "Ho va ten" << left << setw(15) << "Lop" << left << setw(10) << "Ma sach" << left << setw(15) << "Ten sach" << left << setw(15) << "The loai" << left << setw(20) << "Ngay muon" << left << setw(20) << "Ngay hen tra" << left << setw(20) << "Ngay tra" << left << setw(8) << "So Luong" << endl;
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
	cout << "\nTen sach hoac the loai can tra: ";
	cin.ignore();
	getline(cin, x);
	for (int i = 0; i < m; i++)
	{
		s = s + mt[i].tinhSL_ten(x);
	}
	cout << "\nTong so luong sach dang tim da muon: " << s;
}

//Xu ly
void pressAnyKey() {
	printf("\n\nChon phim bat ky de tiep tuc");
	_getch();
	system("cls");
}

void QLSV() {
	SV sv[100];
	int n;
	fstream f;
begin:
	cout << endl << endl;
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                          QUAN LY SINH VIEN                         ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                  1. Them sinh vien                                 ||";
	cout << "\n\t\t\t\t\t    ||                  2. Xuat thong tin sinh vien                       ||";
	cout << "\n\t\t\t\t\t    ||                  3. Kiem tra tinh trang the                        ||";
	cout << "\n\t\t\t\t\t    ||                  4. Tim kiem sinh vien                             ||";
	cout << "\n\t\t\t\t\t    ||                  5.                                                ||";
	cout << "\n\t\t\t\t\t    ||                  6.                                                ||";
	cout << "\n\t\t\t\t\t    ||                  7.                                                ||";
	cout << "\n\t\t\t\t\t    ||                  8.                                                ||";
	cout << "\n\t\t\t\t\t    ||                  9. Tro ve                                         ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung:   ";

	char chon;
	bool k = true;

	do
	{
		if (k == false)
			cout << "Vui long nhap lai: ";
		else
			cin >> chon;
		k = false;
	} while ((chon < '1') || (chon > '9'));
	switch (chon) {
	case '1':
		themSV(sv, n);
		int k;
		do {
			cout << "\nXac nhan luu?";
			cout << "\n\t1. Luu";
			cout << "\n\t2. Khong luu\n";
			cin >> k;
		} while (k != 2 && k != 1);
		if (k == 1)
		{
			luuSVdaThem(sv, f, n);
			cout << "Luu sinh vien thanh cong!";
		}
		if (k == 2)
		{
			cout << "Sinh vien vua nhap khong duoc luu!";
		}
		pressAnyKey();
		break;
	case '2':
		doc_file_SV(sv, n);
		xuatDSSV(sv, n);
		pressAnyKey();
		break;
	case '3':
		doc_file_SV(sv, n);
		checkCard_ds(sv, n);
		pressAnyKey();
		break;
	case '4':
		doc_file_SV(sv, n);
		timKiem_ds(sv, n);
		pressAnyKey();
		break;
	case '5':
		pressAnyKey();
		break;
	case '6':
		pressAnyKey();
		break;
	case '7':
		pressAnyKey();
		break;
	case '8':
		pressAnyKey();
		break;
	case '9':
		goto end;
		break;
	}
	goto begin;
end:;
}

void QLSach() {
	Sach s[100];
	int p;
	fstream f;
begin:
	cout << endl << endl;
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                          QUAN LY SACH                              ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                 1. Them sach                                       ||";
	cout << "\n\t\t\t\t\t    ||                 2. Xuat danh sach sach hien co                     ||";
	cout << "\n\t\t\t\t\t    ||                 3. Tong so luong sach hien co                      ||";
	cout << "\n\t\t\t\t\t    ||                 4.                                                 ||";
	cout << "\n\t\t\t\t\t    ||                 5.                                                 ||";
	cout << "\n\t\t\t\t\t    ||                 6.                                                 ||";
	cout << "\n\t\t\t\t\t    ||                 7.                                                 ||";
	cout << "\n\t\t\t\t\t    ||                 8.                                                 ||";
	cout << "\n\t\t\t\t\t    ||                 9. Tro ve                                          ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung:   ";
	char chon;
	bool k = true;

	do
	{
		if (k == false)
			cout << "Vui long nhap lai:  ";
		else
			cin >> chon;
		k = false;
	} while ((chon < '0') || (chon > '9'));
	switch (chon) {
	case '1':
		them_S(s, p);
		int k;
		do {
			cout << "\nXac nhan luu?";
			cout << "\n\t1. Luu";
			cout << "\n\t2. Khong luu\n";
			cin >> k;
		} while (k != 2 && k != 1);
		if (k == 1)
		{
			luu_S(s, p, f);
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
		xuatDS_S(s, p);
		pressAnyKey();
		break;
	case '3':
		doc_file_s(s, p);
		tongDSS(s, p);
		pressAnyKey();
		break;
	case '4':
		pressAnyKey();
		break;
	case '5':
		pressAnyKey();
		break;
	case '6':
		pressAnyKey();
		break;
	case '7':
		pressAnyKey();
		break;
	case '8':
		pressAnyKey();
		break;
	case '9':
		goto end;
		break;
	}
	goto begin;
end:;
}

void QLMT() {
	MuonTra mt[100];
	int m;
	fstream f;
begin:
	//system("cls");
	cout << endl << endl;
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                          QUAN LY MUON TRA                          ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                     1. Them nguoi muon                             ||";
	cout << "\n\t\t\t\t\t    ||                     2. Xuat nguoi muon                             ||";
	cout << "\n\t\t\t\t\t    ||                     3. Tong sach dang muon                         ||";
	cout << "\n\t\t\t\t\t    ||                     4. Tong loai sach cu the dang muon             ||";
	cout << "\n\t\t\t\t\t    ||                     5.                                             ||";
	cout << "\n\t\t\t\t\t    ||                     6.                                             ||";
	cout << "\n\t\t\t\t\t    ||                     7.                                             ||";
	cout << "\n\t\t\t\t\t    ||                     8.                                             ||";
	cout << "\n\t\t\t\t\t    ||                     9. Tro ve                                      ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
	cout << "\n\t\t\t\t\t    ========================================================================";
	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung:   ";

	char chon;
	bool k = true;

	do
	{
		if (k == false)
			cout << "Vui long nhap lai: ";
		else
			cin >> chon;
		k = false;
	} while ((chon < '0') || (chon > '9'));
	switch (chon) {
	case '1':
		themNM(mt, m);
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
	case '2':
		doc_file_MT(mt, m);
		xuatDSMT(mt, m);
		pressAnyKey();
		break;
	case '3':
		doc_file_MT(mt, m);
		tongSachM(mt, m);
		pressAnyKey();
		break;
	case '4':
		doc_file_MT(mt, m);
		tongSachM_ten(mt, m);
		pressAnyKey();
		break;
	case '5':
		pressAnyKey();
		break;
	case '6':
		pressAnyKey();
		break;
	case '7':
		pressAnyKey();
		break;
	case '8':
		pressAnyKey();
		break;
	case '9':
		goto end;
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
			cout << "Vui long nhap lai:  ";
		else
			cin >> chon;
		k = false;
	} while ((chon < '0') || (chon > '3'));



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
	}
	goto begin;
end:;
}

//void Menu()
//{
//	label:
//	int x;
//	cout << "\n\t\t\t\t\t                              CHUONG TRINH QUAN LY THU VIEN ";
//	cout << "\n\t\t\t\t\t    ========================================================================";
//	cout << "\n\t\t\t\t\t    ||                        1. Quan ly sinh vien                        ||";
//	cout << "\n\t\t\t\t\t    ||                        2. Quan ly sach                             ||";
//	cout << "\n\t\t\t\t\t    ||                        3. Quan ly muon tra                         ||";
//	cout << "\n\t\t\t\t\t    ||                        0. Thoat                                    ||";
//	cout << "\n\t\t\t\t\t    ========================================================================";
//	cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
//	cout << "\n\t\t\t\t\t    ========================================================================";
//	cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung   ";
//	cin >> x;
//	system("cls");
//	switch (x) {
//	case 1:
//		int k;
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||                          QUAN LY SINH VIEN                         ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||                  1. Them sinh vien                                 ||";
//		cout << "\n\t\t\t\t\t    ||                  2. Xuat thong tin sinh vien                       ||";
//		cout << "\n\t\t\t\t\t    ||                  3. Kiem tra tinh trang the                        ||";
//		cout << "\n\t\t\t\t\t    ||                  4. Tim kiem sinh vien                             ||";
//		cout << "\n\t\t\t\t\t    ||                  5.                                                ||";
//		cout << "\n\t\t\t\t\t    ||                  6.                                                ||";
//		cout << "\n\t\t\t\t\t    ||                  7.                                                ||";
//		cout << "\n\t\t\t\t\t    ||                  8.                                                ||";
//		cout << "\n\t\t\t\t\t    ||                  9. Tro ve                                         ||";
//		cout << "\n\t\t\t\t\t    ||                  0. Thoat                                          ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t                   Vui Long Chon Cac Phim Chuc Nang Tuong Ung   ";
//		cin >> k;
//		system("cls");
//		switch (k)
//		{
//		case 0:
//			break;
//		case 9:
//			goto label;
//		}
//		break;
//	case 2:
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||                          QUAN LY SACH                              ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||1 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||2 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||3 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||4 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||5 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||6 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||7 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||8 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||9 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||0 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		break;
//	case 3:
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||                          QUAN LY MUON TRA                          ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||1 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||2 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||3 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||4 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||5 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||6 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||7 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||8 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||9 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ||0 .                                                                 ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		cout << "\n\t\t\t\t\t    ||                              Nhom 23                               ||";
//		cout << "\n\t\t\t\t\t    ========================================================================";
//		break;
//	case 0:
//		break;
//	default: cout << "ERROL: again!";
//	}
//}


int main()
{
	Menu();
	return 0;
}