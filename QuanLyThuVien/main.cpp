#include "sinhvien.h"
#include "sach.h"
#include "muonTra.h"

void doc_file_SV(SV sv[], int& n)
{
	fstream filein;
	filein.open("SinhVien.txt", ios::in);
	filein >> n;
	for (int i = 0; i < n; i++)
	{
		sv[i].doc_file(filein);
	}
	filein.close();
}


int main()
{
	SV sv[100];
	int n = 0;
	doc_file_SV(sv, n);
	/*fstream filein;
	filein.open("SinhVien.txt", ios::in);
	for (int i = 0; i < filein.eof(); i++)
	{
		sv[i].doc_file(filein);
		sv[i].xuatSV();
	}
	filein.close();*/
	/*for (int i = 0; i < filein.eof(); i++)
	{
		sv[i].xuatSV();
	}*/
	/*int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		sv[i].themSV();
	}*/
	return 0;
}