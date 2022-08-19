#pragma once
class CAlgoritmos
{
public:
	int monedas[50];
	int monto;
	int Array_Size;

	CAlgoritmos();
	CAlgoritmos(int _monedas[], int _monto, int _Array_Size);
	void AlgoritmoDinamico();
	void AlgoritmoAvaro();
};

