#include <iostream>
using namespace std;

int main()
{
	int *v = NULL; // vetor apontando para o "nada"
	int N; // tamanho desejado do vetor
	int i = 0; // contador
	int *p; // ponteiro para apontar para o vetor

	cin >> N; // lendo o tamanho do vetor

	v = new int[N]; // alocando memória para vetor

	p = v; // apontando para o endereço do vetor v

	// lendo os elementos dos vetores
	for(i; i < N; i++)
	{
		cin >> v[i];
	}

	// mostrando o que está em cada endereço do vetor
	for(i = 0; i < N; i++)
	{
		cout << *p << " ";
		p++;
	}
	
	delete [] v;

	return 0;
}
