#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// Estrutura para representar um n? da ?rvore bin?ria
struct No
{
	string palavraFicticia;
	string traducaoPortugues;
	string traducaoIngles;
	No* esquerda;
	No* direita;
};

// Fun??o para criar um novo n? com as informa??es fornecidas
No* criarNo(string palavraFicticia, string traducaoPortugues, string traducaoIngles)
{
	No* novoNo = new No;
	novoNo->palavraFicticia = palavraFicticia;
	novoNo->traducaoPortugues = traducaoPortugues;
	novoNo->traducaoIngles = traducaoIngles;
	novoNo->esquerda = NULL;
	novoNo->direita = NULL;
	return novoNo;
}

// Fun??o para inserir uma palavra no vocabul?rio fict?cio
No* inserirPalavra(No* raiz, string palavraFicticia, string traducaoPortugues, string traducaoIngles)
{
	// Se a ?rvore estiver vazia, cria um novo n? e o retorna como raiz
	if (raiz == NULL)
	{
		return criarNo(palavraFicticia, traducaoPortugues, traducaoIngles);
	}

	// Se a palavra for menor, insere ? esquerda
	if (palavraFicticia < raiz->palavraFicticia)
	{
		raiz->esquerda = inserirPalavra(raiz->esquerda, palavraFicticia, traducaoPortugues, traducaoIngles);
	}
	// Se a palavra for maior, insere ? direita
	else if (palavraFicticia > raiz->palavraFicticia)
	{
		raiz->direita = inserirPalavra(raiz->direita, palavraFicticia, traducaoPortugues, traducaoIngles);
	}

	// Retorna a raiz atualizada
	return raiz;
}

// Função para realizar a busca de uma palavra no vocabulário fictício
void buscarPalavra(No* raiz, string palavraFicticia)
{
    // Se a árvore estiver vazia ou a palavra for encontrada, retorna a tradução
    if (raiz == NULL || raiz->palavraFicticia == palavraFicticia)
    {
        if (raiz == NULL)
        {
            cout << "Palavra nao encontrada." << endl;
        }
        else
        {
            cout << "Traducao encontrada: " << raiz->traducaoPortugues << endl;
        }
        return;
    }

    // Se a palavra for menor, busca à esquerda
    if (palavraFicticia < raiz->palavraFicticia)
    {
        buscarPalavra(raiz->esquerda, palavraFicticia);
    }
    // Se a palavra for maior, busca à direita
    else
    {
        buscarPalavra(raiz->direita, palavraFicticia);
    }
}


// Função para remover uma palavra do vocabulário fict?cio pela sua tradução em inglês
No* removerPalavra(No* raiz, string traducaoIngles)
{
	if (raiz == NULL)
	{
		return raiz;
	}

	if (traducaoIngles < raiz->traducaoIngles)
	{
		raiz->esquerda = removerPalavra(raiz->esquerda, traducaoIngles);
	}
	else if (traducaoIngles > raiz->traducaoIngles)
	{
		raiz->direita = removerPalavra(raiz->direita, traducaoIngles);
	}
	else
	{
		if (raiz->esquerda == NULL && raiz->direita == NULL)
		{
			delete raiz;
			return NULL;
		}
		else if (raiz->esquerda == NULL)
		{
			No* temp = raiz->direita;
			delete raiz;
			return temp;
		}
		else if (raiz->direita == NULL)
		{
			No* temp = raiz->esquerda;
			delete raiz;
			return temp;
		}
		else
		{
			No* temp = raiz->direita;
			while (temp->esquerda != NULL)
			{
				temp = temp->esquerda;
			}
			raiz->palavraFicticia = temp->palavraFicticia;
			raiz->traducaoPortugues = temp->traducaoPortugues;
			raiz->traducaoIngles = temp->traducaoIngles;
			raiz->direita = removerPalavra(raiz->direita, temp->traducaoIngles);
		}
	}

	return raiz;
}


// Função para imprimir todas as palavras do vocabulário fictício em ordem crescente
void imprimirEmOrdem(No* raiz)
{
	if (raiz != NULL)
	{
		imprimirEmOrdem(raiz->esquerda);
		cout << raiz->palavraFicticia << " (" << raiz->traducaoPortugues << ", " << raiz->traducaoIngles << ")" << endl;
		imprimirEmOrdem(raiz->direita);
	}
}

// Função para contar quantas palavras fictícias possuem o mesmo tamanho que sua tradução em português
int contarPalavrasMesmoTamanho(No* raiz, int& contador)
{
	if (raiz == NULL)
	{
		return contador;
	}

	if (raiz->palavraFicticia.length() == raiz->traducaoPortugues.length())
	{
		// Verificar se as palavras são diferentes antes de incrementar o contador
		if (raiz->palavraFicticia != raiz->traducaoPortugues)
		{
			cout << "Palavra: " << raiz->palavraFicticia << " (" << raiz->traducaoPortugues << ")" << ", Tamanho: " << raiz->palavraFicticia.length() << endl;
			contador++;
		}
	}

	contador = contarPalavrasMesmoTamanho(raiz->esquerda, contador);
	contador = contarPalavrasMesmoTamanho(raiz->direita, contador);

	return contador;
}


// Função para imprimir todas as palavras em português que se traduzam para a mesma palavra na língua fictícia
void imprimirPalavrasTraducaoPortugues(No* raiz, string palavraFicticia)
{
	if (raiz != NULL)
	{
		if (raiz->palavraFicticia == palavraFicticia)
		{
			cout << raiz->traducaoPortugues << endl;
		}
		imprimirPalavrasTraducaoPortugues(raiz->esquerda, palavraFicticia);
		imprimirPalavrasTraducaoPortugues(raiz->direita, palavraFicticia);
	}
}

