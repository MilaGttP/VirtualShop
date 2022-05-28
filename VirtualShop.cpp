

#include <iostream>
#include <iomanip>
#include <conio.h>
#include "productList.h"

using namespace std;


void userLog()
{
	productList ProductList;

	uint32_t userChoice;
	string clubman;


	cout << "\tLog in as an employee or customer?" << endl;
	cout << "your choice [1][2] ->";
	cin >> userChoice;

	switch (userChoice)
	{
	case 1:
	{
		system("cls");
		cout << "You enter as an employee!" << endl;
		cout << "Enter login: ";
		cout << "Enter password: ";
	}break;
	case 2:
	{
		system("cls");
		cout << "You log in as a customer!" << endl;
		cout << "Enter login: ";
		cout << "Enter password: ";

		cout << "Are you a member of the club? (y/n)";
		cin >> clubman;
		if (clubman == "y")
		{
			cout << "Hello " << "VIP" << "!";
		}
		else
		{
			cout << "Hello " << "!";
		}
	}break;
	default:
		cout << "This user type is missing!" << endl;
		_getch();
		break;
	}
	cout << "Product list: " << endl;
	ProductList.ShowList();


}




int main()
{
	productList ProductList;
	while (true)
	{
		system("cls");
		cout << "List menu" << endl;
		cout << "______________________________________" << endl;
		cout << "1 - Add product" << endl;
		cout << "2 - Show product" << endl;

		uint32_t menuChoice;
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
		{
			system("cls");
			Product product;
			cin >> product;
			ProductList.addProduct(product);
		}break;
		case 2:
		{
			system("cls");
			cout << "Product list: " << endl;
			ProductList.ShowList();
		}break;
		default:
			cout << "Enter a valid value!";
			_getch();
			break;
		}

	}

	//userLog();

	return 0;
}



