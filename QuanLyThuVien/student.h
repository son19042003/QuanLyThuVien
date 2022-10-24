#pragma once
#include <vector>
#include "base.h"


class Student1
{
protected:
	string name;
	string username;
public:
	void setUsername(string username);
	string getUsername();
	void setName(string name);
	string getName();
};


class Student2:public Student1
{
private:
	string password;
	string borrow;
public:
	void setPassword(string password);
	string getPassword();
	void setBorrow(string borrow);
	string getBorrow();
};

