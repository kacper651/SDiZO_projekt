#pragma once

#include <windows.h> //do pomiaru czasu
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "Graf.h"

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}
////====================
//// ---- TEST LIST ----
////====================
//
//float listTestAddFront(int listSize)
//{
//	//List testList;
//	testList.generateList(listSize);
//	
//	StartCounter();//start zegara
//
//	testList.AddFront(rand() % 100);
//
//	return GetCounter(); //koniec zegara
//}
//
//float listTestAddBack(int listSize)
//{
//	//List testList;
//	testList.generateList(listSize);
//
//	StartCounter();//start zegara
//
//	testList.AddBack(rand() % 100);
//
//	return GetCounter();
//}
//
//float listTestAddRandom(int listSize)
//{
//	//List testList;
//	//testList.generateList(listSize);
//
//	StartCounter();//start zegara
//
//	testList.AddRandom(rand() % 100);
//
//	return GetCounter();
//}
//
//float listTestSearch(int listSize)
//{
//	//List testList;
//	//testList.generateList(listSize);
//	
//	StartCounter();//start zegara
//
//	testList.findValue(rand() % 100);
//
//	return GetCounter();
//}
//
//
//float listTestDeleteFront(int listSize)
//{
//	//List testList;
//	//testList.generateList(listSize);
//
//	StartCounter();//start zegara
//
//	testList.deleteElement(testList.getElement(0)->getData());
//
//	return GetCounter();
//}
//
//float listTestDeleteBack(int listSize)
//{
//	//List testList;
//	//testList.generateList(listSize);
//
//	StartCounter();//start zegara 
//
//	testList.deleteElement(testList.getElement(listSize-1)->getData());
//
//	return GetCounter();
//}
//
//float listTestDeleteRandom(int listSize)
//{
////	List testList;
//	//testList.generateList(listSize);
//
//	StartCounter();//start zegara
//	
//	testList.deleteElement(rand() % 100);
//
//	return GetCounter();
//}
//
//void listTest(int listSize)
//{
//	float avgTime = 0;
//
//	for (int i=0; 100>i; i++)
//	{
//		avgTime += listTestAddBack(listSize);
//	}
//
//	avgTime /= 100;
//
//	cout<< avgTime <<endl;
//}
//
////=====================
////---- TEST TABLIC ----
////=====================
//
//float tabTestAddFront(int tabSize)
//{
//	Table testTable;
//	testTable.generateTable(tabSize);
//
//	StartCounter();
//
//	testTable.AddFront(rand() % 100);
//
//	return GetCounter();
//}
//
//float tabTestAddBack(int tabSize)
//{
//	Table testTable;
//	testTable.generateTable(tabSize);
//
//	StartCounter();
//
//	testTable.AddBack(rand() % 100);
//
//	return GetCounter();
//}
//
//float tabTestAddRandom(int tabSize)
//{
//	Table testTable;
//	testTable.generateTable(tabSize);
//
//	StartCounter();
//
//	testTable.AddRandom(rand() % 100);
//
//	return GetCounter();
//}
//
//float tabTestDeleteFront(int tabSize)
//{
//	Table testTable;
//	testTable.generateTable(tabSize);
//
//	StartCounter();
//
//	testTable.deleteFromTable(0);
//
//	return GetCounter();
//}
//
//float tabTestDeleteBack(int tabSize)
//{
//	Table testTable;
//	testTable.generateTable(tabSize);
//
//	StartCounter();
//
//	testTable.deleteFromTable(tabSize-1);
//
//	return GetCounter();
//}
//
//float tabTestDeleteRandom(int tabSize)
//{
//	Table testTable;
//	testTable.generateTable(tabSize);
//
//
//	StartCounter();
//
//	testTable.deleteFromTable(rand() % tabSize);
//
//	return GetCounter();
//}
//
//float tabTestSearch(int tabSize)
//{
//	Table testTable;
//	testTable.generateTable(tabSize);
//
//	StartCounter();
//
//	testTable.IsValueInTable(rand() % 100);
//
//	return GetCounter();
//}
//
//void tabTest(int tabSize)
//{
//	float avgTime = 0;
//
//	for (int i = 0; 100 > i; i++)
//	{
//		avgTime += tabTestDeleteBack(tabSize);
//	}
//
//	avgTime /= 100;
//
//	cout << avgTime << endl;
//}
//
////=====================
////---- TEST KOPCOW ----
////=====================
//
//float heapTestAdd(int heapSize)
//{
//	Heap testHeap(heapSize);
//	//testHeap.generateHeap(heapSize);
//
//	StartCounter();
//
//	//testHeap.insert(rand() % 100);
//
//	return GetCounter();
//}
//
//float heapTestDelete(int heapSize)
//{
//	Heap testHeap(heapSize);
//	//testHeap.generateHeap(heapSize);
//
//	StartCounter();
//
//	testHeap.deleteElement(rand() % heapSize);
//
//	return GetCounter();
//}
////
////float heapTestSearch(int heapSize)
////{
////	Heap testHeap(heapSize);
////	//testHeap.generateHeap(heapSize);
////
////	StartCounter();
////
////	testHeap.isValueInHeap(rand() % 100);
////
////	return GetCounter();
////}
//
//void heapTest(int heapSize)
//{
//	float avgTime = 0;
//
//	for (int i = 0; 100 > i; i++)
//	{
//		avgTime += heapTestAdd(heapSize);
//	}
//
//	avgTime /= 100;
//
//	cout << avgTime << endl;
//}

