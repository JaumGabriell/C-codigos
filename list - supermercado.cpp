#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> listaE; // "ponteiro" para lista ligada/ lista para o estoque
    list<int>::iterator p; // "ponteiro" para varrer a lista
    list<int> listaV; // lista para a venda
    int N; // numero de operações
    int c; // codigo do produto
    int x; // primeiro numero da linha
    int aux = 0; // contador
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        if(x == 1)
        {
            cin >> c;
            listaE.push_back(c);
        }
        else if(x == 2)
        {
            p = listaE.begin();
            listaV.push_front(*p);
            listaE.pop_front();
        }
    }
    cout << "Estoque: ";
    for(p = listaE.begin(); p != listaE.end(); p++)
    {
    cout << *listaE.begin() << " ";
    }
    cout << endl;
    cout << "Venda: ";
    for(p = listaV.begin(); p != listaV.end(); p++)
    {
    cout << *p << " ";
    }
    while(!listaE.empty())
    {
        listaE.pop_front();
    }
    while(!listaV.empty())
    {
        listaV.pop_front();
    }
    return 0;
}
// #include <iostream>
// #include <list>
// using namespace std;
// 
// int main()
// {
// 	list<int> lista; // "ponteiro" para lista ligada
// 	list<int>::iterator p; // "ponteiro" para varrer a lista
// 	int x; // var aux p/ leitura dos dados
// 	int soma; // soma dos elementos da lista
// 	
// 	cin >> x;
// 	 while(x != 0)
// 	{
// 		lista.push_back(x);
// 		cin >> x;
// 	}
// 	soma = 0;
// 	for(p = lista.begin(); p != lista.end(); p++) // estrutura de repetição
// 	{                                             // para vazer a lista com ponteiro
// 		soma += *p; 
// 	}
// 	
// 	cout << "soma = " << soma << endl;
// 	
// 	while(!lista.empty())
// 	{
// 		lista.pop_front();
// 	}
// 	
// 	return 0;
// }