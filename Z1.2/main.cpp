// menu.cpp : Defines the entry point for the console application.
//


#include<conio.h>
#include<string>
#include<iostream>
#include <time.h>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "Graf.h"
#include "Vertex.h"
#include "Tests.h"

using namespace std;

void menuShortestPath()
{
	char opt;
	Graf myGraf;
	string filename;
	int v;
	float den;

	do
	{
		cout << endl;
		cout << "==== NAJKROTSZA SCIEZKA ====" << endl;
		cout << "1. Wczytaj z pliku" << endl;
		cout << "2. Wygeneruj graf losowo" << endl;
		cout << "3. Wyswietl listowo i macierzowo" << endl;
		cout << "4. Algorytm Dijkstry" << endl;
		cout << "5. Algorytm Bellmana-Forda" << endl;
		cout << "0. Wyjscie" << endl;

		opt = _getche();
		cout << endl;

		switch (opt)
		{
		case '1':
			cout << "Podaj nazwe pliku: ";
			cin >> filename;
			myGraf.loadFromFile(filename);
			myGraf.display();
			break;

		case '2':
			cout << "Podaj V: " << endl;
			cin >> v;
			cout << "Podaj gestosc: " << endl;
			cin >> den;
			myGraf.generateGraf(v, den, true);
			myGraf.display();
			break;

		case '3':
			myGraf.display();
			break;

		case '4':
			myGraf.display();
			myGraf.dijkstraMatrix();
			myGraf.dijkstraList();
			break;

		case '5':
			myGraf.display();
			myGraf.bellmanFordMatrix();
			myGraf.bellmanFordList();
			break;
		}

	} while (opt != '0');
}

void menuMST()
{
	char opt;
	Graf myGraf;
	string filename;
	int v;
	float den;

	do
	{
		cout << endl;
		cout << "==== MST ====" << endl;
		cout << "1. Wczytaj z pliku" << endl;
		cout << "2. Wygeneruj graf losowo" << endl;
		cout << "3. Wyswietl listowo i macierzowo" << endl;
		cout << "4. Algorytm Prima" << endl;
		cout << "5. Algorytm Kruskala" << endl;
		cout << "0. Wyjscie" << endl;

		opt = _getche();
		cout << endl;

		switch (opt)
		{
		case '1':
			cout << "Podaj nazwe pliku: ";
			cin >> filename;
			myGraf.loadFromFile(filename, true);
			myGraf.display();
			break;

		case '2':
			cout << "Podaj V: " << endl;
			cin >> v;
			cout << "Podaj gestosc: " << endl;
			cin >> den;			
			myGraf.generateGraf(v, den, false);
			myGraf.display();
			break;

		case '3':
			myGraf.display();
			break;

		case '4':
			myGraf.display();
			myGraf.primMatrix();
			myGraf.primList();
			break;

		case '5':
			myGraf.display();
			myGraf.kruskalMatrix();
			myGraf.kruskalList();
			break;
		}

	} while (opt != '0');
}

void menuZ2()
{
	char option;

	do
	{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Najkrotsza droga" << endl;
		cout << "2.MST" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			menuShortestPath();
			break;

		case '2':
			menuMST();
			break;
		}

	} while (option != '0');
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	menuZ2();

	//Graf g;

	//g.generateGraf(5, 20, false);
	//g.display();

	//g.loadFromFile("dane_droga_sk_BF.txt", false);
	//g.dijkstraMatrix();
	//g.dijkstraList();

	//g.primList();
	//g.primMatrix();

	//g.bellmanFordList();
	//g.bellmanFordMatrix();

	//g.kruskalList();
	//g.kruskalMatrix();

	//graphTestDijkstra();
	//graphTestBellmanFord();
	//graphTestPrim();
	//graphTestKruskal();

	return 0;
}