#pragma once
#include "Item.h"

class Armor : public Item
{
public:
	Armor(string inputName, int inputPrice) : Item(inputName, inputPrice) {};
	void Use() override
	{
		cout << "장비 사용\n";
	}
};
