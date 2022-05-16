#include "Graf.h"
#include <iostream>
#include <fstream>
#include "Heap.h"

Graf::Graf()
{
}

Graf::~Graf()
{
}

void Graf::dijkstra()
{
	int* d = new int[V];
	int* p = new int[V];

	for (int i = 0; i < V; i++)
	{
		d[i] = INT_MAX;
		p[i] = -1;
	}

	d[arg] = 0;//wierzcholek startowy
	Heap Q(V);

	for (int i = 0; i < V; i++)
	{
		Q.insert(&d[i]);
	}

	int u;

	while (Q.getLength() != 0)
	{
		for (u = 0; u < V; u++)
		{
			if (&d[u] == Q.getTop())
				break;
		}

		for (int i = 0; i < V; i++)
		{
			if (macierzWag[i][u] != 0)
			{
				if (d[u] != INT_MAX && d[i] > d[u] + macierzWag[i][u]) //relaksacja
				{
					d[i] = d[u] + macierzWag[i][u]; //korekta Q
					p[i] = u;
				}
			}
		}
		Q.deleteElement(0);
	}

	cout << "Tablica d[i]: " << endl;

	for (int i = 0; i < V; i++)
	{
		cout << d[i] << " ";
	}

	cout << endl << "Tablica p[i]: " << endl;

	for (int i = 0; i < V; i++)
	{
		cout << p[i] << " ";
	}

	cout << endl;
	delete[] p;
	delete[] d;
}

void Graf::bellmanFord()
{
	int* d = new int[V];
	int* p = new int[V];

	for (int i = 0; i < V; i++)
	{
		d[i] = INT_MAX;
		p[i] = -1;
	}

	bool updated; //flaga sprawdzajaca czy nastapila relaksacja

	d[arg] = 0;//wierzcholek startowy

	for (int i=0; i < V - 1; i++) //iteracja po wszystkich mozliwych sasiadach
	{
		updated = false;

		for (int j = 0; j < E; j++)
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

	for (int i=0; i < E && updated; i++) //petla sprawdzajaca czy wystepuje ujemny cykl w grafie
	{
		if (d[krawedzie[i].src] != INT_MAX && d[krawedzie[i].src] + krawedzie[i].cst < d[krawedzie[i].dst])
		{
			cout<<"Ujemny cykl!"<<endl;
			return;
		}
	}

	cout << "Tablica d[i]: " << endl;

	for (int i = 0; i < V; i++) //wypisywanie d[i]
	{
		cout << d[i] << " ";
	}

	cout << endl << "Tablica p[i]: " << endl;

	for (int i = 0; i < V; i++) //wypisywanie p[i]
	{
		cout << p[i] << " ";
	}

	cout << endl;
	delete[] p;
	delete[] d;
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
	krawedzie = new Edge[E];

	for (int i=0; !Plik.eof(); i++)
	{
		Plik >> start; Plik >> end; Plik >> cost;

		if (Plik.eof())
			break;

		macierzWag[start][end] = cost;

		krawedzie[i].src = start;
		krawedzie[i].dst = end;
		krawedzie[i].cst = cost;
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

	int cost, V1, V2;
}

void Graf::display()
{
	cout<<"Macierz wag:"<<endl;

	for (int i = 0; i < V; i++) //reprezentacja macierzowa
	{
		for (int j = 0; j < V; j++)
		{
			cout << macierzWag[i][j]; cout << " ";
		}
		cout << endl;
	}

	cout<<"Krawedzie:"<<endl;

	for (int i=0; i < E; i++)
	{
		cout<<krawedzie[i].src<<" -> "<<krawedzie[i].dst<<" = "<<krawedzie[i].cst<<endl;
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
