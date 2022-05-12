#pragma once

class ElemList
{
	private:
		int data;
		ElemList* next;
		ElemList* prev;

	public:
		ElemList(int data);

		//gettery
		int getData();
		ElemList* getPrev();
		ElemList* getNext();

		//settery
		void setData(int data);
		void setPrev(ElemList* prev);
		void setNext(ElemList* next);

		void insert(ElemList* elem);

		void remove();

		int display();
};
