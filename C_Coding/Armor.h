#pragma once
#include "Item.h"

class Armor : public Item
{
public:
	Armor(string inputName, int inputPrice);
	void Use() override;
};
