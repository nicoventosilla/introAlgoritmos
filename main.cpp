//
// Created by c0d3r on 12/10/2024.
//

#include <iostream>

using namespace std;

int main()
{
    const int tamanioInventario = 5;

    string nombres[tamanioInventario] = {"Laptop", "Mouse", "Teclado", "Monitor", "Impresora"};
    int cantidades[tamanioInventario] = {10, 20, 30, 40, 50};
    double precios[tamanioInventario] = {1000.0, 50.0, 100.0, 500.0, 200.0};

    cout << "Inventario Inicial" << endl;
    cout << "---------------------------------" << endl;
    cout << "Nombre\t\tCantidad\tPrecio" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < tamanioInventario; i++)
    {
        cout << nombres[i] << "\t\t" << cantidades[i] << "\t\t" << precios[i] << endl;
    }

    cantidades[1] -= 5;
    cantidades[3] -= 10;

    cout << "Inventario Final" << endl;
    cout << "---------------------------------" << endl;
    cout << "Nombre\t\tCantidad\tPrecio" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < tamanioInventario; i++)
    {
        cout << nombres[i] << "\t\t" << cantidades[i] << "\t\t" << precios[i] << endl;
    }
}
