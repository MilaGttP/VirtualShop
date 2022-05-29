#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Product
{
private:
	string productName;
	uint32_t productPrice;
	string productNumber;
	string expirationDate;
	uint32_t productID;

public:
	
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
	
	string GetProductName()
	{
		return this->productName;
	}
	uint32_t GetProductPrice()
	{
		return this->productPrice;
	}
	string GetProductNumber()
	{
		return this->productNumber;
	}
	string GetExpirationDate()
	{
		return this->expirationDate;
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
		object.productID+=1;

		return in;
	}

	friend ostream& operator << (ostream& out, Product& object)
	{
		out << "Name -> " << object.productName << endl;
		out << "Price -> " << object.productPrice << endl;
		out << "Number of products -> " << object.productNumber << endl;
		out << "Expiration date -> " << object.expirationDate << endl;
		out << "Product ID -> " << object.productID << endl;

		return out;
	}
	
	~Product()
	{
	this->productName.clear();
	this->productNumber.clear();
	this->expirationDate.clear();
	this->productID = NULL;
	this->productPrice = NULL;
	}
};




