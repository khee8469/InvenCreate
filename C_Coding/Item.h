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
	Item(string inputName = "기본이름", int inputPrice = 0);
	~Item();

	virtual void Use();

	string GetName();
	int GetPrice() const;
	void PrintInfo() const;
};