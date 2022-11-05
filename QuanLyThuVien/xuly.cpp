#include "xuly.h"

char dongChuChay[] = "	NHOM 23 - PHAM THANH SON - PHAM TU THANH - PHAM NHAT TAN - LE CONG TUAN";

void Introduce()
{
	system("color 3E");
	ShowCur(false);
	string a;

	// lay tu file o che do chi doc
	ifstream inFile("intro.txt", ios::in);
	if (inFile.good())  // Kiem tra xem file co ket noi duoc hay khong?
	{
		while (!inFile.eof()) {
			getline(inFile, a);
			SetColor(BLACK);
			Sleep(100);
			cout << a << endl;
		}
	}
	else  //Tra ve loi
	{
		cout << "Lien ket voi File intro khong thanh cong! " << "\n";
	}

	// nhan enter de thoat vong lap
	gotoxy(45, 35);
	SetBGColor(BLUE);
	cout << "Please ! Press ENTER to continue. ";
	normalBGColor();

	while (!_kbhit()) {
		gotoxy(35, 30);
		SetColor(1 + rand() % 15);
		Sleep(100);
		cout << "NHOM 23 - PHAM THANH SON - PHAM TU THANH - PHAM NHAT TAN - LE CONG TUAN";
	}

	SetBGColor(AQUA);
	SetColor(AQUA);
	cin.ignore();

	// am thanh
	Beep(600, 200);
	return;
}


void ManHinhChinh()
{
	system("color 3E");
	clrscr();
	normalTextColor();
	ShowCur(false);
	VeKhungMenu();

	normalBGColor();
	MainMenu(keyMainMenu, 5);
	normalBGColor();

	string a;
	int y = 0;

	// lay tu file va chi doc
	ifstream inFile("QuanLyThuVien.txt", ios::in);

	// Kiem tra xem file co ket noi duoc hay khong?
	if (inFile.good())
	{
		while (!inFile.eof()) {
			getline(inFile, a);
			SetColor(11);
			Sleep(100);
			gotoxy(25, y++);
			cout << a << endl;
		}
	}
	else  //Tra ve loi
	{
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
	}

	normalBGColor();
	SetBGColor(BLACK);

	// set khung
	gotoxy(xOrdinal + 44, yOrdinal + 34);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);

	gotoxy(xOrdinal + 44, yOrdinal + 35);
	cout << char(186) << setw(40) << setfill(' ') << char(186);

	gotoxy(xOrdinal + 44, yOrdinal + 36);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);

	chuChay(dongChuChay, xOrdinal + 45, yOrdinal + 35);
	return;
}
