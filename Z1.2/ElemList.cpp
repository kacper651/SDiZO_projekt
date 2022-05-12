#include "ElemList.h"

ElemList::ElemList(int data)
{
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

int ElemList::getData()
{
	return this->data;
}

void ElemList::setData(int data)
{
	this->data = data;
}

ElemList *ElemList::getPrev()
{
	return this->prev;
}

ElemList *ElemList::getNext()
{
	return this->next;
}

void ElemList::setPrev(ElemList* prev)
{
	this->prev = prev;
}

void ElemList::setNext(ElemList* next)
{
	this->next = next;
}

void ElemList::insert(ElemList* elem)
{
	elem->setNext(this);
	elem->setPrev(this->getPrev());

	if (this->getPrev() != nullptr)
		this->getPrev()->setNext(elem);

	this->setPrev(elem);
}

int ElemList::display()
{
	return data;
}

void ElemList::remove()
{
	if (this->getNext() != nullptr)
		this->getNext()->setPrev(this->getPrev());

	if (this->getPrev() != nullptr)
		this->getPrev()->setNext(this->getNext());
}
