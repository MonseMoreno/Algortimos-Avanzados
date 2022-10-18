#include <vector>

using std::vector;

// Complejidad: O(n^3), donde n es el número de vértices.
// Encuentra la distancia más corta entre cada par de vértices
// Params 
//   - Valor de índice del nodo de origen.

vector<vector<int>> floydAllPairsAlgorithm(vector<vector<int>> graph) {
  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph.size(); j++) {
      for (int k = 0; k < graph.size(); k++) {
      
        if ((graph[j][k] > (graph[j][i] + graph[i][k]) || graph[j][k] == -1) &&
            graph[j][i] != -1 && graph[i][k] != -1) {
          graph[j][k] = graph[j][i] + graph[i][k];
        }
      }
    }
  }

  return graph;
}