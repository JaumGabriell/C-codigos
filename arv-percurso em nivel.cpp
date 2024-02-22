#include <iostream>
#include <list>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};
typedef TreeNode *treenodeptr;

struct no
{
    treenodeptr info;
    no *next;
};

typedef no* noptr;

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

void emNivel(treenodeptr t){

    treenodeptr n;
    list<treenodeptr> q;
    if (t != NULL){

        q.push_back(t);
        while (!q.empty()){

            n = *q.begin();
            q.pop_front();
            if (n->esq != NULL)
                q.push_back(n->esq);
            if (n->dir != NULL)
                q.push_back(n->dir);
            cout << n->info << " ";
        }
        cout << endl;
    }

    //limpa memoria usada pela lista
	while(!q.empty())
		q.pop_front();
}

int main(){
    // cria uma árvore binária vazia
    treenodeptr arvore = NULL;

    int nums; // numeros a serem colocados

    cin >> nums;

    while(nums != -1)
    {
        if(tPesq(arvore,nums) == NULL)
        inserir(arvore,nums);
         cin >> nums;
    }

    emNivel(arvore);

    return 0;
}