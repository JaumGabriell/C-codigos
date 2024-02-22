#include <iostream>
#include <cmath>
using namespace std;

struct ponto {
    float x;
    float y;
};

float area_poligono(ponto v[], int n) {
    float area = 0;
    for (int i = 0; i < n-1; i++) {
        area += (v[i].x * v[i+1].y) - (v[i+1].x * v[i].y);
    }
    area += (v[n-1].x * v[0].y) - (v[0].x * v[n-1].y);
    return fabs(area) / 2;
}

int main() {
    ponto pontos[6];
    
    // Lendo os pontos do polígono
    for (int i = 0; i < 6; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }

    float area = area_poligono(pontos, 6);

    cout << "Area do escudo: " << area << endl;

    return 0;
}
