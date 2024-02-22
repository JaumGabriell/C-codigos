#include <iostream>
#include<queue>
using namespace std;

// Estrutura de um nó da árvore binária
struct TreeNode {
    int info;
    TreeNode* esq;
    TreeNode* dir;
};

typedef TreeNode* treenodeptr;

// Função que verifica se a árvore binária é completa
bool arvoreCompleta(treenodeptr raiz) {
    if (raiz == NULL) {
        return true;
    }

    // Verifica se há um nó não completo anterior
    bool encontrouNoNaoCompleto = false;

    // Fila para realizar a travessia em nível da árvore
    queue<TreeNode*> fila;
    fila.push(raiz);

    while (!fila.empty()) {
        TreeNode* noAtual = fila.front();
        fila.pop();

        // Verifica se um nó não completo anterior foi encontrado
        if (encontrouNoNaoCompleto) {
            // Se há um nó não completo anterior e o nó atual não é nulo, a árvore não é completa
            if (noAtual != NULL) {
                return false;
            }
        } else {
            // Se um nó não completo anterior ainda não foi encontrado e o nó atual é nulo,
            // marca a flag encontrouNoNaoCompleto como true
            if (noAtual == NULL) {
                encontrouNoNaoCompleto = true;
            } else {
                // Adiciona os filhos do nó atual na fila
                fila.push(noAtual->esq);
                fila.push(noAtual->dir);
            }
        }
    }

    // Se a árvore passou por todos os nós e não encontrou um nó não completo,
    // então a árvore é completa
    return true;
}

// Função que insere um nó na árvore binária
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

// Função que busca um elemento na árvore binária
treenodeptr tPesq(treenodeptr p, int x) {
    if (p == NULL) {
        return NULL;
    } else if (x == p->info) {
        return p;
    } else if (x < p->info) {
        return tPesq(p->esq, x);
    } else {
        return tPesq(p->dir, x);
    }
}

void tDestruir(treenodeptr& arvore) {
    if (arvore != NULL) {
        tDestruir(arvore->esq);
        tDestruir(arvore->dir);
        delete arvore;
    }

    arvore = NULL;
}

int main() {
    // Cria uma árvore binária vazia
    treenodeptr arvore = NULL;
    
    bool R;
    int n; // Quantidade de números a serem colocados
    cin >> n;
    int nums; // Números a serem colocados

    for (int i = 0; i < n; i++) {
        cin >> nums;
        if (tPesq(arvore, nums) == NULL) {
            inserir(arvore, nums);
        }
    }

    int x; // Número a ser procurado
    cin >> x;

    if (tPesq(arvore, x) == NULL) {
        cout << "Nao encontrado";
    } else {
        cout << "Encontrado";
    }
    cout << endl;

    R = arvoreCompleta(arvore);

    if(R)
    cout << "completa";
    else
    cout << "incompleta";

    tDestruir(arvore);

    return 0;
}
