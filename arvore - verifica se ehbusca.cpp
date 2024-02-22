#include <iostream>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};
typedef TreeNode *treenodeptr;

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

// Função para verificar se uma árvore binária é uma árvore de busca binária (BST)
bool ehArvoreBusca(TreeNode* p, int minValor, int maxValor) {
    if (p == NULL) {
        return true; // Árvore vazia é considerada uma BST
    }

    // Verifica se o valor do nó está dentro do intervalo permitido
    if (p->info < minValor || p->info > maxValor) {
        return false;
    }

    // Verifica recursivamente se as subárvores também são BSTs
    bool esqBST = ehArvoreBusca(p->esq, minValor, p->info - 1); // Limite máximo na subárvore esquerda é o valor do nó atual - 1
    bool dirBST = ehArvoreBusca(p->dir, p->info + 1, maxValor); // Limite mínimo na subárvore direita é o valor do nó atual + 1

    // Retorna true apenas se as subárvores esquerda e direita também são BSTs
    return esqBST && dirBST;
}

int main(){
    // cria uma árvore binária vazia
    treenodeptr arvore = NULL;

    int n; // quantidade de nuemros a serem colocados
    cin >> n;
    int nums; // numeros a serem colocados

    int INT_MIN, INT_MAX;

    for(int i = 0; i < n; i++)
    {
        cin >> nums;
        if(tPesq(arvore,nums) == NULL)
        inserir(arvore,nums);

    }
    int x; // numero a ser procurado
    cin >> x;

    if(tPesq(arvore,x) == NULL)
    {
        cout << "Nao encontrado";
    }
    else
    cout << "Encontrado";

     bool ehBST = ehArvoreBusca(arvore, INT_MIN, INT_MAX);

    if (ehBST) {
        cout << "A árvore é uma árvore de busca binária (BST)." << endl;
    } else {
        cout << "A árvore não é uma árvore de busca binária (BST)." << endl;
    }

    return 0;
}