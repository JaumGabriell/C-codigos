#include <iostream>
using namespace std;


int main()
{
	int N, Q; // número de marmores e número consultas
	int aux1, aux2, aux3; // var auxiliar
	int v[10]; // vetor
	// contadores
	int g = 1;        
	int i = 0;
	int j = 0;
	bool achei;
	achei = false; 


	cin >> N >> Q;

	while(N != 0 && Q != 0)
	{
		for( i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		
		// colocando em ordem crescente o vetor
		for(i = 1; i< N;i ++)
		{
			aux3 = v[i];
			j = i -1;
			while(j >= 0 && v[j] > aux3)
			{
				v[j+1] = v[j];
				j--;
			}
			v[j+1] = aux3;
		}
			
		

		for(j = 0; j < Q; j++)
		{
			// lendo variavel que deseja saber a posição
			cin >> aux1;
			
			// verificando se está no vetor
			
			for(i = 0; i < N; i++)
			{
				if(v[i] == aux1)
				{
					achei = true;
					aux2 = i + 1;
					break;
				}
			}

			if(j == 0)
				cout << "CASE# " << g << " :" << endl;

			// mostrando em qual posição está o o número desejado
			if(achei)
			{
				cout << aux1 << " found at " << aux2 << endl;
			}
			else
			{
				cout << aux1 << " not found" << endl;
			}
		}

		cin >> N >> Q;
		
		achei = false;

		g++;
	}


	return 0;
}
