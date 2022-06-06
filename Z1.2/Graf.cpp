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

void Graf::dijkstraMatrix()
{
	if (macierzWag != nullptr)
	{
		int* d = new int[V]; //inicjalizacja tablic wynikowych algorytmu
		int* p = new int[V];

		for (int i = 0; i < V; i++) //wypelnienie tablic poczatkowymi wartosciami
		{
			d[i] = INT_MAX;
			p[i] = -1;
		}

		d[arg] = 0;//wierzcholek startowy
		Heap<int*> Q(V); //kolejka priorytetowa w postaci kopca minimalnego

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
				{
					break;
				}
			}

			for (int i = 0; i < V; i++)
			{
				if (macierzWag[i][u] != 0 && d[u] != INT_MAX && d[i] > d[u] + macierzWag[i][u]) //relaksacja
				{
					d[i] = d[u] + macierzWag[i][u];
					p[i] = u;
				}
			}

			Q.deleteElement(0);
		}

		//Wyniki algorytmu
		cout << "Tablica d[i]: " << endl;
		cout << "Indeks: ";
		for (int i = 0; i < V; i++)
			cout << i << " ";
		cout << endl;
		cout << "Dystans:";

		for (int i = 0; i < V; i++)
		{
			cout << d[i] << " ";
		}

		cout << endl << "Tablica p[i]: " << endl;
		cout << "Indeks: ";
		for (int i = 0; i < V; i++)
			cout << i << " ";
		cout << endl;
		cout << "Rodzic: ";

		for (int i = 0; i < V; i++)
		{
			cout << p[i] << " ";
		}

		cout << endl;
		delete[] p;
		delete[] d;
	}
	else
		cout << "Przed proba wykonania algorytmu wczytaj graf!" << endl;
}

void Graf::bellmanFordMatrix()
{
	if (macierzWag != nullptr)
	{
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
		}

		//Wyniki algorytmu
		cout << "Tablica d[i]: " << endl;
		cout << "Indeks: ";
		for (int i = 0; i < V; i++)
			cout << i << " ";
		cout << endl;
		cout << "Dystans:";

		for (int i = 0; i < V; i++) //wypisywanie d[i]
		{
			cout << d[i] << " ";
		}

		cout << endl << "Tablica p[i]: " << endl;
		cout << "Indeks: ";
		for (int i = 0; i < V; i++)
			cout << i << " ";
		cout << endl;
		cout << "Rodzic: ";

		for (int i = 0; i < V; i++) //wypisywanie p[i]
		{
			cout << p[i] << " ";
		}

		cout << endl;
		delete[] p;
		delete[] d;
	}
	else
		cout << "Przed proba wykonania algorytmu wczytaj graf!" << endl;
}

void Graf::dijkstraList()
{
	Heap<Vertex*> heapQueue(V);

	wierzcholki[arg].setDistanceFromStart(0);

	for (int i=0; V>i; i++)
	{
		heapQueue.insert(&(wierzcholki[i]));
	}

	Vertex* currentVertex;
	EdgeClass* currentNeighbourStruct;

	while(heapQueue.getLength() > 0)
	{
		currentVertex = heapQueue.getTop();

		for (int i=0; currentVertex->getNeighboursList().size() > i; i++)
		{
			currentNeighbourStruct = &currentVertex->getNeighboursList()[i];

			if (currentNeighbourStruct->get_dst()->getDistanceFromStart() >
				currentVertex->getDistanceFromStart() + currentNeighbourStruct->get_weight())
			{
				currentNeighbourStruct->get_dst()->setDistanceFromStart(currentVertex->getDistanceFromStart() + currentNeighbourStruct->get_weight());
				currentNeighbourStruct->get_dst()->setParent(currentVertex);
			}
		}

		heapQueue.deleteElement(0);
	}

	for (int i=0; V>i; i++)
	{
		cout<<i<<": "<<&(wierzcholki[i])<<endl;
	}

	for (int i=0; V>i; i++)
	{
		cout<<"Vertex: "<<i<<endl;
		cout<<"Distance from start: "<<wierzcholki[i].getDistanceFromStart()<<endl;
		cout << "Parent: " << wierzcholki[i].getParent()<< endl << endl;
	}
}

void Graf::bellmanFordList()
{

}

