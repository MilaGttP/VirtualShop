
#pragma once
#include <iostream>
#include "Product.h"
#include "Account.h"

FileData <Product> dataBasket("Basket.bin");

class Basket
{
    int summBasket;
    int tmp;
    Product* prod = new Product();
public:
    Basket() = default;
    ~Basket() = default;
    void SearchById()
    {
        FileData <Product> dataProd("ProductList.bin");
        this->prod = dataProd.Load("ProductList.bin");
        int IdChoice;
        cout << "Enter the number of the desired ID: ";
        cin >> IdChoice;
        if (IdChoice == prod->GetProductID())
            dataBasket.Save(prod);
    }
    void SummBasket()
    {
        this->prod = dataBasket.Load("Basket.bin");
        this->tmp = prod->GetPrice();
        this->summBasket += tmp;
        cout << "The amount of purchases -> " << this->summBasket << endl;
    }
    void SumBasketWithDisc()
    {
        uint32_t res = 0;
        this->prod = dataBasket.Load("Basket.bin");
        CoworkerAccount* worker = new CoworkerAccount();
        FileData <CoworkerAccount> fileWorker;
        worker = fileWorker.Load("CoworkerAccount.bin");
        this->tmp = prod->GetPrice();
        if (worker->GetRang() == 1)
            res = tmp - tmp * 0.1;
        else if (worker->GetRang() == 2)
            res = tmp - tmp * 0.2;
        else if (worker->GetRang() == 3)
            res = tmp - tmp * 0.3;
        this->summBasket = res;
        cout << "The amount of purchases with discount -> " << this->summBasket << endl;
    }
};
