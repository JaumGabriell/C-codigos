#include <iostream>
using namespace std;

int main()
{
	int x,y;
	int soma = 0;
	int *p = NULL;
	
	x = 2;
	y = 3;
	
	p = &x; // ponteiro apontando para o endere�o do x
	soma += *p; // soma = zero, soma assume o valor do que est� armazenado 
	// no endere�o do x
	p = &y; // ponteiro apontando para o ender�o de y
	soma += *p; // soma = 2, mais o valor que est� aramazenado no
	// endere�o do y

	
	cout << "soma = " << soma << endl;
	
	return 0;
}