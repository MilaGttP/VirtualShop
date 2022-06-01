
#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;

class Product
{
protected:
	bool isInStock;
	char productName[32];
	int productPrice;
	int productQuantity;
	char expirationDate[32];
	int productID;

public:
	Product() = default;
	~Product() = default;

	char* GetProductName() { return this->productName; }
	int GetPrice() { return this->productPrice; }
	int GetQuantity() { return this->productQuantity; }
	char* GetExpirationDate() { return this->expirationDate; }
	int GetProductID() { return this->productID; }
	bool GetInStock() { return this->isInStock; }

	void EnterProductData()
	{
		int boolStock;
		cout << "Is the product in stock? [1 - yes, 2 - no]: ";
		cin >> boolStock;
		switch (boolStock)
		{
		case 1:
		{
			this->isInStock = true;
		}break;
		case 2:
		{
			this->isInStock = false;
		}break;
		default:
			break;
		}
		cin.ignore();
		cout << "Product ID -> ";
		cin >> productID;
		cin.ignore();
		cout << "Product name -> ";
		cin.getline(this->productName, sizeof(productName));
		cout << "Price -> ";
		cin >> productPrice;
		cin.ignore();
		cout << "Quantity -> ";
		cin >> productQuantity;
		cin.ignore();
		cout << "Expiration date -> ";
		cin.getline(this->expirationDate, sizeof(expirationDate));
	}

	friend ostream& operator << (ostream& out, Product*& object)
	{
		out << "Product ID -> " << object->productID << endl;
		out << "Name -> " << object->productName << endl;
		out << "Price -> " << object->productPrice << endl;
		out << "Quantity of products -> " << object->productQuantity << endl;
		out << "Expiration date -> " << object->expirationDate << endl;
		return out;
	}
};
