
#pragma once

#include <iostream>
#include "Account.h"

class GreetWork
{
public:
    ClientAccount* client = new ClientAccount();
    CoworkerAccount* worker = new CoworkerAccount();

    GreetWork()
    {
        FileData <ClientAccount> fileClient;
        this->client = fileClient.Load("ClientAccount.bin");
        FileData <CoworkerAccount> fileWorker;
        this->worker = fileWorker.Load("CoworkerAccount.bin");
    }
    void PrintGreetClient()
    {
        Account acc;
        if (client->GetClub() == true)
            cout << "Hello, " << client->GetName() << " " << client->GetSurname() << ", (VIP)!" << endl;
        else if (client->GetClub() == false)
            cout << "Hello, " << client->GetName() << " " << client->GetSurname() << "!" << endl;
    }
    void PrintGreetWorker()
    {
        Account acc;
        cout << "Hello, " << worker->GetName() << " " << worker->GetSurname() << " ";
        if (worker->GetRang() == 1)
            cout << "(coworker)!" << endl;
        else if (worker->GetRang() == 2)
            cout << "(manager)!" << endl;
        else if (worker->GetRang() == 3)
            cout << "(team`s member)!" << endl;
    }
    void PrintAllClients()
    {
        cout << "Name: " << client->GetName() << endl
            << "Surname: " << client->GetSurname() << endl;
    }
    void PrintClubMembers()
    {
        if (client->GetClub() == true)
        {
            cout << "Name: " << client->GetName() << endl
                << "Surname: " << client->GetSurname() << endl;
        }
        else
            cerr << "There isn`t clients who are club members!" << endl;
    }
};
#pragma once
