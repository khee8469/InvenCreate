#pragma once

#include <iostream>
#include <algorithm>
#include "Item.h"
using namespace std;


// 1. 템플릿으로 구현
template <typename T>
class Inventory
{
private:
	T* pItems_; // 자료형 설정 x , 메모리할당 x  , 메모리에 데이터도 뭐가잇는지 알수없음
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
	Inventory(const Inventory<T>& other); // 복사생성자
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
