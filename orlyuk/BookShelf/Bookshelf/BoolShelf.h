#pragma once

#include <iostream>
#include <vector>
#include "Book.h"
#include <string>

class BookShelf
{
	std::vector<Book> books;
public:
	
	void LoadBook();
	int Selectbyname();
	int Selectbyyear();
	int Selectbypage();
	int Selectbyauthor();
};