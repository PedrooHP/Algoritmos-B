/*Questão 4) Complemento da questão 3. Agora, construir um método que localize e exiba os nomes replicados.*/

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
}

void listaNomes(string nome, string listaNomes[], int *quantidadeNomes, int tamanho){

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
    string lista;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		// procuradorArquivo >> frase; //lendo palavra por palavra da linha 
		cout << linha << endl;
		//tratar a linha e extrair dados dela
	}
    string nome;
    bool encontrou = false;
    int i;
    for (i = 0; i < int *quantidadeNomes; i++) {
        if (nome == listaNomes[i]) {
            encontrou = true;
            break;
        }
    }

    
    if (encontrou) { //se encontrou o nome, retorna falso pq nao conseguiu inserir
        return false;
    }

    *quantidadeNomes = *quantidadeNomes + 1;
    listaNomes[*quantidadeNomes] = nome;


	procuradorArquivo.close();

    return 1;

    
}