#include <iostream>


using namespace std;


int n; // quantidade de elementos a serem analisados
int quant[2004], peso[2004]; //variaveis de quant para cada item e o peso de cada item
int pd[2004][2004]; //variavel para a pd
int itens_pegos[2004][2004];

int solve(int i, int cap, int pacotes) // os parametros sao o indice do seu produto e a capacidade atual da pacote
{
	int pega, npega; // variavel auxiliar do processo de decisao

	if(cap < 0) //caso nao tenha mais espaco na pacote
		return 0;

	if(pacotes <= 0) //caso nao tenha mais espaco na pacote
		return 0;

	if(i == n) // caso tenha chego no ultimo item
		return 0;
	if(pd[i][cap]!=-1) // caso já esteja calculado o valor ela retorna o proprio valor a fim de evitar calculos desnecessarios
		return pd[i][cap];
	
	
	npega = solve(i + 1, cap, pacotes); // valor caso nao pegue o item

	pd[i][cap] = npega;
	

	if(cap >= peso[i]) //caso seja possivel pegar o item
	{
		pega = solve(i + 1, peso[i], pacotes - 1) + quant[i]; //valor caso pegue o item

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
	
	int pacote;
    cout << "Insira a quantidade de pacotes" << endl;
	cin >> n; 
	cout << "Insira a quantidade de pacotes que pode levar" << endl;
	cin >> pacote; 
	
	for(int i = 0; i < n; i++){
		cout << "Insira o peso e a quantidade de itens:" << endl;
		cin >>peso[i] >> quant[i];
		
	}
	
	for(int i = 0; i< 2004; i++)
		for(int j = 0; j < 2004; j++)
			pd[i][j] = -1;
	
	
	cout << "O valor total foi de: ";
	cout << solve(0, 50, pacote) << endl;
	cout << "---------------------"<< endl;
	
	
	return 0;
}