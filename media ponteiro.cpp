#include <iostream>
#include <vector>

using namespace std;

struct Aluno {
    vector<float> notas;
};

int main() {
    int n;
    cout << "Digite a quantidade de alunos: ";
    cin >> n;

    vector<Aluno> alunos(n);

    for (int i = 0; i < n; i++) {
        alunos[i].notas.resize(3);
        cout << "Digite as notas do aluno " << i+1 << ": ";
        cin >> alunos[i].notas[0] >> alunos[i].notas[1] >> alunos[i].notas[2];
    }

    float media_turma = 0.0;
    for (int i = 0; i < n; i++) {
        float media_aluno = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3.0;
        cout << "A média do aluno " << i+1 << " é " << media_aluno << endl;
        media_turma += media_aluno;
    }
    media_turma /= n;
    cout << "A média da turma é " << media_turma*1.0 << endl;

    return 0;
}
