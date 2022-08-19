#include<iostream>
#include<conio.h>
#include "CMergeSort.h"

int main() {
    int num;
    int e[50];
    CMergeSort Ordenamiento;


    cout << "*************** PROGRAMA MERGE SORT  ****************" << endl;
    cout << endl << endl;
    cout << "Ingrese la cantidad de elementos que desea ordenar: " << endl;
    cin >> num;
    cout << endl;

    for (int i = 1; i <= num; i++) {
        cout << "Ingrese el elemento " << i << " : " << endl;
        cin >> e[i];
        Ordenamiento.a[i] = e[i];
    }


    Ordenamiento.izquierda = 1;
    Ordenamiento.derecha = num;

    Ordenamiento.merge_sort(Ordenamiento.izquierda, Ordenamiento.derecha);
    cout << endl;
    cout << endl << endl;
    cout << "Los elementos ordenados son: " << endl;
    for (int i = 1; i <= Ordenamiento.derecha; i++) {
        cout << Ordenamiento.a[i] << "   ";
    }

    cout << endl;
    cout << endl << endl;
    cout << "Los elementos ordenados de manera inversa son: " << endl;
    for (int i = Ordenamiento.derecha; i >= 1; i--) {
        cout << Ordenamiento.a[i] << "   ";
    }

    cout << endl << endl;

    return 0;
}