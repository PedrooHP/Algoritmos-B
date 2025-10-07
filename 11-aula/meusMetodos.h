#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void gravarPessoaBase(string nome, string email, string baseDados){
    //abrir arquivo para escrita
	ofstream procuradorArquivo; 
    //arquivo sendo aberto para append ou inserir no final
    procuradorArquivo.open(baseDados, ios::out | ios::app);

    procuradorArquivo << nome << " , " << email << endl;
}

int cadastrarPessoa(Pessoa vetor[], int tamanho, int qtdPessoas, string baseDados){
    if (tamanho == qtdPessoas){
        cout << "Estrutura de dados lotada\n";
        return qtdPessoas;
    }
    string nome;
    string email;

    cout << "Nome: ";
    getline(cin, nome);
    fflush(stdin);

    cout << "Email: ";
    cin >> email;
    fflush(stdin);

    //validar se o nome e email ja estao no vetor

    vetor[qtdPessoas].nome = nome;
    vetor[qtdPessoas].email = email;
    qtdPessoas += 1;

    //Gravar a pessoa (nome, email) na base
    gravarPessoaBase (nome, email, baseDados);
    return qtdPessoas;
}

void listarPessoas(Pessoa vetor[], int qtdPessoas){
    for (int i = 0; i < qtdPessoas; i++){
        cout << "Nome: "<< vetor[i].nome << ". Email" << vetor[i].email << endl;
    }
    cout << "_________\n";
    cout << "Total de registros: " << qtdPessoas << endl;
}

void menu(Pessoa vetor[], int tamanho, int qtdPessoas, string baseDados){
    int opcao;
    do{
        cout << "Menu\n";
        cout << "1 - Listar pessoass\n";
        cout << "2 - Cadastrar pessoa\n";
        cout << "3 - Sair\n";
        cout << "opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
            case 1:
            cout << "Listar pessoas: \n";
            listarPessoas(vetor, qtdPessoas);
            break;

            case 2:
                cout << "Cadastrar pessoa\n";
                qtdPessoas = cadastrarPessoa(vetor, tamanho, qtdPessoas, baseDados);
                break;
            case 3:
                break;
            default:
                cout << "Opcao invalida\n";
        }
    }while (opcao != 3);
}

void split(string vetor[], string str, string deli = " ") {        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}


int conectarBase(string baseDados, Pessoa vetor[], int tamanho) {
    int qtd_pessoas = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados); 

    if (!procuradorArquivo) {
        cout << "Arquivo da base de dados não localizado. Programa encerrado." << endl;
        exit(0);
    } 
    if (qtd_pessoas == tamanho) {
        cout << "Vetor lotado. Programa encerrado." << endl;
        exit(0);
    }

    //le o arquivo capturando as pessoas linha a linha
	string linha;
    string vetorLinha[2];
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo, linha); //lendo a linha inteira
        //linha = Alexandre Zamberlan,alexz@ufn.edu.br
        split(vetorLinha, linha, ",");
        //vetorLinha[0] = "Alexandre Zamberlan"
        //vetorLinha[1] = "alexz@ufn.edu.br"
        vetor[qtd_pessoas].nome = vetorLinha[0];
        vetor[qtd_pessoas].email = vetorLinha[1];
        qtd_pessoas += 1;
	}
	procuradorArquivo.close();
    cout << "Quantidade " << qtd_pessoas << endl;
    return qtd_pessoas;
}