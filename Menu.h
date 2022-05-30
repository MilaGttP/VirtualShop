#include <iostream>
#include <fstream>
#include <Windows.h> 
#include <string>
#include "Account.h"



using namespace std;


class Print
{
public:
    void PrintClient()
    {
        ClientAccount* client = new ClientAccount();
        FileData <ClientAccount> file("ClientAccount.bin");
        client = file.Load("ClientAccount.bin");
        cout << "Client name: " << client->GetName() << endl;
        cout << "Client surname: " << client->GetSurname() << endl;
        cout << "Club: " << client->GetClub() << endl;
    }
    void PrintWorker()
    {
        CoworkerAccount* coworker = new CoworkerAccount();
        FileData <CoworkerAccount> file("CoworkerAccount.bin");
        coworker = file.Load("CoworkerAccount.bin");
        cout << "Coworker name: " << coworker->GetName() << endl;
        cout << "Coworker surname: " << coworker->GetSurname() << endl;
        cout << "Rang: " << coworker->GetRang() << endl;
    }
};



void run()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string client = "";
    uint32_t tmp;
    Print print;
    cout << "MENU";
    cout << "1 - Worker;" << endl;
    cout << "2 - Client;" << endl;
    cout << "Hide menu item: " << endl;
    cin >> tmp;
    switch (tmp)
    {
    case 1:
    {
        print.PrintWorker();
        break;
    }
    case 2:
    {
        print.PrintClient();
        break;
    }
}
