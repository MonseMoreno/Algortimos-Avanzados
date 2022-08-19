#include "CMergeSort.h"


CMergeSort::CMergeSort() {

}

CMergeSort::CMergeSort(int left, int mid, int right, int A[50]) {
    a[20] = A[20];
    izquierda = left;
    derecha = right;
    medio = mid;

}


void CMergeSort::merge_sort(int izquierda, int derecha) {
    int medio;
    if (izquierda < derecha) {
        medio = (izquierda + derecha) / 2;
        merge_sort(izquierda, medio);
        merge_sort(medio + 1, derecha);
        merge(izquierda, medio, derecha);
    }
}
void CMergeSort::merge(int izquierda, int medio, int derecha) {
    int b[50], i;
    int k, h, j;
    h = izquierda;
    i = izquierda;
    j = medio + 1;


    while ((h <= medio) && (j <= derecha)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > medio) {
        for (k = j; k <= derecha; k++) {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= medio; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for (k = izquierda; k <= derecha; k++) {
        a[k] = b[k];
    }
}