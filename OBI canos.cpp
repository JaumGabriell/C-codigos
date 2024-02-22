#include <iostream>

using namespace std;

int n; // quantidade de elementos a serem analisados
int comprimento[2004], valor[2004]; //variaveis de comprimento e valor de cada cano
int pd[2004][2004]; //variavel para a pd
int itens_pegos[2004][2004];

int solve(int i, int cap) // os parametros sao o indice do seu produto e a capacidade atual da mochila
{
	int pega, npega; // variavel auxiliar do processo de decisao

	if(cap < 0) //caso nao tenha mais espaco na mochila
		return 0;

	if(i == n) // caso tenha chego no ultimo item
		return 0;
	if(pd[i][cap]!=-1) // caso já esteja calculado o valor ela retorna o proprio valor a fim de evitar calculos desnecessarios
		return pd[i][cap];
	
	
	npega = solve(i + 1, cap); // valor caso nao pegue o item

	pd[i][cap] = npega;
	

	if(cap >= comprimento[i]) //caso seja possivel pegar o item
	{
		pega = solve(i + 1, comprimento[i]) + valor[i]; //valor caso pegue o item

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
    int T; // tamanho do cano da OBI // que seria a capacidade da mochila //

    //lendo número de proposta que receberam
    cin >> n;

    // lendo tamanho do cano da OBI
    cin >> T;

    // lendo o comprimento e o valor de cada cano

    for(int i = 0; i < n; i++)
    {
        cin >> comprimento[i] >> valor[i];
    }
    
    for(int i = 0; i< 2004; i++){
		for(int j = 0; j < 2004; j++){
			pd[i][j] = -1;
        }
    }

    cout << "O valor da melhor proposta foi de: ";
    cout << solve(0,T) << endl;

    return 0;
}