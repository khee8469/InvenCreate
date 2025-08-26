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
		{ cout << "�κ��丮 ����� ���� ������\n"; }
		pItems_ = new T[capacity_]; // �޸� 1 �Ҵ�
		//pItems_ = (T*)malloc(sizeof(T) * capacity_);
	}
	Inventory(const Inventory<T>& other) // ���������
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		cout << "�κ��丮 ���� �Ϸ�" << endl;
	} 
	void Assign(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		cout << "�κ��丮 ���� �Ϸ�" << endl;
	}

	~Inventory()
	{
		delete[] pItems_; // �޸� 1 ����
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
			cout << "�κ��丮�� �߰�\n";
			pItems_[size_] = item;
			++size_;
		}
		else // ��á�� ��
		{
			cout << "�κ��丮 ũ�� ���� �� �߰�\n";
			capacity_ *= 2;
			T* temp_ptr = new T[capacity_];
			for (int i = 0; i < size_; ++i)
			{
				temp_ptr[i] = pItems_[i];
			}
			temp_ptr[size_] = item;
			++size_;

			// ���� �ּ� ����
			delete[] pItems_; 
			pItems_ = nullptr;
			// �� �ּ� ����
			pItems_ = temp_ptr;
		}
	}

	void RemoveLastItem()
	{
		if (size_ != 0)
		{
			--size_;
			cout << "�κ��丮�� �� �� ����.\n";
		}
		else
		{
			cout << "�κ��丮�� ����ֽ��ϴ�.\n";
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
			capacity_ = newCapacity; // �� ū ������ ����
			T* temp_ptr = new T[capacity_];
			for (int i = 0; i < size_; ++i)
			{
				temp_ptr[i] = pItems_[i];
			}

			// ���� �ּ� ����
			delete[] pItems_;
			pItems_ = nullptr;
			// �� �ּ� ����
			pItems_ = temp_ptr;
		}
		else
		{
			capacity_ = newCapacity; // �� ���� ������ ����
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
		cout << "�κ��丮�� ���ݼ� ����.\n";
	}

	static bool compareItemsByPrice(const Item& a, const Item& b)
	{
		return a.GetPrice() < b.GetPrice();
	}
};

