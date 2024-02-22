#include <iostream>
using namespace std;

const int MAXIMO_DE_DIAS = 50;

// Função analisar recebe um vetor de lucros, a quantidade de dias e o custo por dia.
int analisar(int lucros[], int quantidadeDeDias, int custoPorDia) {
    int maximo = 0;
    int maximoAteAqui = 0;

    // Iteração pelos dias
    for (int dia = 0; dia < quantidadeDeDias; dia++) {
    	
        // Calcula o lucro do dia considerando o custo por dia.
        int lucro = lucros[dia] - custoPorDia;

        // Se o lucro for negativo, não considera para a soma acumulada.
        maximoAteAqui = max(0, maximoAteAqui + lucro);

        // Verifica se o novo valor acumulado é maior que o máximo encontrado até então.
        maximo = max(maximo, maximoAteAqui);
    }

    return maximo; // Retorna o lucro máximo acumulado.
}

int main() {
    int DIAS, CUSTO_POR_DIA;
    int LUCROS[MAXIMO_DE_DIAS];

    // Iteração pelos casos de teste
    while (cin >> DIAS >> CUSTO_POR_DIA) {
    	
        // Leitura dos lucros de cada dia
        for (int i = 0; i < DIAS; i++) {
            cin >> LUCROS[i];
        }

        // Chamada da função analisar e impressão do resultado.
        cout << analisar(LUCROS, DIAS, CUSTO_POR_DIA) << endl;
    }

    return 0;
}
