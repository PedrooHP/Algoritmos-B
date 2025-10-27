#include <iostream>

// Inclui a struct Aluno e a constante TAM
#include "meusTipos.h" 

// Inclui as funções de leitura, exibição e cálculo
#include "minhasFuncoes.h" 

using namespace std;

void executarPrograma() {
    // 1. Criação do vetor de structs
    Aluno turma[TAM]; 

    // 2. Chamada da função para ler e preencher o vetor
    lerAlunos(turma); 

    // 3. Chamada da função para salvar os dados no arquivo
    salvarAlunosEmArquivo(turma, "alunos.txt");

    // 4. Chamada da função para exibir o vetor
    exibirAlunos(turma);
    
    // 5. Chamada da função com retorno para calcular a média
    float mediaFinal = calcularMediaGeral(turma);
    
    // 6. Exibe a média geral
    cout << "\n========================================\n";
    cout << "MEDIA GERAL DA TURMA: " << mediaFinal << endl;
    cout << "========================================\n";
    
    cout << "\nPrograma finalizado.\n";
}

// ----------------------------------------------------------------------
// MAIN
// ----------------------------------------------------------------------
int main() {
    executarPrograma(); 
    return 0;
}