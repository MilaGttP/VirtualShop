
#include <iostream>
#include <cstdio>
#include "Account.h"

using std::cout;
using std::endl;

class GreetWork {
  public:
      vector<Worker> workers;
      string greetings;
      vector<Product*> products;
      vector<ClientAccount*> clients;
      vector<ClientPage> clientPage;
      size_t length = 0;

      GreetWork()
      {
          this->greetings = " ";
      }

      GreetWork(string name, string surname, uint32_t rang) : GreetWork()
      {
          Account acc;

          if (acc.SignIn() == 2) {
              ClientAccount* client = new ClientAccount();
              FileData <ClientAccount> file("ClientAccount.bin");
              client = file.Load("ClientAccount.bin");
              cout << "Client name: " << client->GetName() << endl;
              cout << "Client surname: " << client->GetSurname() << endl;
              cout << "Club: " << client->GetClub() << endl;
          }
      }

      void PrintAllClients()
      {
          if (clients.empty())
          {
              cout << "Clients empty!" << endl;
          }
          else
          {
              for (auto item : clients)
              {
                  cout << item << endl;
              }
          }
      }

      void PrintClubMembers()
      {
          if (clients.empty())
          {
              cout << "Clients members empty!" << endl;
          }
          else 
          {
              for (auto &item : clients)
              {
                  if (item->GetClub())
                  {
                      cout << item << endl;
                  }
              }
          }
      }

      void PrintOnePurch() 
      {
          if (clientPage.empty())
          {
              cout << "The list of clients who have made at least one purchase is empty!" << endl;
          }
          else
          {
              for (auto& item : clients)
              {
                  if (item->numberPurch())
                  {
                      cout << item << endl;
                  }
              }
          }
      }

      void PrintHighPurch()
      {
          if (clients.empty())
          {
              cout << "You don't have any clients yet!" << endl;
          }
          else
          {
              for (auto& item : clients)
              {
                  if (item->highSummPurch())
                  {
                      cout << item << endl;
                  }
              }
          }
      }

      void AddNewProd(Product* product)
      {
          this->products.push_back(product);
      }
};
