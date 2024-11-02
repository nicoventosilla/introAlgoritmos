```cpp
#include <iostream>

using namespace std;

void menu()
{
    cout << endl;
    cout << "MENU\n";
    cout << "-------------\n";
    cout << "1. LISTAR ELEMENTOS\n";
    cout << "2. AGREGAR AL FINAL\n";
    cout << "3. ELIMINAR EN POSICION\n";
    cout << "4. AGREGAR AL INICIO\n";
    cout << "5. MODIFICAR EN POSICION\n";
    cout << "6. INSERTAR EN POSICION\n";
    cout << "7. ORDENAR DE MAYOR A MENOR\n";
    cout << "8. SALIR\n";
}

void listarElementos(int* arreglo, int n) // Listar elementos del arreglo
{
    cout << "Elementos del arreglo: ";
    for (int i = 0; i < n; i++) // Recorrer el arreglo
    {
        cout << arreglo[i] << " "; // Mostrar el elemento
    }
    cout << endl;
}

// int*& arreglo: Para poder modificar el arreglo original
// int& n: Para poder modificar la cantidad de elementos del arreglo
// int valor: Valor a agregar al final del arreglo

void agregarValor(int*& arreglo, int& n, int valor) // Agregar un valor al final del arreglo
{
    int* nuevoArreglo = new int[n + 1]; // Reservar memoria para el nuevo arreglo

    for (int i = 0; i < n; i++)
    {
        nuevoArreglo[i] = arreglo[i];
    }

    nuevoArreglo[n] = valor; // Agregar el valor al final del nuevo arreglo
    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al arreglo original
    n++; // Incrementar la cantidad de elementos del nuevo arreglo
}

void eliminarPosicion(int*& arreglo, int& n, int posicion) // Eliminar un elemento en una posicion
{
    int* nuevoArreglo = new int[n - 1]; // Reservar memoria para el nuevo arreglo

    for (int i = 0; i < posicion; i++)
    {
        nuevoArreglo[i] = arreglo[i]; // Copiar los elementos antes de la posicion a eliminar
    }

    for (int i = posicion + 1; i < n; i++)
    {
        nuevoArreglo[i - 1] = arreglo[i]; // Copiar los elementos despues de la posicion a eliminar
    }

    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al arreglo original
    n--; // Decrementar la cantidad de elementos del nuevo arreglo
}

void agregarValorInicio(int*& arreglo, int& n, int valor) // Agregar un valor al inicio del arreglo
{
    int* nuevoArreglo = new int[n + 1]; // Reservar memoria para el nuevo arreglo

    nuevoArreglo[0] = valor; // Agregar el valor al inicio del nuevo arreglo

    for (int i = 0; i < n; i++)
    {
        nuevoArreglo[i + 1] = arreglo[i]; // Copiar los elementos del arreglo original
    }

    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al arreglo original
    n++; // Incrementar la cantidad de elementos del nuevo arreglo
}

void modificarPosicion(int*& arreglo, int& n, int posicion, int valor)
{
    arreglo[posicion] = valor; // Modificar el valor en la posicion indicada
}

void insertarPosicion(int*& arreglo, int& n, int posicion, int valor)
{
    int* nuevoArreglo = new int[n + 1]; // Reservar memoria para el nuevo arreglo

    for (int i = 0; i < posicion; i++)
    {
        nuevoArreglo[i] = arreglo[i]; // Copiar los elementos antes de la posicion a insertar
    }

    nuevoArreglo[posicion] = valor; // Agregar el valor en la posicion indicada

    for (int i = posicion; i < n; i++)
    {
        nuevoArreglo[i + 1] = arreglo[i]; // Copiar los elementos despues de la posicion a insertar
    }

    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al arreglo original
    n++; // Incrementar la cantidad de elementos del nuevo arreglo
}

void ordenarDeMayorAMenor(int*& arreglo, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arreglo[i] < arreglo[j])
            {
                int aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}

int main()
{
    int n; // Cantidad de elementos del arreglo
    int opcion; // Opcion del menu

    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> n;

    int* arreglo = new int[n]; // Reservar memoria para el arreglo

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    do
    {
        menu();

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            listarElementos(arreglo, n);
            break;
        case 2:
            int nuevo_valor;
            cout << "Ingrese el valor a agregar: ";
            cin >> nuevo_valor; // Nuevo valor a agregar
            agregarValor(arreglo, n, nuevo_valor);
            listarElementos(arreglo, n);
            break;
        case 3:
            int posicion;
            cout << "Ingrese la posicion a eliminar: ";
            cin >> posicion; // Posicion a eliminar
            eliminarPosicion(arreglo, n, posicion);
            listarElementos(arreglo, n);
            break;
        case 4:
            int nuevo_valor_inicio;
            cout << "Ingrese el valor a agregar al inicio: ";
            cin >> nuevo_valor_inicio; // Nuevo valor a agregar al inicio
            agregarValorInicio(arreglo, n, nuevo_valor_inicio);
            listarElementos(arreglo, n);
            break;
        case 5:
            int posicion_modificar;
            int valor_modificar;
            cout << "Ingrese la posicion a modificar: ";
            cin >> posicion_modificar; // Posicion a modificar
            cout << "Ingrese el nuevo valor: ";
            cin >> valor_modificar; // Nuevo valor
            modificarPosicion(arreglo, n, posicion_modificar, valor_modificar);
            listarElementos(arreglo, n);
            break;
        case 6:
            int posicion_insertar;
            int valor_insertar;
            cout << "Ingrese la posicion a insertar: ";
            cin >> posicion_insertar; // Posicion a insertar
            cout << "Ingrese el valor a insertar: ";
            cin >> valor_insertar; // Valor a insertar
            insertarPosicion(arreglo, n, posicion_insertar, valor_insertar);
            listarElementos(arreglo, n);
            break;
        case 7:
            ordenarDeMayorAMenor(arreglo, n);
            listarElementos(arreglo, n);
            break;
        default:
            break;
        }
    }
    while (opcion != 8); // Salir del menu
}
```