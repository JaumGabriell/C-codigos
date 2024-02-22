#include <iostream>

using namespace std;

const int MAXN = 1001;

int n, m;
int peso[MAXN], valor[MAXN];
int pd[MAXN][MAXN];

int solve(int idx, int cap)
{
    // caso base: se j� processou todos os itens ou se a capacidade da mochila � 0
    if (idx == n || cap == 0)
    {
        return 0;
    }

    // verificando se j� calculou o valor dessa posi��o da matriz de memoiza��o
    if (pd[idx][cap] != -1)
    {
        return pd[idx][cap];
    }

    // caso n�o pegue o item atual
    int nao_pega = solve(idx + 1, cap);

    int pega = 0;
    // caso pegue o item atual, se ele n�o ultrapassar a capacidade da mochila
    if (cap >= peso[idx])
    {
        pega = valor[idx] + solve(idx + 1, cap - peso[idx]);
    }

    // atualizando a matriz de memoiza��o com o maior valor encontrado
    pd[idx][cap] = max(nao_pega, pega);

    return pd[idx][cap];
}

int main()
{
	cin >> n;
	
    while (n != 0)
    {

        if (n == 0)
        {
            break;
        }

        cin >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> peso[i] >> valor[i];
        }

        // inicializando a matriz de memoiza��o com -1
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                pd[i][j] = -1;
            }
        }

        // chamando a fun��o solve para obter o valor m�ximo poss�vel
        int max_valor = solve(0, m);

        cout << max_valor << " min." << endl;
        
        cin >> n;
    }

    return 0;
}
