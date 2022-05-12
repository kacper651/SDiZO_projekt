#pragma once
#include <string>
#include "ElemList.h"

using namespace std;

class List
{
	private:
		ElemList* head;
		ElemList* tail;

		ElemList* insert(int index, int value);
		void destroyList();

	public:
		List();
		~List();

		int loadFromFile(string FileName);

		void AddFront(int value);

		void AddBack(int value);

		void AddRandom(int value);

		void AddAtPosition(int value, int index);

		ElemList* findValue(int value);

		ElemList* getElement(int index);

		void deleteElement(int value);

		void display();

		int size();

		void generateList(int size);
};