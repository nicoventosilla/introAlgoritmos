```cpp
#include <iostream>

using namespace std;

// Muestra el menú de opciones
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

// Lista los elementos del arreglo
void listarElementos(int* arreglo, int n)
{
    cout << "Elementos del arreglo: ";
    for (int i = 0; i < n; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Agrega un valor al final del arreglo
// int*& arreglo: Referencia al arreglo para modificarlo
// int& n: Referencia a la cantidad de elementos del arreglo
// int valor: Valor a agregar al final del arreglo
void agregarValor(int*& arreglo, int& n, int valor)
{
    int* nuevoArreglo = new int[n + 1]; // Reservar memoria para el nuevo arreglo

    for (int i = 0; i < n; i++)
    {
        nuevoArreglo[i] = arreglo[i]; // Copiar elementos del arreglo original
    }

    nuevoArreglo[n] = valor; // Agregar el nuevo valor al final
    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al original
    n++; // Incrementar la cantidad de elementos
}

// Elimina un elemento en una posición específica del arreglo
// int*& arreglo: Referencia al arreglo para modificarlo
// int& n: Referencia a la cantidad de elementos del arreglo
// int posicion: Posición del elemento a eliminar
void eliminarPosicion(int*& arreglo, int& n, int posicion)
{
    int* nuevoArreglo = new int[n - 1]; // Reservar memoria para el nuevo arreglo

    for (int i = 0; i < posicion; i++)
    {
        nuevoArreglo[i] = arreglo[i]; // Copiar elementos antes de la posición a eliminar
    }

    for (int i = posicion + 1; i < n; i++)
    {
        nuevoArreglo[i - 1] = arreglo[i]; // Copiar elementos después de la posición a eliminar
    }

    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al original
    n--; // Decrementar la cantidad de elementos
}

// Agrega un valor al inicio del arreglo
// int*& arreglo: Referencia al arreglo para modificarlo
// int& n: Referencia a la cantidad de elementos del arreglo
// int valor: Valor a agregar al inicio del arreglo
void agregarValorInicio(int*& arreglo, int& n, int valor)
{
    int* nuevoArreglo = new int[n + 1]; // Reservar memoria para el nuevo arreglo

    nuevoArreglo[0] = valor; // Agregar el nuevo valor al inicio

    for (int i = 0; i < n; i++)
    {
        nuevoArreglo[i + 1] = arreglo[i]; // Copiar elementos del arreglo original
    }

    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al original
    n++; // Incrementar la cantidad de elementos
}

// Modifica el valor en una posición específica del arreglo
// int*& arreglo: Referencia al arreglo para modificarlo
// int posicion: Posición del elemento a modificar
// int valor: Nuevo valor a asignar
void modificarPosicion(int*& arreglo, int posicion, int valor)
{
    arreglo[posicion] = valor; // Modificar el valor en la posición indicada
}

// Inserta un valor en una posición específica del arreglo
// int*& arreglo: Referencia al arreglo para modificarlo
// int& n: Referencia a la cantidad de elementos del arreglo
// int posicion: Posición donde insertar el nuevo valor
// int valor: Valor a insertar
void insertarPosicion(int*& arreglo, int& n, int posicion, int valor)
{
    int* nuevoArreglo = new int[n + 1]; // Reservar memoria para el nuevo arreglo

    for (int i = 0; i < posicion; i++)
    {
        nuevoArreglo[i] = arreglo[i]; // Copiar elementos antes de la posición de inserción
    }

    nuevoArreglo[posicion] = valor; // Insertar el nuevo valor en la posición indicada

    for (int i = posicion; i < n; i++)
    {
        nuevoArreglo[i + 1] = arreglo[i]; // Copiar elementos después de la posición de inserción
    }

    arreglo = nuevoArreglo; // Asignar el nuevo arreglo al original
    n++; // Incrementar la cantidad de elementos
}

// Ordena el arreglo de mayor a menor
// int*& arreglo: Referencia al arreglo para modificarlo
// int n: Cantidad de elementos del arreglo
void ordenarDeMayorAMenor(int*& arreglo, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            if (arreglo[j] < arreglo[i])
            {
                int temp = arreglo[j];
                arreglo[j] = arreglo[i];
                arreglo[i] = temp;
            }
        }
    }
}

int main()
{
    int n; // Cantidad de elementos del arreglo
    int opcion; // Opción del menú

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

        cout << "Ingrese una opción: ";
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
            cout << "Ingrese la posición a eliminar: ";
            cin >> posicion; // Posición a eliminar
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
            cout << "Ingrese la posición a modificar: ";
            cin >> posicion_modificar; // Posición a modificar
            cout << "Ingrese el nuevo valor: ";
            cin >> valor_modificar; // Nuevo valor
            modificarPosicion(arreglo, posicion_modificar, valor_modificar);
            listarElementos(arreglo, n);
            break;
        case 6:
            int posicion_insertar;
            int valor_insertar;
            cout << "Ingrese la posición a insertar: ";
            cin >> posicion_insertar; // Posición a insertar
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
    while (opcion != 8); // Salir del menú
}
```