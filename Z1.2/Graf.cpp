#include "Graf.h"
#include <iostream>
#include <fstream>

Graf::Graf()
{
}

Graf::~Graf()
{
}

void Graf::dijkstra()
{
}

void Graf::bellmanFord()
{
}

void Graf::prim()
{
}

void Graf::kruskal()
{
}

void Graf::loadFromFile(string Filename)
{
	ifstream Plik(Filename);

	if (!Plik.good())
	{
		cout << "nie znaleziono pliku\n";
		return;
	}
	
	Plik >> E; Plik >> V; Plik >> arg;

	this->init(); //usuniecie istniejacej macierzy i wypelnienie nowej zerami wedlug ilosci wcztanych wyzej wierzcholkow

	int start, end, cost;

	while (!Plik.eof())
	{
		Plik >> start; Plik >> end; Plik >> cost;
		macierzWag[start][end] = cost;
		macierzWag[end][start] = cost;
	}
}

void Graf::generateGraf()
{
	cout << "Podaj ilosc wierzcholkow grafu: ";
	cin >> V;
	cout << "Podaj gestosc zapelnienia grafu w %: ";
	float density;
	cin >> density;
	density /= 100;
	E = density * V * (V - 1) / 2;

	this->init(); //usuniecie istniejacej macierzy i wypelnienie nowej zerami wedlug ilosci wcztanych wyzej wierzcholkow


}

void Graf::display()
{
	for (int i = 0; i < V; i++) //reprezentacja macierzowa
	{
		for (int j = 0; j < V; j++)
		{
			cout << macierzWag[i][j];
		}
		cout << endl;
	}
}

void Graf::init()
{
	if (macierzWag != nullptr) //uswanie istniejacej macierzy
	{
		for (int i = 0; i < V; i++)
		{
			delete[] macierzWag[i];
		}
		delete macierzWag;
		macierzWag = nullptr;
	}

	macierzWag = new int* [V];
	for (int i = 0; i < V; i++)
	{
		macierzWag[i] = new int[V];
		for (int j = 0; j < V; j++) //wypelnienie zerami
		{
			macierzWag[i][j] = 0;
		}
	}
}
