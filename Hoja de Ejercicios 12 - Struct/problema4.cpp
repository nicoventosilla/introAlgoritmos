//
// Created by c0d3r on 22/11/2024.
//

#include "problema4.h"
#include <iostream>

using namespace std;

/**
* 4. La información de todos los empleados de la empresa DATASYSTEM está almacenadaen una variable de
tipo struct llamada “empleado”. La información con que se cuenta de cada empleado es: nombre, sexo y
sueldo.
Por tanto se pide: Realizar un programa en C++ que lea en un array de estructuras los datos de los N
trabajadores de la empresa y que imprima los datos del empleado con mayor y menor salario.
*/

struct Empleado
{
    string nombre;
    char sexo; // M o F
    float sueldo;
};

void ingresarDatos(Empleado empleados[], int numero_empleados)
{
    for (int i = 0; i < numero_empleados; i++)
    {
        cout << "Ingrese los datos del empleado " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> empleados[i].nombre;
        cout << "Sexo (M o F): ";
        cin >> empleados[i].sexo;
        cout << "Sueldo: ";
        cin >> empleados[i].sueldo;
        cout << endl;
    }
}

void empleadoConMayorSueldo(Empleado ArrayEmpleados[], int numero_empleados)
{
    float mayor_sueldo = ArrayEmpleados[0].sueldo;
    int index = 0;
    for (int i = 1; i < numero_empleados; i++)
    {
        if (ArrayEmpleados[i].sueldo > mayor_sueldo)
        {
            mayor_sueldo = ArrayEmpleados[i].sueldo;
            index = i;
        }
    }

    cout << "Empleado con mayor sueldo: " << endl;
    cout << "Nombre: " << ArrayEmpleados[index].nombre << endl;
    cout << "Sexo: " << ArrayEmpleados[index].sexo << endl;
    cout << "Sueldo: " << ArrayEmpleados[index].sueldo << endl;
    cout << endl;
}

void empleadoConMenorSueldo(Empleado ArrayEmpleados[], int numero_empleados)
{
    float menor_sueldo = ArrayEmpleados[0].sueldo;
    int index = 0;
    for (int i = 1; i < numero_empleados; i++)
    {
        if (ArrayEmpleados[i].sueldo < menor_sueldo)
        {
            menor_sueldo = ArrayEmpleados[i].sueldo;
            index = i;
        }
    }

    cout << "Empleado con menor sueldo: " << endl;
    cout << "Nombre: " << ArrayEmpleados[index].nombre << endl;
    cout << "Sexo: " << ArrayEmpleados[index].sexo << endl;
    cout << "Sueldo: " << ArrayEmpleados[index].sueldo << endl;
    cout << endl;
}

void problema4()
{
    int numero_empleados;
    cout << "Ingrese el numero de empleados: ";
    cin >> numero_empleados;

    Empleado ArrayEmpleados[numero_empleados];

    ingresarDatos(ArrayEmpleados, numero_empleados);
    empleadoConMayorSueldo(ArrayEmpleados, numero_empleados);
    empleadoConMenorSueldo(ArrayEmpleados, numero_empleados);
}
