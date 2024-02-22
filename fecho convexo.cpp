#include <iostream>
#include <cmath>
#include <vector>

struct Coordenada {
    int x;
    int y;
};

double calcularDistancia(Coordenada p1, Coordenada p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return std::sqrt(dx*dx + dy*dy);
}

double calcularPerimetroCerca(std::vector<Coordenada> reservas) {
    double perimetro = 0.0;
    int n = reservas.size();
    
    for (int i = 0; i < n; ++i) {
        Coordenada atual = reservas[i];
        Coordenada proxima = reservas[(i + 1) % n];
        perimetro += calcularDistancia(atual, proxima);
    }
    
    return perimetro;
}

int main() {
    int numReservas;
    std::cout << "Digite o número de reservas florestais: ";
    std::cin >> numReservas;
    
    double totalPerimetro = 0.0;
    
    for (int i = 0; i < numReservas; ++i) {
        int numArvores;
        std::cout << "Digite a quantidade de árvores na reserva " << (i + 1) << ": ";
        std::cin >> numArvores;
        
        std::vector<Coordenada> reservas;
        
        for (int j = 0; j < numArvores; ++j) {
            Coordenada coordenada;
            std::cout << "Digite as coordenadas da árvore " << (j + 1) << " (x y): ";
            std::cin >> coordenada.x >> coordenada.y;
            reservas.push_back(coordenada);
        }
        
        double perimetro = calcularPerimetroCerca(reservas);
        totalPerimetro += perimetro;
    }
    
    std::cout << "A quantidade mínima de material para cercar os territórios é: " << totalPerimetro << std::endl;
    
    return 0;
}
