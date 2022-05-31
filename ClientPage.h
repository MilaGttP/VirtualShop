
#include <iostream>

class ClientPage
{  
private:
    string name;
    string surname;
    string clubMember;
    int numberPurch;
    uint32_t summPurch;
    uint32_t highSummPurch;
    string username;
    string password;
public:


    ClientPage()
    {
        this->name = " ";
        this->surname = " ";
        this->clubMember = " ";
        this->numberPurch = 0;
        this->summPurch = 0;
        this->highSummPurch = 0;
        this->username = " ";
        this->password = " ";
    }

    ClientPage(string name, string surname, string clubMember, int numberPurch, uint32_t summPurch) : ClientPage()
    {
        this->name = name;
        this->surname = surname;
        this->clubMember = clubMember;
        this->numberPurch = 0;
        this->summPurch = 0;
        this->highSummPurch = 0;
        this->username = username;
        this->password = password;
    }

    string GetName() {
        return this->name;
    }

    string GetClubMember() {
        return this->clubMember;
    }

    int GetNumberPurch() {
        return this->numberPurch;
    }

    uint32_t GetSummPurch() {
        return this->summPurch;
    }
   
    uint32_t GetHighSummPurch() {
        return this->highSummPurch;
    }

    string GetUsername() {
        return this->username;
    }

    string GetPassword() {
        return this->password;
    }

    friend istream& operator >> (istream& in, ClientPage& object)
    {
        cout << "Name: ";
        in >> object.name;
        cout << "Surname: ";
        in >> object.surname;
        cout << "Club member: ";
        in >> object.clubMember;
        cout << "Number of purchases: ";
        in >> object.numberPurch;
        cout << "Highest purchase amount: ";
        in >> object.highSummPurch;
        cout << "Username: ";
        in >> object.username;
        cout << "Password: ";
        in >> object.password;

        return in;
    }

    friend ostream& operator << (ostream& out, ClientPage object)
    {
        out << "Name: " << object.name << endl;
        out << "Surname: " << object.surname << endl;
        out << "Club member: " << object.clubMember << endl;
        out << "Number of purchases: " << object.numberPurch << endl;
        out << "Highest purchase amount: " << object.highSummPurch << endl;
        out << "Username: " << object.username << endl;
        out << "Password: " << object.password << endl;

        return out;
    }

    ~ClientPage()
    {
        this->name.clear();
        this->surname.clear();
        this->clubMember.clear();
        this->numberPurch = 0;
        this->summPurch = 0;
        this->highSummPurch = 0;
        this->username.clear();
        this->password.clear();
    }
};