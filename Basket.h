#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


class Basket
{
	ProductList MyBasket;
	uint32_t summBasket;
	
public:
	
	void ShowList()
	{
		for (auto& item : MyBasket.products) {
			copy(MyBasket.products.begin(), MyBasket.products.end(), ostream_iterator<Basket>(cout, ""));
			cout << "\t";
		}
		_getch();
	}

	void addProdToBask(Basket bskt)
	{
		uint32_t userFind;
		cout << "Choose products" << endl;
		cout << "Enter the name of the selected product :	";
		cin >> userFind;
		Product temp = MyBasket.SearchProduct(userFind);
	
		this->MyBasket.products.push_back(temp);
	}

	/*Basket SearchPrice()
	{
		auto item = find(MyBasket.begin(), MyBasket.end(), [=](Basket& p1) { return p1.productPrice == id; });
		auto index = distance(MyBasket.begin(), item);

		return MyBasket[index];
	}*/


	/*void summBask(Basket bskt)
	{
		Basket tmp = MyBasket.SearchPrice();
		summBask += tmp;
	}*/

};


