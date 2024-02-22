#include <iostream>
#include <list>
using namespace std;

int main()
{
	int N; // numero de casos teste
	int F1, F2; // quantidade de figurinhas de Ricardo e Vicente
	int r; // resultado
	int aux1, aux2; // vars auxiliares
	int dividendo, divisor, resto; //

	// lendo numero de casos testes
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		// lendo numero de figurinhas de Ricardo e Vicente
		cin >> F1 >> F2;

		if(F1 > F2)
		{
			aux1 = F1 % F2;
			if(aux1 == 0)
			{
				cout << F2 << endl;
			}
			dividendo = F1;
			divisor = F2;
		}
		else
		{
			aux2 = F2 % F1;
			if(aux2 == 0)
			{
				cout << F1 << endl;
			}
			dividendo = F2;
			divisor = F1;
		}

		while(dividendo % divisor != 0)
		{
			resto = dividendo % divisor;
			dividendo = divisor;
			divisor = resto;
			cout << divisor << endl;
		}


	}

	return 0;
}

