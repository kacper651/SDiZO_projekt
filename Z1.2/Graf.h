#pragma once

#include <string>
#include "List.h"

using namespace std;

class Graf
{
private:
	int V; //ilosc wierzcholkow
	int E; //ilosc krawedzi
	int arg;

	int** macierzWag = nullptr; //macierz wag

public:
	Graf();
	~Graf();

	void dijkstra();
	void bellmanFord();

	void prim();
	void kruskal();

	void loadFromFile(string Filename);
	void generateGraf(int V, float gestosc);

	void display();
};
