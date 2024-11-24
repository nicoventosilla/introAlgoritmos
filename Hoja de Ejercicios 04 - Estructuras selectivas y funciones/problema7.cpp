//
// Created by c0d3r on 18/09/2024.
//

#include "problema7.h"
#include <iostream>
#include <string>
using namespace std;

bool esCapicua(int n)
{
    string numString = to_string(n); // Convert int to string
    string reverseString = string(numString.rbegin(), numString.rend()); // Reverse string
    return numString == reverseString;
}

void problema7()
{
    int n;

    do
    {
        cout << "Ingrese numero de tres cifras: ";
        cin >> n;

        if (n < 100 || n > 999)
        {
            cout << "Numero incorrecto" << endl;
        }
    }
    while (n < 100 || n > 999);

    if (esCapicua(n))
    {
        cout << "El numero es capicua" << endl;
    }
    else
    {
        cout << "El numero no es capicua" << endl;
    }
}
