#include <iostream>
#include <cstring>

using namespace std;

struct info
{
    char nome[100];
    int idade;
    float peso;
    float altura; 
};
struct dado
{
    info atleta; // nome, idade, peso e altura de cada atleta
    int k; // chave
    int status; // 0:vazio, 1:ocupado, 2:removido
};
int h1(int k, int m)
{
	int h_1 = k % m;
	if(h_1 < 0)
		h_1 += m;
	return h_1;
}

int h2(int k, int m)
{
	int h_2 = 1 + (k % (m - 1));
	if(h_2 < 0)
		h_2 += m;
	return h_2;
}

int dhash(int k, int m, int i) // fazendo double hashing
{
	int dh = (h1(k, m) + i * h2(k, m)) % m;
	return dh;
}

int hash_insert(dado t[], int m, int k, info inf) // fazendo inserções pelo vetor t[j].k e pelo t[j].status
{
	int i = 0;
	int j;
	do // inserindo os valores
	{
		j = dhash(k, m, i);
		if (t[j].status != 1)
		{
			t[j].atleta = inf;
			t[j].k = k;
			t[j].status = 1;
			return j;
		}
		else
		{
			i = i + 1;
		}
	}
	while (i != m);
	return -1;
}
int hash_search(dado t[], int m, int k, char info[])
{
	int i = 0;
	int j;
	do // fazendo a busca pelo vetor
	{
		j = dhash(k, m, i);
		if(t[j].k == k && strcmp(t[j].atleta.nome, info) == 0)
		{
			return j;
		}
		i += 1;
	}
	while(t[j].status != 0 && i < m);

	return -1; // se não achar o vetor o programa ira retornar -1
}
int hash_remove(dado t[], int m, int k, info inf)
{
	int j;
	j = hash_search(t, m, k, inf.nome);
	if(j != -1)
	{
		strcpy(t[j].atleta.nome, "vazio");
		t[j].status = 2;
		t[j].k = -1;
		return 0; // consegui remover
	}
	else
	{
		return -1; // k não foi encontrado
	}
}

int calcula_chave(char nome[])
{
	int tam; // comprimento do nome
	int i; // contador
	int k = 0; // chave
	tam = strlen(nome);
	for(i = 0; i < tam; i++)
		k += (int)nome[i];
	return k;
}
int main()
{
	info inf;
	dado t[100];
	char nome[50];
	int k; // chave
	int m; // tamanho
	int i; // contador
	int op; // var para escolher uma opção
	int r; // resultado do calculo da chave
	int s; // resultado pesquisa

	// lendo tamanho e opção desejada
	cin >> m >> op;

	for(i = 0; i < m; i++)
	{
		t[i].k = -1; // colocando todos os vetores de t[i].k = -1
		t[i].status = 0; // colocando todos os vetores de t[j].status = 0
		strcpy(t[i].atleta.nome, "vazio");
	}


	while(op != 5)// se op = 5 sai do programa
	{
		if(op == 1) // inserir
		{
			cin.ignore();
			cin.getline(inf.nome, 50); // lendo o nome do atleta
			cin >> inf.idade; // lendo a idade do atleta
			cin >> inf.peso; // lendo o peso do atleta
			cin >> inf.altura; // lendo a altura do atleta
							
			r = calcula_chave(inf.nome);

			hash_insert(t, m, r, inf);

			cin >> op;
		}
		else if(op == 2) // pesquisar
		{
			cin.ignore();
			cin.getline(inf.nome, 50); // lendo nome que desejo pesquisar
			r = calcula_chave(inf.nome);
			s= hash_search(t, m, r, inf.nome);
			if(s == -1)
			cout << inf.nome << " nao encontrado" << endl;
			else
			{
		     	cout << t[s].atleta.nome << endl;
		     	cout << t[s].atleta.idade << endl;
		     	cout << t[s].atleta.peso << endl;
		     	cout << t[s].atleta.altura << endl;
            }
			cin >> op;
		}
		else if(op == 3) // remover
		{
			cin.ignore();
			cin.getline(nome, 50); // lendo nome que desejo remover

			r = calcula_chave(inf.nome);

			hash_remove(t, m, r, inf);

			cin >> op;
		}
		else if(op == 4) // listar
		{
			for(int i = 0; i < m; i++)
			{
				cout << t[i].atleta.nome << endl;
		     	cout << t[i].atleta.idade << endl;
		     	cout << t[i].atleta.peso << endl;
		     	cout << t[i].atleta.altura << endl;
			}

			cout << endl;

			cin >> op;
		}
	}

	return 0;
}
