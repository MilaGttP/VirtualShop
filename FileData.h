
#pragma once

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <string.h>
using namespace std;

template<typename T>
class FileData
{
protected:
	string binFile;
	fstream stream;
public:
	FileData() = default;
	FileData(string fileName) { this->binFile = fileName; }
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
	T* Load(string fileName)
	{
		try
		{
			T* object = new T;
			this->stream.open((fileName), ios::in | ios::binary);
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