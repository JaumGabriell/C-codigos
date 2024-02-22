#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> pilha; // ponteiro para lista
    int i; // contador
    int x; // var aux para a leitura e escrita
    // lendo elementos e inserindo-os na pilha
    for(i = 0; i<4; i++)
    {
        cin >> x;
        pilha.push_front(x);
    }
    // removendo e mostrando elementos na tela
    while(!pilha.empty())
    {
        x = *pilha.begin();
        cout << x << " "; // primeiro a ser colocado vai ser o ultimo a ser mostrado e removido
        pilha.pop_front();
    }
    
    return 0;
}