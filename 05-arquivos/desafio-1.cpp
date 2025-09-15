//Construa um programa (com módulo/método) que leia n nomes completos de pessoas e os exiba na tela;

#include <iostream>
#include <string>
#define TAM 5
using namespace std;

struct Pessoa {
    string nome;
};

void lerPessoa (Pessoa vetor[], int n){
    for (int i = 0; i < n; i++){
        cout << "Digite o nome da pessoa: \n";
        getline(cin, vetor[i].nome);
    }
}


void exibirPessoa (Pessoa vetor[], int n){
    for (int i = 0; i < n; i++){
        cout << "Nome: " << vetor[i].nome << endl;
    }
}

int main() {
    Pessoa vetor[TAM];

    lerPessoa(vetor, TAM);
    exibirPessoa(vetor, TAM);

    return 0;
}