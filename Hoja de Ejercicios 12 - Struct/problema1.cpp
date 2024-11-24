//
// Created by c0d3r on 05/11/2024.
//

#include "problema1.h"
#include <iostream>
#include <cstdlib> // Para usar srand y rand
#include <ctime> // Para usar time

using namespace std;

/*
*1. La empresa TATUM S.A. ha realizado una encuesta a nivel de Lima sobre el nivel de aprobación de
los primeros 100 días de gobierno del Presidente Regional. En ella los niveles fueron identificados
por un número entre 1 (malo) y 5 (excelente).
Se desea realizar un programa en C++ que permita realizar lo siguiente:
 Ingrese el número de personas encuestadas. Este es un valor que no debe ser mayor a 100.
 Genere aleatoriamente los datos de cada uno de los encuestados, es decir el nivel de
aprobación (entre 1 y 5), su edad (mayor a 17) y su nivel socio económico (A, B, C o D).
 Calcule e imprima cual es el nivel de aprobación que obtuvo la mayor votación.
 Calcule e imprima cuantas personas del nivel socio económico A, participaron de la
encuesta.
 Determine e imprima la edad de la persona más joven que fue encuestada.
Recuerde que la aplicación deberá realizar las validaciones necesarias
 */

// Estructura para almacenar los datos de un encuestado
struct Encuestado
{
    int nivel_aprobacion;
    int edad;
    char nivel_socioeconomico;
};

int generarAleatorio(int min, int max) // Generar un numero aleatorio entre min y max
{
    return rand() % (max - min + 1) + min; // Formula para generar un numero aleatorio entre min y max
}

char generarAleatorioSocioeconomico() // Generar un nivel socioeconomico aleatorio
{
    char niveles_socioeconomicos[] = {'A', 'B', 'C', 'D'}; // Niveles socioeconomicos
    return niveles_socioeconomicos[rand() % 4]; // Seleccionamos un nivel socioeconomico aleatorio
}

void generarDatosEncuestados(Encuestado ArregloEncuestados[], int numero_personas_encuestadas)
{
    cout << "Generando datos de encuestados..." << endl;
    for (int i = 0; i < numero_personas_encuestadas; i++)
    {
        ArregloEncuestados[i].nivel_aprobacion = generarAleatorio(1, 5); // Generamos un nivel de aprobacion aleatorio
        ArregloEncuestados[i].edad = generarAleatorio(18, 100); // Generamos una edad aleatoria
        ArregloEncuestados[i].nivel_socioeconomico = generarAleatorioSocioeconomico(); // Generamos un nivel socioeconomico aleatorio
    }
    cout << endl;
}

void mostrarEncuestados(Encuestado ArregloEncuestados[], int numero_personas_encuestadas) // Mostrar los datos de los encuestados
{
    for (int i = 0; i < numero_personas_encuestadas; i++)
    {
        cout << "Encuestado " << i << ": " << endl;
        cout << "Nivel de aprobacion: " << ArregloEncuestados[i].nivel_aprobacion << endl;
        cout << "Edad: " << ArregloEncuestados[i].edad << endl;
        cout << "Nivel socioeconomico: " << ArregloEncuestados[i].nivel_socioeconomico << endl;
        cout << endl;
    }
}

void mayorVotacion(Encuestado ArregloEncuestados[], int numero_personas_encuestadas) // Calcular el nivel de aprobacion con mayor votacion
{
    int votos[5] = {0, 0, 0, 0, 0}; // Inicializamos el arreglo de votos en 0 para cada nivel de aprobacion
    for (int i = 0; i < numero_personas_encuestadas; i++) // Contamos los votos
    {
        votos[ArregloEncuestados[i].nivel_aprobacion - 1]++; // Restamos 1 al nivel de aprobacion para que sea un indice valido
    }

    int mayor_votacion = 0;
    int nivel_aprobacion_mayor_votacion = 0;
    for (int i = 0; i < 5; i++) // Buscamos el nivel de aprobacion con mayor votacion
    {
        if (votos[i] > mayor_votacion) // Si encontramos un nivel de aprobacion con mayor votacion
        {
            mayor_votacion = votos[i]; // Actualizamos la mayor votacion
            nivel_aprobacion_mayor_votacion = i + 1; // Actualizamos el nivel de aprobacion con mayor votacion
        }
    }

    cout << "El nivel de aprobacion que obtuvo la mayor votación fue: " << nivel_aprobacion_mayor_votacion << " con " <<
        mayor_votacion << " votos" << endl;
}

void nivelSocioeconomicoA(Encuestado ArregloEncuestados[], int numero_personas_encuestadas) // Calcular cuantas personas del nivel socioeconomico A participaron de la encuesta
{
    int personas_nivel_socioeconomico_a = 0;
    for (int i = 0; i < numero_personas_encuestadas; i++) // Contamos las personas del nivel socioeconomico A
    {
        if (ArregloEncuestados[i].nivel_socioeconomico == 'A') // Si encontramos una persona del nivel socioeconomico A
        {
            personas_nivel_socioeconomico_a++; // Aumentamos el contador
        }
    }

    cout << "El numero de personas del nivel socioeconomico A que participaron de la encuesta fue: " <<
        personas_nivel_socioeconomico_a << endl;
}

void edadPersonaMasJoven(Encuestado ArregloEncuestados[], int numero_personas_encuestadas) // Calcular la edad de la persona mas joven que fue encuestada
{
    int edad_mas_joven = ArregloEncuestados[0].edad; // Inicializamos la edad mas joven con la primera persona encuestada
    for (int i = 1; i < numero_personas_encuestadas; i++) // Buscamos la edad mas joven
    {
        if (ArregloEncuestados[i].edad < edad_mas_joven) // Si encontramos una edad mas joven
        {
            edad_mas_joven = ArregloEncuestados[i].edad; // Actualizamos la edad mas joven
        }
    }

    cout << "La edad de la persona mas joven que fue encuestada fue: " << edad_mas_joven << endl;
}

void problema1() // int main()
{
    srand(time(0)); // Semilla para generar numeros aleatorios

    int numero_personas_encuestadas;

    do
    {
        cout << "Ingrese el numero de personas encuestadas: ";
        cin >> numero_personas_encuestadas;
    }
    while (numero_personas_encuestadas < 1 || numero_personas_encuestadas > 100);

    Encuestado ArregloEncuestados[numero_personas_encuestadas]; // Arreglo de encuestados

    generarDatosEncuestados(ArregloEncuestados, numero_personas_encuestadas);
    mostrarEncuestados(ArregloEncuestados, numero_personas_encuestadas);
    mayorVotacion(ArregloEncuestados, numero_personas_encuestadas);
    nivelSocioeconomicoA(ArregloEncuestados, numero_personas_encuestadas);
    edadPersonaMasJoven(ArregloEncuestados, numero_personas_encuestadas);
}
