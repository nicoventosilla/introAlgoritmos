//
// Created by c0d3r on 12/09/2024.
//

#include "problema5.h"
#include <iostream>
using namespace std;

int obtenerPrecio(long long codigoBarras)
{
    return codigoBarras % 100;
}

int calcularMontoAPagar(int precio, int cantidadComprada)
{
    return precio * cantidadComprada;
}

double calcularDescuento(int montoAPagar)
{
    if (montoAPagar > 1500)
    {
        return 0.2;
    }
    else if (montoAPagar > 1000 && montoAPagar <= 1500)
    {
        return 0.1;
    }
    else if (montoAPagar <= 1000)
    {
        return 0;
    }
}

void imprimirResultados(long long codigoBarras, int precio, int montoAPagar, int cantidadComprada, double descuento)
{
    cout << "Codigo de barras: " << codigoBarras << endl;
    cout << "Precio: " << precio << endl;
    cout << "Cantidad comprada: " << cantidadComprada << endl;
    cout << "El monto a pagar por " << cantidadComprada << " unidades es: " << montoAPagar << endl;
    cout << "Descuento obtenido: " << montoAPagar * descuento << "(" << descuento * 100 << "%)" << endl;
    cout << "Monto total a pagar: " << montoAPagar - (montoAPagar * descuento) << endl;
}

void problema5()
{
    long long codigo_barras;
    int cantidad_comprada;

    cout << "Ingrese el codigo de barras del producto: ";
    cin >> codigo_barras;

    cout << "Ingrese la cantidad que desea comprar: ";
    cin >> cantidad_comprada;

    int precio = obtenerPrecio(codigo_barras);

    int monto_a_pagar = calcularMontoAPagar(precio, cantidad_comprada);

    double descuento_obtenido = calcularDescuento(monto_a_pagar);

    imprimirResultados(codigo_barras, precio, monto_a_pagar, cantidad_comprada, descuento_obtenido);
}
