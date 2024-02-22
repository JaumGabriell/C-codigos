#include <iostream>
using namespace std;

long long int fibonacci[1000];

void init_fibonacci() {
    for(int i = 0; i < 1000; i++) {
        fibonacci[i] = -1;
    }
    fibonacci[0] = 0;
    fibonacci[1] = 1;
}

long long int fibonacci_rec(int n) {
    if(fibonacci[n] != -1) {
        return fibonacci[n];
    }
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    fibonacci[n] = fibonacci_rec(n - 1) + fibonacci_rec(n - 2);

    return fibonacci[n];
}

int main() {
    init_fibonacci();
    int n;
    cout << "Digite o n�mero desejado da sequ�ncia de Fibonacci: ";
    cin >> n;
    cout << "O n�mero " << n << " da sequ�ncia de Fibonacci � " << fibonacci_rec(n) << endl;
    return 0;
}
