#include <iostream>
using namespace std;

struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};

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

int maior(TreeNode* arvore)
{
    if(arvore == NULL)
    {
        return -1;
    }
    
    while(arvore -> dir)
    {
        arvore = arvore->dir;
    }

    return arvore->info;


}
int menor(TreeNode* arvore)
{
    if(arvore == NULL)
    {
        return -1;
    }
    
    while(arvore -> esq)
    {
        arvore = arvore->esq;
    }

    return arvore->info;

}

int main() {
    TreeNode* arvore = NULL;
    int num;

    // menor e maior numero
    int min, max;
    cin >> num;
    while (num != -1) {
        inserir(arvore, num);
        cin >> num;
    }

    min = menor(arvore);
    max = maior(arvore);

    cout << min << " e " << max;
    
    cout << endl;
    return 0;
}
