#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

class Product
{
protected:
	string productName;
	uint32_t productPrice;
	string productNumber;
	string expirationDate;
	uint32_t productID;

public:
	//>-----------------<Init>-----------------<
	Product()
	{
		this->productName = "";	
		this->productPrice = 0;
		this->productNumber = "";
		this->expirationDate = "";
		this->productID = 0;
	}
	Product(string productName, string productNumber, string expirationDate, uint32_t productID, uint32_t productPrice)
	{
		this->productName = productName;
		this->productPrice = productPrice;
		this->productNumber = productNumber;
		this->expirationDate = expirationDate;
		this->productID = productID;
	}
	//>----------------<Getter>----------------<
	//string GetProductName()
	//{
	//	return this->productName;
	//}
	//string GetProductNumber()
	//{
	//return this->productNumber;
	//}
	//string GetExpirationDate()
	//{
	//return this->expirationDate;
	//}
	//uint32_t GetProductID()
	//{
	//return this->productID;
	//}
	
	//>----------------<Setter>----------------<
	/*void SetProductName(string productName)
	{
	this->productName = productName;
	}
	void SetProductNumber(string productNumber)
	{
	this->productNumber = productNumber;
	}
	void SetExpirationDate(string expirationDate)
	{
	this->expirationDate = expirationDate;
	}
	void SetProductID(uint32_t productID)
	{
	this->productID = productID;
	}*/
	//>-----------------<Foo>------------------<
	friend istream& operator >> (istream& in, Product object) 
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
		object.productID++;

		return in;
	}

	friend ostream& operator << (ostream& out, Product object)
	{
		out << "Name -> " << object.productName << endl;
		out << "Price -> " << object.productPrice << endl;
		out << "Number of products -> " << object.productNumber << endl;
		out << "Expiration date -> " << object.expirationDate << endl;
		out << "Product ID -> " << object.productID << endl;

		return out;
	}
	//>-----------------<Del>------------------<
	~Product()
	{
	this->productName.clear();
	this->productNumber.clear();
	this->expirationDate.clear();
	this->productID = NULL;
	this->productPrice = NULL;
	}
};


class productList
{
protected:
	vector<Product> products;
	uint32_t length = size(products);

public:
	
	void addProduct(Product prod)
	{
		this->products.push_back(prod);
	}

	void ShowList()
	{
		for (auto& item : products) {
			cout << item << endl;
			_getch();
		}
	}
};

