#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include "List.h"

using namespace std;

template<typename T>
void List<T>::AddFront(T value)
{
	this->insert(0, value);
}



template<typename T>
void List<T>::AddRandom(T value)
{
	int index = rand() % this->size();

	this->insert(index, value);
}

template<typename T>
void List<T>::AddAtPosition(T value, int index)
{
	if(index < (size()))
		ElemList* elem = this->insert(index, value);
	else if (index == 0)
		AddFront(value);
	else if (index == (size()))
		AddBack(value);
}

template<typename T>
ElemList *List<T>::findValue(T value)
{
	ElemList* elem = head;

	while(elem != nullptr && elem->getData() != value)
	{
		elem = elem->getNext();
	}

	return elem;
}

template<typename T>
int List<T>::loadFromFile(string FileName)
{
	destroyList();

	ifstream Plik(FileName);
	int size, tmp;

	if (!Plik.is_open())
	{
		cout << "nie ma pliku\n";
		return 1;
	}
		
	Plik >> size;

	for (int i = 0; i < size; i++)
	{
		Plik >> tmp;
		this->AddBack(tmp);
	}

	return 0;
}



template<typename T>
void List<T>::deleteElement(T value)
{
	ElemList* elem = findValue(value);

	if (elem != nullptr)
	{
		if (elem == head)
			head = elem->getNext();

		if (elem == tail)
			tail = elem->getPrev();

		elem->remove();

		delete elem;
	}
}

template<typename T>
void List<T>::generateList(int size)
{
	for (int i = 0; i < size; i++)
	{
		AddFront(rand() % 100);
	}
}
