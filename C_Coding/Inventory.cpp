#include "Inventory.h"
#include "Item.h"

template class Inventory<Item>;  // �̰� ����

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
	{ cout << "�κ��丮 ����� ���� ������\n"; }
	pItems_ = new T[capacity_]; // �޸� 1 �Ҵ�
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
	cout << "�κ��丮 ���� �Ϸ�" << endl;
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
	cout << "�κ��丮 ���� �Ϸ�" << endl;
}

template <typename T>
Inventory<T>::~Inventory()
{
	delete[] pItems_; // �޸� 1 ����
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

template <typename T>
void Inventory<T>::RemoveLastItem()
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
	cout << "�κ��丮�� ���ݼ� ����.\n";
}
