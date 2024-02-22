#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int *v = NULL; // vetor apontando para o "nada"
	int N; // tamanho desejado do vetor
	int i = 0; // contador
	int *p; // ponteiro para apontar para o vetor
    int aux = 0;

	cin >> N; // lendo o tamanho do vetor

	v = new int[N]; // alocando memória para vetor

	p = v; // apontando para o endereço do vetor v

	// lendo os elementos dos vetores
	for(i; i < N; i++)
	{
		cin >> v[i];
	}

	// varrendo o vetor com um ponteiro e analisando quem é o maior
	for(i = 0; i < N; i++)
	{
		if(*p > aux)
			aux = *p;
		p++;
	}
	
	// mostrando o maior valor que está no vetor
	
	cout << aux;
	
	delete [] v;

	return 0;
}