//TEST GRAFÓW

float graphTestDijkstraMatrix(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, true);

	StartCounter();
	for(int i = 0; i < 50; i++)
		testGraf.dijkstraMatrix();

	return GetCounter()/50;
}

float graphTestDijkstraList(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, true);

	StartCounter();
	for (int i = 0; i < 50; i++)
	testGraf.dijkstraList();

	return GetCounter()/50;
}

float graphTestBellmanFordMatrix(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, false);

	StartCounter();
	for (int i = 0; i < 50; i++)
	testGraf.bellmanFordMatrix();

	return GetCounter()/50;
}

float graphTestBellmanFordList(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, false);

	StartCounter();
	for (int i = 0; i < 50; i++)
	testGraf.bellmanFordList();

	return GetCounter()/50;
}

float graphTestPrimMatrix(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, false);

	StartCounter();
	for (int i = 0; i < 50; i++)
	testGraf.primMatrix();

	return GetCounter()/50;
}

float graphTestPrimList(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, false);

	StartCounter();
	for (int i = 0; i < 50; i++)
	testGraf.primList();

	return GetCounter()/50;
}

float graphTestKruskalMatrix(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, false);

	StartCounter();
	for (int i = 0; i < 50; i++)
	testGraf.kruskalMatrix();

	return GetCounter()/50;
}

float graphTestKruskalList(int v, float den)
{
	Graf testGraf;
	testGraf.generateGraf(v, den, false);

	StartCounter();
	for (int i = 0; i < 50; i++)
	testGraf.kruskalList();

	return GetCounter()/50;
}

void graphTestDijkstra()
{
	float avgTime;

	cout << "dijkstra matrix 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestDijkstraMatrix(v, 20) << endl;
	}

	cout << "dijkstra list 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestDijkstraList(v, 20) << endl;
	}

	cout << "dijkstra matrix 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestDijkstraMatrix(v, 60) << endl;
	}

	cout << "dijkstra list 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestDijkstraList(v, 60) << endl;
	}

	cout << "dijkstra matrix 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestDijkstraMatrix(v, 99) << endl;
	}

	cout << "dijkstra list 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestDijkstraList(v, 99) << endl;
	}
}

void graphTestBellmanFord()
{
	cout << "bellmanford matrix 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestBellmanFordMatrix(v, 20) << endl;
	}

	cout << "bellmanford list 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestBellmanFordList(v, 20) << endl;
	}

	cout << "bellmanford matrix 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestBellmanFordMatrix(v, 60) << endl;
	}

	cout << "bellmanford list 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestBellmanFordMatrix(v, 60) << endl;
	}
	cout << "bellmanford list 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestBellmanFordMatrix(v, 20) << endl;
	}

	cout << "bellmanford matrix 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestBellmanFordMatrix(v, 99) << endl;
	}
}

void graphTestPrim()
{
	cout << "prim matrix 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestPrimMatrix(v, 20) << endl;
	}

	cout << "prim list 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestPrimList(v, 20) << endl;
	}

	cout << "prim matrix 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestPrimMatrix(v, 60) << endl;
	}

	cout << "prim list 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestPrimList(v, 60) << endl;
	}

	cout << "prim list 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestPrimList(v, 20) << endl;
	}

	cout << "prim matrix 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestPrimMatrix(v, 99) << endl;
	}

	
}

void graphTestKruskal()
{
	cout << "kruskal matrix 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestKruskalMatrix(v, 20) << endl;
	}

	cout << "kruskal list 20: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestKruskalList(v, 20) << endl;
	}

	cout << "kruskal matrix 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestKruskalMatrix(v, 60) << endl;
	}

	cout << "kruskal list 60: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestKruskalList(v, 60) << endl;
	}

	cout << "kruskal list 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestKruskalList(v, 20) << endl;
	}

	cout << "kruskal matrix 99: " << endl;

	for (int v = 5; v <= 35; v += 5)
	{
		cout << graphTestKruskalMatrix(v, 99) << endl;
	}
}