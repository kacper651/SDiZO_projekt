#pragma once

#include <string>

using namespace std;

class Heap
{
	private:
		int* arr;
		int size;
		int len;

		bool isFull();
		bool isValidIndex(int index);

		int getLeftChild(int parentIndex);
		int getRightChild(int parentIndex);
		int getParent(int childIndex);

		void resize(int newSize);
		void swapElements(int index1, int index2);

		void maxHeapifyUp(int index);
		void maxHeapifyDown(int parentIndex);

		void init(int size);
		void destroyHeap();

	public:
		Heap(int size);
		~Heap();

		void insert(int value);
		void deleteElement(int index);
		bool isValueInHeap(int value);

		void display();

		void loadFromFile(string FileName);
		void generateHeap(int size);
};