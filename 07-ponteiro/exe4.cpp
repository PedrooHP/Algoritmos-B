//faça um metodo que receba o vetor, substitua todos os numeros pares por zero e retorne a quantidade
//de numeros que foram substituidos contudo não é permitido usar return

#include <iostream>
#include <ctime>

#define TAM 3
using namespace std;

void popula(int *v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20;
    }
}

void exibe(int *v, int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}

void paresImpares(int *v, int n, int *pares, int *impares){
    *pares = 0;
    *impares = 0;
    for (int i = 0; i < n; i++){
        if (v[i] %2 == 0){
            *pares = *pares + 1;
        } else {
            *impares = *impares + 1;
        }
    }
}

void menorMaior(int *v, int n, int *menor, int *maior) {
    *menor = v[0];
    *maior = v[0];
    for (int i = 0; i < n; i++) {
        if (v[i] < *menor) {
            *menor = v[i];
        }
        if (v[i] > *maior) {
            *maior = v[i];
        }
    }
}

void troca(int *v, int n, int *pares){
    for (int i = 0; i < n; i++){
        if (v[i] %2 == 0){

        }
    }
}

int main() {
   int vetor[TAM];
   popula(vetor, TAM);
   exibe(vetor, TAM);

   int menor;
   int maior;
   menorMaior(vetor, TAM, &menor, &maior);

   cout << "Menor: " << menor << endl;
   cout << "Maior: " << maior << endl;

   int qtdPares;
   int qtdImpares;
   paresImpares(vetor, TAM, &qtdPares, &qtdImpares);

   cout << "Total de pares: " << qtdPares << endl;
   cout << "Total de impares: " << qtdImpares << endl;
}