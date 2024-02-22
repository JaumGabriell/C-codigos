#include <iostream>

using namespace std;

int n; // quantidade de elementos a serem analisados
int X[2004], Y[2004]; //variaveis de X(poder de destruição do canhão) e Y peso de cada projétil
int pd[2004][2004]; //variavel para a pd
int itens_pegos[2004][2004];

int solve(int i, int cap) // os parametros sao o indice do seu produto e a X atual da mochila
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
	

	if(cap >= Y[i]) //caso seja possivel pegar o item
	{
		pega = solve(i + 1, cap - Y[i]) + X[i]; //valor caso pegue o item

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
		return pd[i][cap]; // caso nao tenha mais X
}

int main()
{
    int S; // resultado da função solve

    int R; // resistência do castelo

    int K; // capacidade do canhão // que seria a capacidade da mochila //

    //lendo número de projeteis disponiveis
    cin >> n;

    // lendo o X (poder de destruição) e peso de cada projétil

    for(int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    
    for(int i = 0; i< 2004; i++){
		for(int j = 0; j < 2004; j++){
			pd[i][j] = -1;
        }
    }

    // lendo capacidade do canhão
    cin >> K;

	// lendo resistência do castelo

    cin >> R;

    S = solve(0,K);

    if(S >= R)
    {
        cout << "Missao completada com sucesso";
    }
    else
    cout << "Falha na missao";

    

    return 0;
}