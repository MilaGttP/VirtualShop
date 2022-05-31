

#include <iostream>
#include <iomanip>
#include <conio.h>

#include "Product.h"
#include "ProductList.h"
#include "Basket.h"
//#include "Account.h"

using namespace std;

void userLog()
{

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
		//SingIn();
	}break;
	case 2:
	{
		system("cls");
		cout << "You log in as a customer!" << endl;
		//SingIn();

		cout << "Are you a member of the club? (y/n)";
		cin >> clubman;
		if (clubman == "y")
		{
			//cout << "Hello " << GetName() << " " << GetSurname() << "VIP" << "!";
		}
		else
		{
			//cout << "Hello "  << GetName() << " " << GetSurname() << "!";
		}
	}break;
	default:
		cout << "This user type is missing!" << endl;
		_getch();
		break;
	}
	system("cls");
	cout << "Product list: " << endl;
	//ProductList.ShowList();

	



}




int main()
{
	ProductList productList;
	

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
			
			Product* prod = new Product;
			cin >> *prod;
			productList.addProduct(*prod);
		}break;
		case 2:
		{
			system("cls");
			productList.ShowList();

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



