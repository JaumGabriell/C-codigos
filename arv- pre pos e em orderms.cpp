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

// função para mostra em Pre Ordem
void preOrdem(treenodeptr arvore)
{
    if(arvore != NULL)
    {
        cout << arvore ->info << " ";
        preOrdem(arvore -> esq);
        preOrdem(arvore -> dir);
    }
}
// função para mostrar em Pós Ordem
void posOrdem(treenodeptr arvore)
{
    if(arvore != NULL)
    {
        posOrdem(arvore -> esq);
        posOrdem(arvore -> dir);
        cout << arvore ->info << " ";
    }
}
// função para mostrar em Em Ordem
void emOrdem(treenodeptr arvore)
{
    if(arvore != NULL)
    {
        emOrdem(arvore -> esq);
        cout << arvore ->info << " ";
        emOrdem(arvore -> dir);
    }
}

int main(){
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    int num; // numero a ser inserido na arvore

    // lendo numeros para colocar dentro da arvore

    cin >> num;

    while(num != 0)
    {
        if(tPesq(arvore,num)== NULL)
        inserir(arvore,num);
        cin >> num;
    }

    // mostrando em pre pos e em
    cout << "Pre: ";
    preOrdem(arvore);
    cout << endl;
    cout << "Em ordem: ";
    emOrdem(arvore);
    cout << endl;
    cout << "PosOrdem: ";
    posOrdem(arvore);

    return 0;
}