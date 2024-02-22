#include <iostream>
#include <iomanip>
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


int calcularsoma(treenodeptr p)
{
    if(p == NULL)
    {
        return 0; // nenhum elemento encontrado
    }
    else
    return p-> info + calcularsoma(p->esq) + calcularsoma(p->dir);
}
int numelementos(treenodeptr p)
{
    if(p == NULL)
    {
        return 0; // nenhum elemento encontrado
    }
    else
    return 1+ numelementos(p->esq) + numelementos(p->dir);
}

// função para calcular media
float media(treenodeptr arvore)
{
    int soma = calcularsoma(arvore);
    int n = numelementos(arvore);
    if(n < 0)
    {
        return 0;
    }
    else
    {
        return (1.0*soma)/(n*1.0);
    }
    

}

int main(){
    // cria uma árvore binária vazia
    TreeNode* arvore = NULL;

    // numero a ser inserido na arvore
    int num;
    int x; // numero a ser procurado
    float mediar;


    // lendo numeros para colocar dentro da arvore
    cin >> num;

    while(num != -1)
    {
        inserir(arvore,num);
        cin >> num;
    }

    mediar = media(arvore);

    cout << fixed << setprecision (2);

    cout << mediar << endl;

    

    return 0;
}