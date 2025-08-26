#pragma once
#include "Item.h"

class Potion : public Item
{
public:
	Potion(string inputName , int inputPrice);
	void Use() override;
};