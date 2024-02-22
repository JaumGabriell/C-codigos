#include <iostream>
using namespace std;

int main()
{
	int vetor[5]; // 0x67feec endereço do vetor posição 0
	int *p; // ponteiro 
	int i; // contador
	
	for(i = 0;i < 5; i++)
		vetor[i] = i;
	
	p = vetor; // p vale o endereço vetor
	
	for(i = 0;i < 5; i++) // mostrando o que esta armazenado no endereço do vetor
	{
		cout << *p << endl; // mostrando o que esta armazenado no endereço de cada posição do vetor
		p++; // passando da posição 0 para 1 do vetor etc...
	}
	
	
	return 0;
}