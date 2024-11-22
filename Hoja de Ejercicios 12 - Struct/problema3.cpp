//
// Created by c0d3r on 22/11/2024.
//

#include "problema3.h"
#include <iostream>

using namespace std;

/*
*3. A partir de la declaración de las siguientes estructuras realice un programa en C que lea el array “ats” y
devuelva los datos (nombre, país, deporte) del atleta que ha ganado mayor número de medallas.
struct datos
{
char nombre[40];
char pais[25];
};

struct atleta
{
char deporte[30];
struct datos pers;
int nmedallas;
};

struct atleta ats[30];
*/

struct datos
{
    char nombre[40];
    char pais[25];
};

struct atleta
{
    char deporte[30];
    struct datos pers;
    int nmedallas;
};

void ingresarDatos(atleta ats[], int numero_atletas)
{
    for (int i = 0; i < numero_atletas; i++)
    {
        cout << "Ingrese los datos del atleta " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> ats[i].pers.nombre;
        cout << "Pais: ";
        cin >> ats[i].pers.pais;
        cout << "Deporte: ";
        cin >> ats[i].deporte;
        cout << "Numero de medallas: ";
        cin >> ats[i].nmedallas;
        cout << endl;
    }
}

void atletaConMasMedallas(atleta ats[], int numero_atletas)
{
    int indice_mayor_medallas = 0;
    for (int i = 1; i < numero_atletas; i++)
    {
        if (ats[i].nmedallas > ats[indice_mayor_medallas].nmedallas)
        {
            indice_mayor_medallas = i;
        }
    }

    cout << "El atleta con mayor numero de medallas es:" << endl;
    cout << "Nombre: " << ats[indice_mayor_medallas].pers.nombre << endl;
    cout << "Pais: " << ats[indice_mayor_medallas].pers.pais << endl;
    cout << "Deporte: " << ats[indice_mayor_medallas].deporte << endl;
    cout << "Numero de medallas: " << ats[indice_mayor_medallas].nmedallas << endl;
}

void problema3()
{
    atleta ats[30];
    int numero_atletas;

    cout << "Ingrese el numero de atletas: ";
    cin >> numero_atletas;

    ingresarDatos(ats, numero_atletas);
    atletaConMasMedallas(ats, numero_atletas);
}