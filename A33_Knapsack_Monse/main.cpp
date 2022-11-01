/*
Código trabajado por: Monserrat Karime Moreno Casas A01276775
Actividad 3.3 Implementación de "Knapsack problem"

Ejecución de código:
  Consola de replit 
      1.  g++ -std=c++17 -g -o main *.cpp
      2. ./main < pruebaN.txt
*/

#include <iostream>

#include "knapsack_Algorithm.h"
using namespace std; 
int main(int argc, char *argv[])
{
    int N = 0, W = 0, value = 0;
    // Vectores de inicio.
    vector<int> elementValues;
    vector<int> elementWeights;
    // Lee los valores txt
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> W;
        elementValues.push_back(W);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> W;
        elementWeights.push_back(W);
    }
    cin >> W;

    // Imprime resultados
    value = KnapsackAlgorith(elementValues, elementWeights, W);
    cout << "Beneficio óptimo: " <<  value  << endl ;

    return 0;
}