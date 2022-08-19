#pragma once

using namespace std;

class CMergeSort
{
public:
	int a[20];
	int izquierda;
	int derecha;
	int medio;


	CMergeSort();
	CMergeSort(int left, int mid, int right, int A[20]);
	void merge_sort(int izquierda, int derecha);
	void merge(int izquierda, int medio, int derecha);


};







