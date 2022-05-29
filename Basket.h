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
		string result;
		cout << "Choose products" << endl;
		cout << "Enter the name of the selected product :	";
		getline(cin, result);

		find(ProductList.begin(), ProductList.end(), result);

		/*if (t <= 0)
		{
			cout << "Enter a value greater than 0!" << endl;
		}*/

		this->MyBasket.push_back(bskt);

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


