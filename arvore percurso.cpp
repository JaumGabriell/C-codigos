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
        return "Em";
    }
    if (x < p->info) {
        string ordem = buscar(p->esq, x);
        if (ordem != "Em") {
            return "Pre";
        }
    } else {
        string ordem = buscar(p->dir, x);
        if (ordem != "Em") {
            return "Pos";
        }
    }
    return "Elemento nao encontrado";
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // lê alguns números para inserir na árvore
    int num;
   // int n; // quantidade de elementos

    // cout << "Digite a quantidade de elementos" << endl;
    // cin >> n;
    cin >> num;

    // cout << "Digite os numeros a serem inseridos na arvore: " << endl;
    while(num != -1) {
        inserir(arvore, num);
        cin >> num;
    }

    // lê o número a ser procurado na árvore
    int numProcurado;

    cin >> numProcurado;

    // busca o número na árvore e mostra em qual ordem ele é encontrado
    string ordem = buscar(arvore, numProcurado);
    // cout << "O numero " << numProcurado << " foi encontrado na ordem: " << ordem << endl;
    cout << ordem;

    return 0;
}
