#pragma once
#include "update.h"
#include <ctime>


int c;

string get_time();

string get_day();

void intime();

void success();

void returnBook(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);

void borrow(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);

void user1(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);

void user2(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);

void user3(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);

void user4(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);

void user5(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);

void user(vector<Student2>& st2, long& amountS, vector<Book1>& book1, long& amountB, int k);