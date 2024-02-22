#include <iostream>

using namespace std;

int main()
{
	int a; // a é uma variável
	int *b = NULL; // b é um ponteiro
	// O operado * é chamado de operador de derreferência,
	// e mostra o conteúdo armazenado na posição apontada por b
	
	a = 2; // a é armazenada no endereço 0x67fee8,
	// e armazena o valor 2
	
	 // b armazena o valor de a, ou seja: 0x67fee8
	
	*b = 3; // substituindo o que está armazenado no enderoço 0x67fee8
	// por 3
	
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "b = " << b << endl;
	cout << "*b = " << *b << endl; 
	// *b é o que está armazenado no endereço 0x67fee8,
	// ou seja: 2
	
	
	return 0;
}