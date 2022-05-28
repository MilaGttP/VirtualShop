
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include<vector>
#include<Windows.h>

using namespace std;

class Worker
{
private:
    string name;
    string surname;
    uint32_t rang;
    uint32_t age;
public:
  

    Worker()
    {
        this->name = "";
        this->surname = "";
        this->rang = 0;
        this->age = 0;
    }

    Worker(string name, string surname, uint32_t rang, uint32_t age) : Worker()
    {
        this->name = name;
        this->surname = surname;
        this->age = 0;
        this->rang = 0;
    }

    string GetName() {
        return this->name;
    }

    uint32_t GetRang() {
        return this->rang;
    }

    friend istream& operator >> (istream& in, Worker object)
    {
        cout << "Name: ";
        in >> object.name;
        cout << "Surname: ";
        in >> object.surname;
        cout << "Age: ";
        in >> object.age;
        cout << "Rang: ";
        in >> object.rang;
    
        return in;
    }

    friend ostream& operator << (ostream& out, Worker object)
    {
        out << "Name: " << object.name << endl;
        out << "Surname: " << object.surname << endl;
        out << "Age: " << object.age << endl;
        out << "Rang: " << object.rang << endl;
        return out;
    }

    ~Worker()
    {
        this->name.clear();
        this->surname.clear();
        this->age = 0;
        this->rang = 0;
    }
};

class Team
{
public:
    vector<Worker> workers;
    size_t length = 0;
    int num = 0;

    void AddWorker(Worker worker)
    {
        this->workers.push_back(worker);
    }

    void Show()
    {
        for (auto& item : workers)
        {
            cout << item << endl;
        }
    }

    void SortByRang() {
        sort(workers.begin(), workers.end(), [](Worker w1, Worker w2) { return w1.GetRang() < w2.GetRang(); });
        system("pause");
    }

    void Find()
    {
        
        system("pause");
    }

    void DeleteWorker()
    {
        string name;
        cin.ignore();
        cout << "Enter worker for delete: " << endl;
        cin >> name;
        auto iter = std::find_if(workers.begin(), workers.end(),
            [=](Worker& s) { return s.GetName() == name; } );
        if (iter != workers.end())
            workers.erase(iter);
        else
            cout << "Object not found!.\n";
    }
};
