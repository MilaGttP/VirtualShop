
#pragma once

#include <iostream>
#include <fstream>
#include <conio.h>
#include "FileData.h"

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

	char* GetName() { return this->name; }
	char* GetSurname() { return this->surname; }
	char* GetUsername() { return this->username; }
	char* GetPassword() { return this->password; }

	bool IsExistingUsername(string fileName, char username[])
	{
		Account* acc = new Account();
		fstream fin;
		fin.open(fileName, ios::in | ios::binary);
		while (!fin.eof())
		{
			Account buff;
			fin.read((char*)&buff, sizeof(buff));
			*acc = buff;
			if (strcmp(buff.username, username) == 0)
			{
				return true;
				break;
			}
			else
				return false;
		}
		fin.close();
	}
	bool IsExistingData(string fileName, char username[], char password[])
	{
		Account* acc = new Account();
		fstream fin;
		fin.open(fileName, ios::in | ios::binary);
		while (!fin.eof())
		{
			Account buff;
			fin.read((char*)&buff, sizeof(buff));
			*acc = buff;
			if (strcmp(buff.username, username) == 0 && strcmp(buff.password, password) == 0)
			{
				return true;
				break;
			}
			else
				return false;
		}
		fin.close();
	}
	bool IsExistUsername(char username[])
	{
		string binFileCl = "ClientAccount.bin";
		string binFileCw = "CoworkerAccount.bin";
		if (IsExistingUsername(binFileCl, username) == true || IsExistingUsername(binFileCw, username) == true)
			return true;
		return false;
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
		if (IsExistUsername(this->username))
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
	bool SignIn()
	{
		cin.ignore();
		cout << "Enter your username: ";
		cin.getline(this->username, sizeof(username));
		cout << "Enter your password: ";
		cin.getline(this->password, sizeof(password));

		if (IsExistingData("ClientAccount.bin", this->username, this->password) == true
			|| IsExistingData("CoworkerAccount.bin", this->username, this->password) == true)
			return true;
		else
			return false;
	}
};

class ClientAccount : public Account
{
protected:
	bool isClubMember;
public:
	ClientAccount() { this->isClubMember = false; }
	~ClientAccount() = default;
	bool GetClub() { return this->isClubMember; }
	void CreateClientAcc()
	{
		EnterData();
		uint32_t tmp;
		cout << "Are you a club member?" << endl;
		cout << "\t1 - Yes" << endl;
		cout << "\t2 - No" << endl;
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
		cout << "\t1 - Average coworker" << endl;
		cout << "\t2 - Manager" << endl;
		cout << "\t3 - Member of the management team" << endl;
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
