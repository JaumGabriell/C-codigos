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

// função que busca um elemento na árvore binária e o remove, caso encontrado
void tPesq(TreeNode*& p, int x) {
    if (p == NULL) {
        cout << "Elemento nao encontrado" << endl;
    } else if (x == p->info) {
        cout << "Elemento encontrado!" << endl;
        TreeNode* aux;
        if (p->esq == NULL && p->dir == NULL) {
            aux = p;
            p = NULL;
            delete aux;
        } else if (p->esq == NULL) {
            aux = p;
            p = p->dir;
            delete aux;
        } else if (p->dir == NULL) {
            aux = p;
            p = p->esq;
            delete aux;
        } else {
            aux = p->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }
            p->info = aux->info;
            tPesq(p->esq, aux->info);
        }
    } else if (x < p->info) {
        tPesq(p->esq, x);
    } else {
        tPesq(p->dir, x);
    }
}

// função recursiva que imprime os elementos da árvore em ordem crescente
void imprimir(TreeNode* p) {
    if (p != NULL) {
        imprimir(p->esq);
        cout << p->info << " ";
        imprimir(p->dir);
    }
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // lê números para inserir na árvore
    cout << "Digite os numeros a serem inseridos na arvore (digite 0 para encerrar): ";
    int num;
    cin >> num;
    while (num != 0) {
        inserir(arvore, num);
        cin >> num;
    }

    // lê números para buscar e remover na árvore
    cout << "Digite os numeros a serem buscados e removidos da arvore (digite 0 para encerrar): ";
    cin >> num;
    while (num != 0) {
        tPesq(arvore, num);
        cin >> num;
    }

    // imprime os elementos da árvore em ordem crescente
    cout << "Elementos da arvore em ordem crescente: ";
    imprimir(arvore);
    cout << endl;

    return 0;
}
