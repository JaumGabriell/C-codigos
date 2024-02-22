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

int main(){
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // numero a ser inserido na arvore
    int num;
    int n; // quantidade de numeros
    int x; // numero a ser procurado

    // lendo quantidade de numeros
    cin >> n;

    // lendo numeros para colocar dentro da arvore

    for(int i = 0; i< n; i++)
    {
        cin >> num;
        inserir(arvore, num);
    }
    
    // lendo numero a ser procurado
    cin >> x;

    // mostrando se está ou nao na arvore
    tPesq(arvore,x);

    return 0;
}