/*Questão 2) Construir um programa que gere aleatoriamente n números inteiros e os armazene em um vetor de tamanho TAM. Contudo, é necessário criar um método que receba: 
a) o vetor com os números gerados automaticamente 
b) o tamanho desse vetor ou a quantidade de números inseridos no vetor 
c) um vetor de resultado que irá armazenar somente os pares

Ao final, o método deve retornar a quantidade de pares inseridos nesse vetor de números pares.*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define TAM 5

void popular(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(int vetor[], int quantidade, int tamanho) {
    if (quantidade > tamanho) {
        cout << "Essa quantidade nao eh possivel...";
        return;
    }
    cout << vetor << endl;
    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i] << endl;
    }
}


int main() {
    int vetor[TAM];
    int quantidade = 5;

    
    popular(vetor, quantidade, TAM);

    //metodo que exiba o vetor
    exibir(vetor, quantidade, TAM);

    return 1;
}
