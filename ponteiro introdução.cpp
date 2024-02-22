#include <iostream>

using namespace std;

int main()
{
	int a; // a � uma vari�vel
	int *b = NULL; // b � um ponteiro
	// O operado * � chamado de operador de derrefer�ncia,
	// e mostra o conte�do armazenado na posi��o apontada por b
	
	a = 2; // a � armazenada no endere�o 0x67fee8,
	// e armazena o valor 2
	
	 // b armazena o valor de a, ou seja: 0x67fee8
	
	*b = 3; // substituindo o que est� armazenado no endero�o 0x67fee8
	// por 3
	
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "b = " << b << endl;
	cout << "*b = " << *b << endl; 
	// *b � o que est� armazenado no endere�o 0x67fee8,
	// ou seja: 2
	
	
	return 0;
}