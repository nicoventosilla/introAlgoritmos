//
// Created by c0d3r on 28/09/2024.
//

#include "hojaejercicios7a.h"
#include "encuesta1.h"
// #include "encuesta2.h"
// #include "encuesta3.h"
// #include "encuesta4.h"
// #include "encuesta5.h"
// #include "encuesta6.h"
#include "figuras1.h"
#include "figuras2.h"
#include "figuras3.h"
// #include "figuras4.h"
// #include "figuras5.h"
// #include "figuras6.h"
// #include "figuras7.h"
// #include "figuras8.h"
// #include "figuras9.h"
// #include "figuras10.h"
// #include "series1.h"
// #include "series2.h"
// #include "series3.h"
// #include "series4.h"
// #include "series5.h"
#include "animaciones1.h"
// #include "animaciones2.h"
// #include "animaciones3.h"
// #include "animaciones4.h"
// #include "animaciones5.h"
// #include "animaciones6.h"
// #include "animaciones7.h"
// #include "animaciones8.h"
// #include "animaciones9.h"
// #include "animaciones10.h"
// #include "animaciones11.h"
#include <iostream>
using namespace std;

void mostrarMenu()
{
    cout << "1. encuesta1" << endl;
    // cout << "2. encuesta2" << endl;
    // cout << "3. encuesta3" << endl;
    // cout << "4. encuesta4" << endl;
    // cout << "5. encuesta5" << endl;
    // cout << "6. encuesta6" << endl;
    cout << "7. figuras1" << endl;
    cout << "8. figuras2" << endl;
    cout << "9. figuras3" << endl;
    // cout << "10. figuras4" << endl;
    // cout << "11. figuras5" << endl;
    // cout << "12. figuras6" << endl;
    // cout << "13. figuras7" << endl;
    // cout << "14. figuras8" << endl;
    // cout << "15. figuras9" << endl;
    // cout << "16. figuras10" << endl;
    // cout << "17. series1" << endl;
    // cout << "18. series2" << endl;
    // cout << "19. series3" << endl;
    // cout << "20. series4" << endl;
    // cout << "21. series5" << endl;
    // cout << "22. animaciones1" << endl;
    // cout << "23. animaciones2" << endl;
    // cout << "24. animaciones3" << endl;
    // cout << "25. animaciones4" << endl;
    // cout << "26. animaciones5" << endl;
    // cout << "27. animaciones6" << endl;
    // cout << "28. animaciones7" << endl;
    // cout << "29. animaciones8" << endl;
    // cout << "30. animaciones9" << endl;
    // cout << "31. animaciones10" << endl;
    // cout << "32. animaciones11" << endl;
    cout << "0. Salir" << endl;
}

int main()
{
    int opcion;

    mostrarMenu();

    cout << "Ingrese su opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        encuesta1();
        break;
    // case 2:
    //     encuesta2();
    //     break;
    // case 3:
    //     encuesta3();
    //     break;
    // case 4:
    //     encuesta4();
    //     break;
    // case 5:
    //     encuesta5();
    //     break;
    // case 6:
    //     encuesta6();
    //     break;
    case 7:
        figuras1();
        break;
    case 8:
        figuras2();
        break;
    case 9:
        figuras3();
        break;
    // case 10:
    //     figuras4();
    //     break;
    // case 11:
    //     figuras5();
    //     break;
    // case 12:
    //     figuras6();
    //     break;
    // case 13:
    //     figuras7();
    //     break;
    // case 14:
    //     figuras8();
    //     break;
    // case 15:
    //     figuras9();
    //     break;
    // case 16:
    //     figuras10();
    //     break;
    // case 17:
    //     series1();
    //     break;
    // case 18:
    //     series2();
    //     break;
    // case 19:
    //     series3();
    //     break;
    // case 20:
    //     series4();
    //     break;
    // case 21:
    //     series5();
    //     break;
    // case 22:
    //     animaciones1();
    //     break;
    // case 23:
    // animaciones2();
    // break;
    // case 24:
    // animaciones3();
    // break;
    // case 25:
    // animaciones4();
    // break;
    // case 26:
    // animaciones5();
    // break;
    // case 27:
    // animaciones6();
    // break;
    // case 28:
    // animaciones7();
    // break;
    // case 29:
    // animaciones8();
    // break;
    // case 30:
    // animaciones9();
    // break;
    // case 31:
    // animaciones10();
    // break;
    // case 32:
    // animaciones11();
    // break;
    case 0:
        cout << "Saliendo del programa..." << endl;
        break;
    default:
        cout << "Opcion no valida!" << endl;
        break;
    }
}
