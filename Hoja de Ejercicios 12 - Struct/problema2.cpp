//
// Created by c0d3r on 21/11/2024.
//

#include "problema2.h"
#include <iostream>
#include <cstdlib> // Para usar srand y rand
#include <ctime> // Para usar time
#include <algorithm> // Para usar sort

using namespace std;

/*
*La empresa "ENCUESTAFA" se dedica a realizar estudios estadísticos sobre diversos temas. Su último
proyecto tiene como meta analizar el monto mensual aproximado que las personas gastan
comprando gaseosas o algún otro tipo de bebida embotellada, según el sexo y edad.
Para probar las funcionalidades del programa desarrollado para este proyecto. Se desea realizar un
programa en C++ que solicite el número de personas N con las que se trabajara y genere en un Arreglo
un monto aleatorio entre 25 y 500 Nuevos Soles para cada una de las personas. Los
géneros también se generan de manera aleatoria y las edades están comprendidas entre 15 – 50
años.
Se pide mostrar en pantalla:
 El listado de los N montos generados al azar (N tendrá un valor máximo de 200)
 El listado ordenado ascendentemente según el género y los montos.
 EL promedio de gasto según cada género.
 El promedio de gasto según la edad.
*/

// Estructura para almacenar los datos de una persona
struct Persona
{
    char sexo;
    int edad;
    int monto_gastado;
};

int generarAleatorio2(int min, int max) // Generar un numero aleatorio entre min y max
{
    return rand() % (max - min + 1) + min; // Formula para generar un numero aleatorio entre min y max
}

char generarAleatorioSexo() // Generar un sexo aleatorio
{
    char sexos[] = {'M', 'F'}; // Sexos
    return sexos[generarAleatorio2(0, 1)]; // Seleccionamos un sexo aleatorio
}

void generarDatosPersonas(Persona ArregloPersonas[], int numero_personas) // Generar datos de personas
{
    cout << "Generando datos de personas..." << endl;
    for (int i = 0; i < numero_personas; i++)
    {
        ArregloPersonas[i].sexo = generarAleatorioSexo(); // Generamos un sexo aleatorio
        ArregloPersonas[i].edad = generarAleatorio2(15, 50); // Generamos una edad aleatoria
        ArregloPersonas[i].monto_gastado = generarAleatorio2(25, 500); // Generamos un monto gastado aleatorio
    }
    cout << endl;
}

void mostrarPersonas(Persona ArregloPersonas[], int numero_personas)
{
    for (int i = 0; i < numero_personas; i++)
    {
        cout << "Persona " << i << ": " << endl;
        cout << "Sexo: " << ArregloPersonas[i].sexo << endl;
        cout << "Edad: " << ArregloPersonas[i].edad << endl;
        cout << "Monto gastado: " << ArregloPersonas[i].monto_gastado << endl;
        cout << endl;
    }
}

void ordenarPersonasPorGeneroYMontos(Persona ArregloPersonas[], int numero_personas) // Ordenar personas por genero y montos
{
    cout << "Ordenando personas por genero y montos..." << endl;
    for (int j = 0; j < numero_personas - 1; j++) // Recorremos el arreglo de personas
    {
        for (int i = j + 1; i < numero_personas; i++)
        {
            // Si el genero es mayor o si el genero es igual y el monto gastado es mayor
            if (ArregloPersonas[j].sexo > ArregloPersonas[i].sexo || (ArregloPersonas[j].sexo == ArregloPersonas[i].sexo
                && ArregloPersonas[j].monto_gastado > ArregloPersonas[i].monto_gastado))
            {
                swap(ArregloPersonas[j], ArregloPersonas[i]); // Intercambiamos las personas
            }
        }
    }
    mostrarPersonas(ArregloPersonas, numero_personas);
}

void promedioGastoPorGenero(Persona ArregloPersonas[], int numero_personas) // Promedio de gasto por genero
{
    double suma_gasto_hombres = 0.0;
    double suma_gasto_mujeres = 0.0;
    int cantidad_hombres = 0;
    int cantidad_mujeres = 0;

    for (int i = 0; i < numero_personas; i++) // Recorremos el arreglo de personas
    {
        if (ArregloPersonas[i].sexo == 'M') // Si es hombre
        {
            suma_gasto_hombres += ArregloPersonas[i].monto_gastado; // Sumamos el monto gastado
            cantidad_hombres++; // Aumentamos la cantidad de hombres
        }
        else // Si es mujer
        {
            suma_gasto_mujeres += ArregloPersonas[i].monto_gastado; // Sumamos el monto gastado
            cantidad_mujeres++; // Aumentamos la cantidad de mujeres
        }
    }

    cout << "Promedio de gasto de hombres: " << suma_gasto_hombres / cantidad_hombres << endl;
    cout << "Promedio de gasto de mujeres: " << suma_gasto_mujeres / cantidad_mujeres << endl;
}

void promedioGastoPorEdad(Persona ArregloPersonas[], int numero_personas) // Promedio de gasto por edad
{
    const int max_edad = 50; // Edad maxima
    const int min_edad = 15; // Edad minima
    const int rango_edades = max_edad - min_edad + 1; // Rango de edades

    double suma_gasto_por_edad[rango_edades] = {0.0}; // Suma de gasto por edad
    int cantidad_por_edad[rango_edades] = {0}; // Cantidad de personas por edad

    for (int i = 0; i < numero_personas; i++) // Recorremos el arreglo de personas
    {
        int edad = ArregloPersonas[i].edad; // Edad de la persona
        suma_gasto_por_edad[edad - min_edad] += ArregloPersonas[i].monto_gastado; // Sumamos el monto gastado
        cantidad_por_edad[edad - min_edad]++; // Aumentamos la cantidad de personas
    }

    for (int i = 0; i < rango_edades; i++) // Recorremos el rango de edades
    {
        if (cantidad_por_edad[i] > 0) // Si hay personas en esa edad
        {
            double promedio = suma_gasto_por_edad[i] / cantidad_por_edad[i]; // Calculamos el promedio
            cout << "Promedio de gasto para la edad " << (i + min_edad) << ": " << promedio << endl; // Mostramos el promedio
        }
    }
}

void problema2()
{
    srand(time(0));

    int numero_personas;
    cout << "Ingrese el numero de personas: ";
    cin >> numero_personas;

    Persona ArregloPersonas[numero_personas];

    generarDatosPersonas(ArregloPersonas, numero_personas);
    mostrarPersonas(ArregloPersonas, numero_personas);
    ordenarPersonasPorGeneroYMontos(ArregloPersonas, numero_personas);
    promedioGastoPorGenero(ArregloPersonas, numero_personas);
    promedioGastoPorEdad(ArregloPersonas, numero_personas);
}
