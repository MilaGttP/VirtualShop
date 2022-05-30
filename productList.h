#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class ProductList
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
		}
		_getch();
	}


};
