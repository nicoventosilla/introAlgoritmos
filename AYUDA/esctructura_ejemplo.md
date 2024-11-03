```cpp
#include <iostream>

using namespace std;

// Estructura para almacenar la fecha de nacimiento
struct FechaNacimiento
{
    int anio;
    int mes;
    int dia;
};

// Estructura para almacenar la información de una persona
struct Persona
{
    int edad;
    float altura;
    char genero;
    FechaNacimiento fechaNacimiento; // Composición: una persona tiene una fecha de nacimiento
};

int main()
{
    // Reservar memoria para un arreglo de 10 personas
    Persona* personas = new Persona[10];
    Persona persona1;

    // Inicializar los datos de persona1
    persona1.altura = 1.75;
    persona1.edad = 30;
    persona1.genero = 'M';
    persona1.fechaNacimiento.anio = 1989;
    persona1.fechaNacimiento.mes = 5;
    persona1.fechaNacimiento.dia = 16;

    // Copiar los datos de persona1 a cada elemento del arreglo personas
    for (int i = 0; i < 10; i++)
    {
        personas[i] = persona1;
    }

    // Otra forma de copiar los datos de persona1 a cada elemento del arreglo personas
    for (int i = 0; i < 10; i++)
    {
        personas[i].altura = persona1.altura;
        personas[i].edad = persona1.edad;
        personas[i].genero = persona1.genero;
        personas[i].fechaNacimiento = persona1.fechaNacimiento;
    }

    // Imprimir los datos de persona1
    cout << "Altura: " << persona1.altura << endl;
    cout << "Edad: " << persona1.edad << endl;
    cout << "Genero: " << persona1.genero << endl;
    cout << "Fecha de nacimiento: " << persona1.fechaNacimiento.dia << "/" << persona1.fechaNacimiento.mes << "/" << persona1.fechaNacimiento.anio << endl;

    // Liberar la memoria reservada para el arreglo de personas
    delete[] personas;

    return 0;
}
```
