    #include <iostream>
    #include <iomanip>
    
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

   // função que percorre a árvore e calcula a soma e a quantidade de elementos
void percorrerArvore(TreeNode* p, int& soma, int& quantidade) {
    if (p != NULL) {
        percorrerArvore(p->esq, soma, quantidade);
        soma += p->info;
        quantidade++;
        percorrerArvore(p->dir, soma, quantidade);
    }
}
    int main() {
        // cria uma árvore binária vazia
        TreeNode* arvore = NULL;

        // lê alguns números para inserir na árvore
        int num;
        int n; // quantidade de elementos

        cout << "Digite a quantidade de elementos" << endl;
        cin >> n;

        cout << "Digite os numeros a serem inseridos na arvore: ";
        cout << endl;

        for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        inserir(arvore, num);
        }
          // calcula a média dos elementos da árvore
    int soma = 0;
    int quantidade = 0;
    percorrerArvore(arvore, soma, quantidade);
    double media = soma / (double)quantidade;

    // imprime a média
    cout << fixed << setprecision(2);
    cout << "A media dos elementos da arvore eh: " << media << endl;
    

        return 0;
    }