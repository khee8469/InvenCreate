#pragma once

#include <string>
#include <iostream>
using namespace std;

class Item
{
private:
	string name;
	int price;

public:
	//Item() { name = "�⺻�̸�", price = 0; }
	Item(string inputName = "�⺻�̸�", int inputPrice = 0) : name(inputName), price(inputPrice) {}
	~Item() { }
	virtual void Use() {};

	string GetName()
	{
		return name;
	}

	int GetPrice() const
	{
		return price;
	}

	void PrintInfo() const 
	{
		cout << "[�̸�: " << name << ", ����: " << price << "G]" << endl;
	}
};