#include<iostream>
#include<conio.h>
#include "CMergeSort.h"

int main() {
    int num;
    int e[50];
    CMergeSort Ordenamiento;


    cout << "*************** PROGRAMA MERGE SORT  ****************" << endl;
    cout << endl << endl;

    // PETICIÓN DE MONEDAS
    cout << "Ingrese la cantidad de elementos que desea ordenar: " << endl;
    cin >> num;
    cout << endl;

    for (int i = 1; i <= num; i++) {
        cout << "Ingrese el elemento " << i << " : " << endl;
        cin >> e[i];
        Ordenamiento.a[i] = e[i];
    }

// SE INICIALIZAN VARIABLES IZQUIERDA Y DERECHA 
    Ordenamiento.izquierda = 1; // EMPIEZA POR EL UNO
    Ordenamiento.derecha = num; // TERMINA CON LA CANTIDAD DE MONEDAS

    Ordenamiento.merge_sort(Ordenamiento.izquierda, Ordenamiento.derecha); // SE ENVIÁN LAS VARIABLES MERGE SORT PARA ORDENARLAS
    cout << endl;
    cout << endl << endl;
    cout << "Los elementos ordenados son: " << endl;
    for (int i = 1; i <= Ordenamiento.derecha; i++) {
        cout << Ordenamiento.a[i] << "   "; // SE IMPRIMEN LAS VARIABLES EN ORDEBN
    }

    cout << endl;
    cout << endl << endl;
    cout << "Los elementos ordenados de manera inversa son: " << endl;
    for (int i = Ordenamiento.derecha; i >= 1; i--) {
        cout << Ordenamiento.a[i] << "   "; // SE IMPRIMEN LAS VARIABLES DE MANERA INVERSA
    }

    cout << endl << endl;

    return 0;
}