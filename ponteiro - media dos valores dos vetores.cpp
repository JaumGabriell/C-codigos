#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int *v = NULL; // vetor apontando para o "nada"
	int N; // tamanho desejado do vetor
	int i = 0; // contador
	int *p; // ponteiro para apontar para o vetor
	float soma = 0; // soma dos valores do vetor
	float media; // media dos valores

	cin >> N; // lendo o tamanho do vetor

	v = new int[N]; // alocando memória para vetor

	p = v; // apontando para o endereço do vetor v

	// lendo os elementos dos vetores
	for(i; i < N; i++)
	{
		cin >> v[i];
	}

	// varrendo o vetor com um ponteiro e somando ao soma
	for(i = 0; i < N; i++)
	{
		soma += *p;
		p++;
	}
	
	// fazendo a media dos valores
	media = soma/N;
	
	// mostrando a media dos valores
	
	cout << fixed << setprecision(2) << media << endl;
	
	delete [] v;

	return 0;
}
