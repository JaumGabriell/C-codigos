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

// funções para remover nó
treenodeptr tMenor(treenodeptr &raiz)
{
    treenodeptr t;
    t = raiz;
    if(t->esq == NULL) // encontrou o menor valor
    {
        raiz = raiz->dir;
        return t;
    }
    else// continua a busca
    return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x)
{
    treenodeptr p;
    
    if(raiz == NULL)// arvore vazia
    return 1;
    if(x == raiz->info)
    {
        p = raiz;
        if(raiz->esq == NULL) // a raiz nao tem filho esquerdo
        {
            raiz = raiz->esq;
        }
        else if(raiz->dir == NULL){ //raiz nao tem filho direito
        raiz = raiz -> dir;
        }
        else // raiz tem ambos filhos
        {
            p = tMenor(raiz->dir);
            raiz->info = p -> info;
        }

        delete p;
        return 0;

    }
    else if(x < raiz -> info)
    {
        return tRemove(raiz->esq,x);
    }
    else
    return tRemove(raiz->dir,x);
}

// função para imprimir em ordem crescente
void imprimirEmOrdemCrescente(TreeNode* p) {
    
    if (p != NULL) {
        imprimirEmOrdemCrescente(p->esq);
            cout << p->info << " ";
        imprimirEmOrdemCrescente(p->dir);
    }
}

int main(){
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    int num; // numero a ser inserido na arvore

    int x; // numero a ser removido

    int aux; // var auxiliar


    // lendo numeros para colocar dentro da arvore

    cin >> num;

    while(num != 0)
    {
        if(tPesq(arvore,num)== NULL)
        inserir(arvore,num);
        cin >> num;
    }
    
    // lendo numero a ser removido
    cin >> x;

    aux = tRemove(arvore,x);

    if(aux == 0)
    {
        imprimirEmOrdemCrescente(arvore);
    }

    

    return 0;
}