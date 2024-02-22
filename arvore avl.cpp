#include <iostream>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};
typedef TreeNode* treenodeptr;

// função que insere um nó na árvore binária
void inserir(treenodeptr& p, int x) {
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
treenodeptr tPesq(treenodeptr p, int x, int& contador) {
    if (p == NULL) {
        return NULL;
    } else if (x == p->info) {
        contador++;
        return p;
    } else if (x < p->info) {
        contador++;
        return tPesq(p->esq, x, contador);
    } else {
        contador++;
        return tPesq(p->dir, x, contador);
    }
}

// estrutura de um nó da árvore AVL
struct AVLNode {
    int info;
    int altura;
    AVLNode* esq;
    AVLNode* dir;
};
typedef AVLNode* avlnodeptr;

// função que retorna a altura de um nó
int altura(avlnodeptr p) {
    if (p == NULL) {
        return -1;
    } else {
        return p->altura;
    }
}

// função que atualiza a altura de um nó
void atualizarAltura(avlnodeptr p) {
    int alturaEsq = altura(p->esq);
    int alturaDir = altura(p->dir);
    p->altura = 1 + max(alturaEsq, alturaDir);
}

// função que realiza uma rotação simples à esquerda
void rotacaoEsquerda(avlnodeptr& p) {
    avlnodeptr q = p->dir;
    p->dir = q->esq;
    q->esq = p;
    atualizarAltura(p);
    atualizarAltura(q);
    p = q;
}

// função que realiza uma rotação simples à direita
void rotacaoDireita(avlnodeptr& p) {
    avlnodeptr q = p->esq;
    p->esq = q->dir;
    q->dir = p;
    atualizarAltura(p);
    atualizarAltura(q);
    p = q;
}

// função que realiza uma rotação dupla à esquerda
void rotacaoDuplaEsquerda(avlnodeptr& p) {
    rotacaoDireita(p->dir);
    rotacaoEsquerda(p);
}

// função que realiza uma rotação dupla à direita
void rotacaoDuplaDireita(avlnodeptr& p) {
    rotacaoEsquerda(p->esq);
    rotacaoDireita(p);
}

// função que insere um nó na árvore AVL
void inseriravl(avlnodeptr& p, int x) {
    if (p == NULL) {
        p = new AVLNode;
        p->info = x;
        p->altura = 0;
        p->esq = NULL;
        p->dir = NULL;
    } else {
        if (x < p->info) {
            inseriravl(p->esq, x);
            if (altura(p->esq) - altura(p->dir) == 2) {
                if (x < p->esq->info) {
                    rotacaoDireita(p);
                } else {
                    rotacaoDuplaDireita(p);
                }
            }
        } else if (x > p->info) {
            inseriravl(p->dir, x);
            if (altura(p->dir) - altura(p->esq) == 2) {
                if (x > p->dir->info) {
                    rotacaoEsquerda(p);
                } else {
                    rotacaoDuplaEsquerda(p);
                }
            }
        }
        atualizarAltura(p);
    }
}

// função que busca um elemento na árvore AVL
avlnodeptr tPesqAVL(avlnodeptr p, int x, int& contador) {
    if (p == NULL) {
        return NULL;
    } else if (x == p->info) {
        contador++;
        return p;
    } else if (x < p->info) {
        contador++;
        return tPesqAVL(p->esq, x, contador);
    } else {
        contador++;
        return tPesqAVL(p->dir, x, contador);
    }
}

int main() {
    // cria uma árvore binária vazia
    treenodeptr arvoreBinaria = NULL;

    // cria uma árvore AVL vazia
    avlnodeptr arvoreAVL = NULL;
    int contadorAVL = 0;

    int nums; // números a serem colocados
     cin >> nums;

    while(nums != 0) {
        inseriravl(arvoreAVL, nums);
        inserir(arvoreBinaria, nums);
         cin >> nums;
    }

    int x; // número a ser procurado
    cin >> x;

    int contadorBinaria = 0;
    treenodeptr resultadoBinaria = tPesq(arvoreBinaria, x, contadorBinaria);

    avlnodeptr resultadoAVL = tPesqAVL(arvoreAVL, x, contadorAVL);
    
     cout << "Arvore normal: " << contadorBinaria << endl;

    cout << "AVL: " << contadorAVL << endl;

    return 0;
}
