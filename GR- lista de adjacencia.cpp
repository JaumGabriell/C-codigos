#include <iostream>
#include <list>
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
int main()
{
	list <no> adj[10]; // lista de adjacencias
	int u, v; // origem e destino
	int p; // peso da aresta
	int nVertices; // # de vertices
	list<no>:: iterator q; // interador p/ varrer as listas
	int orientado; // 1 orientado; 0 não orientado
	
	// lendo numero de vertices do grafo
	cin >> nVertices;
	
	// lendo se o grafo é orientado ou não
	cin >> orientado;
	
	// lendo origem, destino e peso da aresta
	cin >> u >> v >>p;
	while(u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		cin >> u >> v >> p;
	}
	// mostrando lista de adjacencia
	for(int i = 0; i < nVertices; i++)
		for(q = adj[i].begin(); q != adj[i].end(); q++)
		{
			cout << i << " "<< q -> v << " " << q -> peso << endl;
		}
	
	return 0;
}