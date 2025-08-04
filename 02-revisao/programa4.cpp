//código do programa 3 só que com C++

#include <iostream>
#include <string>
#define TAM 5
 
using namespace std;
 
int main() {
    cout << "Exemplo de vetor de placas que sao strings\n\n";
    string placa;
    string vetor[TAM];
 
    //rotina que o usuario digita TAM numeros inteiros
    for (int i = 0; i < TAM; i++) {
        cout << "Digite uma placa: ";
        cin >> placa;
 
        vetor[i] = placa;
    }
 
    //rotina que o programa exibe os numeros inteiros um depois do outro
    cout << "Placas: ";
    for (int i = 0; i < TAM; i++) {
        cout << vetor[i] << "\t";
    }
    cout << "\n";
 
 
    return 1;
}