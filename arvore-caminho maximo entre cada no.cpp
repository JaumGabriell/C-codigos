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

// Função para encontrar o caminho máximo entre dois nós em uma árvore binária
int caminhoMaximo(TreeNode* p) {
    if (p == NULL) {
        return 0; // Árvore vazia
    }

    int caminhoEsq = caminhoMaximo(p->esq);
    int caminhoDir = caminhoMaximo(p->dir);

    // Verifica qual caminho é maior: da esquerda ou da direita
    int caminhoAtual = max(caminhoEsq, caminhoDir);

    // Verifica se o caminho máximo passa pelo nó atual
    int caminhoPassandoAtual = caminhoEsq + caminhoDir + 1;

    // Retorna o maior valor entre o caminho máximo atual e o caminho máximo passando pelo nó atual
    return max(caminhoAtual, caminhoPassandoAtual);
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
    int x; // numero a ser procurado
    cin >> x;

    if(tPesq(arvore,x) == NULL)
    {
        cout << "Nao encontrado";
    }
    else
    cout << "Encontrado";

    // Cálculo do caminho máximo
    int caminhoMax = caminhoMaximo(arvore);

    cout << "Caminho máximo da árvore: " << caminhoMax << endl;

    return 0;
}