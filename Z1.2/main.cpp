// menu.cpp : Defines the entry point for the console application.
//


#include<conio.h>
#include<string>
#include<iostream>
#include <time.h>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "Tests.h"
#include "Graf.h"

using namespace std;

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Testuj" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void menu_table()
{
	Table myTab; 
	char opt;
	string fileName;
	int index, value;

	do
	{
		displayMenu("--- TABLICA ---");
		opt = _getche();
		cout << endl;

		switch (opt)
		{
			case '1': //tutaj wczytytwanie  tablicy z pliku
				cout << " Podaj nazwê zbioru:";
				cin >> fileName;
				myTab.loadFromFile(fileName);
				myTab.display();
				break;

			case '2': //tutaj usuwanie elemenu z tablicy
				cout << " podaj index:";
				cin >> index;
				myTab.deleteFromTable(index);
				myTab.display();
				break;

			case '3': //tutaj dodawanie elemetu do tablicy
				cout << "Jaki element chcesz dodac?";
				cin >> value;
				cout << "Na ktory index?";
				cin >> index;
				myTab.AddAtIndex(value, index);
				myTab.display();
				break;

			case '4': //tutaj znajdowanie elemetu w tablicy
				cout << " podaj waertoœæ:";
				cin >> value;
				if (myTab.IsValueInTable(value))
					cout << "podana wartoœc jest w tablicy";
				else
					cout << "podanej wartoœci NIE ma w tablicy";
				break;

			case '5':  //tutaj generowanie  tablicy
				cout << "Podaj iloœæ elementów tablicy:";
				cin >> value;
				myTab.generateTable(value);
				myTab.display();
				break;

			case '6':  //tutaj wyœwietlanie tablicy
				myTab.display();
				break;

			case '7': //test
				int tab[] = { 2000, 5000, 8000, 10000, 16000, 20000, 24000, 30000 }; //ilosc elementow do pomiaru
				for (int i = 0; i < 8; i++)
					tabTest(tab[i]);
				break;
		}

	} while (opt != '0');
}

void menu_list()
{
	//analogicznie jak menu_table()
	List myList;
	char opt;
	string fileName;
	int value, size, index;

	do {
		displayMenu("--- LISTA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie listy z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			myList.loadFromFile(fileName);
			myList.display();
			break;

		case '2': //tutaj usuwanie elemenu z listy
			cout << "Podaj wartosc, ktory chcesz usunac:";
			cin >> index;
			myList.deleteElement(index);
			myList.display();
			break;

		case '3': //tutaj dodawanie elemetu do listy
			cout << "Jaka wartosc chcesz dodac?";
			cin >> value;
			cout << "Na ktory index chcesz dodac?";
			cin >> index;
			myList.AddAtPosition(value, index);
			myList.display();
			break;

		case '4': //tutaj znajdowanie elemetu w liœcie
			cout << "Podaj wartosc, ktora chcesz znalezc:";
			cin >> value;
			if (myList.findValue(value) != nullptr)
				cout << "podana wartosc jest w liscie";
			else
				cout << "podanej wartoœci NIE ma w liscie";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow listy, ktora chcesz wygenerowac:";
			cin >> size;
			myList.generateList(size);
			myList.display();
			break;

		case '6':  //tutaj wyœwietlanie listy
			myList.display();
			break;

		case '7': //test
			int tab[] = { 2000, 5000, 8000, 10000, 16000, 20000, 24000, 30000 }; //ilosc elementow do pomiaru
			for(int i = 0; i < 8; i++)
				listTest(tab[i]);
			break;
		}

	} while (opt != '0');
}

void menu_heap()
{
	//analogicznie jak menu_table()
	Heap myHeap(10);
	char opt;
	string fileName;
	int value, size, index;

	do {
		displayMenu("--- KOPEC ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie kopca z pliku
			cout << " Podaj nazwe zbioru:";
			cin >> fileName;
			//myHeap.loadFromFile(fileName);
			myHeap.display();
			break;

		case '2': //tutaj usuwanie elemenu z kopca
			cout << "Podaj index, ktory chcesz usunac:";
			cin >> index;
			myHeap.deleteElement(index);
			myHeap.display();
			break;

		case '3': //tutaj dodawanie elemetu do kopca
			cout << "Jaka wartosc chcesz dodac?";
			cin >> value;
			//myHeap.insert(value);
			myHeap.display();
			break;

		case '4': //tutaj znajdowanie elemetu w kopcu
			cout << "Podaj wartosc, ktora chcesz znalezc:";
			cin >> value;
//			if (myHeap.isValueInHeap(value))
//				cout << "podana wartosc jest w kopcu";
//			else
//				cout << "podanej wartoœci NIE ma w kopcu";
			break;

		case '5':  //tutaj generowanie kopca
			cout << "Podaj ilosc elementow listy, ktora chcesz wygenerowac:";
			cin >> size;
			//myHeap.generateHeap(size);
			myHeap.display();
			break;

		case '6':  //tutaj wyœwietlanie kopca
			myHeap.display();
			break;

		case '7': //test
			int tab[] = { 2000, 5000, 8000, 10000, 16000, 20000, 24000, 30000 }; //ilosc elementow do pomiaru
			for (int i = 0; i < 8; i++)
				heapTest(tab[i]);
			break;
		}

	} while (opt != '0');
}

void menuZ1()
{
	char option;

	do
	{
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
		}

	} while (option != '0');
}

void menuShortestPath()
{
	char opt;
	Graf myGraf;
	string filename;

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

		switch (opt)
		{
		case '1':
			cout << "Podaj nazwe pliku: ";
			cin >> filename;
			myGraf.loadFromFile(filename);
			myGraf.display();
			break;

		case '2':
			myGraf.generateGraf();
			myGraf.display();
			break;

		case '3':
			myGraf.display();
			break;

		case '4':
			myGraf.display();
			myGraf.dijkstra();
			break;

		case '5':
			myGraf.display();
			myGraf.bellmanFord();
			break;
		}

	} while (opt != '0');
}

void menuMST()
{
	char opt;
	Graf myGraf;
	string filename;

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

		switch (opt)
		{
		case '1':
			myGraf.loadFromFile(filename);
			myGraf.display();
			break;

		case '2':
			myGraf.generateGraf();
			myGraf.display();
			break;

		case '3':
			myGraf.display();
			break;

		case '4':
			myGraf.display();
			myGraf.prim();
			break;

		case '5':
			myGraf.display();
			myGraf.kruskal();
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
	menuZ2();

	return 0;
}