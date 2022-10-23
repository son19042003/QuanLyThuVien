#include "base.h"

class Student1
{
protected:
	std::string hoTen;
	std::string username;
};


class Student2:public Student1
{
private:
	std::string password;
	std::string borrow;
public:
	void setUsername(std::string username)
	{
		this->username = username;
	}
	std::string getUsername()
	{
		return username;
	}

	void setPassword(std::string password)
	{
		this->password = password;
	}
	std::string getPassword()
	{
		return password;
	}
};