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
    
    string colorInicial[4]= {"\x1B[31m", "\x1B[32m", "\033[1;33m", "\x1B[34m"};
    string colorFinal[4]= {"\x1B[0m", "\x1B[0m", "\x1B[0m", "\x1B[0m"};
    int selecColor = 2;

    string colorArg = args[3];
    transform(colorArg.begin(), colorArg.end(), colorArg.begin(), ::tolower);

    if (colorArg == "rojo" || colorArg == "red")
    {
        selecColor = 0;
    }else if (colorArg == "verde" || colorArg == "green")
    {
        selecColor = 1;
    }else if (colorArg == "amarrillo" || colorArg == "yellow")
    {
        selecColor = 2;
    }else if (colorArg == "azul" || colorArg == "blue")
    {
        selecColor = 3;
    }else
    {
        cout<<"Color no válido, se usará el amarrillo por defecto"<<endl;
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
    int numDeCoincidenciasLineas = 0;
    cout<<endl;

    for (int i = 0; i < numDeCaracteres; i++)
    {
        string linea = texto[i];
        transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
        size_t pos = linea.find(palabra);

        if (pos != string::npos)
        {
            textoFinal[i] = texto[i];
            numDeCoincidenciasLineas++;
        }
    }

    int numDeCoincidencias = 0;
    for (int i = 0; i < numDeCaracteres; i++)
    {
        string linea = textoFinal[i];
        transform(linea.begin(), linea.end(), linea.begin(), ::tolower);
        size_t inicio =0;
        size_t pos = linea.find(palabra);

        while (pos != string::npos)
        {
            cout<<textoFinal[i].substr(inicio, pos - inicio);
            cout<<colorInicial[selecColor]<<textoFinal[i].substr(pos, palabra.length())<<colorFinal[selecColor];

            inicio = pos + palabra.length();
            pos = linea.find(palabra, inicio);
            numDeCoincidencias++;
        }

        if (!textoFinal[i].empty())
        {
            cout<<textoFinal[i].substr(inicio);
            cout<<endl;
        }
    }
    cout<<endl;

    cout<<numDeCoincidencias<<" coincidencias en "<<numDeCoincidenciasLineas<<" lineas"<<endl;
    cout<<endl;
}