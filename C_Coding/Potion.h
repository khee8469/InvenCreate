#pragma once
#include "Item.h"

class Potion : public Item
{
public:
	Potion(string inputName , int inputPrice) : Item(inputName, inputPrice) {};
	void Use() override
	{
		cout << "���� ���\n";
	}
};