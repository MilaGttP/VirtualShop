
#pragma once
#include "Account.h"
#include "Product.h"

class ProductList
{
protected:
	Product* product = new Product();
public:
	ProductList()
	{
		FileData <Product> dataProd;
		this->product = dataProd.Load("ProductList.bin");
	}
	~ProductList() = default;
	void ShowList()
	{
		cout << "\n\tList: " << endl;
		cout << "Id: " << product->GetProductID() << endl
			<< "Name: " << product->GetProductName() << endl
			<< "Expiration date: " << product->GetExpirationDate() << endl
			<< "Price: " << product->GetPrice() << endl;
	}
};