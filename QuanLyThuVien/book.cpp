#include "base.h"


class Book1
{
protected:
	std::string id;
	std::string name;
	std::string category;
	int amount;
};


class Book2:public Book1
{
private:
	
};