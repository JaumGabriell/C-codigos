#include <iostream>
using namespace std;

int main()
{
	int vetor[5]; // 0x67feec endere�o do vetor posi��o 0
	int *p; // ponteiro 
	int i; // contador
	
	for(i = 0;i < 5; i++)
		vetor[i] = i;
	
	p = vetor; // p vale o endere�o vetor
	
	for(i = 0;i < 5; i++) // mostrando o que esta armazenado no endere�o do vetor
	{
		cout << *p << endl; // mostrando o que esta armazenado no endere�o de cada posi��o do vetor
		p++; // passando da posi��o 0 para 1 do vetor etc...
	}
	
	
	return 0;
}