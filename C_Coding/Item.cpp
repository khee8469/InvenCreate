#include "Item.h"

Item::Item(string inputName, int inputPrice) : name(inputName), price(inputPrice)
{

}

Item::~Item() { }

void Item::Use() {}

string Item::GetName()
{
	return name;
}

int Item::GetPrice() const
{
	return price;
}

void Item::PrintInfo() const
{
	cout << "[�̸�: " << name << ", ����: " << price << "G]" << endl;
}
