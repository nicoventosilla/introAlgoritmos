//
// Created by c0d3r on 14/11/2024.
//

#include "problema2.h"
#include <iostream>

using namespace std;

/*
La empresa UPCImagenes necesita conocer el número de veces que se repite un patrón numérico en
una matriz de tamaño N (N no será mayor a 30) que solo almacena dígitos, esto significa valores entre
0 y 9.

La empresa conocedora de su habilidad para programar lo contrata para que escriba un programa en
Lenguaje C++ y que aplicando sus vastos conocimientos de arreglos realice lo siguiente:

- Solicitar el tamaño de la matriz.
- Generar aleatoriamente los datos de la matriz de tamaño N. Recuerde que la matriz almacena
dígitos entre 0 y 9.
- Solicite el ingreso del patrón numérico, el cual será un número mayor que 99 pero menor que
1000.
- Luego, determinar y mostrar la cantidad de veces que se repite horizontalmente, de izquierda a
derecha, el patrón numérico en la matriz.

Recuerde que la aplicación deberá validar el ingreso de datos.
*/

void problema2()
{
    int N, patron, contador = 0;

    do
    {
        cout << "Ingrese el tamano de la matriz (N): ";
        cin >> N;
    }
    while (N < 1 || N > 30);

    int** Matriz = new int*[N]; // Reservando memoria para la matriz

    for (int i = 0; i < N; i++) // Reservando memoria para las columnas
    {
        Matriz[i] = new int[N];
    }

    // Generando la matriz de tamaño N
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Matriz[i][j] = rand() % 10;
        }
    }

    cout << "Matriz generada: " << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << Matriz[i][j] << " ";
        }
        cout << endl;
    }

    do
    {
        cout << "Ingrese el patron numerico (mayor que 99 y menor que 1000): ";
        cin >> patron;
    }
    while (patron < 100 || patron > 999);

    int digito1 = patron / 100;
    int digito2 = (patron % 100) / 10;
    int digito3 = patron % 10;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 2; j++)
        {
            if (Matriz[i][j] == digito1 && Matriz[i][j + 1] == digito2 && Matriz[i][j + 2] == digito3)
            {
                contador++;
            }
        }
    }

    cout << "El numero de veces que se repite el patron es " << contador;

    // Liberando memoria de la matriz
    for (int i = 0; i < N; i++)
    {
        delete[] Matriz[i];
    }

    delete[] Matriz;
}
