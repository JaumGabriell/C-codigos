#include <iostream>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};

// função que verifica se um número é primo
bool ehPrimo(int x) {
    if (x <= 1) {
        return false; // números menores ou iguais a 1 não são primos
    }

    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return false; // divisível por algum número, não é primo
        }
    }

    return true; // não é divisível por nenhum número, é primo
}

// função que conta a quantidade de números primos na árvore binária
int contaPrimos(TreeNode* p) {
    if (p == NULL) {
        return 0; // árvore vazia, nenhum número primo
    }

    int primos = 0; // contador de números primos

    // Verifica se o número na raiz da árvore é primo
    if (ehPrimo(p->info)) {
        primos++;
    }

    // Verifica os números primos nas subárvores esquerda e direita recursivamente
    primos += contaPrimos(p->esq);
    primos += contaPrimos(p->dir);

    return primos;
}

// função que insere um nó na árvore binária
void inserir(TreeNode*& p, int x) {
    if (p == NULL) {
        p = new TreeNode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    } else {
        if (x < p->info) {
            inserir(p->esq, x);
        } else {
            inserir(p->dir, x);
        }
    }
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // números a serem colocados
    int num;
    
    // lendo valores
    cin >> num;
    while(num != -1) {
        inserir(arvore, num);
        cin >> num;
    }

    int quantidadePrimos = contaPrimos(arvore);

    cout << quantidadePrimos << " numeros primos" << endl;

    return 0;
}
