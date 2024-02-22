#include <iostream>
using namespace std;

int main()
{
	int *v = NULL; // vetor apontando para o "nada"
	int N; // tamanho desejado do vetor
	int i = 0; // contador
	int *p; // ponteiro para apontar para o vetor

	cin >> N; // lendo o tamanho do vetor

	v = new int[N]; // alocando mem�ria para vetor

	p = v; // apontando para o endere�o do vetor v

	// lendo os elementos dos vetores
	for(i; i < N; i++)
	{
		cin >> v[i];
	}

	// mostrando o que est� em cada endere�o do vetor
	for(i = 0; i < N; i++)
	{
		cout << *p << " ";
		p++;
	}
	
	delete [] v;

	return 0;
}
