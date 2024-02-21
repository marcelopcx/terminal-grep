#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** args) {
    fstream ruta;
    ruta.open(args[1]);

    if (!ruta.is_open())
    {
        cerr<<"Error al abrir el archivo"<<endl;
    }
    
    string line;
    int numDeCaracteres = 0;
    string texto[100];

    while (getline(ruta, line))
    {
        texto[numDeCaracteres] = line;
        numDeCaracteres++;
    } 
}