#include <iostream> // <stdio.h>
 
using namespace std;
 
//equivalent printf - std::cout
//equivalente scanf/gets - std::cin
 
//menu e no futuro um sistema de gestão de emprestimos de itens pessoais
//emprestar - nome/apelido; celular; data emprestimo; descricao do item
//menu
//1 - Emprestar
//2 - Devolver
//3 - Listar
//4 - Sair
//Opção
int main()
{
    int opcao;
 
    do
    {
        cout << "M E N U" << endl;
        cout << "1 - Emprestar" << endl;
        cout << "2 - Devolver" << endl;
        cout << "3 - Listar emprestimos" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: " << endl;
        cin >> opcao;
 
        switch (opcao)
        {
        case 1:
            cout << "AREA DE EMPRESTIMO" << endl;
            break;
        case 2:
            cout << "AREA DE DEVOLUCAO" << endl;
            break;
        case 3:
            cout << "LISTAGEM DE EMPRESTIMOS" << endl;
            break;
        case 4:
            cout << "Voce esta encerrando o programa...." << endl;
            break;
        default:
            cout << "Opcao invalida...." << endl;
            break;
        }
 
    } while (opcao != 4);
    cout << "Programa encerrado....\n";
    return 1;
}