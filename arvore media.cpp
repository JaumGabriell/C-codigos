#include <iostream>
#include <iomanip>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};

// função que verifica se um número é primo
bool isPrimo(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
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

// função para calcular a soma dos elementos da árvore
int calcularSoma(TreeNode* p) {
    if (p == NULL) {
        return 0;
    } else {
        return p->info + calcularSoma(p->esq) + calcularSoma(p->dir);
    }
}

// função para contar o número de elementos da árvore
int contarElementos(TreeNode* p) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + contarElementos(p->esq) + contarElementos(p->dir);
    }
}

// função para calcular a média dos elementos da árvore
float media(TreeNode* arvore) {
    int soma = calcularSoma(arvore);
    int numElementos = contarElementos(arvore);
    if (numElementos > 0) {
        return static_cast<float>(soma) / numElementos;
    } else {
        return 0;
    }
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // lê os números para inserir na árvore
    int num;
    cin >> num;
    while (num != -1) {
        inserir(arvore, num);
        cin >> num;
    }

    // calcula e exibe a média dos elementos da árvore
    float avg = media(arvore);
    cout << fixed << setprecision(2);
    cout << "Media: " << avg << endl;

    return 0;
}
