#include <iostream>
#include <fstream>
#include <windows.h> 
#include<string>




using namespace std;


struct delo
{
    string Employee;
    string Ñlient;
    string Basket;
    string Product;
    string Shop;
};

void InfoEmployee(string Employee)
{

}

void InfoClient(string Client)
{

}

void InfoBasket(string Basket)
{

}

void InfoProduct(string Product)
{

}

void InfoShop(string Shop)
{

}


void run()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string client = "";
    short menu = -1;
    do
    {
        cout << "MENU";
        cout << "1 - Employee;" << endl;
        cout << "2 - Client;" << endl;
        cout << "3 - Basket;" << endl;
        cout << "4 - Product;" << endl;
        cout << "5 - Shop;" << endl;
        cout << "Hide menu item: " << endl;
        cin >> menu;
    } while (true);
}