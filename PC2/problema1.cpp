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

// Constantes
const int AULAS = 3;
const int HORAS_DIA = 23;

// Estructura para almacenar los datos de un registro de asistencia
struct RegistroAsistencia
{
    int asistencias, dia, hora;
};

// Inicializar la matriz de asistencias con valores predeterminados (0)
void inicializarMatriz(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Inicializando matriz..." << endl;

    for (int i = 0; i < AULAS; i++)
    {
        for (int j = 0; j < HORAS_DIA; j++)
        {
            MatrizAsistencias[i][j].asistencias = 0;
            MatrizAsistencias[i][j].dia = 0;
            MatrizAsistencias[i][j].hora = 0;
        }
    }
    cout << endl;
}

// Mostrar los registros de asistencia en la matriz
void mostrarRegistros(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    for (int i = 0; i < AULAS; i++)
    {
        for (int j = 0; j < HORAS_DIA; j++)
        {
            cout << "A: " << MatrizAsistencias[i][j].asistencias;
            cout << " D: " << MatrizAsistencias[i][j].dia;
            cout << " H: " << MatrizAsistencias[i][j].hora;
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Realizar el seguimiento de la asistencia de estudiantes en varias aulas durante un día
void registrarAsistencia(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Registrando asistencia..." << endl;

    int aula, asistencias, dia, hora;
    cout << "Ingrese aula: ";
    cin >> aula;
    cout << "Ingrese estudiantes que asistieron: ";
    cin >> asistencias;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese hora del dia: ";
    cin >> hora;

    MatrizAsistencias[aula][hora].asistencias = asistencias;
    MatrizAsistencias[aula][hora].dia = dia;
    MatrizAsistencias[aula][hora].hora = hora;

    cout << "Asistencia registrada correctamente" << endl;
}

// Consultar la hora con mayor asistencia en un aula específica
void consultarHoraConMayorAsistencia(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Consultando hora con mayor asistencia en un aula..." << endl;

    int aula;
    cout << "Ingrese aula a buscar: ";
    cin >> aula;

    int mayorAsistencias = MatrizAsistencias[aula][0].asistencias; // Inicializar con las asistencias de la hora 0
    int horaMayorAsistencias = 0; // Inicializar con la hora 0

    for (int i = 1; i < HORAS_DIA; i++) // Recorrer las horas del día (de 1 a 23)
    {
        if (MatrizAsistencias[aula][i].asistencias > mayorAsistencias)
        // Si las asistencias son mayores que las actuales
        {
            mayorAsistencias = MatrizAsistencias[aula][i].asistencias; // Actualizar las asistencias
            horaMayorAsistencias = i; // Actualizar la hora
        }
    }

    cout << "El mayor numero de asistencias para el aula " << aula << " es: " << mayorAsistencias << " a las " <<
        horaMayorAsistencias << " horas" << endl;
}

void consultarHoraConMenorAsistencia(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Consultando hora con menor asistencia en un aula..." << endl;

    int aula;
    cout << "Ingrese aula a buscar: ";
    cin >> aula;

    int menorAsistencias = MatrizAsistencias[aula][0].asistencias; // Inicializar con las asistencias de la hora 0
    int horaMenorAsistencias = 0; // Inicializar con la hora 0

    for (int i = 1; i < HORAS_DIA; i++) // Recorrer las horas del día (de 1 a 23)
    {
        if (MatrizAsistencias[aula][i].asistencias < menorAsistencias)
        // Si las asistencias son menores que las actuales
        {
            menorAsistencias = MatrizAsistencias[aula][i].asistencias; // Actualizar las asistencias
            horaMenorAsistencias = i; // Actualizar la hora
        }
    }

    cout << "El menor numero de asistencias para el aula " << aula << " es: " << menorAsistencias << " a las " <<
        horaMenorAsistencias << " horas" << endl;
}

void modificarAsistenciaEnUnaHoraParaUnAula(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Modificando asistencia en una hora para un aula..." << endl;

    int aula, asistencias, dia, hora;
    cout << "Ingrese aula: ";
    cin >> aula;
    cout << "Ingrese hora: ";
    cin >> hora;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese estudiantes que asistieron: ";
    cin >> asistencias;

    MatrizAsistencias[aula][hora].asistencias = asistencias;
    MatrizAsistencias[aula][hora].dia = dia;
    MatrizAsistencias[aula][hora].hora = hora;
    cout << "Asistencia modificada correctamente" << endl;
}

void consultarAsistenciaEnUnaHoraParaUnAula(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Consultando asistencia..." << endl;

    int aula, hora;
    cout << "Ingrese aula: ";
    cin >> aula;
    cout << "Ingrese hora del dia: ";
    cin >> hora;

    cout << "Asistencias en el aula " << aula << " a las " << hora << " horas: " << MatrizAsistencias[aula][hora].
        asistencias << endl;
}

void calcularTotalDeAsistenciasParaUnAula(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Calculando total de asistencias en la manana..." << endl;

    int aula;
    cout << "Ingrese aula: ";
    cin >> aula;

    int totalAsistencias = 0;

    for (int i = 6; i <= 11; i++) // Recorrer las horas de la mañana (de 6 a 11 horas)
    {
        totalAsistencias += MatrizAsistencias[aula][i].asistencias; // Sumar las asistencias de cada hora de la mañana
    }

    cout << "Total de asistencias en la manana para el aula " << aula << ": " <<
        totalAsistencias << endl;
}

void mostrarRegistrosDescendentesParaUnAula(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Mostrando registros de asistencia en orden ascendente..." << endl;

    int aula;
    cout << "Ingrese aula: ";
    cin >> aula;

    // Ordenar los registros de asistencia en orden descendente por el número de asistencias
    for (int i = 0; i < HORAS_DIA - 1; i++)
    {
        for (int j = i + 1; j < HORAS_DIA; j++)
        {
            // Si el registro actual tiene menos asistencias que el siguiente, intercambiarlos
            if (MatrizAsistencias[aula][i].asistencias < MatrizAsistencias[aula][j].asistencias)
            {
                swap(MatrizAsistencias[aula][i], MatrizAsistencias[aula][j]); // Intercambiar los registros
            }
        }
    }

    mostrarRegistros(MatrizAsistencias);
}

void problema1()
{
    RegistroAsistencia MatrizAsistencias[AULAS][HORAS_DIA];

    inicializarMatriz(MatrizAsistencias); // Inicializar matriz
    mostrarRegistros(MatrizAsistencias); // Mostrar registros
    registrarAsistencia(MatrizAsistencias); // Registrar asistencia
    registrarAsistencia(MatrizAsistencias); // Registrar asistencia nuevamente
    mostrarRegistros(MatrizAsistencias); // Mostrar registros
    consultarHoraConMayorAsistencia(MatrizAsistencias); // Consultar hora con mayor asistencia
    consultarHoraConMenorAsistencia(MatrizAsistencias); // Consultar hora con menor asistencia
    modificarAsistenciaEnUnaHoraParaUnAula(MatrizAsistencias); // Modificar asistencia
    mostrarRegistros(MatrizAsistencias); // Mostrar registros
    consultarAsistenciaEnUnaHoraParaUnAula(MatrizAsistencias); // Consultar asistencia
    calcularTotalDeAsistenciasParaUnAula(MatrizAsistencias); // Calcular total de asistencias en la mañana
    mostrarRegistrosDescendentesParaUnAula(MatrizAsistencias); // Mostrar registros en orden descendente
}
