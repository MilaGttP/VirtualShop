#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class ProductList
{
public:
	
	vector<Product*> products;

	void addProduct(Product prod)
	{
		this->products.push_back(&prod);
	}

	void ShowList()
	{
		for (auto& item : products) {

			cout << item << endl;
		}
		_getch();
	}

	Product* SearchProduct(uint32_t id)
	{
		auto item = find(products.begin(), products.end(), [](Product& p1, uint32_t id) { return p1.GetProductID() == id; });

		if (item == products.end())
		{
			cout << "The product is not available!" << endl;
		}
		else
		{
			cout << "Product added to basket" << endl;
		}
		return (Product*)&item;

	}

};
