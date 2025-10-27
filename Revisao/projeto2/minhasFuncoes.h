#include <iostream>
#include <string>
using namespace std;
#define TAM 5

void lerAlunos(Aluno vetorAlunos[]){
    cout << "DADOS DOS ALUNOS\n";
    for (int i = 0; i < TAM; i++){
        cout << "\n [Aluno " << i + 1 << "]\n";

        cout << "Nome: ";
        
        if (i == 0) cin.ignore();
        getline(cin, vetorAlunos[i].matricula);

        //leitura de notas

        cout << "Nota: ";
        cin >> vetorAlunos[i].nota;

        if (i < TAM - 1) cin.ignore();
    }
}

//Função para exibir os dados dos alunos

void exibirAlunos (Aluno vetorAlunos[]){
    cout << "\n\nLISTAGEM DOS ALUNOS CADASTRADOS\n";
    for (int i = 0; i < TAM; i++){
        cout << "\n [Aluno " << i + 1 << "]\n";
        cout << "Nome : " << vetorAlunos[i].nome << endl;
        cout << "Matricula: " << vetorAlunos[i].matricula << endl;
        cout << "Nota: " << vetorAlunos[i].nota << endl;
    }
}

float calcularMediaGeral(Aluno vetorAlunos[]){
    float somaNotas = 0.0;

    for (int i = 0; i < TAM; i++){
        somaNotas += vetorAlunos[i].nota;
    }

    //calcula a média dividindo
    float media = somaNotas / TAM;

    return media;
}