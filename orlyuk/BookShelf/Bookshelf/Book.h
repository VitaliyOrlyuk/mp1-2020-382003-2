#pragma once

#include <iostream>
#include <string>

using namespace std;

class Book
{
public:	
	string name;
	string author;
	int year;
	int page;
	string str;
	Book();
	Book(string str);
};