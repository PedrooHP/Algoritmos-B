#include "exe1.h"
#include <string>
#include <cctype>

int contarVogais(const std::string &frase) {
    int cont = 0;
    for(char c : frase) {
        char letra = std::tolower(c);
        if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            cont++;
        }
    }
    return cont;
}