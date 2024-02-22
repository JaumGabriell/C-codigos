#include <iostream>


using namespace std;


int n; // quantidade de elementos a serem analisados
int v[2004], peso[2004]; //variaveis de quantidade de nota na mala e o peso de cada mala
int pd[2004][2004]; //variavel para a pd
int itens_pegos[2004][2004];

int solve(int i, int cap, int t) // os parametros sao o indice do seu produto e a capacidade atual da mochila
{
	int pega, npega; // variavel auxiliar do processo de decisao

	if(cap < 0) //caso nao tenha mais espaco na mochila
		return 0;

	if(i == n) // caso tenha chego no ultimo item
		return 0;
	if(pd[i][cap] != -1) // caso já esteja calculado o valor ela retorna o proprio valor a fim de evitar calculos desnecessarios
		return pd[i][cap];


	npega = solve(i + 1, cap, t); // valor caso nao pegue o item

	pd[i][cap] = npega;


	// coloquei t > 0 por medo de algum caso muito especifico a capacidade de malas do carro zerar antes da capacidade de peso
	// depois consegue me explicar se precisava ou não?
	if(cap >= peso[i] && t > 0) //caso seja possivel pegar o item
	{
		pega = solve(i + 1, cap - peso[i], t - 1) + v[i]; //valor caso pegue o item

		if(pega > npega)  //caso pegar seja uma melhor opcao
		{
			itens_pegos[i][cap] = 1; // caminho valendo 1 significa que peguei o item
			pd[i][cap] = pega;
			return pd[i][cap];
		}
		else
		{
			itens_pegos[i][cap] = 0; // caminho valendo 0 significa que nao peguei o item
			return pd[i][cap];
		}
	}

	else
		return pd[i][cap]; // caso nao tenha mais capacidade
}

int main()
{
	int C;
	int T;
	cout << "Insira a quantidade de malas" << endl;
	cin >> n;
	cout << "Insira a capacidade de peso do carro" << endl;
	cin >> C;
	cout << "Insira a quantidade de malas que cabem no carro" << endl;
	cin >> T;

	for(int i = 0; i < n; i++)
	{
		cout << "Insira o peso de cada mala e a quantidade de notas nela" << endl;
		cin >> peso[i] >> v[i];

	}

	for(int i = 0; i < 2004; i++)
		for(int j = 0; j < 2004; j++)
			pd[i][j] = -1;


	cout << "O valor total de notas foi de: ";
	cout << solve(0, C, T) << endl;
	cout << "---------------------" << endl;



	return 0;
}
