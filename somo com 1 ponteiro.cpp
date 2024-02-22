#include <iostream>
using namespace std;

int main()
{
	int x,y;
	int soma = 0;
	int *p = NULL;
	
	x = 2;
	y = 3;
	
	p = &x; // ponteiro apontando para o endereço do x
	soma += *p; // soma = zero, soma assume o valor do que está armazenado 
	// no endereço do x
	p = &y; // ponteiro apontando para o enderço de y
	soma += *p; // soma = 2, mais o valor que está aramazenado no
	// endereço do y

	
	cout << "soma = " << soma << endl;
	
	return 0;
}