
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

class Account
{
protected:
	char name[20];
	char surname[20];
	char username[20];
	char password[20];
	
public:
	Account() = default;
	~Account() = default;
	Account(string name, string surname, string username, string password)
	{
		strcpy(this->name, name.c_str());
		strcpy(this->surname, surname.c_str());
		strcpy(this->username, username.c_str());
		strcpy(this->password, password.c_str());
	}
	char* GetName() { return this->name; }
	char* GetSurname() { return this->surname; }
	char* GetUsername() { return this->username; }
	char* GetPassword() { return this->password; }

	bool IsExist(char name[], char surname[], char username[], char password[])
	{

	}
	void EnterData()
	{
		cin.ignore();
		cout << "Enter your name: ";
		cin.getline(this->name, sizeof(name));
		if (strpbrk(this->name, "0123456789"))
		{
			cerr << "Your name includes digits!" << endl;
			exit(0);
		}
		cout << "Enter your surname: ";
		cin.getline(this->surname, sizeof(surname));
		if (strpbrk(this->surname, "0123456789"))
		{
			cerr << "Your surname includes digits!" << endl;
			exit(0);
		}
		cout << "Enter your user name: ";
		cin.getline(this->username, sizeof(username));
		if (IsExist(this->name, this->surname, this->username, this->password) == true)
		{
			cerr << "This username has already exists!" << endl;
			exit(0);
		}
		cout << "Enter your password: ";
		cin.getline(this->password, sizeof(password));
		if (strlen(this->password) < 6)
		{
			cerr << "Your password is less than 6 symbols!" << endl;
			exit(0);
		}
	}
	void SingIn()
	{
		EnterData();
		if (IsExist(this->name, this->surname, this->username, this->password) == true)
			cout << "Success!" << endl;
		else
			cerr << "You cannot sign in not existing account!" << endl;
	}
};

class ClientAccount : public Account
{
protected:
	bool isClubMember;
public:
	ClientAccount() { this->isClubMember = false; }
	~ClientAccount() = default;
	void CreateClientAcc()
	{
		EnterData();
		uint32_t tmp;
		cout << "Are you a club member?" << endl;
		cout << "1 - Yes" << endl;
		cout << "2 - No" << endl;
		cin >> tmp;
		switch (tmp)
		{
		case 1:
		{
			this->isClubMember = true;
		}break;
		case 2:
		{
			this->isClubMember = false;
		}break;
		}
	}
	friend ostream& operator << (ostream& out, ClientAccount*& object)
	{
		out << "Name: " << object->name << endl;
		out << "Surname: " << object->surname << endl;
		out << "Username: " << object->username << endl;
		out << "Password: " << object->password << endl;
		if (object->isClubMember == true)
			out << "Is a club member" << endl;
		else if (object->isClubMember == false)
			out << "Isn`t a club member" << endl;
		return out;
	}
};

class CoworkerAccount : public Account
{
protected:
	uint32_t rang;
public:
	CoworkerAccount() { this->rang = 0; }
	~CoworkerAccount() = default;
	uint32_t GetRang() { return this->rang; }
	void CreateCoworkerAcc()
	{
		EnterData();
		uint32_t tmp;
		cout << "Which rang is yours?" << endl;
		cout << "1 - Average coworker" << endl;
		cout << "2 - Manager" << endl;
		cout << "3 - Member of the management team" << endl;
		cout << "Enter wanted case: ";
		cin >> tmp;
		switch (tmp)
		{
		case 1:
		{
			this->rang = 1;
		}break;
		case 2:
		{
			this->rang = 2;
		}break;
		case 3:
		{
			this->rang = 3;
		}break;
		}
	}
	friend ostream& operator << (ostream& out, CoworkerAccount*& object)
	{
		out << "Name: " << object->name << endl;
		out << "Surname: " << object->surname << endl;
		out << "Username: " << object->username << endl;
		out << "Password: " << object->password << endl;
		if (object->rang == 1)
			out << "Average coworker" << endl;
		else if (object->rang == 2)
			out << "Manager" << endl;
		else if (object->rang == 3)
			out << "Memeber of the management team" << endl;
		return out;
	}
};

template<typename T>
class FileData
{
protected:
	string binFile = "accountData.bin";
	fstream stream;
public:
	FileData() = default;
	~FileData() = default;
	bool Save(T* object)
	{
		try 
		{
			this->stream.open(binFile, ios::app | ios::binary);
			if (!stream.is_open())
				throw;
			else 
			{
				T buf = *object;
				stream.write((char*)&buf, sizeof(buf));
				stream.close();
			}
			return true;
		}
		catch (const ifstream::failure& e)
		{
			cout << e.what() << endl;
			return false;
		}
	}
	T* Load()
	{
		try 
		{
			T* object = new T;
			this->stream.open((binFile), ios::in | ios::binary);
			if (!stream.is_open())
				throw;
			else 
			{
				T buf;
				stream.read((char*)&buf, sizeof(buf));
				*object = buf;
				stream.close();
			}
			return object;
		}
		catch (const ifstream::failure& e)
		{
			cout << e.what() << endl;
			return nullptr;
		}
	}
};


void Run()
{
	uint32_t tmp, temp;
	Account acc;
	cout << "Hello! Menu: " << endl;
	cout << "\t1 - Create an account" << endl;
	cout << "\t2 - Sing in existing account" << endl;
	cout << "\t3 - Exit" << endl;
	cout << "Enter wanted case: "; cin >> tmp;
	switch (tmp)
	{
	case 1:
	{
		FileData <ClientAccount> dataClient;
		FileData <CoworkerAccount> dataCoworker;
		ClientAccount* clientAcc = new ClientAccount();
		CoworkerAccount* coworkerAcc = new CoworkerAccount();
		cout << "\t1 - Create a client account" << endl;
		cout << "\t2 - Create a coworker account" << endl;
		cout << "Enter: "; cin >> temp;
		switch (temp)
		{
		case 1:
		{
			clientAcc->CreateClientAcc();
			dataClient.Save(clientAcc);
			cout << endl;
		}break;
		case 2:
		{
			coworkerAcc->CreateCoworkerAcc();
			dataCoworker.Save(coworkerAcc);
			cout << endl;
		}break;
		}
		break;
	}
	case 2:
	{
		acc.SingIn();
		break;
	}
	case 3:
	{
		exit(0);
		break;
	}
	}
}

int main()
{
	Run();
	return 0;
}