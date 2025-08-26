#include "Inventory.h"

#include "Potion.h"
#include "Armor.h"
#include <iostream>

using namespace std;

int main() 
{
	Inventory<Item> inven(4);

	Potion potion1("체력물약", 400);
	Potion potion2("마법물약", 300);
	Potion potion3("무적물약", 1000);
	Armor armor1("투구", 500);
	Armor armor2("갑옷", 700);
	Armor armor3("장갑", 200);

	inven.AddItem(potion1);
	inven.AddItem(potion2);
	inven.AddItem(potion3);
	inven.AddItem(armor1);
	inven.AddItem(armor2);
	inven.AddItem(armor3);

	//인베
	inven.PrintAllItems();

	//맨뒤 제거
	inven.RemoveLastItem();

	//인베
	inven.PrintAllItems();

	//정렬
	inven.SortItems();

	//인베
	inven.PrintAllItems();

	//대입복사
	Inventory<Item> inven2(4);
	inven2.Assign(inven);

	return 0;
}