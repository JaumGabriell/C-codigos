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

bool verificarSimetria(TreeNode* arvore1, TreeNode* arvore2) {
    // Caso base: se ambos os nós são nulos, eles são considerados simétricos
    if (arvore1 == NULL && arvore2 == NULL) {
        return true;
    }

    // Se apenas um dos nós é nulo, eles não são simétricos
    if (arvore1 == NULL || arvore2 == NULL) {
        return false;
    }

    // Verificar se os valores nos nós são iguais e se as subárvores são simétricas
    return (arvore1->info == arvore2->info) &&
           verificarSimetria(arvore1->esq, arvore2->dir) &&
           verificarSimetria(arvore1->dir, arvore2->esq);
}

bool arvoreSimetrica(TreeNode* arvore) {
    // Se a árvore é nula, ela é considerada simétrica
    if (arvore == NULL) {
        return true;
    }

    // Chamar a função auxiliar para verificar a simetria das subárvores esquerda e direita
    return verificarSimetria(arvore->esq, arvore->dir);
}


void tDestruir(treenodeptr &arvore)
{
    if(arvore != NULL)
    {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }

    arvore = NULL;
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

if (arvoreSimetrica(arvore)) {
    cout << "A árvore é simétrica" << endl;
} else {
    cout << "A árvore não é simétrica" << endl;
}

tDestruir(arvore);


    return 0;
}