#include <iostream> // Entrada e sa�da
#include <climits> // INT_MAX

using namespace std;

int n; // quantidade de elementos a serem analisados
int v[2004], comprimento[2004]; // valor e comprimento de cada item
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

		if(cap>=comprimento[i])
		{
			itens_pegos[i] = i;
			val += v[i];
			cap -= comprimento[i];
		}


	}
	return val;
}

int main()
{
	int T;
	cout << "Insira a capacidade dos canos" << endl;
	cin >> T;
	cout << "Insira a quantidade de elementos" << endl;
	cin >> n;

	for(int i =0; i < n;i ++)
	{
		cin >> v[i] >> comprimento[i];
	}

	int auxV; // var aux para o valor
	int auxP; // var aux para o comprimento


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

				auxP = comprimento[i];
				comprimento[i] = comprimento[j]; // ordernando vetor de comprimento
				comprimento[j] = auxP;
			}
		}
	}

	cout << "O valor total foi de:" << endl;
	cout << solve(T) << endl;
	
	
	return 0;
}