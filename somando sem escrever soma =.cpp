#include <iostream>
using namespace std;

int main()
{
	int x,y;
	int soma;
	int *p = NULL, *q = NULL;
	
	x = 2;
	y = 3;
	
	q = &soma; // q vale o endere�o de soma
	
	*q = 0; // o que esta armazenado no endere�o vale 0
	
	p = &x; // p vale endere�o de x
	
	*q += *p; // somando o que esta no endere�o de soma com o que esta no endere�o de x
	
	p = &y; // p vale endere�o de y
	
	*q += *p; // somando o que esta no endere�o de soma com o que esta no endere�o de y
	
	cout << "soma = " << soma << endl;
	
	return 0;
}