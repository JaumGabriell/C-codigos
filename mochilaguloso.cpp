#include <iostream> // Entrada e sa�da
#include <climits> // INT_MAX

using namespace std;

int n; // quantidade de elementos a serem analisados
int v[2004], peso[2004]; // valor e peso de cada item
int itens_pegos[2004]; // 

int solve(int cap)
{
	int val = 0;

	for(int i = 0; i<n; i++)
	{
		if(cap < 0)
		{
			return val;
		}

		if(cap>=peso[i])
		{
			itens_pegos[i] = i;
			val += v[i];
			cap -= peso[i];
		}


	}
	return val;
}

int main()
{
	int mochila;
	cout << "Insira a capacidade da mochila" << endl;
	cin >> mochila;
	cout << "Insira a quantidade de elementos" << endl;
	cin >> n;

	for(int i =0; i < n;i ++)
	{
		cin >> v[i] >> peso[i];
	}

	int auxV; // var aux para o valor
	int auxP; // var aux para o peso


   // ordernando do maior para menor
	for(int i = 0; i< n;i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(v[j] < v[i])
			{
				auxV = v[i];
				v[i] = v[j]; // ordernando vetor de valor
				v[j] = auxV;

				auxP = peso[i];
				peso[i] = peso[j]; // ordernando vetor de peso
				peso[j] = auxP;
			}
		}
	}

	cout << "O valor total foi de:" << endl;
	cout << solve(mochila) << endl;
	
	
	return 0;
}