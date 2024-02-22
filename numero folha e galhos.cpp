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

// função que conta a quantidade de folhas na árvore
int contarFolhas(TreeNode* p) {
    if (p == NULL) {
        return 0;
    } else if (p->esq == NULL && p->dir == NULL) {
        return 1;
    } else {
        return contarFolhas(p->esq) + contarFolhas(p->dir);
    }
}

// função que conta a quantidade de nós que não são folhas na árvore
int contarNaoFolhas(TreeNode* p) {
    if (p == NULL) {
        return 0;
    } else if (p->esq == NULL && p->dir == NULL) {
        return 0;
    } else {
        return 1 + contarNaoFolhas(p->esq) + contarNaoFolhas(p->dir);
    }
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // lê alguns números para inserir na árvore
    int num;
    int n; // quantidade de elementos

    cout << "Digite a quantidade de elementos: ";
    cin >> n;

    cout << "Digite os numeros a serem inseridos na arvore: ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        inserir(arvore, num);
    }

    int folhas = contarFolhas(arvore);
    int naoFolhas = contarNaoFolhas(arvore);

    cout << "Quantidade de folhas: " << folhas << endl;
    cout << "Quantidade de nos que nao sao folhas: " << naoFolhas << endl;

    return 0;
}
