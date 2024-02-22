#include <iostream>
#include <list>
#include <cstring>
using namespace std;

struct no
{
	int v; // vertice adjacente
	int peso; // peso da aresta
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; // var aux p/ inserir as arestas na lista de adjacencia
	aux.v = v;
	aux.peso = p;
	adj[u].push_back(aux);
	// caso não seja orientado
	if(orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

}

void bfs(list<no>adj[], int nVertices, int s)
{


	int u; // não descoberto
	list<int> Q;
	list<no>:: iterator p;
	int v;

	char state [100]; 
	int pai [100];

	for(u = 0; u < nVertices; u++)
	{
		if(u != s)
		{
			state[u] = 'u'; // não descoberto
			pai[u] = -1; // sem pais
		}
	}
	state[s] = 'd'; // descoberto
	pai[s] = -1;
	Q.push_back(s);

	while(!Q.empty())
	{
		u = *Q.begin();
		Q.pop_front();
		cout << u << endl;
		for(p = adj[u].begin(); p != adj[u].end(); p++)
		{
			v = p-> v;
			cout << u  << " " << v << endl;
			if(state[v] == 'u')
			{
				state[v] = 'd';
				pai[v] = u;
				Q.push_back(v);
			}
		}
		state[u] = 'p';
	}
}

int main()
{
	list <no> adj[10]; // lista de adjacencias
	int u, v; // origem e destino
	int p; // peso da aresta
	int nVertices; // # de vertices
	list<no>:: iterator q; // interador p/ varrer as listas
	int orientado = 0; // 1 orientado; 0 não orientado
	int s; // vertice inicial

	// lendo numero de vertices do grafo
	cin >> nVertices;

	// lendo vertice inicial
	cin >> s;

	// lendo origem, destino e peso da aresta
	cin >> u >> v >> p;
	while(u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}

	// mostrando lista de adjacencia

	bfs(adj, nVertices, s);


	return 0;
}