void Graf::primMatrix()
{
	int* p = new int[V]; //rodzice
	int* key = new int[V]; //tablica najmniejszych wartosci krawedzi wierzcholka
	Heap<int*> Q(V); //kolejka priorytetowa w postaci kopca
	bool* mstSet = new bool[V];

	for (int i = 0; i < V; i++)
	{
		key[i] = INT_MAX;
		p[i] = -1;
		mstSet[i] = false;
	}

	key[0] = 0; //wierzcholek startowy
	p[0] = -1; //wierzcholek startowy nie ma rodzica

	for (int i = 0; i < V; i++) //zapełnienie kopca
	{
		Q.insert(&key[i]);
	}

	int u;

	while (Q.getLength() != 0)
	{
		for (u = 0; u < V; u++)
		{
			if (&key[u] == Q.getTop())
			{
				break;
			}
		}

		mstSet[u] = true;

		for (int i = 0; i < V; i++)
		{
			if (mstSet[i] == false && macierzWag[u][i] != 0 && key[u] != INT_MAX && key[i] > macierzWag[u][i]) //relaksacja
			{
				key[i] = macierzWag[u][i];
				p[i] = u;
			}
		}

		Q.deleteElement(0);
	}

	int mstValue = 0;

	//Wyniki algorytmu
	for (int i = 0; i < V; i++)
	{
		mstValue += key[i];
	}

	cout << "Waga MST: " << mstValue << endl;
	cout << "Rodzic[i]: ";

	for (int i = 0; i < V; i++)
	{
		cout << p[i] << " ";
	}

	cout<<endl;

	delete[] p;
	delete[] key;
}

void Graf::primList()
{

}

Vertex *Graf::findSet(Vertex *v)
{
	if (v->getParent() != v)
		v->setParent(findSet(v->getParent()));

	return v->getParent();
}

void Graf::unionSet(Vertex *v_1, Vertex *v_2)
{
	Vertex* a = this->findSet(v_1);
	Vertex* b = this->findSet(v_2);

	if (a->getRank() < b->getRank())
	{
		a->setParent(b);
	}
	else
	{
		b->setParent(a);
	}

	if (a->getRank() == b->getRank())
	{
		a->setRank(a->getRank() + 1);
	}
}

void Graf::kruskalList()
{
	rank = new int[V];
	Heap<EdgeClass*> edges(E);
	List<EdgeClass*> mst;

	for (int i=0; V>i; i++)
	{
		rank[i] = 0;
	}

	for (int i=0; wierzcholki.size()>i; i++)
	{
		wierzcholki[i].setParent(&wierzcholki[i]);

		for (int j=0; wierzcholki[i].getNeighboursList().size()>j; j++)
		{
			edges.insert(&(wierzcholki[i].getNeighboursList()[j]));
		}
	}

	Vertex* v_1;
	Vertex* v_2;

	while(!edges.isEmpty())
	{
		v_1 = edges.getTop()->get_src();
		v_2 = edges.getTop()->get_dst();

		if (v_1->getParent() != v_2->getParent())
		{
			mst.AddBack(edges.getTop());
			this->unionSet(v_1, v_2);
		}

		edges.deleteElement(0);
	}

	for (int i=0; wierzcholki.size()>i; i++)
	{
		cout<<i<<". "<<&wierzcholki[i]<<endl;
	}

	int sum = 0;

	for (int i=0; mst.size()>i; i++)
	{
		cout<<mst[i]->get_src()<<" -> "<<mst[i]->get_dst()<<": "<<mst[i]->get_weight()<<endl;
		sum += mst[i]->get_weight();
	}

	cout<<"Suma MST: "<<sum<<endl;
}

void Graf::loadFromFile(string Filename, bool mst)
{
	ifstream Plik(Filename);

	if (!Plik.good())
	{
		cout << "Nie znaleziono pliku\n";
		return;
	}
	
	Plik >> E; Plik >> V;

	if (!mst)
	{
		Plik >> arg;
	}

	this->init(); //usuniecie istniejacej macierzy i wypelnienie nowej zerami wedlug ilosci wcztanych wyzej wierzcholkow

	int start, end, cost;
	krawedzie = new Edge[E];

	for (int i=0; V>i; i++)
	{
		wierzcholki.AddBack(Vertex());
	}

	for (int i=0; !Plik.eof(); i++)
	{
		Plik >> start; Plik >> end; Plik >> cost;

		if (Plik.eof())
			break;

		macierzWag[start][end] = cost;

		if (mst)
			macierzWag[end][start] = cost;

		krawedzie[i].src = start;
		krawedzie[i].dst = end;
		krawedzie[i].cst = cost;

		//reprezentacja listowa
		wierzcholki[start].addNeighbour(&wierzcholki[start], &wierzcholki[end], cost);
		wierzcholki[start].setVertexNumber(start);
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
	E = density * V * (V - 1) / 2; //ilosc wierzcholkow ze wzoru w oparciu na gestosc grafu

	this->init(); //usuniecie istniejacej macierzy i wypelnienie nowej zerami wedlug ilosci wcztanych wyzej wierzcholkow

	int cost, V1, V2;
}

void Graf::display()
{
	if (macierzWag != nullptr)
	{
		cout << "Macierz wag:" << endl;

		for (int i = 0; i < V; i++) //reprezentacja macierzowa
		{
			for (int j = 0; j < V; j++)
			{
				cout << macierzWag[i][j]; cout << " ";
			}
			cout << endl;
		}

		cout << "Krawedzie:" << endl;

		for (int i = 0; i < E; i++)
		{
			cout << krawedzie[i].src << " -> " << krawedzie[i].dst << " = " << krawedzie[i].cst << endl;
		}
	}
	else
		cout << "Nie mozna wyswietlic reprezentacji, wczytaj graf!" << endl;
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
