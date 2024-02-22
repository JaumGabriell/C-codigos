#include <iostream>
using namespace std;

struct PedraPreciosa
{
	int valor;
	int peso;
	int volume;
};

int main()
{

	int N; // Quantidade de pedras dispon�veis
	// lendo quantidade disponivel
	cin >> N;

	int C; // Peso m�ximo suportado pelo carrinho
	// lendo peso m�ximo
	cin >> C;

	int V; // Volume m�ximo suportado pelo carrinho
	// lendo volume m�ximo
	cin >> V;

	PedraPreciosa p[N]; //p � um vetor de dados do tipo PedraPreciosa

	for(int i = 0; i < N; i++)
		cin >> p[i].valor >> p[i].peso >> p[i].volume;

	// Alocando a matriz dp dinamicamente
	int*** dp = new int**[N + 1];
	for (int i = 0; i <= N; i++)
	{
		dp[i] = new int*[C + 1];
		for (int j = 0; j <= C; j++)
		{
			dp[i][j] = new int[V + 1];
		}
	}

	// Preenchimento da matriz dp
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= C; j++)
		{
			for (int k = 0; k <= V; k++)
			{
				if (i == 0 || j == 0 || k == 0)
				{
					// Se for a primeira linha, coluna ou profundidade, o valor � 0
					dp[i][j][k] = 0;
				}
				else if (p[i - 1].peso <= j && p[i - 1].volume <= k)
				{
					// Se o peso e o volume da pedra forem menores ou iguais aos limites do carrinho,
					// atualiza-se o valor m�ximo poss�vel que pode ser obtido
					dp[i][j][k] = max(dp[i - 1][j][k], p[i - 1].valor + dp[i - 1][j - p[i - 1].peso][k - p[i - 1].volume]);
				}
				else
				{
					// Se n�o for poss�vel adicionar a pedra, o valor m�ximo continua o mesmo da pedra anterior
					dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}

	// Valor m�ximo que pode ser obtido
	cout << "Valor maximo que pode ser obtido: " << dp[N][C][V] << endl;

	// Libera��o da mem�ria alocada pela matriz dp
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= C; j++)
		{
			delete[] dp[i][j];
		}
		delete[] dp[i];
	}
	delete[] dp;

	return 0;
}
