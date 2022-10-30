#include "update.h"



void update1(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB)
{
	fstream fin, fout;
	fin.open("student.csv", ios::in);
	fout.open("studentnew.csv", ios::out);
	for (int i = 0; i <= amountS; i++)
	{
		fout << st2[i].getUsername() << "," << st2[i].getPassword() << "," << st2[i].getName() << "," << st2[i].getBorrow() << "\n";
	}
	fin.close();
	fout.close();

	remove("student.csv");
	rename("studentnew.csv", "student.csv");



	fin.open("book_list.csv", ios::in);
	fout.open("book_listnew.csv", ios::out);
	for (int i = 0; i <= amountB; i++)
	{
		fout << book1[i].getID() << "," << book1[i].getNameBook() << "," << book1[i].getCategory() << "," << book1[i].getAmount() << "\n";
	}
	fin.close();
	fout.close();

	remove("book_list.csv");
	rename("book_listnew.csv", "book_list.csv");
}


void update2(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, map<string, int> k)
{
	fstream fin, fout;
	fin.open("student.csv", ios::in);
	fout.open("studentnew.csv", ios::out);
	for (int i = 0; i <= amountS; i++)
	{
		if (k[st2[i].getUsername()] == 1)
		{
			fout << st2[i].getUsername() << "," << st2[i].getPassword() << "," << st2[i].getName() << "," << st2[i].getBorrow() << "\n";
		}
	}

	fin.close();
	fout.close();

	remove("student.csv");
	rename("studentnew.csv", "student.csv");
}