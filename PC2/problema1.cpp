//
// Created by c0d3r on 14/11/2024.
//

#include "problema1.h"
#include <iostream>

using namespace std;

/*
* REGISTRO DIARIO DE ASISTENCIA A CLASES
*
* En una universidad, se desea realizar un seguimiento de la asistencia de estudiantes en varias aulas durante un día.
* Cada aula tiene un registro de asistencia por hora, y se necesita almacenar información adicional sobre cada registro de asistencia para realizar un análisis detallado.
*
* Estructura de Datos
* 1. Estructura RegistroAsistencia: Esta estructura contendrá la siguiente información:
* -	asistencias: Número de estudiantes que asistieron en una hora específica.
* -	dia: Día del mes en el que se realiza el registro.
* -	hora: Hora específica del día (de 0 a 23).
*
* 2. Matriz asistencias:
* -	La matriz almacenará los registros de asistencia para cada aula y cada hora del día, donde cada elemento de la matriz es un RegistroAsistencia.
* -	La fila representa el aula.
* -	La columna representa la hora del día.
* -	Cada posición en la matriz asistencias[aula][hora] guarda un RegistroAsistencia que contiene el número de asistencias, el día y la hora específicos para esa aula.
*
* FUNCIONALIDADES DEL PROGRAMA
* 1.	Registrar asistencia: Permitir al usuario ingresar el número de asistencias en una aula específica para una hora determinada. Esto incluirá la hora y el día en que se registran las asistencias.
* 2.	Consultar hora con mayor asistencia en un aula específica: Mostrar la hora del día en la que se registró el mayor número de asistencias en un aula
* 3.	Consultar hora con menor asistencia en un aula específica: Mostrar la hora del día en la que se registró el menor número de asistencias en un aula.
* 4.	Modificar asistencia: Permitir al usuario modificar el número de asistencias y la hora para un aula específica en un día dado.
* 5.	Consultar asistencia específica: Mostrar el número de asistencias registradas en una hora específica para un aula indicada.
* 6.	Calcular total de asistencias en la mañana: Calcular el total de asistencias registradas en el turno de la mañana (6 a 11 horas) para un aula específica en un día determinado.
* 7.	Mostrar registros de asistencia en orden descendente: Presentar todos los registros de asistencia de un aula, ordenados de mayor a menor, para ese día.
*/

struct RegistroAsistencia
{
    int asistencias;
    int dia;
    int hora;
};

void mostrarMenuOpciones()
{
    cout << "\nREGISTRO DIARIO DE ASISTENCIA A CLASE" << endl;
    cout << "1. Registrar asistencia" << endl;
    cout << "2. Consultar hora con mayor asistencia en un aula especifica" << endl;
    cout << "3. Consultar hora con menor asistencia en un aula especifica" << endl;
    cout << "4. Modificar asistencia" << endl;
    cout << "5. Consultar asistencia especifica" << endl;
    cout << "6. Calcular total de asistencias en la manana" << endl;
    cout << "7. Mostrar registros de asistencia en orden descendente" << endl;
    cout << "8. Salir" << endl;
}

void registrarAsistencia(RegistroAsistencia** Asistencias, int aulas, int horas)
{
    int aula;
    int hora;
    int asistencias;
    int dia;

    cout << "Ingrese el aula (0 - " << aulas - 1 << "): ";
    cin >> aula;

    cout << "Ingrese la hora (0 - " << horas - 1 << "): ";
    cin >> hora;

    cout << "Ingrese el numero de asistencias: ";
    cin >> asistencias;

    cout << "Ingrese el dia (1 - 31): ";
    cin >> dia;

    if (aula >= 0 && aula < aulas && hora >= 0 && hora < horas && dia >= 1 && dia <= 31)
    {
        Asistencias[aula][hora].asistencias = asistencias;
        Asistencias[aula][hora].dia = dia;
        Asistencias[aula][hora].hora = hora;
    }
    else
    {
        cout << "Aula, hora o dia no validos" << endl;
    }
}

void consultarHoraMayorAsistencia(RegistroAsistencia** Asistencias, int aulas, int horas)
{
    int aula;

    cout << "Ingrese el aula (0 - " << aulas - 1 << "): ";
    cin >> aula;

    if (aula >= 0 && aula < aulas)
    {
        int maxAsistencias = Asistencias[aula][0].asistencias;
        int horaMaxAsistencias = 0;

        for (int i = 1; i < horas; ++i)
        {
            if (Asistencias[aula][i].asistencias > maxAsistencias)
            {
                maxAsistencias = Asistencias[aula][i].asistencias;
                horaMaxAsistencias = i;
            }
        }

        cout << "La hora con mayor asistencia en el aula " << aula << " es: " << horaMaxAsistencias << endl;
    }
    else
    {
        cout << "Aula no valida" << endl;
    }
}

void consultarHoraMenorAsistencia(RegistroAsistencia** Asistencias, int aulas, int horas)
{
    int aula;

    cout << "Ingrese el aula: ";
    cin >> aula;

    if (aula >= 0 && aula < aulas)
    {
        int minAsistencias = Asistencias[aula][0].asistencias;
        int horaMinAsistencias = 0;

        for (int i = 1; i < horas; ++i)
        {
            if (Asistencias[aula][i].asistencias < minAsistencias)
            {
                minAsistencias = Asistencias[aula][i].asistencias;
                horaMinAsistencias = i;
            }
        }

        cout << "La hora con menor asistencia en el aula " << aula << " es: " << horaMinAsistencias << endl;
    }
    else
    {
        cout << "Aula no valida" << endl;
    }
}

