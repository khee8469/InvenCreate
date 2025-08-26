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
	Inventory(int capacity = 10)   
	{
		if (capacity < 0)
		{
			capacity_ = 1;
		}
		else
		{
			capacity_ = capacity;
		}
		size_ = 0;
		{ cout << "인벤토리 사용자 정의 생성자\n"; }
		pItems_ = new T[capacity_]; // 메모리 1 할당
		//pItems_ = (T*)malloc(sizeof(T) * capacity_);
	}
	Inventory(const Inventory<T>& other) // 복사생성자
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 복사 완료" << endl;
	} 
	void Assign(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 대입 완료" << endl;
	}

	~Inventory()
	{
		delete[] pItems_; // 메모리 1 해제
		pItems_ = nullptr;
	}

	int GetSize() const
	{
		return size_;
	}

	int GetCapacity() const
	{
		return capacity_;
	}

	void AddItem(const T& item)
	{
		if (size_ < capacity_)
		{
			cout << "인벤토리에 추가\n";
			pItems_[size_] = item;
			++size_;
		}
		else // 꽉찼을 때
		{
			cout << "인벤토리 크기 증가 후 추가\n";
			capacity_ *= 2;
			T* temp_ptr = new T[capacity_];
			for (int i = 0; i < size_; ++i)
			{
				temp_ptr[i] = pItems_[i];
			}
			temp_ptr[size_] = item;
			++size_;

			// 옛날 주소 해제
			delete[] pItems_; 
			pItems_ = nullptr;
			// 새 주소 연결
			pItems_ = temp_ptr;
		}
	}

	void RemoveLastItem()
	{
		if (size_ != 0)
		{
			--size_;
			cout << "인벤토리가 맨 뒤 제거.\n";
		}
		else
		{
			cout << "인벤토리가 비어있습니다.\n";
		}
	}

	void PrintAllItems() const
	{
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i].PrintInfo();
		}
	}

	void Resize(int newCapacity)
	{
		if (capacity_ < newCapacity)
		{
			capacity_ = newCapacity; // 더 큰 값으로 변경
			T* temp_ptr = new T[capacity_];
			for (int i = 0; i < size_; ++i)
			{
				temp_ptr[i] = pItems_[i];
			}

			// 옛날 주소 해제
			delete[] pItems_;
			pItems_ = nullptr;
			// 새 주소 연결
			pItems_ = temp_ptr;
		}
		else
		{
			capacity_ = newCapacity; // 더 작은 값으로 변경
			if (capacity_ < size_)
			{
				size_ = capacity_;
			}
		}
	}

	T* begin()
	{
		return &pItems_[0];
	}

	T* end()
	{
		return &pItems_[capacity_];
	}

	void SortItems()
	{
		sort(begin(), begin() + size_, compareItemsByPrice);
		cout << "인벤토리가 가격순 정렬.\n";
	}

	static bool compareItemsByPrice(const Item& a, const Item& b)
	{
		return a.GetPrice() < b.GetPrice();
	}
};

