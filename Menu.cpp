
#include <Windows.h>
#include "Account.h"
#include "GreetWork.h"
#include "ProductList.h"
#include "Product.h"
#include "Basket.h"
#include "Print.h"

void RunClient()
{
	uint32_t tmp, temp;
	Print print;
	GreetWork greetWork;
	ProductList prodList;
	Basket basket;
	while (true)
	{
		system("cls");
		greetWork.PrintGreetClient();
		cout << "\nClient menu: " << endl << endl;
		cout << "1 - Do a purchase" << endl;
		cout << "2 - Exit" << endl << endl;
		cout << "Enter: "; cin >> tmp;
		switch (tmp)
		{
		case 1:
		{
			system("cls");
			cout << "What do want to do: " << endl << endl;
			cout << "1 - Continue purchasing" << endl;
			cout << "2 - Show a receipt" << endl;
			cout << "Enter: "; cin >> temp;
			switch (temp)
			{
			case 1:
			{
				prodList.ShowList();
				basket.SearchById();
			}break;
			case 2:
			{
				basket.SummBasket();
			}break;
			}
		}break;
		case 2:
		{
			cout << "Your data: " << endl;
			print.PrintClient();
			exit(0);
		}break;
		}
	}
}

void RunWorker()
{
	ProductList prodList;
	Basket basket;
	Print print;
	GreetWork grWork;
	Product* prod = new Product();
	FileData <Product> dataProd("ProductList.bin");
	int temp;
	system("cls");
	while (true)
	{
		grWork.PrintGreetWorker();
		cout << "\nWorker menu: " << endl << endl;
		cout << "1 - Print all clients" << endl;
		cout << "2 - Print a list of clients who are only club members" << endl;
		cout << "3 - Add a new product" << endl;
		cout << "4 - Do a purchase" << endl;
		cout << "5 - Exit" << endl << endl;
		cout << "Enter: "; cin >> temp;
		switch (temp)
		{
		case 1:
		{
			system("cls");
			grWork.PrintAllClients();
			system("pause");
			system("cls");
		}break;
		case 2:
		{
			system("cls");
			grWork.PrintClubMembers();
			system("pause");
			system("cls");
		}break;
		case 3:
		{
			system("cls");
			prod->EnterProductData();
			dataProd.Save(prod);
		}break;
		case 4:
		{
			system("cls");
			cout << "What do want to do: " << endl << endl;
			cout << "1 - Continue purchasing" << endl;
			cout << "2 - Show a receipt" << endl;
			cout << "Enter: "; cin >> temp;
			switch (temp)
			{
			case 1:
			{
				prodList.ShowList();
				basket.SearchById();
			}break;
			case 2:
			{
				basket.SumBasketWithDisc();
			}break;
			}
		}break;
		case 5:
		{
			cout << "Your data: " << endl;
			print.PrintWorker();
			cout << "Exit." << endl;
			exit(0);
		}break;
		default:
		{
			cerr << "Enter a valid value!" << endl;
		}break;
		}

	}
}

void RunMainMenu()
{
	uint32_t tmp, temp;
	Account acc;
	cout << "Hello! Menu: " << endl;
	cout << "\t1 - Create an account" << endl;
	cout << "\t2 - Sign in existing client account" << endl;
	cout << "\t3 - Sign in existing worker account" << endl;
	cout << "\t4 - Exit" << endl;
	cout << "Enter wanted case: "; cin >> tmp;
	switch (tmp)
	{
	case 1:
	{
		FileData <ClientAccount> dataClient("ClientAccount.bin");
		FileData <CoworkerAccount> dataCoworker("CoworkerAccount.bin");
		ClientAccount* clientAcc = new ClientAccount();
		CoworkerAccount* coworkerAcc = new CoworkerAccount();
		cout << "\t1 - Create a client account" << endl;
		cout << "\t2 - Create a coworker account" << endl;
		cout << "Enter: "; cin >> temp;
		switch (temp)
		{
		case 1:
		{
			clientAcc->CreateClientAcc();
			dataClient.Save(clientAcc);
			cout << endl;
		}break;
		case 2:
		{
			coworkerAcc->CreateCoworkerAcc();
			dataCoworker.Save(coworkerAcc);
			cout << endl;
		}break;
		}
		break;
	}
	case 2:
	{
		if (acc.SignIn() == true)
			RunClient();
		else
			cerr << "This account doesn`t exist!" << endl;
		break;
	}
	case 3:
	{
		if (acc.SignIn() == true)
			RunWorker();
		else
			cerr << "This account doesn`t exist!" << endl;
		break;
	}
	case 4:
	{
		exit(0);
		break;
	}
	}
}

int main()
{
	RunMainMenu();
	return 0;
}