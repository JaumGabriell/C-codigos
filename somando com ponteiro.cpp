#include <iostream>
using namespace std;

int main()
{
	int x,y;
	int soma;
	int *p = NULL, *q = NULL;
	
	x = 2;
	y = 3;
	
	p = &x; // ponteiro apontando para o endereço do x
	q = &y; // ponteiro apontando para o endereço do y
	
	soma = *p+*q; // somando oq está armazenado no endereço x + o que 
	// esta armazenado no endereço do y
	
	cout << "soma = " << soma << endl;
	
	return 0;
}