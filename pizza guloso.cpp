#include <iostream> // Entrada e sa�da
#include <climits> // INT_MAX

using namespace std;

int n; // quantidade de elementos a serem analisados
int tempo[2004], pizzas[2004]; // tempo e pizzas de cada item
int itens_pegos[2004]; // 

int soltempoe(int cap)
{
	int tempoal = 0;

	for(int i = 0; i<n; i++)
	{
		if(cap < 0)
		{
			return tempoal;
		}

		if(cap>=pizzas[i])
		{
			itens_pegos[i] = i;
			tempoal += tempo[i];
			cap -= pizzas[i];
		}


	}
	return tempoal;
}

int main()
{
	int mochila;
    cout << "Insira a quantidade de pedidos" << endl;
	cin >> n;
	cout << "Insira a capacidade de pizzas que podem ser entregues por Roberto" << endl;
	cin >> mochila; // capacidade


	for(int i =0; i < n;i ++)
	{
		cin >> tempo[i] >> pizzas[i];
	}

	int auxtempo; // tempoar aux para o tempoalor
	int auxP; // tempoar aux para o pizzas


   // ordernando do maior para menor
	for(int i = 0; i< n;i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(tempo[j] < tempo[i])
			{
				auxtempo = tempo[i];
				tempo[i] = tempo[j]; // ordernando tempoetor de tempoalor
				tempo[j] = auxtempo;

				auxP = pizzas[i];
				pizzas[i] = pizzas[j]; // ordernando tempoetor de pizzas
				pizzas[j] = auxP;
			}
		}
	}

	cout << "O tempo total foi de:" << endl;
	cout << soltempoe(mochila) << endl;
	
	
	return 0;
}