
using namespace std;
#include <vector>
#include <limits.h>

using std::vector;

int INF = INT_MAX;

// Complejidad: O(n), donde n es el número de nodos (vértices).
// Devuelve el índice del nodo más cercano (menor distancia) si no ha sido visitado.

// Params : 
//       - El número total de nodos en el gráfico.
//       - Array (bool) de nodos visitados.
//       - Distancias desde el nodo fuente al resto.


int obtainNearestNode(int totalNodes, vector<bool> visitedNodes, vector<int> distances)
{
  int minDistance = INF;
  int nearestNode = 0;
  // Iteración de nodos 
  for (int i = 0; i < totalNodes; i++)  //Determina el más cercano
  {
    // Revisa el nodo no visitado
    if (visitedNodes[i] != true && (distances[i] <= minDistance) && distances[i] != -1)
    {
      minDistance = distances[i];
      nearestNode = i;
    }
  }
  return nearestNode;
}


// Complejidad: O(V^2), donde V es el número de vértices.
// Encuentra la ruta más corta desde un nodo de origen hasta el resto de nodos en un gráfico.
// Params: 
//     - Mtriz de adyacencias que representan un gráfico con dirección.
//     - Valor de índice del nodo de origen.

vector<int> dijkstraAlgorithm(vector<vector<int>> graph, int sourceNode){


  // Valor de la distancia desde el nodo de origen hasta cada nodo de índice.
  vector<int> distanceResults(graph[0].size(), INF); 

// Matriz para realizar un seguimiento de los nodos visitados.
  vector<bool> visitedNodes (graph[0].size(), false); 

  distanceResults[sourceNode] = 0; 
  for (int i = 0; i < graph[0].size(); i++)
  {
    int nearestNode = obtainNearestNode(graph[0].size(), visitedNodes, distanceResults);
    visitedNodes[nearestNode] = true; // Marcar el nodo como visitado

    // Visitar los nodos cercanos al obtenido 
    for (int j = 0; j < graph[0].size(); j++)
    {
      
      if ((graph[nearestNode][j] != -1 && distanceResults[nearestNode] != INF)&&distanceResults[j] > distanceResults[nearestNode] + graph[nearestNode][j])
      {
        distanceResults[j] = distanceResults[nearestNode] + graph[nearestNode][j]; 
      }
    }
  }
  
  for (int i = 0; i < distanceResults.size(); i++)
  {
    if (distanceResults[i] == INF)
    {
      distanceResults[i] = -1;
    }
  }
  return distanceResults;
}