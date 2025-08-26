#pragma once

#include <iostream>
#define ARR_SIZE 4

using namespace std;

// 1. ���ø����� ����
template <typename T>
class Vector   
{
private:
	T* arr;  
	int size;
	int cap;

public:
	Vector()
	{
		arr = (T*)malloc( sizeof(T) * ARR_SIZE);
		size = 0;
		cap = ARR_SIZE;
	}

	int getSize()
	{
		return size;
	}

	int getCap()
	{
		return cap;
	}
	
	// �ݺ���
	T* begin()
	{
		return arr;
	}

	T* end()
	{
		return arr[cap];
	}

	void Add_back(T& data)
	{
		if (size != cap) 
		{
			cout << "vector ����" << endl;
			arr[size] = data;
			++size;
		}
		else
		{
			cout << "vector ��á��" << endl;
		}
	}

	T pull_back()
	{
		if (size != 0)
		{
			T temp = arr[size];
			arr[size] = nullptr;
			--size;
			return temp;
		}
		else
		{
			cout << "vector �������" << endl;
		}
	}
};
