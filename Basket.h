#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


class Basket
{
protected:
	vector<Basket> MyBasket;
	uint32_t summBasket;

public:
	
	void addProdToBask(Basket bskt)
	{
		string userFind;
		cout << "Choose products" << endl;
		cout << "Enter the name of the selected product :	";
		getline(cin, userFind);

		auto result = find(products.begin(), products.end(), userFind);

		if (result == products.end())
		{
			cout << "The product is not available!" << endl;
		}
		else
		{
			cout << "Product added to basket" << endl;
			this->MyBasket.push_back(result);
		}
		

	}

	void ShowList()
	{
		for (auto& item : MyBasket) {

			//cout << item << endl;
			copy(MyBasket.begin(), MyBasket.end(), ostream_iterator<Basket>(cout, ""));
			cout << "\t";
		}
		_getch();
	}



};


