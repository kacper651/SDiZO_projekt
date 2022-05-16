#include "Heap.h"
#include <math.h>
#include <iostream>
#include <fstream>

Heap::Heap(int size)
{
	init(size);
}

void Heap::insert(int* value)
{
	if (isFull())
	{
		this->resize(this->size + 10);
	}

	arr[len] = value; //przypisanie nowej wartości na koniec tablicy
	minHeapifyUp(len); //uporządkowanie (przwrócenie własności) kopca
	len++; //zwiększenie licznika elementów
}

void Heap::resize(int newSize)
{
	int** tmp_arr = new int*[newSize];

	for (int i=0; this->len > i; i++)
	{
		tmp_arr[i] = arr[i];
	}

	delete[] arr;

	arr = tmp_arr;
	this->size = newSize;
}

void Heap::swapElements(int index1, int index2)
{
	if (index1 == index2)
		return;

	int* tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
}

void Heap::minHeapifyUp(int index)
{
	int parentIndex = getParent(index);

	while(isValidIndex(parentIndex) && *(arr[index]) < *(arr[parentIndex]))
	{
		swapElements(index, parentIndex);
		index = parentIndex;
		parentIndex = getParent(index);
	}
}

void Heap::minHeapifyDown(int parentIndex)
{
	int leftChildIndex = getLeftChild(parentIndex);
	int rightChildIndex;
	int smallerValueIndex;

	while(isValidIndex(leftChildIndex))
	{
		smallerValueIndex = leftChildIndex;

		rightChildIndex = getRightChild(parentIndex);

		if (isValidIndex(rightChildIndex) && *(arr[rightChildIndex]) < *(arr[leftChildIndex]))
		{
			smallerValueIndex = rightChildIndex;
		}

		if (*(arr[smallerValueIndex]) < *(arr[parentIndex]))
		{
			swapElements(smallerValueIndex, parentIndex);
			parentIndex = smallerValueIndex;
			leftChildIndex = getLeftChild(parentIndex);
		}
		else
			break;
	}
}

int Heap::getLeftChild(int parentIndex)
{
	return (2 * parentIndex) + 1;
}

int Heap::getRightChild(int parentIndex)
{

	return (2 * parentIndex) + 2;
}

int Heap::getParent(int childIndex)
{

	return floor((childIndex - 1) / 2);
}

bool Heap::isFull()
{
	return len >= size;
}

bool Heap::isValidIndex(int index)
{
	return (index >= 0 && index < len);
}

void Heap::display()
{
	cout<<"---DISPLAY---"<<endl;
	for (int i=0; len>i; i++)
	{
		cout<<i<<". "<<arr[i]<<"\nval: "<<*(arr[i])<<endl;
	}

	cout<<endl<<endl;
}

//void Heap::loadFromFile(string FileName)
//{
//	destroyHeap();
//
//	ifstream Plik(FileName);
//	int cnt_size, tmp;
//
//	if (!Plik.good())
//	{
//		cout << "nie ma pliku\n";
//		return;
//	}
//
//	Plik >> cnt_size;
//	init(cnt_size + 10);
//
//	for (int i = 0; i < cnt_size; i++)
//	{
//		Plik >> tmp;
//		this->insert(tmp);
//	}
//}

void Heap::deleteElement(int index)
{
	if (!isValidIndex(index))
		return;
	swapElements(index, len-1);
	len--;
	minHeapifyDown(len-1);
	minHeapifyUp(len-1);
}

void Heap::destroyHeap()
{
	if (arr != nullptr)
		delete[] arr;

	arr = nullptr;
	len = 0;
	size = 0;
}

void Heap::init(int size)
{
	this->arr = new int*[size];
	this->size = size;
	this->len = 0;
}

Heap::~Heap()
{
	destroyHeap();
}

//void Heap::generateHeap(int size)
//{
//	destroyHeap();
//	init(size);
//
//	for (int i=0; size>i; i++)
//	{
//		insert(rand() % 100);
//	}
//}

int Heap::getLength()
{
	return this->len;
}

int* Heap::getTop()
{
	return arr[0];
}

void Heap::clear()
{
	this->len = 0;
}

//int* Heap::getElement(int index)
//{
//	if(isValidIndex(index))
//		return this->arr[index];
//
//	return nullptr;
//}

//void Heap::setElement(int index, int* newValue)
//{
//	if (isValidIndex(index))
//		arr[index] = newValue;
//}

bool Heap::isValueInHeap(int* value)
{
	for (int i=0; len>i; i++)
	{
		if (arr[i] == value)
			return true;
	}

	return false;
}
