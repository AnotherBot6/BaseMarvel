#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "marvel-wikia-data.csv"
using namespace std;

int main()
{
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    
    cout << "Archivo completo de  personajes de marvel" << endl;
    cout << "Introduzca la primera letra del nombre de personaje que desea buscar: ";
    char abc;
    cin >> abc; 
    abc = toupper(abc);
    int cont = 0;
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string page_id, name, urlslug, ID, ALIGN, EYE, HAIR, SEX, GSM, ALIVE, APPEARANCES, FIRSTAPPEARANCE, Year;
        // Extraer todos los valores de esa fila
        getline(stream, page_id, delimitador);
        getline(stream, name, delimitador);

        // Imprimir
        //cout << "==================" << endl;
        //cout << "Id: " << page_id << endl;
        if ( name[0] == abc){
            cout << "Personaje: " << name << endl;
            cont = cont + 1;
        }
    }
    cout << "Total de personajes que empiezan con " << abc << ": " << cont << endl;
    archivo.close();
    
} 
