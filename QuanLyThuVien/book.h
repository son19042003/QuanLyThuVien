#pragma once
#include "base.h"


class Book1
{
protected:
	string id;
	string nameB;
	string category;
	int amount;
public:
	void setID(string ID);
	string getID();
	void setNameBook(string nameB);
	string getNameBook();
	void setCategory(string category);
	string getCategory();
	void setAmount(int amount);
	int getAmount();
};


class Book2 :public Book1
{
private:

};