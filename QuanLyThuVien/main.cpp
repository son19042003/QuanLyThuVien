#include "sinhvien.h"
#include "sach.h"
#include "muonTra.h"

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


void luuSVdaThem(SV sv[], fstream f, int n)
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
	n = dem;
	filein.open("SinhVien.txt", ios::in);
	for (int i = 0; i < n-1; i++)
	{
		sv[i].doc_file(filein);
	}
	filein.close();
}


void xuatDSSV(SV sv[], int n)
{
	cout << left << setw(15) << "Ma sinh vien" << left << setw(25) << "Ho va ten" << left << setw(15) << "Lop" << left << setw(12) << "Ngay het han the" << endl;
	for (int i = 0; i < n-1; i++)
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

//Sach



int main()
{
	return 0;
}