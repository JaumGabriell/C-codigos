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

	v = new int[N]; // alocando mem�ria para vetor

	p = v; // apontando para o endere�o do vetor v

	// lendo os elementos dos vetores
	for(i; i < N; i++)
	{
		cin >> v[i];
	}

	// varrendo o vetor com um ponteiro e analisando quem � o maior
	for(i = 0; i < N; i++)
	{
		if(*p > aux)
			aux = *p;
		p++;
	}
	
	// mostrando o maior valor que est� no vetor
	
	cout << aux;
	
	delete [] v;

	return 0;
}
