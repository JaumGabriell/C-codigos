#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;

struct ponto
{
    float x;
    float y;
};

typedef ponto vetor;

struct reta
{
    ponto A;
    ponto B;
};

typedef reta segmento;

vetor cria_vetor(ponto A, ponto B)
{
    vetor AB;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    return AB;
}

float vetorial(vetor A, vetor B)
{
    float v;
    v = A.x * B.y - A.y * B.x;
    return v;
}

float escalar(vetor A, vetor B)
{
    float e;
    e = A.x * B.x + A.y * B.y;
    return e;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
    vetor AB;
    vetor AC;
    float area;
    AB = cria_vetor(A, B);
    AC = cria_vetor(A, C);
    area = fabs(vetorial(AB, AC)) / 2;
    return area;
}

int sentido(ponto A, ponto B, ponto C)
{
    vetor AB;
    vetor AC;
    float vet;
    AB = cria_vetor(A, B);
    AC = cria_vetor(A, C);
    vet = vetorial(AB, AC);
    if (vet > 0)
        return 1;
    else if (vet < 0)
        return -1;
    else
        return 0;
}

int dentro_triangulo(ponto A, ponto B, ponto C, ponto P)
{
    int s1, s2, s3;
    s1 = sentido(A, B, P);
    s2 = sentido(B, C, P);
    s3 = sentido(C, A, P);
    if (s1 == s2 && s2 == s3)
        return 1;
    else if (s1 * s3 == -1 || s1 * s2 == -1 || s2 * s3 == -1)
        return -1;
    else
        return 0;
}

float area_poligono(ponto v[], int n)
{
    float area = 0;
    for (int i = 0; i < n - 2; i++)
    {
        area = area + area_triangulo(v[0], v[i + 1], v[i + 2]);
    }
    return area;
}

bool ponto_segmento(segmento S, ponto P)
{
    if (sentido(S.A, S.B, P) != 0)
        return false;
    else if (P.x > S.A.x && P.x < S.B.x)
        return true;
    else if (P.x < S.A.x && P.x > S.B.x)
        return true;
    else if (P.y < S.A.y && P.y > S.B.y)
        return true;
    else if (P.y > S.A.y && P.y < S.B.y)
        return true;
    else
        return false;
}

bool cmp(ponto a, ponto b)
{
    float angA = atan2(a.y, a.x);
    float angB = atan2(b.y, b.x);
    if (angA == angB)
    {
        float distA = sqrt(pow(a.x, 2) + pow(a.y, 2));
        float distB = sqrt(pow(b.x, 2) + pow(b.y, 2));
        return distA > distB;
    }
    else
        return angA < angB;
}

void ordena_pelo_angulo(ponto p[], int n)
{
    ponto pivot;
    int pos_pivot;
    pivot = p[0];
    pos_pivot = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].y < pivot.y)
        {
            pivot = p[i];
            pos_pivot = i;
        }
        else if (p[i].y == pivot.y && p[i].x < pivot.x)
        {
            pivot = p[i];
            pos_pivot = i;
        }
    }

    p[pos_pivot] = p[0];
    p[0] = pivot;

    for (int i = 0; i < n; i++)
    {
        p[i].x -= pivot.x;
        p[i].y -= pivot.y;
    }

    sort(p + 1, p + n, cmp);

    for (int i = 0; i < n; i++)
    {
        p[i].x += pivot.x;
        p[i].y += pivot.y;
    }
}

ponto next_to_top(list<ponto> pilha)
{
    pilha.pop_back();
    return pilha.back();
}

list<ponto> Graham_scan(ponto p[], int n)
{
    list<ponto> pilha;

    ordena_pelo_angulo(p, n);

    pilha.push_back(p[0]);
    pilha.push_back(p[1]);
    pilha.push_back(p[2]);
    int i = 3;
    while (i < n)
    {
        if (sentido(next_to_top(pilha), pilha.back(), p[i]) == 1)
        {
            pilha.push_back(p[i]);
            i++;
        }
        else
            pilha.pop_back();
    }
    return pilha;
}

int main()
{
    int n;
    cout << "Digite o numero de pontos do poligono: ";
    cin >> n;

    ponto v[n];
    cout << "Digite as coordenadas dos pontos (x y):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].x >> v[i].y;
    }

    list<ponto> convex_hull = Graham_scan(v, n);
    int num_lados = convex_hull.size();

    cout << "Numero de lados do poligono convexo: " << num_lados << endl;

    return 0;
}
