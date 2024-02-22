#include <iostream>
using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};

// função que verifica se um número é primo
bool isPrimo(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
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
void tPesq(TreeNode* p, int x) {
    if (p == NULL) {
        cout << "Nao encontrado" << endl;
    } else if (x == p->info) {
        cout << "Encontrado" << endl;
    } else if (x < p->info) {
        tPesq(p->esq, x);
    } else {
        tPesq(p->dir, x);
    }
}

// função para remover um nó da árvore binária
TreeNode* remover(TreeNode* p, int x) {
    if (p == NULL) {
        return NULL;
    } else if (x < p->info) {
        p->esq = remover(p->esq, x);
        return p;
    } else if (x > p->info) {
        p->dir = remover(p->dir, x);
        return p;
    } else {
        if (p->esq == NULL && p->dir == NULL) {
            delete p;
            return NULL;
        } else if (p->esq == NULL) {
            TreeNode* tmp = p->dir;
            delete p;
            return tmp;
        } else if (p->dir == NULL) {
            TreeNode* tmp = p->esq;
            delete p;
            return tmp;
        } else {
            TreeNode* tmp = p->dir;
            while (tmp->esq != NULL) {
                tmp = tmp->esq;
            }
            p->info = tmp->info;
            p->dir = remover(p->dir, tmp->info);
            return p;
        }
    }
}

// emprimindo em ordem crescente
void imprimirEmOrdemCrescente(TreeNode* p) {
    if (p != NULL) {
        imprimirEmOrdemCrescente(p->esq);
        if (!isPrimo(p->info)) {
            cout << p->info << " ";
        }
        imprimirEmOrdemCrescente(p->dir);
    }
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;
    int x; // número a ser procurado
    bool aux = false; // var auxiliar

    // lê alguns números para inserir na árvore
    int num;
    int n; // quantidade de elementos
   
   // lendo quantidade de elementos
    cin >> n;
   
    cout << endl;

    // lendo numeros a serem colocados
   for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    inserir(arvore, num);
    }
    // lendo número a ser procurado
    cin >> x;

    tPesq(arvore,x);
    

    return 0;
}
