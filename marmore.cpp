#include <iostream>
using namespace std;

int binaria(int vetor[], int tam, int x)
{

	bool achou = false;
	int baixo = 0, meio, alto = tam - 1;

	while ((baixo <= alto) && (achou == false))
	{

		meio = (baixo + alto) / 2;

		if(x < vetor[meio])
			alto = meio - 1;
		else if(x > vetor[meio])
			baixo = meio + 1;
		else
			achou = true;
	}
	if(achou)
		return meio;
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
			r = binaria(v, N, aux1);

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


		g++;
	}


	return 0;
}
