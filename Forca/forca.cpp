#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string palavraSecreta = "computador";
    string palavraOculta (palavraSecreta.length(), '_');
    vector <char> letrasErradas;

    int tentativas = 6;

    cout << "===Jogo da forca===\n";

    while (tentativas > 0 && palavraOculta != palavraSecreta){
        cout << "\n palavra" << palavraOculta << "\n";
        cout << "erros";
        for (char letra : letrasErradas){
            cout <<  letra << ' ';
        }

        cout << "Tentativas restantes: " << tentativas << "\n";

        char letra;
        cout << "Digite uma : ";
        cin >> letra;
        letra = tolower(letra);

        // Verifica se a letra já foi usada
        if (palavraOculta.find(letra))
    }
}