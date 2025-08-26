#pragma once

#include <iostream>
#include <algorithm>
#include "Item.h"
using namespace std;


// 1. ���ø����� ����
template <typename T>
class Inventory
{
private:
	T* pItems_; // �ڷ��� ���� x , �޸��Ҵ� x  , �޸𸮿� �����͵� �����մ��� �˼�����
	int capacity_;
	int size_;

public:
	/*Inventory() 
	{
		capacity_ = 10;
		size_ = 0;
		pItems_ = new T[capacity_];
	}*/
	Inventory(int capacity = 10);
	Inventory(const Inventory<T>& other); // ���������
	void Assign(const Inventory<T>& other);
	~Inventory();

	int GetSize() const;
	int GetCapacity() const;

	void AddItem(const T& item);
	void RemoveLastItem();
	void PrintAllItems() const;
	void Resize(int newCapacity);

	T* begin();
	T* end();

	void SortItems();

	static bool compareItemsByPrice(const Item& a, const Item& b)
	{
		return a.GetPrice() < b.GetPrice();
	}
};
