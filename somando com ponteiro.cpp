#include <iostream>
using namespace std;

int main()
{
	int x,y;
	int soma;
	int *p = NULL, *q = NULL;
	
	x = 2;
	y = 3;
	
	p = &x; // ponteiro apontando para o endere�o do x
	q = &y; // ponteiro apontando para o endere�o do y
	
	soma = *p+*q; // somando oq est� armazenado no endere�o x + o que 
	// esta armazenado no endere�o do y
	
	cout << "soma = " << soma << endl;
	
	return 0;
}