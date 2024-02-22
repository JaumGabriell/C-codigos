#include <iostream>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};
typedef TreeNode *treenodeptr;
// função que verifica se um número é primo
bool ehPar(int x) {
    return x % 2 == 0;
}

// função para contar numeros pares
int contaPares(TreeNode* p) {
    if (p == NULL) {
        return 0; // árvore vazia, nenhum número par
    }

    int pares = 0; // contador de números pares

    // Verifica se o número na raiz da árvore é par
    if (ehPar(p->info)) {
        pares++;
    }

    // Verifica os números pares nas subárvores esquerda e direita recursivamente
    pares += contaPares(p->esq);
    pares += contaPares(p->dir);

    return pares;
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

// função que busca um elemento na árvore binária
treenodeptr tPesq(TreeNode* p, int x) {
    if (p == NULL) {
        return NULL;
    } else if (x == p->info) {
        return p;
    } else if (x < p->info) { // procura na subarvore esq
        return tPesq(p->esq, x);
    } else { // procura na subarvore dir
        return tPesq(p->dir, x);
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
        if(tPesq(arvore,num)== NULL)
        inserir(arvore, num);
        cin >> num;
    }
    
int quantidadePares = contaPares(arvore);
cout << quantidadePares << " numeros pares" << endl;


    return 0;
}
