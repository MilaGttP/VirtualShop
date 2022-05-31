
#include <iostream>
#include "Product.h"

void MenuWorker() {
    Team team;

    while (true)
    {
        system("cls");
        cout << "MENU" << endl << endl;
        cout << "1 - Add worker" << endl;
        cout << "2 - Show workers" << endl;
        cout << "3 - Sort by rang" << endl;
        cout << "4 - Find" << endl;
        cout << "5 - Delete" << endl;
        cout << "6 - Exit" << endl << endl;
        cout << "Enter: ";
        int menu;
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            system("cls");
            Worker* worker = new Worker;
            cin >> *worker;
            team.AddWorker(*worker);
        }break;

        case 2:
        {
            team.Show();
        }break;

        case 3:
        {
            team.SortByRang();
            team.Show();
        }break;

        case 4:
        {
            string name;
            cout << "Enter>";
            cin >> name;
            team.Find(name);
        }break;

        case 5:
        {
            string name;
            cout << "Enter>";
            cin >> name;
            team.DeleteWorker(name);
        }break;
        }

        system("pause");
    }
}

void MenuPrint() {
    GreetWork grWork;
    Product product;

    while (true)
    {
        system("cls");
        cout << "MENU" << endl << endl;
        cout << "1 - Print a list of all clients." << endl;
        cout << "2 - Print a list of clients who are only club members." << endl;
        cout << "3 - Print a list of customers who have made at least one purchase." << endl;
        cout << "4 - Print the customer whose purchase amount is the highest." << endl;
        cout << "5 - Adding a new product to the store." << endl;
        cout << "6 - Exit" << endl << endl;
        cout << "Enter: ";
        int menu;
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            grWork.PrintAllClients();
        }break;

        case 2:
        {
            grWork.PrintClubMembers();
        }break;

        case 3:
        {
            grWork.PrintOnePurch();
        }break;

        case 4:
        {
            grWork.PrintHighPurch();
        }break;

        case 5:
        {
            system("cls");
            Product* product = new Product;
            cin >> product;
            grWork.AddNewProd(product);
        }break;
        }
        system("pause");
    }
}