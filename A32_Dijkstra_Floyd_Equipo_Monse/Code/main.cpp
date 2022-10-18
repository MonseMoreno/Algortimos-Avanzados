//Actividad 3.2 - Implementación de "Dijkstra and Floyd".
//Código trabajado por : Monserrat Kairme Moreno Casas

/*
 Para compilar:
  g++ -std=c++11 main.cpp -o app

  Para ejecutar:
  ./app < inputX.txt > mysolutionX.txt
*/



#include <iostream>
#include <vector>
using namespace std;

#include "dijkstra.h"
#include "floyd.h"



// LECTURA DEL ARCHIVO TXT
int main(int argc, char *argv[]) {
  int n = 0;

  // Para leer los valores txt
  cin >> n;
  //Matriz cuadrada inicial 
  //Matriz resultante
  vector<vector<int>> matrix(n, vector<int>(n));
  vector<vector<int>> dijkstraResultMatrix = matrix;
  vector<int> dijkstraResultArray = matrix[0];
  vector<vector<int>> floydResultMatrix = matrix;

  //Insertar valores en la matris
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  // ----------------------- Dijkstra ----------------------------
  /// Para cada nodo se calcula la ruta más corta
  for (int node = 0; node < matrix[0].size(); node++)
  {
    // Array para la ruta más corta 
    dijkstraResultArray = dijkstraAlgorithm(matrix, node);
    
    // Inserta el array en la matriz de resultados
    dijkstraResultMatrix[node] = dijkstraResultArray;
  }

  
  // --------------------------  Floyd ---------------------------
  // Mostrar los resultados
  floydResultMatrix = floydAllPairsAlgorithm(matrix);
  

  /// Dijkstra.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j)
      {
        cout << "node " << i+1 << " to node " << j+1 << " : " << dijkstraResultMatrix[i][j];
        cout << std::endl;
      }
    }
  }
  /// Floyd.
  for (int i = 0; i < n; i++) {
    cout << endl;
    for (int j = 0; j < n; j++) {
      cout << " " << floydResultMatrix[i][j];
    }
  }
  return 0;
}