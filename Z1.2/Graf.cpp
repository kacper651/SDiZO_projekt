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
	if (macierzWag != nullptr)
	{
		for (int i = 0; i < V; i++)
		{
			delete[] macierzWag[i];
		}
		delete macierzWag;
		macierzWag = nullptr;
	}

	ifstream Plik(Filename);

	if (!Plik.good())
	{
		cout << "nie znaleziono pliku\n";
		return;
	}
	
	Plik >> E; Plik >> V; Plik >> arg;

	macierzWag = new int* [V];
	for (int i = 0; i < V; i++)
	{
		macierzWag[i] = new int[V];
		for (int j = 0; j < V; j++)
		{
			macierzWag[i][j] = 0;
		}
	}
	int start, end, cost;

	while (!Plik.eof())
	{
		Plik >> start; Plik >> end; Plik >> cost;
		macierzWag[start][end] = cost;
		macierzWag[end][start] = cost;
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout << macierzWag[i][j];
		}
		cout << endl;
	}
}

void Graf::generateGraf(int V, float gestosc)
{

}

void Graf::display()
{

}
