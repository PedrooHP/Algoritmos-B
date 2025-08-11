#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
 
int main()
{
    time_t agora = time(nullptr);
    tm* agora_local = localtime(&agora);
 
    string dia = to_string(agora_local->tm_mday);
    string mes = to_string(agora_local->tm_mon + 1);
    string ano = to_string(agora_local->tm_year + 1900);
 
    cout << "Data: " << dia << "/" << mes << "/" << ano << endl;
    return 0;
}