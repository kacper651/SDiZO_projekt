#pragma once

#include <string>
#include "List.h"
#include "Edge.h"
#include "Vertex.h"

using namespace std;

class Graf
{
private:
	int V; //ilosc wierzcholkow
	int E; //ilosc krawedzi
	int arg; //argument opisujacy czy wierzcholek startowy, uzywany w tablicy d[i]

	int** macierzWag = nullptr; //macierz wag
	Edge* krawedzie = nullptr; //krawędzie
	List<Vertex> wierzcholki;

	//dla kruskala
	int* rank;
	Vertex* findSet(Vertex* v);
	void unionSet(Vertex* v_1, Vertex* v_2);

public:
	Graf();
	~Graf();

	//sciezka macierzowo
	void dijkstraMatrix();
	void bellmanFordMatrix();

	//sciezka listowo
	void dijkstraList();
	/*
	int* d = new int[V]; //inicjalizacja tablic wynikowych algorytmu
		int* p = new int[V];

		for (int i = 0; i < V; i++) //wypelnienie tablic poczatkowymi wartosciami
		{
			d[i] = INT_MAX;
			p[i] = -1;
		}

		bool updated; //flaga sprawdzajaca czy nastapila relaksacja

		d[arg] = 0;//wierzcholek startowy

		for (int i = 0; i < V - 1; i++) //iteracja po wszystkich mozliwych sasiadach
		{
			updated = false;

			for (int j = 0; j < E; j++) //E = liczba krawedzi
			{
				if (d[krawedzie[j].src] != INT_MAX && d[krawedzie[j].src] + krawedzie[j].cst < d[krawedzie[j].dst]) //relaksacja
				{
					d[krawedzie[j].dst] = d[krawedzie[j].src] + krawedzie[j].cst;
					p[krawedzie[j].dst] = krawedzie[j].src;
					updated = true;
				}
			}

			if (updated == false) //sprawdzenie czy jest sens dalej iterowac
				break;
		}

		for (int i = 0; i < E && updated; i++) //petla sprawdzajaca czy wystepuje ujemny cykl w grafie
		{
			if (d[krawedzie[i].src] != INT_MAX && d[krawedzie[i].src] + krawedzie[i].cst < d[krawedzie[i].dst])
			{
				cout << "Ujemny cykl!" << endl;
				return;
			}
		}*/
	void bellmanFordList();

	//mst macierzowo
	void primMatrix();

	//mst listowo
	void primList();
	void kruskalList();


	//utility
	void loadFromFile(string Filename, bool mst = false);
	void generateGraf();

	void display();

	void init(); //usuniecie istniejacej macierzy i wypelnienie nowej zerami wedlug ilosci wcztanych wyzej wierzcholkow
};
