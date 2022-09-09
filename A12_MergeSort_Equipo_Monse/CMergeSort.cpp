#include "CMergeSort.h"


CMergeSort::CMergeSort() {

}

//CONTROLADOR DE LA FUNCIÓN
CMergeSort::CMergeSort(int left, int mid, int right, int A[50]) {
    a[20] = A[20];
    izquierda = left;
    derecha = right;
    medio = mid;

}

//ORDENAMIENTO DE VARIABLES

void CMergeSort::merge_sort(int izquierda, int derecha) {
    int medio;
    if (izquierda < derecha) {
        medio = (izquierda + derecha) / 2; // SE BUSCA EL MEDIO DEL ARREGLO
        merge_sort(izquierda, medio);
        merge_sort(medio + 1, derecha);
        merge(izquierda, medio, derecha);
    }
    
}


void CMergeSort::merge(int izquierda, int medio, int derecha) {

    // DECLARACIÓN DE VARIABLES 
    int b[50], i;
    int k, h, j;
    h = izquierda;
    i = izquierda;
    j = medio + 1;


// VERIDFICA QUE IZQUIERDA Y DERECHA SEAN MENORES AL MEDIO
    while ((h <= medio) && (j <= derecha)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++; // SUMA A IZQUIERDA
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++; //SUMA A DERECHA
    }
    if (h > medio) {
        for (k = j; k <= derecha; k++) {
            b[i] = a[k];
            i++;// SUMA A IZQUIERDA
        } 
    }
    else
    {
        for (k = h; k <= medio; k++) {
            b[i] = a[k];
            i++;// SUMA A IZQUIERDA
        }
    }
    for (k = izquierda; k <= derecha; k++) {
        a[k] = b[k];
    }
}