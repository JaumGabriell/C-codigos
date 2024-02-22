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

// função que retorna a profundidade da árvore binária
int profundidade(TreeNode* p) {
    if (p == NULL) {
        return 0;
    } else {
        int profundidade_esq = profundidade(p->esq);
        int profundidade_dir = profundidade(p->dir);
        return max(profundidade_esq, profundidade_dir) + 1;
    }
}

int main() {
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // lê alguns números para inserir na árvore
    int num;
    int n; // quantidade de elementos

    cout << "Digite a quantidade de elementos: ";
    cin >> n;

    cout << "Digite os numeros a serem inseridos na arvore: ";
    cout << endl;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        inserir(arvore, num);
    }
  
    // calcula a profundidade da árvore binária
    int profund = profundidade(arvore);

    // exibe o resultado
    cout << "A profundidade da arvore e: " << profund - 1 << endl;

    return 0;
}
