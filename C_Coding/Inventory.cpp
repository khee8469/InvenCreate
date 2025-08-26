#include "Inventory.h"
#include "Item.h"

template class Inventory<Item>;  // 이건 뭐여

template <typename T>
Inventory<T>::Inventory(int capacity)
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

template <typename T>
Inventory<T>::Inventory(const Inventory<T>& other)
{
	capacity_ = other.capacity_;
	size_ = other.size_;
	pItems_ = new T[capacity_];
	for (int i = 0; i < size_; ++i) {
		pItems_[i] = other.pItems_[i];
	}
	cout << "인벤토리 복사 완료" << endl;
}

template <typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
	capacity_ = other.capacity_;
	size_ = other.size_;
	pItems_ = new T[capacity_];
	for (int i = 0; i < size_; ++i) {
		pItems_[i] = other.pItems_[i];
	}
	cout << "인벤토리 대입 완료" << endl;
}

template <typename T>
Inventory<T>::~Inventory()
{
	delete[] pItems_; // 메모리 1 해제
	pItems_ = nullptr;
}

template <typename T>
int Inventory<T>::GetSize() const
{
	return size_;
}

template <typename T>
int Inventory<T>::GetCapacity() const
{
	return capacity_;
}

template <typename T>
void Inventory<T>::AddItem(const T& item)
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

template <typename T>
void Inventory<T>::RemoveLastItem()
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

template <typename T>
void Inventory<T>::PrintAllItems() const
{
	for (int i = 0; i < size_; ++i)
	{
		pItems_[i].PrintInfo();
	}
}

template <typename T>
void Inventory<T>::Resize(int newCapacity)
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

template <typename T>
T* Inventory<T>::begin()
{
	return &pItems_[0];
}

template <typename T>
T* Inventory<T>::end()
{
	return &pItems_[size_];
}

template <typename T>
void Inventory<T>::SortItems()
{
	sort(begin(), begin() + size_, compareItemsByPrice);
	cout << "인벤토리가 가격순 정렬.\n";
}
