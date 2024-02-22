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

// função que busca um elemento na árvore binária
void tPesq(TreeNode* p, int x) {
    if (p == NULL) {
        cout << "Elemento nao encontrado" << endl;
    } else if (x == p->info) {
        cout << "Elemento encontrado" << endl;
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
            cout << p->info << " ";
        imprimirEmOrdemCrescente(p->dir);
    }
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // lê alguns números para inserir na árvore
    int num;
    // numero a ser removido
    int x; 
    int aux = 0;
    //int n; // quantidade de elementos
    //cout << "Digite a quantidade de elementos" << endl;
    //cin >> n;
    //cout << "Digite os numeros a serem inseridos na arvore: ";
   // cout << endl;
    cin >> num;
    aux++;
   while(num != 0) {
    inserir(arvore, num);
    cin >> num;
    aux++;
    }
    cin >> x;
    // remove os nos da árvore que possuem o no numero 'x'
    
    arvore = remover(arvore, x);
    
    // imprime os elementos da árvore em ordem crescente
    //cout << "Elementos em ordem crescente: ";
    imprimirEmOrdemCrescente(arvore); 
    cout << endl;

    return 0;
}
