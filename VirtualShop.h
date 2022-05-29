
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include<vector>
#include<Windows.h>

using namespace std;
using std::cout;

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
        this->name = " ";
        this->surname = " ";
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

    friend istream& operator >> (istream& in, Worker &object)
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
