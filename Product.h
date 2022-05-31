#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "id.h"

using namespace std;

class Product : public Id
{
private:
	string productName;
	
	string productNumber;
	string expirationDate;
	

public:
	uint32_t productPrice;
	uint32_t productID;
	Product()
	{
		this->productName = "";	
		this->productPrice = 0;
		this->productNumber = "";
		this->expirationDate = "";
		this->productID = 0;
	}

	Product(string productName, string productNumber, uint32_t productPrice, string expirationDate, uint32_t productID)
	{
		this->productName = productName;
		this->productPrice = productPrice;
		this->productNumber = productNumber;
		this->expirationDate = expirationDate;
		this->productID = productID;
	}
	
	uint32_t GetProductID()
	{
		return this->productID;
	}
	
	friend istream& operator >> (istream& in, Product &object) 
	{
		cout << "Enter product details:" << endl;
		cout << "Name -> ";
		in >> object.productName;
		cout << "Price -> ";
		in >> object.productPrice;
		cout << "Number of products -> ";
		in >> object.productNumber;
		cout << "Expiration date ->";
		in >> object.expirationDate;
		object.productID = Id::getId();

		return in;
	}

	friend ostream& operator << (ostream& out, Product& object)
	{
		out << "Product ID -> " << object.productID << endl;
		out << "Name -> " << object.productName << endl;
		out << "Price -> " << object.productPrice << endl;
		out << "Number of products -> " << object.productNumber << endl;
		out << "Expiration date -> " << object.expirationDate << endl;

		return out;
	}

	friend bool operator==(Product& item, Product& value);
	
	Product& operator=(Product& t);

	~Product()
	{
	this->productName.clear();
	this->productNumber.clear();
	this->expirationDate.clear();
	this->productID = NULL;
	this->productPrice = NULL;
	}
};

bool operator==(Product& item, Product& value)
{
	return item.GetProductID() == value.GetProductID();
}

Product& Product::operator=(Product& t)
{
	return t;
}



