#include <iostream>
using namespace std;

long long int fobonacci[1000];{
for(int i = 0; i < 1000; i++){
	fibonacci[i] = -1
}
fibonacci [0] = 0
fibonacci [1] = 1
}

int fibonaccii(int X[], int n, int Y) // vetor onde esta a seq, tamanho e posição que deseja saber qual o numero q é
{
	int a; // var auxiliar para salvar a posição que está o numero desejado
	for(int i = 0; i <= n; i++)
	{
		if(i == Y)
			a = i;
	}

	return X[a];
}


long long int fibonacci_rec(int n)
{
	if(fibonacci[n] != -1)
		return fibonacci[n];
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	fibonacci[n] = fibonacci_rec(n - 1) + fibonacci_rec(n - 2);

	return fibonacci[n];
}

int main()
{
	int N; // numero de posições
	int y; // posição desejada
	int r; // resultado
	bool e = true; // var aux

	cin >> N;

	int i = 0; // contador
	int aux = 0, aux2 = 1;
	int x[100]; // var para seq

	for(i = 0; i <= N; i++)
	{
		if(i <= 1)
			x[i] = i;
		else
  		{
			x[i] = aux + aux2;
			aux = aux2;
			aux2 = x[i];
		}

		cout << x[i] << endl;
	}
	// lendo a posição desejada
	do
	{
		cin >> y;
		
		if(y == -1)
		{
			return 0;
		}

		
		//buscando qual numero esta na posição desejada
		
		r = fibonaccii(x, N, y);
		
		// mostrando a posição

		cout << r << endl;
	}
	while(e);


	cout << fibonacci_rec(N);

	return 0;
}
