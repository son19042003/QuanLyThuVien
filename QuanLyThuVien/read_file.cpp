#include "read_file.h"
#include <string>



void read_file(vector<Student2>& st2, long &amountS, vector<Book1>& book1, long& amountB)
{
	int t = -1;
	ifstream ip1("student.csv");
	string userName;
	string passWord;
	string borRow;
	string fullName;
	while (ip1.peek()!=EOF)
	{
		t++;
		getline(ip1, userName, ',');
		getline(ip1, passWord, ',');
		getline(ip1, borRow, ';');
		getline(ip1, fullName, '\n');

		Student2 objS2;
		objS2.setUsername(userName);
		objS2.setPassword(passWord);
		objS2.setName(fullName);
		objS2.setBorrow(borRow);

		st2.push_back(objS2);
	}

	amountS = t;
	ip1.close();


	ifstream ip2("book_list.csv");
	t = -1;
	string ID;
	string nameBook;
	string cateGory;
	int aMount;
	while (ip2.peek() != EOF)
	{
		t++;
		getline(ip2, ID, ',');
		getline(ip2, nameBook, ',');
		getline(ip2, cateGory, ',');
		ip2 >> aMount;
		cout << "\n";

		Book1 objB1;
		objB1.setID(ID);
		objB1.setNameBook(nameBook);
		objB1.setCategory(cateGory);
		objB1.setAmount(aMount);

		book1.push_back(objB1);
	}
	amountB = t;
	ip2.close();
}