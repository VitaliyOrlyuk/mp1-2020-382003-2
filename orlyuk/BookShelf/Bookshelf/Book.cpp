#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"
#include <fstream>
#include <sstream>
using namespace std;

Book::Book()
{
	name = "\"\"";
	author = "";
	year = 0;
	page = 0;
}

Book::Book(string str)
{
	stringstream b;
	b << str;
	b >> name >> author >> year >> page;
}