void modificarAsistencia(RegistroAsistencia** Asistencias, int aulas, int horas)
{
    int aula;
    int hora;
    int asistencias;
    int dia;

    cout << "Ingrese el aula (0 - " << aulas - 1 << "): ";
    cin >> aula;

    cout << "Ingrese la hora (0 - " << horas - 1 << "): ";
    cin >> hora;

    cout << "Ingrese el numero de asistencias: ";
    cin >> asistencias;

    cout << "Ingrese el dia (1 - 31): ";
    cin >> dia;

    if (aula >= 0 && aula < aulas && hora >= 0 && hora < horas && dia >= 1 && dia <= 31)
    {
        Asistencias[aula][hora].asistencias = asistencias;
        Asistencias[aula][hora].dia = dia;
        Asistencias[aula][hora].hora = hora;
    }
    else
    {
        cout << "Aula, hora o dia no validos" << endl;
    }
}

void consultarAsistenciaEspecifica(RegistroAsistencia** Asistencias, int aulas, int horas)
{
    int aula;
    int hora;

    cout << "Ingrese el aula (0 - " << aulas - 1 << "): ";
    cin >> aula;

    cout << "Ingrese la hora (0 - " << horas - 1 << "): ";
    cin >> hora;

    if (aula >= 0 && aula < aulas && hora >= 0 && hora < horas)
    {
        cout << "El numero de asistencias en el aula " << aula << " a la hora " << hora << " es: " << Asistencias[aula][
            hora].asistencias << endl;
    }
    else
    {
        cout << "Aula o hora no validos" << endl;
    }
}

void calcularTotalAsistenciasManana(RegistroAsistencia** Asistencias, int aulas)
{
    int aula;
    int dia;

    cout << "Ingrese el aula (0 - " << aulas - 1 << "): ";
    cin >> aula;

    cout << "Ingrese el dia (1 - 31): ";
    cin >> dia;

    if (aula >= 0 && aula < aulas && dia >= 1 && dia <= 31)
    {
        int totalAsistenciasManana = 0;

        for (int i = 6; i < 12; ++i)
        {
            totalAsistenciasManana += Asistencias[aula][i].asistencias;
        }

        cout << "El total de asistencias en la mañana en el aula " << aula << " es: " << totalAsistenciasManana << endl;
    }
    else
    {
        cout << "Aula o dia no validos" << endl;
    }
}

void mostrarRegistrosAsistenciaOrdenDescendente(RegistroAsistencia** Asistencias, int aulas, int horas)
{
    int aula;

    cout << "Ingrese el aula (0 - " << aulas - 1 << "): ";
    cin >> aula;

    if (aula >= 0 && aula < aulas)
    {
        // Crear un arreglo de registros de asistencia
        RegistroAsistencia* registros = new RegistroAsistencia[horas];

        // Copiar los registros de asistencia del aula al arreglo
        for (int i = 0; i < horas; ++i)
        {
            registros[i] = Asistencias[aula][i];
        }

        // Ordenar los registros de asistencia en orden descendente
        for (int i = 0; i < horas - 1; ++i)
        {
            for (int j = i + 1; j < horas; ++j)
            {
                if (registros[i].asistencias < registros[j].asistencias)
                {
                    swap(registros[i], registros[j]);
                }
            }
        }

        // Mostrar los registros de asistencia en orden descendente
        for (int i = 0; i < horas; ++i)
        {
            cout << "Hora: " << registros[i].hora << " - Asistencias: " << registros[i].asistencias << endl;
        }

        // Liberar memoria
        delete[] registros;
    }
    else
    {
        cout << "Aula no valida" << endl;
    }
}

void problema1()
{
    int aulas = 5;
    int horas = 24;
    int opcion;

    RegistroAsistencia** Asistencias = new RegistroAsistencia*[aulas];

    for (int i = 0; i < aulas; ++i)
    {
        Asistencias[i] = new RegistroAsistencia[horas];
    }

    // Crear matriz de asistencias
    for (int i = 0; i < aulas; ++i)
    {
        for (int j = 0; j < horas; ++j)
        {
            Asistencias[i][j].asistencias = 0;
            Asistencias[i][j].dia = 0;
            Asistencias[i][j].hora = 0;
        }
    }

    // Menu de opciones
    do
    {
        mostrarMenuOpciones();
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarAsistencia(Asistencias, aulas, horas);
            break;
        case 2:
            consultarHoraMayorAsistencia(Asistencias, aulas, horas);
            break;
        case 3:
            consultarHoraMenorAsistencia(Asistencias, aulas, horas);
            break;
        case 4:
            modificarAsistencia(Asistencias, aulas, horas);
            break;
        case 5:
            consultarAsistenciaEspecifica(Asistencias, aulas, horas);
            break;
        case 6:
            calcularTotalAsistenciasManana(Asistencias, aulas);
            break;
        case 7:
            mostrarRegistrosAsistenciaOrdenDescendente(Asistencias, aulas, horas);
            break;
        case 8:
            cout << "Saliendo..." << endl;
            break;
        }
    }
    while (opcion != 8);

    // Liberar memoria
    for (int i = 0; i < aulas; ++i)
    {
        delete[] Asistencias[i];
    }
}
