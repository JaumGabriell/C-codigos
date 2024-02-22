#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int>lista1; // ponteiro para lista1
	list<int>lista2; // ponteiro para lista2
	list<int>lista3; // ponteiro para lista3
	list<int>::iterator p1; // "ponteiro" para varrer a lista1
	list<int>::iterator p2; // "ponteiro" para varrer a lista2
	list<int>::iterator p3; // "ponteiro" para varrer a lista3

	int x; // var para entrada de dados

	// lendo a entrada de dados da fila1
	cin >> x;
	while(x != 0)
	{
		lista1.push_back(x);
		cin >> x;
	}

	// lendo a entrada de dados da fila2
	cin >> x;
	while(x != 0)
	{
		lista2.push_back(x);
		cin >> x;
	}
	// apontando os ponteiros para lista
	p1 = lista1.begin(); 
	p2 = lista2.begin();
	
	// vendo elementos maiores ou menores
	while(p1 != lista1.end() && p2 != lista2.end())
	{
		if(*p1 == *p2)
		{
			lista3.push_back(*p1);
			p1++;
			p2++;
		}
		else if(*p1 < *p2)
		{
			lista3.push_back(*p1);
			p1++;
		}
		else if(*p2 < *p1)
		{
			lista3.push_back(*p2);
			p2++;
		}
	}
	
	// caso sobre alguma lista com elementos
	if(p1 != lista1.end())
	{
		while(p1 != lista1.end())
		{
			lista3.push_back(*p1);
			p1++;
		}
	} else if(p2 != lista2.end())
	{
		while(p2 != lista2.end())
		{
			lista3.push_back(*p2);
			p2++;
		}
	}
	
	// mostrando o que se pede
	for(p3 = lista3.begin(); p3 != lista3.end(); p3++)
	{
		cout << *p3 << " ";
	}

	// deletando
	while(!lista1.empty())
	{
		lista1.pop_front();
	}
	while(!lista2.empty())
	{
		lista2.pop_front();
	}
	while(!lista3.empty())
	{
		lista3.pop_front();
	}


	return 0;
}
