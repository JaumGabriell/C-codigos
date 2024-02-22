#include <iostream>
using namespace std;

const int MAXIMO_DE_DIAS = 50;

// Fun��o analisar recebe um vetor de lucros, a quantidade de dias e o custo por dia.
int analisar(int lucros[], int quantidadeDeDias, int custoPorDia) {
    int maximo = 0;
    int maximoAteAqui = 0;

    // Itera��o pelos dias
    for (int dia = 0; dia < quantidadeDeDias; dia++) {
    	
        // Calcula o lucro do dia considerando o custo por dia.
        int lucro = lucros[dia] - custoPorDia;

        // Se o lucro for negativo, n�o considera para a soma acumulada.
        maximoAteAqui = max(0, maximoAteAqui + lucro);

        // Verifica se o novo valor acumulado � maior que o m�ximo encontrado at� ent�o.
        maximo = max(maximo, maximoAteAqui);
    }

    return maximo; // Retorna o lucro m�ximo acumulado.
}

int main() {
    int DIAS, CUSTO_POR_DIA;
    int LUCROS[MAXIMO_DE_DIAS];

    // Itera��o pelos casos de teste
    while (cin >> DIAS >> CUSTO_POR_DIA) {
    	
        // Leitura dos lucros de cada dia
        for (int i = 0; i < DIAS; i++) {
            cin >> LUCROS[i];
        }

        // Chamada da fun��o analisar e impress�o do resultado.
        cout << analisar(LUCROS, DIAS, CUSTO_POR_DIA) << endl;
    }

    return 0;
}
