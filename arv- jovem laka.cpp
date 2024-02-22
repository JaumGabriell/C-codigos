#include <iostream>
#include <list>
using namespace std;


struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;

};


typedef treenode *treenodeptr;


void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

void preOrdem (int y, treenodeptr arvore, int &pre, int &pre2)
{

	if (arvore != NULL)
	{
		pre++;
		if(arvore->info == y)
			pre2 = pre;
	//	cout <<"Pre" << arvore->info << endl;
		preOrdem(y, arvore->esq,pre, pre2);
		preOrdem(y, arvore->dir,pre, pre2);
	}
}


void emOrdem (int y, treenodeptr arvore, int &em, int &em2)
{
   
	if (arvore != NULL)
	{
		emOrdem(y, arvore->esq,em, em2);
			em++;
		if(arvore->info == y)
			em2 = em;
	//	cout << " Em" << arvore->info << " ";
		emOrdem(y, arvore->dir, em,em2);
	}
}


void posOrdem (int y, treenodeptr arvore,int &pos, int &pos2)
{

	if (arvore != NULL)
	{
		
		posOrdem(y, arvore->esq,pos, pos2);
		posOrdem(y, arvore->dir,pos, pos2);
		pos++;
		if(arvore->info == y)
		{
			pos2 = pos;
		}
	//	cout << "Pos" << arvore->info << endl;
	}
}

treenodeptr tPesq(treenodeptr p, int x){

    if (p == NULL) // elemento não encontrado
        return NULL;
    else if (x == p->info) // elemento encontrado na raiz
        return p;
    else
        // procura na sub ´arvore esquerda
    if (x < p->info)
        return tPesq(p->esq,x);
        // procura na sub ´arvore direita
    else
        return tPesq(p->dir,x);
}

void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}



int main()
{
	int x = 0;
	treenodeptr arvore = NULL;

	int y;

	cin >> x;

	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	
	
	cin >> y;
	if (tPesq(arvore, y)!= NULL) {
		
		int em2 = 0; 
		int pos2 = 0;
		int pre2 = 0;
		int em = 0; 
		int pos = 0; 
		int pre = 0;
		emOrdem(y,arvore,em,em2);
		posOrdem(y, arvore,pos,pos2);
		preOrdem(y, arvore,pre,pre2);
	
		if(pre2 <= pos2 && pre2 <= em2)
		{
			cout << "Pre" << endl;
		}
		else if(pos2 <= pre2 && pos2 <= em2)
		{
			cout << "Pos" << endl;
		}
		else
			cout << "Em" << endl;
		
	} else {
		cout << "Elemento nao encontrado" << endl;
	}



	tDestruir(arvore);
	return 0;
}