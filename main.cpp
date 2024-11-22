#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void mostrarMenu() {
    cout << "Menu de Operaciones Basicas con Arreglos" << endl;
    cout << "1. Llenar arreglo con valores aleatorios" << endl;
    cout << "2. Mostrar arreglo" << endl;
    cout << "3. Buscar un valor en el arreglo" << endl;
    cout << "4. Ordenar el arreglo" << endl;
    cout << "5. Salir" << endl;
}

void llenarArreglo(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Valores aleatorios entre 0 y 99
    }
}

void mostrarArreglo(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int buscarValor(int arr[], int size, int valor) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1; // Valor no encontrado
}

void ordenarArreglo(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int opcion;
    const int size = 10;
    int arreglo[size];

    do {
        mostrarMenu();
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                llenarArreglo(arreglo, size);
                cout << "Arreglo llenado con valores aleatorios." << endl;
                break;
            case 2:
                mostrarArreglo(arreglo, size);
                break;
            case 3:
                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                int indice;
                indice = buscarValor(arreglo, size, valor);
                if (indice != -1) {
                    cout << "Valor encontrado en la posicion: " << indice << endl;
                } else {
                    cout << "Valor no encontrado." << endl;
                }
                break;
            case 4:
                ordenarArreglo(arreglo, size);
                cout << "Arreglo ordenado." << endl;
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}