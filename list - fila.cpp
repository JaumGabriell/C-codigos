#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> fila; // ponteiro para fila
	int i; // contador
	int x; // var aux para leitura e escrita
	//lendo elementos e inserindo-os na fila
	for(i = 0; i< 4; i++)
	{
		cin >> x;
		fila.push_back(x);
	}
	// removendo e mostrando na tabela
	while(!fila.empty())
	{
		x = *fila.begin(); // primeiro a ser colocado vai ser o primeiro a ser mostrado e a ser removido
		cout << x << " ";
		fila.pop_front();
	}
	return 0;
}