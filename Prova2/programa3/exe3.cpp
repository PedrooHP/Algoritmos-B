/*Dado um arquivo texto chamado de nomes.txt, criar um programa que leia o arquivo e armazene esses nomes numa lista de nomes do tipo string. 
Ao final, exibir a lista populada com a quantidade de nomes lidos do arquivo. Exemplo de arquivo nomes.txt 
Anderson Dick 
Guilherme Londero 
João Messias 
Alexandre Zamberlan 
Anderson Dick
Guilherme Londero*/

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std; 

int contarNomes(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    
    
    while (stream >> palavra) {
        cout << palavra << endl;
        contagem++;
    }
    
    return contagem;
}

int main() {
    //abrir um arquivo texto e exibir seu conteudo na tela

    string nomeArquivo;
	cout << "Informe nome do arquivo que quer exibir na tela: ";
	cin >> nomeArquivo;
    
    
	ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo); 

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    } 
 
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		// procuradorArquivo >> frase; //lendo palavra por palavra da linha 
		cout << linha << endl;
		//tratar a linha e extrair dados dela
	}

	procuradorArquivo.close();

    return 1;

    
}