/*Questão 1) Construir um programa em que o usuário insira/digite 10 nomes completos de pessoas (validar se o nome lido tem duas palavras no mínimo). 
Esses nomes devem ser transformados para maiúsculo e armazenados em um vetor de tamanho 10 (ou TAM 10). Ao final, esses nomes devem ser exibidos. Contudo, 
o programa deve ser composto por métodos (com ou sem retorno).*/

#include <iostream>
#include <string>
#define TAM 10

using namespace std;

struct Pessoa {
    string nome;
};

void lerPessoa(Pessoa vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nome: ";
        getline(cin, vetor[i].nome);
    }
}

void exibirPessoa (Pessoa vetor[], int n){
    for (int i = 0; i < n; i++){
        cout << "Nome: " << vetor[i].nome << endl;
    }
}

int contarPalavras(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    
    // Enquanto houver palavras na frase
    while (stream >> palavra) {
        cout << palavra << endl;
        contagem++;
    }
    
    return contagem;
}

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

int main() {
    Pessoa vetor[TAM];

    lerPessoa(vetor, TAM);
    exibirPessoa(vetor, TAM);

    return 0;
}