#include <iostream> // Entrada e sa�da
#include <climits> // INT_MAX

using namespace std;

int n; // quantidade de elementos a serem analisados
int quant[2004], peso[2004]; // quant e peso de cada item
int itens_pegos[2004]; // 

int solve(int cap, int pac)
{
	int val = 0;

	for(int i = 0; i<n; i++)
	{
		if(cap < 0 || pac < 0)
		{
			return val;
		}

		if(cap>=peso[i] || pac>0)
		{
			itens_pegos[i] = i;
			val += quant[i];
			cap -= peso[i];
		}


	}
	return val;
}

int main()
{
    cout << "Insira a quantidade de pecaotes" << endl;
	cin >> n;
	int pacote;
	cout << "Insira a capacidade da pacote" << endl;
	cin >> pacote;
	

	for(int i =0; i < n;i ++)
	{
		cin >> peso[i] >> quant[i];
	}

	int auxquant; // var aux para a quant
	int auxP; // var aux para o peso


   // ordernando do maior para menor
	for(int i = 0; i< n;i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(quant[j] < quant[i])
			{
				auxquant = quant[i];
				quant[i] = quant[j]; // ordernando vetor de valor
				quant[j] = auxquant;

				auxP = peso[i];
				peso[i] = peso[j]; // ordernando vetor de peso
				peso[j] = auxP;
			}
		}
	}

	cout << "O valor total foi de:" << endl;
	cout << solve(50,pacote) << endl;
	
	
	return 0;
}