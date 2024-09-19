//
// Created by c0d3r on 03/09/2024.
//

#include "problema8.h"
#include <iostream>

void problema8()
{
    std::string codigo, anio, codigo_id, tipo_canal;

    std::cout << "Ingresa codigo de barras: ";
    std::cin >> codigo;

    anio = codigo.substr(0, 4);
    codigo_id = codigo.substr(4, 5);
    tipo_canal = codigo.substr(9, 1);

    tipo_canal = tipo_canal == "1" ? "Por E-Commerce" : tipo_canal == "0" ? "Otros canales" : "Opcion no valida";

    std::cout << "Anio: " << anio << std::endl;
    std::cout << "Codigo ID: " << codigo_id << std::endl;
    std::cout << "Tipo de canal: " << tipo_canal << std::endl;
}
