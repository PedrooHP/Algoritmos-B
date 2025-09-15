//Construa um programa (com módulo/método) que leia n nomes completos de pessoas e os adicione em um vetor de n posicoes em que deve ser armazenado o nome completoe o sobrenome. Use a seguinte estrutura;

//typedef struct { string nomeCompleto; string sobreNome; } Pessoa;

//Dica: será preciso fazer uma função que extraia o sobrenome de um nome completo.

#include <iostream>
#include <string>
#define TAM 5
using namespace std;

typedef struct {
    string nomeCompleto;
    string sobreNome;
}Pessoa;

void lerPessoa (Pessoa vetor[], int n){
    for (int i = 0; i < n; i++){
        cout << "Digite o nome da pessoa: \n";
        getline(cin, vetor[i].nomeCompleto);

        size_t pos = vetor[i].nomeCompleto.find_last_of(' ');
        if (pos != string::npos) {
            vetor[i].sobreNome = vetor[i].nomeCompleto.substr(pos + 1);
        } else {
            vetor[i].sobreNome = vetor[i].nomeCompleto; // Se só tiver uma palavra
        }
    }
}

void exibirPessoa (Pessoa vetor[], int n){
    for (int i = 0; i < n; i++){
        cout << "Nome: " << vetor[i].nomeCompleto << endl;
        cout << "Sobrenome: " << vetor[i].sobreNome << endl;
    }
}

int main() {
    Pessoa vetor[TAM];

    lerPessoa(vetor, TAM);
    exibirPessoa(vetor, TAM);

    return 0;
}