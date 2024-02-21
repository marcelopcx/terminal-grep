#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** args) {
    fstream ruta;
    ruta.open(args[1]);

    if (!ruta.is_open())
    {
        cerr<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    
    string line;
    int numDeCaracteres = 0;
    string texto[100];

    while (getline(ruta, line))
    {
        texto[numDeCaracteres] = line;
        numDeCaracteres++;
    } 

    string palabra = (args[2]);
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

    string textoFinal[100];
    cout<<endl;

    for (int i = 0; i < numDeCaracteres; i++)
    {
        string linea = texto[i];
        transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
        size_t pos = linea.find(palabra);

        if (pos != string::npos)
        {
            textoFinal[i] = texto[i];
        }
    }

    for (int i = 0; i < numDeCaracteres; i++)
    {
        string linea = textoFinal[i];
        transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
        size_t inicio =0;
        size_t pos = linea.find(palabra);

        while (pos != string::npos)
        {
            cout<<textoFinal[i].substr(inicio, pos - inicio);
            cout<<"\033[1;33m"<<textoFinal[i].substr(pos, palabra.length())<<"\033[0m";

            inicio = pos + palabra.length();
            pos = linea.find(palabra, inicio);
        }

        if (!textoFinal[i].empty())
        {
            cout<<textoFinal[i].substr(inicio);
            cout<<endl;
        }
    }
    cout<<endl;
}