#include "Armor.h"

Armor::Armor(string inputName, int inputPrice) : Item(inputName, inputPrice) {}

void Armor::Use()
{
	cout << "장비 사용\n";
}
