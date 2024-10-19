//
// Created by c0d3r on 12/10/2024.
//

#include <iostream>
using namespace std;

void stackExample() {
    int a = 10; // Variable en el stack
    int b = 20; // Variable en el stack

    cout << "Stack Example:" << endl;
    cout << "a: " << a << " y su direccion de memoria es: " << &a << endl;
    cout << "b: " << b << " y su direccion de memoria es: " << &b << endl;

    int *ptrA = &a; // Puntero a una variable en el stack
    int *ptrB = &b; // Puntero a una variable en el stack

    *ptrA = 30; // Modificando el valor de 'a' a través del puntero
    *ptrB = 40; // Modificando el valor de 'b' a través del puntero

    cout << "ptrA: " << *ptrA << " y su direccion de memoria es: " << ptrA << endl;
    cout << "ptrB: " << *ptrB << " y su direccion de memoria es: " << ptrB << endl;
}

void heapExample() {
    int *ptrA = new int; // Asignando memoria en el heap
    int *ptrB = new int; // Asignando memoria en el heap

    *ptrA = 50; // Asignando valor a la memoria en el heap
    *ptrB = 60; // Asignando valor a la memoria en el heap

    cout << "Heap Example:" << endl;
    cout << "ptrA: " << *ptrA << " y su direccion de memoria es: " << ptrA << endl;
    cout << "ptrB: " << *ptrB << " y su direccion de memoria es: " << ptrB << endl;

    delete ptrA; // Liberando memoria en el heap
    delete ptrB; // Liberando memoria en el heap
}

int main() {
    stackExample();
    heapExample();
    return 0;
}