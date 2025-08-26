#pragma once

#include <iostream>
#define ARR_SIZE 4

using namespace std;

// 1. 템플릿으로 구현
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
	
	// 반복자
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
			cout << "vector 넣음" << endl;
			arr[size] = data;
			++size;
		}
		else
		{
			cout << "vector 꽉찼음" << endl;
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
			cout << "vector 비어있음" << endl;
		}
	}
};
