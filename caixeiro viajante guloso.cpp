#include <iostream> // Entrada e sa?da
#include <climits> // INT_MAX

using namespace std;

int main()
{
	int custo[100][100]; // 100 -> numero maximo de cidades
	// custo[i][j] = custo de ir da cidade 'i' para a cidade 'j'
	int cidade_inicial; // Primeira e ultima cidade
	int n; // numero de cidades

	cout << "Entre com o numero de cidades" << endl;
	cin >> n;
	cout << "Entre com a cidade inicial" << endl;
	cin >> cidade_inicial;

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			cout << "Entre com o custo de ir da cidade " << i << " para a cidade " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}

	bool vis[100]; // marca se ja visitou ou nao uma cidade
	int menor_custo; // menor custo da viagem
	int custo_at; // menor custo atual
	int cidade_atual; // cidade atual
	int proxima_cidade; // proxima cidade

	// inicializando vetor vis (nenhuma cidade foi visitada no inicio)
	for(int i = 0; i < n; i++)
		vis[i] = false;

	// guloso

	// fa?a seu c?digo aqui


	menor_custo = INT_MAX; // menor custo recebe um valor muito grande inicialmente
	custo_at = 0; // custo atual come�a em zero
	cidade_atual = cidade_inicial; // come�a na cidade inicial
	vis[cidade_inicial] = true; // marca a cidade inicial como visitada


	while(true)
	{
		proxima_cidade = -1; // inicializa a pr�xima cidade como inv�lida

		// percorre as cidades, procurando pela mais pr�xima
		for(int i = 0; i < n; i++)
		{
			// se a cidade i ainda n�o foi visitada e o custo de deslocamento da cidade atual para i � menor que o menor custo atual
			if(!vis[i] && custo[cidade_atual][i] < menor_custo)
			{
				proxima_cidade = i; // a cidade i � a mais pr�xima encontrada at� o momento
				menor_custo = custo[cidade_atual][i]; // atualiza o menor custo
			}
		}

		// se n�o foi encontrada nenhuma cidade pr�xima, ent�o todas as cidades foram visitadas
		if(proxima_cidade == -1)
			break;

		// caso contr�rio, visita a cidade mais pr�xima e atualiza as vari�veis
		vis[proxima_cidade] = true;
		cidade_atual = proxima_cidade;
		custo_at += menor_custo;
		menor_custo = INT_MAX; // reseta o menor custo para a pr�xima itera��o
	}

// adiciona o custo de retorno para a cidade inicial
	custo_at += custo[cidade_atual][cidade_inicial];

// imprime o custo total da viagem
	cout << "Custo total da viagem: " << custo_at << endl;


	return 0;
}
