#include <iostream>
#include <string>
using namespace std;
#define TAM 5

typedef struct{
    string nome;
    string matricula;
    float nota;
} Aluno;

//função para ler os dados de 5 alunos:

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

void executrarPrograma (){
    //Criação do vetor de structs
    Aluno turma[TAM];

    //chamada da função para ler e preencher o vetor
    lerAlunos(turma);

    //chamada da função para exibir o vetor
    exibirAlunos (turma);

    cout << "\n programa encerrado ";

}

int main (){
    executrarPrograma();
    return 0;
}