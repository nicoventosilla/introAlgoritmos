//
// Created by c0d3r on 14/09/2024.
//

#include "problema1.h"
#include <iostream>
#include <string>
using namespace std;

void problema1()
{
    char tipo_usuario, tipo_acceso;
    int hora_acceso;
    int contador_manager = 0, contador_desarrollador = 0, contador_analista = 0;
    int contador_madrugada = 0, contador_manana = 0, contador_tarde = 0, contador_noche = 0;
    int contador_tipo_acceso_monitoreo = 0, contador_tipo_acceso_cambio_equipo = 0,
        contador_tipo_acceso_cambio_configuracion = 0;
    string momento_mayor_acceso, tipo_mayor_acceso;

    while (true)
    {
        // INGRESAR TIPO DE USUARIO
        do
        {
            cout << "Ingrese tipo de usuario (M: Manager; D: Desarrollador: A: Analista): ";
            cin >> tipo_usuario;
        }
        while (tipo_usuario != 'M' && tipo_usuario != 'm' && tipo_usuario != 'D' && tipo_usuario != 'd' && tipo_usuario
            != 'A' && tipo_usuario != 'a' && tipo_usuario != 'F' && tipo_usuario != 'f');

        // Si el tipo de usuario es F o f, se sale del bucle
        if (tipo_usuario == 'F' || tipo_usuario == 'f')
        {
            break;
        }

        // Contar el tipo de usuario
        if (tipo_usuario == 'M' || tipo_usuario == 'm')
        {
            contador_manager++;
        }
        else if (tipo_usuario == 'D' || tipo_usuario == 'd')
        {
            contador_desarrollador++;
        }
        else if (tipo_usuario == 'A' || tipo_usuario == 'a')
        {
            contador_analista++;
        }

        // INGRESAR HORA DE ACCESO
        do
        {
            cout << "Ingrese hora de acceso (Entero positivo entre 0 y 23): ";
            cin >> hora_acceso;
        }
        while (hora_acceso < 0 || hora_acceso > 23);

        // Contar la hora de acceso
        if (hora_acceso >= 0 && hora_acceso <= 5)
        {
            contador_madrugada++;
        }
        else if (hora_acceso >= 6 && hora_acceso <= 12)
        {
            contador_manana++;
        }
        else if (hora_acceso >= 13 && hora_acceso <= 17)
        {
            contador_tarde++;
        }
        else if (hora_acceso >= 18 && hora_acceso <= 23)
        {
            contador_noche++;
        }

        // INGRESAR TIPO DE ACCESO
        do
        {
            cout << "Ingrese tipo de Acceso (M: Monitoreo; E: Cambio de Equipo; C: Cambio de Configuracion): ";
            cin >> tipo_acceso;
        }
        while (tipo_acceso != 'M' && tipo_acceso != 'm' && tipo_acceso != 'E' && tipo_acceso != 'e' && tipo_acceso
            != 'C' && tipo_acceso != 'c');

        // Contar el tipo de acceso
        if (tipo_acceso == 'M' || tipo_acceso == 'm')
        {
            contador_tipo_acceso_monitoreo++;
        }
        else if (tipo_acceso == 'E' || tipo_acceso == 'e')
        {
            contador_tipo_acceso_cambio_equipo++;
        }
        else if (tipo_acceso == 'C' || tipo_acceso == 'c')
        {
            contador_tipo_acceso_cambio_configuracion++;
        }
    }

    // Determinar el momento de mayor acceso
    if (contador_madrugada > contador_manana && contador_madrugada > contador_tarde && contador_madrugada >
        contador_noche)
    {
        momento_mayor_acceso = "Madrugada";
    }
    else if (contador_manana > contador_madrugada && contador_manana > contador_tarde && contador_manana >
        contador_noche)
    {
        momento_mayor_acceso = "Mañana";
    }
    else if (contador_tarde > contador_madrugada && contador_tarde > contador_manana && contador_tarde > contador_noche)
    {
        momento_mayor_acceso = "Tarde";
    }
    else if (contador_noche > contador_madrugada && contador_noche > contador_manana && contador_noche > contador_tarde)
    {
        momento_mayor_acceso = "Noche";
    }

    // Determinar el tipo de acceso con mayor frecuencia
    if (contador_tipo_acceso_monitoreo > contador_tipo_acceso_cambio_equipo && contador_tipo_acceso_monitoreo >
        contador_tipo_acceso_cambio_configuracion)
    {
        tipo_mayor_acceso = "Monitoreo";
    }
    else if (contador_tipo_acceso_cambio_equipo > contador_tipo_acceso_monitoreo && contador_tipo_acceso_cambio_equipo >
        contador_tipo_acceso_cambio_configuracion)
    {
        tipo_mayor_acceso = "Cambio de Equipo";
    }
    else if (contador_tipo_acceso_cambio_configuracion > contador_tipo_acceso_monitoreo &&
        contador_tipo_acceso_cambio_configuracion >
        contador_tipo_acceso_cambio_equipo)
    {
        tipo_mayor_acceso = "Cambio de Configuracion";
    }

    cout << endl;
    cout << "RESULTADOS" << endl;
    cout << "--------------------------------" << endl;
    cout << "Manager: " << contador_manager << endl;
    cout << "Desarrollador: " << contador_desarrollador << endl;
    cout << "Analista: " << contador_analista << endl;
    cout << endl;
    cout << "En la " << momento_mayor_acceso << " se registraron mas accesos." << endl;
    cout << endl;
    cout << "Predominan los accesos de tipo: " << tipo_mayor_acceso << "." << endl;
}
