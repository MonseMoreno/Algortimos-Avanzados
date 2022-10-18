//Codigo trabajado por: Monserrat Karime Moreno Casas 
#include <iostream>
#include <vector>
#include <algorithm>
#include "CAlgoritmos.h"

using namespace std;

int main() {


    cout << "************************************************************" << endl;
    cout << "*********************  Actividad 1.3  **********************" << endl;
    cout << "************************************************************" << endl;

    cout << "\nEscribe el número de monedas a ingresar: ";
    int n;
    cin >> n;
    int monedas[n];


    cout << "\n***** Escriba el valor de las monedas *****\n" << endl;

    for (int i = 0; i < n; i++) {

        cout << "Moneda " << i + 1 << ": $";

        int temp;
        cin >> temp;
        monedas[i] = temp;

    }

    int p, q, algorithm;

    cout << "\nEscribe el precio del producto: $";
    cin >> p; // Precio
    cout << "Escribe la cantidad con la que se pagará el producto: $";
    cin >> q; // Cantidad pagada

    cout << "\n************** Menú de Algoritmos ****************" << endl;
    cout << "1. Algoritmo de programación avara" << endl;
    cout << "2. Algoritmo de programación dinámica" << endl;
    cout << "**************************************************" << endl;

    CAlgoritmos Objeto(monedas, q - p, n);

    do {

        cout << "\nElige el algoritmo de la solución (escribe 1 o 2): ";
        cin >> algorithm;

        if (algorithm == 1) {

            cout << "\nCambio: $" << q - p;
            Objeto.AlgoritmoAvaro();

        }
        else
            if (algorithm == 2) {

                cout << "\nCambio: $" << q - p;
                Objeto.AlgoritmoDinamico();

            }

    } while (algorithm != 1 && algorithm != 2);

    return 0;

}