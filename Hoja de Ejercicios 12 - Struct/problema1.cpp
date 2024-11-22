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

struct Encuestado
{
    int nivel_aprobacion;
    int edad;
    char nivel_socioeconomico;
};

int generarAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

char generarAleatorioSocioeconomico()
{
    char niveles_socioeconomicos[] = {'A', 'B', 'C', 'D'};
    return niveles_socioeconomicos[rand() % 4];
}

void generarDatosEncuestados(Encuestado ArregloEncuestados[], int numero_personas_encuestadas)
{
    cout << "Generando datos de encuestados..." << endl;
    for (int i = 0; i < numero_personas_encuestadas; i++)
    {
        ArregloEncuestados[i].nivel_aprobacion = generarAleatorio(1, 5);
        ArregloEncuestados[i].edad = generarAleatorio(18, 100);
        ArregloEncuestados[i].nivel_socioeconomico = generarAleatorioSocioeconomico();
    }
    cout << endl;
}

void mostrarEncuestados(Encuestado ArregloEncuestados[], int numero_personas_encuestadas)
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

void mayorVotacion(Encuestado ArregloEncuestados[], int numero_personas_encuestadas)
{
    int votos[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < numero_personas_encuestadas; i++)
    {
        votos[ArregloEncuestados[i].nivel_aprobacion - 1]++;
    }

    int mayor_votacion = 0;
    int nivel_aprobacion_mayor_votacion = 0;
    for (int i = 0; i < 5; i++)
    {
        if (votos[i] > mayor_votacion)
        {
            mayor_votacion = votos[i];
            nivel_aprobacion_mayor_votacion = i + 1;
        }
    }

    cout << "El nivel de aprobacion que obtuvo la mayor votación fue: " << nivel_aprobacion_mayor_votacion << endl;
}

void nivelSocioeconomicoA(Encuestado ArregloEncuestados[], int numero_personas_encuestadas)
{
    int personas_nivel_socioeconomico_a = 0;
    for (int i = 0; i < numero_personas_encuestadas; i++)
    {
        if (ArregloEncuestados[i].nivel_socioeconomico == 'A')
        {
            personas_nivel_socioeconomico_a++;
        }
    }

    cout << "El numero de personas del nivel socioeconomico A que participaron de la encuesta fue: " <<
        personas_nivel_socioeconomico_a << endl;
}

void edadPersonaMasJoven(Encuestado ArregloEncuestados[], int numero_personas_encuestadas)
{
    int edad_mas_joven = ArregloEncuestados[0].edad;
    for (int i = 1; i < numero_personas_encuestadas; i++)
    {
        if (ArregloEncuestados[i].edad < edad_mas_joven)
        {
            edad_mas_joven = ArregloEncuestados[i].edad;
        }
    }

    cout << "La edad de la persona mas joven que fue encuestada fue: " << edad_mas_joven << endl;
}

void problema1()
{
    srand(time(0));

    int numero_personas_encuestadas;

    do
    {
        cout << "Ingrese el numero de personas encuestadas: ";
        cin >> numero_personas_encuestadas;
    }
    while (numero_personas_encuestadas < 1 || numero_personas_encuestadas > 100);

    Encuestado ArregloEncuestados[numero_personas_encuestadas];

    generarDatosEncuestados(ArregloEncuestados, numero_personas_encuestadas);
    mostrarEncuestados(ArregloEncuestados, numero_personas_encuestadas);
    mayorVotacion(ArregloEncuestados, numero_personas_encuestadas);
    nivelSocioeconomicoA(ArregloEncuestados, numero_personas_encuestadas);
    edadPersonaMasJoven(ArregloEncuestados, numero_personas_encuestadas);
}
