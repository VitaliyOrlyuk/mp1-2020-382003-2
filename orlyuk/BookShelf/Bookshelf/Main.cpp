#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "BoolShelf.h"
#include "Book.h"
#include <fstream>
using namespace std;
void menu()
{
	cout << "----------MENU-------------------------" << endl;
	cout << "| 1. ������ ���� �� ����������        |" << endl;
	cout << "| 2. ����� ���� �� ��������           |" << endl;
	cout << "| 3. ����� ���� �� ������             |" << endl;
	cout << "| 4. ����� ���� �� ����               |" << endl;
	cout << "| 5. ����� ���� �� ���������� ������� |" << endl;
	cout << "| 0. Exit                             |" << endl;
	cout << "---------------------------------------" << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	BookShelf a;
	int t = 7;
	while(t != 0)
	{
		menu();
		cin >> t;
		switch(t)
		{
		case 1:
		{
			a.LoadBook();
			break;
		}
		case 2:
		{
			a.Selectbyname();
			break;
		}
		case 3:
		{
			a.Selectbyauthor();
			break;
		}
		case 4:
		{
			a.Selectbyyear();
			break;
		}
		case 5:
		{
			a.Selectbypage();
			break;
		}
		}
	}
}