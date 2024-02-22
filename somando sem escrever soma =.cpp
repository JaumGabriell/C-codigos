#include <iostream>
using namespace std;

int main()
{
	int x,y;
	int soma;
	int *p = NULL, *q = NULL;
	
	x = 2;
	y = 3;
	
	q = &soma; // q vale o endereço de soma
	
	*q = 0; // o que esta armazenado no endereço vale 0
	
	p = &x; // p vale endereço de x
	
	*q += *p; // somando o que esta no endereço de soma com o que esta no endereço de x
	
	p = &y; // p vale endereço de y
	
	*q += *p; // somando o que esta no endereço de soma com o que esta no endereço de y
	
	cout << "soma = " << soma << endl;
	
	return 0;
}