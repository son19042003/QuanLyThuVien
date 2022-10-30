#include "user.h"


string get_time()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	return to_string(time->tm_hour) + ":" + to_string(time->tm_min) + ":" + to_string(time->tm_sec);
}


string get_day()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	return to_string(time->tm_mday) + "/" + to_string(1 + time->tm_mon) + "/" + to_string(1900 + time->tm_year);
}


void intime()
{
	cout << "Thoi gian: " << get_time() << "\n";
	cout << "Ngay: " << get_day() << "\n";
}


void success()
{
	cout << "-----------------------" << endl;
	setColor(0, 9);
	cout << "Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	setColor(0, 7);
	cout << "-----------------------" << endl;
}


void returnBook(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k)
{
	bool* kt = new bool[amountB + 1];
	for (int i = 0; i <= amountB; i++)
	{
		kt[i] = false;
	}
	string a = st2[k].getBorrow();
	string s;
	int br;
	for (int i = 0; i <= a.length(); i++)
	{
		if (a[i] == ';')
		{
			br++;
			kt[stoi(s)] = true;
			s = " ";
		}
		else
		{
			s = s + a[i];
		}
	}
	int n;
	cout << "Nhap so sach muon tra hoac nhan 0 de huy yeu cau...";
	cin >> n;
	while (n > br - 1)
	{
		setColor(0, 12);
		cout << "Khong hop le! So sach ban dang muon chi la " << br - 1 << "quyen";
		setColor(0, 7);
		cout << (char)16 << "Nhap lai so sach ban muon tra...";
		cin >> n;
	}
	while (n < 0)
	{
		setColor(0, 12);
		cout << "Khong hop le! Vui long nhap lai..." << "\n";
		setColor(0, 7);
		cout << " " << (char)16 << (char)16;
		cin >> n;
	}

	if (n == 0)
	{
		setColor(0, 10);
		cout << "Ban da huy yeu cau tra sach..." << "\n";
		setColor(0, 7);
	}
	if (n > 0)
	{
		vector<int> id1;
		cout << "Nhap ma sach can tra..." << "\n";
		int x = 0;
		int y = n;
		while (n > 0)
		{
			n--;
			x++;
			int id;
			cout << (char)16 << (char)16 << "Nhap ma thu " << x << ": ";
			cin >> id;
			while (id <= 0)
			{
				setColor(0, 12);
				cout << "Ma sach khong hop le! Vui long nhap lai: " << endl;
				setColor(0, 7);
				cout << " " << (char)16 << (char)16;
				cin >> id;
			}
			while (kt[id] == false)
			{
				setColor(0, 12);
				cout << "Ban chua muon sach nay ";
				cout << "cac sach ma sach ban dang muon: ";
				cout << st2[k].getBorrow() << endl;
				setColor(0, 7);
				cout << "Nhap lai:";
				cin >> id;
			}
			
			id1.push_back(id);
			kt[id] = false;
			setColor(0, 2);
			cout << "Ban dang tra quyen: " << book1[id].getNameBook() << "\n";
			setColor(0, 7);

			stringstream ss;
			ss << id;

		}
	}
}