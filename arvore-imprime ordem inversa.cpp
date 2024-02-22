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

// Função para imprimir os nós da árvore em ordem inversa (da direita para a esquerda)
void imprimirOrdemInversa(TreeNode* p) {
    if (p == NULL) {
        return;
    }

    imprimirOrdemInversa(p->dir);  // Imprime os nós da subárvore direita
    cout << p->info << " ";       // Imprime o valor do nó atual
    imprimirOrdemInversa(p->esq);  // Imprime os nós da subárvore esquerda
}

int main(){
    // cria uma árvore binária vazia
    treenodeptr arvore = NULL;

    int n; // quantidade de nuemros a serem colocados
    cin >> n;
    int nums; // numeros a serem colocados

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

    imprimirOrdemInversa(arvore);

    return 0;
}