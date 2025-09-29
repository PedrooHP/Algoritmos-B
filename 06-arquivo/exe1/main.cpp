#include <iostream>
#include <fstream>
#include <string>
#include "exe1.h"

using namespace std;

int main() {
    ifstream entrada("entrada.txt");
    ofstream saida("saida.txt");

    if (!entrada.is_open() || !saida.is_open()) {
        cout << "Erro ao abrir arquivos!" << endl;
        return 1;
    }

    string frase;
    getline(entrada, frase);

    int qtd = contarVogais(frase);

    saida << "Frase: " << frase << endl;
    saida << "Quantidade de vogais: " << qtd << endl;

    entrada.close();
    saida.close();

    return 0;
}
