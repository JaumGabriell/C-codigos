#include <iostream>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};

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

// função que busca um número na árvore binária e retorna em qual ordem ele é encontrado
string buscar(TreeNode* p, int x) {
    if (p == NULL) {
        return "Elemento nao encontrado";
    }
    if (p->info == x) {
        return "Em-ordem";
    }
    if (x < p->info) {
        string ordem = buscar(p->esq, x);
        if (ordem != "Elemento nao encontrado") {
            return "Pre-ordem";
        }
    } else {
        string ordem = buscar(p->dir, x);
        if (ordem != "Elemento nao encontrado") {
            return "Pos-ordem";
        }
    }
    return "Elemento nao encontrado";
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // lê alguns números para inserir na árvore
    int num;
    int n; // quantidade de elementos

    cout << "Digite a quantidade de elementos" << endl;
    cin >> n;

    cout << "Digite os numeros a serem inseridos na arvore: " << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        inserir(arvore, num);
    }

    // lê o número a ser procurado na árvore
    int numProcurado;
    cout << "Digite o numero a ser procurado na arvore: ";
    cin >> numProcurado;

    // busca o número na árvore e mostra em qual ordem ele é encontrado
    string ordem = buscar(arvore, numProcurado);
    cout << "O numero " << numProcurado << " foi encontrado na ordem: " << ordem << endl;

    return 0;
}