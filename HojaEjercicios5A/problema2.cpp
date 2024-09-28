#include "problema2.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;



void problema2()
{
    int n, x, y;

    do
    {
        cout << "Ingrese el valor de n: ";
        cin >> n;
    }
    while (n <= 1 || n > 10);

    do
    {
        cout << "Ingrese el valor de x: ";
        cin >> x;
    }
    while (x < 2 || x > 5);

    do
    {
        cout << "Ingrese el valor de y: ";
        cin >> y;
    }
    while (y < 1 || y > 9);

    //Todo: Por hacer 5A2
}
