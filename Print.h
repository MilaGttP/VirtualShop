
#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h> 
#include <string>
#include "Account.h"
#include "Basket.h"
using namespace std;

class Print
{
public:
    void PrintClient()
    {
        ClientAccount* client = new ClientAccount();
        FileData <ClientAccount> file("ClientAccount.bin");
        client = file.Load("ClientAccount.bin");
        cout << "Name: " << client->GetName() << endl;
        cout << "Surname: " << client->GetSurname() << endl;
        if (client->GetClub() == true)
            cout << "You are a club member!" << endl;
        else
            cout << "You aren`t a club member!" << endl;
        Basket basket;
        basket.SummBasket();
    }
    void PrintWorker()
    {
        CoworkerAccount* coworker = new CoworkerAccount();
        FileData <CoworkerAccount> file("CoworkerAccount.bin");
        coworker = file.Load("CoworkerAccount.bin");
        cout << "Name: " << coworker->GetName() << endl;
        cout << "Surname: " << coworker->GetSurname() << endl;
        cout << "Rang: " << coworker->GetRang() << endl;
    }
};
