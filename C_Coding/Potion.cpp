#include "Potion.h"

Potion::Potion(string inputName, int inputPrice) : Item(inputName, inputPrice) {}

void Potion::Use()
{
	cout << "물약 사용\n";
}
