
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <string.h>
using namespace std;

class Account
{
protected:
	string name;
	string surname;
	string username;
	string password;
	
public:
	Account()
	{
		this->name = " ";
		this->surname = " ";
		this->username = " ";
		this->password = " ";
	}
	Account(string name, string surname, string username, string password)
	{
		this->name = name; this->surname = surname;
		this->username = username; this->password = password;
	}
	string GetName() { return this->name; }
	string GetSurname() { return this->surname; }
	string GetUsername() { return this->username; }
	string GetPass() { return this->password; }
	
	void EnterData()
	{
		//check (without numbers?)
		cin.ignore();
		cout << "Enter your name: ";
		getline(cin, name);
		//check (without numbers?)
		cout << "Enter your surname: ";
		getline(cin, surname);
		//check whether it already exist
		cout << "Enter your user name: ";
		getline(cin, username);
		//check if it not less than 6 symbols
		cout << "Enter your password: ";
		getline(cin, password);
	}
	void SingIn()
	{

	}
};

class ClientAccount : public Account
{
protected:
	bool isClubMember;
public:
	ClientAccount() { this->isClubMember = false; }
	ClientAccount(string name, string surname, string username, string password, bool isClubMember)
		: Account(name, surname, username, password)
	{
		this->isClubMember = false;
	}
	//~ClientAccount() = default;
	bool GetClub() { return this->isClubMember; }
	void CreateClientAcc()
	{
		EnterData();
		getline(cin, password);
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
		getline(cin, password);
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
			this->stream.open(binFile, ios::out | ios::binary);
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
			{
				throw;
			}
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
	FileData <ClientAccount> dataClient;
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
		ClientAccount* ca1 = new ClientAccount();
		ClientAccount* ca = new ClientAccount("Ivan", "Fill", "JK", "1345", true);
		CoworkerAccount cw;
		cout << "\t1 - Create a client account" << endl;
		cout << "\t2 - Create a coworker account" << endl;
		cout << "Enter: "; cin >> temp;
		switch (temp)
		{
		case 1:
		{
			//ca1->CreateClientAcc();
			//dataClient.Save(ca);
			ca = dataClient.Load();
		}break;
		case 2:
		{
			cw.CreateCoworkerAcc();
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