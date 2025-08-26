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
	//Item() { name = "기본이름", price = 0; }
	Item(string inputName = "기본이름", int inputPrice = 0) : name(inputName), price(inputPrice) {}
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
		cout << "[이름: " << name << ", 가격: " << price << "G]" << endl;
	}
};