#include <iostream>
#include <string>
using namespace std;

// Função que recebe a palavra e a letra, e conta quantas vezes aparece
void contarLetra(const string& palavra, char letra) {
    int contador = 0;

    for (char c : palavra) {
        if (tolower(c) == tolower(letra)) { // deixa case-insensitive
            contador++;
        }
    }

    cout << "A letra '" << letra << "' aparece " << contador << " vez(es) na palavra \"" << palavra << "\".\n";
}

int main() {
    string palavra;
    char letra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    cout << "Digite uma letra: ";
    cin >> letra;

    contarLetra(palavra, letra);

    return 0;
}