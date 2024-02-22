#include <iostream>
using namespace std;

int achar(int vetor[], int tam, int x)
{

	bool achei = false;
	int auxv; // var auxiliar

	achei = false; // inicialmente, nao achei
	for(int i = 0; i < tam; i++)
	{
		if(x == vetor[i]) // se for igual
		{
			achei = true; // achei
			auxv = i;
		}
	}
	if(achei)
		return auxv;
	else
		return -1;
}

int main()
{
	int N, Q; // número de marmores e número consultas
	int aux1; // var auxiliar
	int v[10]; // vetor
	int r; // resultado
	int g = 1; // contador de casos           :o
	int i = 0;
	int j = 0;


	cin >> N >> Q;

	while(N != 0 && Q != 0)
	{
		for( i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		for(j = 0; j < Q; j++)
		{
			// lendo variavel que deseja saber a posição
			cin >> aux1;

			if(j == 0)
				cout << "CASE# " << g << " :" << endl;

			// procurando no vetor de busca binaria
			r = achar(v, i, aux1);

			// mostrando em qual posição está o o número desejado
			if(r == -1)
			{
				cout << aux1 << " not found" << endl;
			}
			else
			{
				cout << aux1 << " found at " << r << endl;
			}
		}

		cin >> N >> Q;
		
		achei = false;

		g++;
	}


	return 0;
}