// Função para percorrer a árvore em pré-ordem e verificar se uma palavra em inglês é encontrada primeiro
bool percursoPreOrdem(No* raiz, string traducaoIngles)
{
	if (raiz != NULL)
	{
		if (raiz->traducaoIngles == traducaoIngles)
		{
			return true;
		}

		bool encontradaEsquerda = percursoPreOrdem(raiz->esquerda, traducaoIngles);
		if (encontradaEsquerda)
		{
			return true;
		}

		bool encontradaDireita = percursoPreOrdem(raiz->direita, traducaoIngles);
		if (encontradaDireita)
		{
			return true;
		}
	}

	return false;
}
// Função para percorrer a ?rvore em pr?-ordem
void percursoPreOrdem(No* raiz)
{
	if (raiz != NULL)
	{
		cout << raiz->palavraFicticia << " (" << raiz->traducaoPortugues << ", " << raiz->traducaoIngles << ")" << endl;
		percursoPreOrdem(raiz->esquerda);
		percursoPreOrdem(raiz->direita);
	}
}

// Função para percorrer a ?rvore em ordem
void percursoEmOrdem(No* raiz)
{
	if (raiz != NULL)
	{
		percursoEmOrdem(raiz->esquerda);
		cout << raiz->palavraFicticia << " (" << raiz->traducaoPortugues << ", " << raiz->traducaoIngles << ")" << endl;
		percursoEmOrdem(raiz->direita);
	}
}

// Função para percorrer a árvore em pós-ordem
void percursoPosOrdem(No* raiz)
{
	if (raiz != NULL)
	{
		percursoPosOrdem(raiz->esquerda);
		percursoPosOrdem(raiz->direita);
		cout << raiz->palavraFicticia << " (" << raiz->traducaoPortugues << ", " << raiz->traducaoIngles << ")" << endl;
	}
}

int main()
{
	No* raiz = NULL;
	int opcao = 0;

	while (opcao != 10)
	{
		cout << "Selecione uma opcao: " << endl;
		cout << "1. Inserir palavra" << endl;
		cout << "2. Buscar palavra" << endl;
		cout << "3. Remover palavra" << endl;
		cout << "4. Imprimir palavras em ordem crescente" << endl;
		cout << "5. Contar palavras com mesmo tamanho da traducao em portugues" << endl;
		cout << "6. Imprimir palavras em portugues com mesma traducao" << endl;
		cout << "7. Pre-ordem" << endl;
		cout << "8. Em-ordem" << endl;
		cout << "9. Pos-ordem" << endl;
		cout << "10. Sair" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		cout << endl;

		string palavraFicticia, traducaoPortugues, traducaoIngles;

		switch (opcao)
		{
		case 1:
			cout << "Insira a palavra em portugues: " << endl;
			cin >> traducaoPortugues;
			cout << "Insira a traducao em ingles: " << endl;
			cin >> traducaoIngles;
			cout << "Insira a taducao ficticia: " << endl;
			cin >> palavraFicticia;
			raiz = inserirPalavra(raiz, palavraFicticia, traducaoPortugues, traducaoIngles);
			cout << "Palavra inserida com sucesso!" << endl;
			cout << endl;
			break;

		case 2:
			cout << "Insira a palavra ficticia a ser buscada: " << endl;
			cin >> palavraFicticia;
			buscarPalavra(raiz, palavraFicticia);
			cout << endl;
			
			break;

		case 3:
			cout << "Insira a traducao em ingles da palavra a ser removida: " << endl;
			cin >> traducaoIngles;
			raiz = removerPalavra(raiz, traducaoIngles);
			cout << "Palavra removida com sucesso!" << endl;
			cout << endl;
			break;

		case 4:
			cout << "Palavras em ordem crescente: " << endl;
			imprimirEmOrdem(raiz);
			cout << endl;
			break;

		case 5:
		{
			int contador = 0;
			contarPalavrasMesmoTamanho(raiz, contador);

			if (contador == 0)
			{
				cout << "Nao ha palavras ficticias com o mesmo tamanho que sua traducao em portugues." << endl;
			}
			else
			{
				cout << "Numero de palavras ficticias com o mesmo tamanho que sua traducao em portugues: " << contador << endl;
			}
			cout << endl;

			break;
		}

		case 6:
			cout << "Insira a palavra ficticia para imprimir as traducoes em portugues: " << endl;
			cin >> palavraFicticia;
			cout << "Palavras em portugues com mesma traducao: " << endl;
			imprimirPalavrasTraducaoPortugues(raiz, palavraFicticia);
			cout << endl;
			break;

		case 7:
			cout << "Percorrendo a arvore em pre-ordem: " << endl;
			percursoPreOrdem(raiz);
			cout << endl;
			break;
		case 8:
			cout << "Percorrendo a arvore em em-ordem: " << endl;
			percursoEmOrdem(raiz);
			cout << endl;
			break;
		case 9:
			cout << "Percorrendo a arvore em pos-ordem: " << endl;
			percursoPosOrdem(raiz);
			cout << endl;

			break;
		case 10:
			cout << "Encerrando o programa..." << endl;
			cout << endl;
			return 0;

		default:
			cout << "Opcao invalida. Tente novamente." << endl;

		}
	}

	return 0;
}
