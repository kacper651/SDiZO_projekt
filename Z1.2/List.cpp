#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include "List.h"

using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
}

void List::AddFront(int value)
{
	this->insert(0, value);
}

void List::AddBack(int value)
{
	this->insert((this->size()-1), value);
}

void List::AddRandom(int value)
{
	int index = rand() % this->size();

	this->insert(index, value);
}

void List::AddAtPosition(int value, int index)
{
	if(index < (size()))
		ElemList* elem = this->insert(index, value);
	else if (index == 0)
		AddFront(value);
	else if (index == (size()))
		AddBack(value);
}

ElemList* List::insert(int index, int value)
{
	ElemList* new_elem = new ElemList(value);

	if (index == (this->size()-1) && tail != nullptr)
	{
		tail->setNext(new_elem);
		new_elem->setPrev(tail);

		tail = new_elem;
		return new_elem;
	}
	

	ElemList* elem = getElement(index);

	if (elem != nullptr)
		elem->insert(new_elem);

	if (new_elem->getPrev() == nullptr)
		head = new_elem;

	if (new_elem->getNext() == nullptr)
		tail = new_elem;

	return new_elem;
}

void List::destroyList()
{
	ElemList* elem = head;
	ElemList* next_elem = nullptr;

	if (elem != nullptr)
		next_elem = elem->getNext();

	while (elem != nullptr)
	{
		delete elem;

		elem = next_elem;

		if (elem != nullptr)
			next_elem = elem->getNext();
	}

	head = nullptr;
	tail = nullptr;
}

ElemList *List::findValue(int value)
{
	ElemList* elem = head;

	while(elem != nullptr && elem->getData() != value)
	{
		elem = elem->getNext();
	}

	return elem;
}

ElemList *List::getElement(int index)
{
	ElemList* elem = head;
	
	while(index > 0 && elem != nullptr)
	{
		elem = elem->getNext();
		index--;
	}

	return elem;
}

int List::loadFromFile(string FileName)
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

void List::display()
{
	ElemList* elem = head;						

	cout<<"front: ";

	while(elem != nullptr)
	{
		cout<<elem->display()<<" ";
		elem = elem->getNext();
	}

	cout<<"\nback: ";
	elem = tail;

	while(elem != nullptr)
	{
		cout<<elem->display()<<" ";
		elem = elem->getPrev();
	}

	cout<<endl<<endl;
}

void List::deleteElement(int value)
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

int List::size()
{
	ElemList* elem = head;
	int len = 0;

	while (elem != nullptr)
	{
		elem = elem->getNext();
		len++;
	}

	return len;
}

void List::generateList(int size)
{
	for (int i = 0; i < size; i++)
	{
		AddFront(rand() % 100);
	}
}



List::~List()
{
	destroyList();
}
