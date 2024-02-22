// escolhi o metodo guloso para retornar o valor mais rápido possível
// já que é natal o rapaz tem que comprar os enfeites logo ou vai acabar


#include <iostream> // Entrada e sa�da
#include <climits> // INT_MAX

using namespace std;

int n; // quantidade de elementos a serem analisados
int v[2004], peso[2004]; // quantidade e peso de cada pacote
int itens_pegos[2004]; //

int solve(int cap, int quantpact)
{
	int val = 0;

	for(int i = 0; i < quantpact; i++)
	{
		if(cap < 0)
		{
			return val;
		}

		if(cap >= peso[i])
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
	int P; // quantidade de pacotes
	int W; // peso que o galho suporta
	cout << "Insira a quantidade de galhos" << endl;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cout << "Insira a quantidade de pacotes" << endl;
		cin >> P;
		cout << "Insira o peso que o galho suporta" << endl;
		cin >> W;

		for(int i = 0; i < P; i ++)
		{
			cout << "Insira a quantidade de enfeites e peso do pacote" << endl;
			cin >> v[i] >> peso[i];
		}

		int auxV; // var aux para o quantidade
		int auxP; // var aux para o peso


		// ordernando do maior para menor
		for(int i = 0; i < P; i++)
		{
			for(int j = 0; j < P; j++)
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

		cout << "Galho " << i + 1 << ":" << endl;

		cout << "Numero total de enfeites: " << solve(W, P) << endl;
	}


	return 0;
}
