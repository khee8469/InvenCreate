#include "Potion.h"

Potion::Potion(string inputName, int inputPrice) : Item(inputName, inputPrice) {}

void Potion::Use()
{
	cout << "���� ���\n";
}
