#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "BoolShelf.h"
#include "Book.h"
#include <fstream>
#include <sstream>
using namespace std;

void BookShelf::LoadBook()
{
	string tmp;
	ifstream f2("book.txt");
	if (f2.is_open())
	{
		while (!f2.eof())
		{
			getline(f2, tmp);
			books.push_back(Book(tmp));
		}
	}
	f2.close();
}

int BookShelf::Selectbyname()
{
	vector<Book>::iterator it = books.begin();
	string name;
	cout << "Введите название, по которому будет идти поиск книг" << endl;
	cin >> name;

	ofstream f1("book1.txt");
	if (f1)
	{
		for (it = books.begin(); it!= books.end(); it++)
		{
			Book b = *it;;
			if (name == b.name)
				f1 << b.name << " " << b.author << " " << b.year << " " << b.page << "\n";
		}
	}
	f1.close();

	return 0;
}

int BookShelf::Selectbyyear()
{
	vector<Book>::iterator it = books.begin();
	int year;
	cout << "Введите год, по которому будет идти поиск книг" << endl;
	cin >> year;

	ofstream f1("book1.txt");
	if (f1)
	{
		for (it = books.begin(); it != books.end(); it++)
		{
			Book b = *it;

			if (year == b.year)
				f1 << b.name << " " << b.author << " " << b.year << " " << b.page << "\n";
		}
	}
	f1.close();
	return 0;
}

int BookShelf::Selectbypage()
{
	vector<Book>::iterator it = books.begin();
	int page;
	cout << "Введите количество страниц, по которому будет идти поиск книг" << endl;
	cin >> page;

	ofstream f1("book1.txt");
	if (f1)
	{
		for (it = books.begin(); it != books.end(); it++)
		{
			Book b = *it;

			if (page == b.page)
				f1 << b.name << " " << b.author << " " << b.year << " " << b.page << "\n";
		}
	}
	f1.close();
	return 0;
}

int BookShelf::Selectbyauthor()
{
	vector<Book>::iterator it = books.begin();
	string author;
	cout << "Введите автора, по которому будет идти поиск книг" << endl;
	cin >> author;

	ofstream f1("book1.txt");
	if (f1)
	{
		for (it = books.begin(); it != books.end(); it++)
		{
			Book b = *it;

			if (author == b.author)
				f1 << b.name << " " << b.author << " " << b.year << " " << b.page << "\n";
		}
	}
	f1.close();
	return 0;
}
