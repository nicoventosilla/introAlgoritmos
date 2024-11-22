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

const int AULAS = 3;
const int HORAS_DIA = 23;

struct RegistroAsistencia
{
    int asistencias, dia, hora;
};

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

void consultarHoraConMayorAsistencia(RegistroAsistencia MatrizAsistencias[][HORAS_DIA])
{
    cout << "Consultando hora con mayor asistencia en un aula..." << endl;
    int aula;
    cout << "Ingrese aula a buscar: ";
    cin >> aula;
    int mayorAsistencias = MatrizAsistencias[aula][0].asistencias;
    int horaMayorAsistencias = 0;
    for (int i = 1; i < HORAS_DIA; i++)
    {
        if (MatrizAsistencias[aula][i].asistencias > mayorAsistencias)
        {
            mayorAsistencias = MatrizAsistencias[aula][i].asistencias;
            horaMayorAsistencias = i;
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
    int menorAsistencias = MatrizAsistencias[aula][0].asistencias;
    int horaMenorAsistencias = 0;
    for (int i = 1; i < HORAS_DIA; i++)
    {
        if (MatrizAsistencias[aula][i].asistencias < menorAsistencias)
        {
            menorAsistencias = MatrizAsistencias[aula][i].asistencias;
            horaMenorAsistencias = i;
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
    cout << "Ingrese hora del dia: ";
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
    for (int i = 6; i <= 11; i++)
    {
        totalAsistencias += MatrizAsistencias[aula][i].asistencias;
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
    for (int i = 0; i < HORAS_DIA - 1; i++)
    {
        for (int j = i + 1; j < HORAS_DIA; j++)
        {
            if (MatrizAsistencias[aula][i].asistencias < MatrizAsistencias[aula][j].asistencias)
            {
                swap(MatrizAsistencias[aula][i], MatrizAsistencias[aula][j]);
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
    registrarAsistencia(MatrizAsistencias); // Registrar asistencia
    mostrarRegistros(MatrizAsistencias); // Mostrar registros
    consultarHoraConMayorAsistencia(MatrizAsistencias);
    consultarHoraConMenorAsistencia(MatrizAsistencias);
    modificarAsistenciaEnUnaHoraParaUnAula(MatrizAsistencias);
    mostrarRegistros(MatrizAsistencias);
    consultarAsistenciaEnUnaHoraParaUnAula(MatrizAsistencias);
    calcularTotalDeAsistenciasParaUnAula(MatrizAsistencias);
    mostrarRegistrosDescendentesParaUnAula(MatrizAsistencias);
}
