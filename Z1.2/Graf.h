#pragma once

#include <string>
#include "List.h"
#include "Edge.h"

using namespace std;

class Graf
{
private:
	int V; //ilosc wierzcholkow
	int E; //ilosc krawedzi
	int arg; //argument opisujacy czy wierzcholek startowy, uzywany w tablicy d[i]

	int** macierzWag = nullptr; //macierz wag
	Edge* krawedzie = nullptr; //krawędzie

public:
	Graf();
	~Graf();

	void dijkstra();
	void bellmanFord();

	void prim();
	void kruskal();

	void loadFromFile(string Filename);
	void generateGraf();

	void display();

	void init(); //usuniecie istniejacej macierzy i wypelnienie nowej zerami wedlug ilosci wcztanych wyzej wierzcholkow
};
