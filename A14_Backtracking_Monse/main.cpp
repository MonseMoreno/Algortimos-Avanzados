// Código trabajado por: Monserrat Karime Moreno Casas

#include <iostream>
#include <vector>
using namespace std;

// En el peor caso puede ser O(n*m) ya que podria llegar a checar todas las
// casillas

// Función para comprobar si los caminos encontrados son válidos
bool Validate(vector<vector<int>> mapa, int i, int j, int n) {
  if ((i >= 0 && i < n) && (j >= 0 && j < n) && (mapa[i][j] == 1))
    return true;
  return false;
}

// Función para encontrar las posibles soluciones del laberinto
bool findPath(vector<vector<int>> mapa, vector<vector<int>> solucion, int i,
              int j, int n) {
  if (i == n - 1 && j == n - 1 && mapa[i][j] == 1) { // caso base
    solucion[i][j] = 1; // Si entra aquí es porque encontró la salida
    cout << "\nBacktracking\n" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << "  " << solucion[i][j] << "  ";
      }
      cout << endl;
    }
    return true;
  }

  if (Validate(mapa, i, j, n)) {
    // Analiza el bloque de la solución de no ser así lo agrega como solución
    if (solucion[i][j] == 1)
      return false;
    solucion[i][j] = 1;

    // ------------------------------- Movimientos
    // ----------------------------------------------

    if (findPath(mapa, solucion, i, j + 1, n) == true) // derecha
      return true;

    if (findPath(mapa, solucion, i + 1, j, n) == true) { // abajo
      return true;
    }
    if (findPath(mapa, solucion, i, j - 1, n) == true) { // izquierda
      return true;
    }
    if (findPath(mapa, solucion, i - 1, j, n) == true) { // arriba
      return true;
    }

    // No solución
    solucion[i][j] = 0;
    return false;
  }
  return false;
}

//----------------------------------------------------------------------------------------------------------------------

// Comprobación de caminos válidos
bool Validate(vector<vector<int>> mapa, int i, int j, int n, int pasosI,
              int Max_pasos) {

  if ((i >= 0 && i < n) && (j >= 0 && j < n) && (mapa[i][j] == 1) &&
      (pasosI < Max_pasos)) {
    return true;
  }
  return false;
}

// Encontrar las soluciones
bool RamiPoda(vector<vector<int>> mapa, vector<vector<int>> solucion, int i,
              int j, int n, int pasosI, int Max_pasos) {
  if (i == n - 1 && j == n - 1 && mapa[i][j] == 1 &&
      pasosI <= Max_pasos) { // caso base
    solucion[i][j] = 1;
    pasosI++;
    cout << "Ramificación y Poda" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << " [ " << solucion[i][j] << " ] ";
      }
      cout << endl;
    }
    return true;
  }

  if (Validate(mapa, i, j, n, pasosI, Max_pasos)) {
    pasosI++;
    // Analiza el bloque de la solución de no ser así lo agrega como solución
    if (solucion[i][j] == 1)
      return false;

    solucion[i][j] = 1;

    // ------------------------------- Movimientos
    // ----------------------------------------------
    if (RamiPoda(mapa, solucion, i, j + 1, n, pasosI, Max_pasos) ==
        true) // derecha
      return true;

    if (RamiPoda(mapa, solucion, i + 1, j, n, pasosI, Max_pasos) ==
        true) { // abajo
      return true;
    }
    if (RamiPoda(mapa, solucion, i, j - 1, n, pasosI, Max_pasos) ==
        true) { // izquierda
      return true;
    }
    if (RamiPoda(mapa, solucion, i - 1, j, n, pasosI, Max_pasos) ==
        true) { // arriba
      return true;
    }
    // No solución
    solucion[i][j] = 0;
    return false;
  }
  return false;
}

// Validar numero reales
int ValidateInt(int valor) {
  while ((cin >> valor).fail() || valor <= 0) {
    cin.clear();
    fflush(stdin);
    cout << "Dato no válido" << endl;
    cout << "Ingrese un valor para dato: ";
  }
  cin.clear();
  fflush(stdin);
  return valor;
}

bool ValidateBool(bool valor) {

  while ((cin >> valor).fail() || valor < 0 || valor > 1) {
    cin.clear();
    fflush(stdin);
    cout << "Dato no válido" << endl;
    cout << "Ingrese un valor para dato: ";
  }
  cin.clear();
  fflush(stdin);
  return valor;
}

int main() {
  int M, Max_pasos;
  bool valor;
  cout << " ********************************** Actividad 1.4 "
          "***************************************** "
       << endl;
  cout << " **** Implementación de la técnica de programación backtracking y "
          "ramificación y poda ****"
       << endl;
  cout << " *******************************************************************"
          "**********************"
       << endl;
  cout << "\nInserte el numero de filas y columnas de la matriz: ";
  M = ValidateInt(M);

  cout << "Ingresa los pasos maximos: ";
  Max_pasos = ValidateInt(Max_pasos);

  // Matriz main  y Matriz solución
  vector<vector<int>> matriz(M);
  vector<vector<int>> solucion(M);
  vector<vector<int>> solucionBB(M);

  // Matriz main
  for (int i = 0; i < M; i++) {
    matriz[i].resize(M);
  }

  // Matriz solucion
  for (int i = 0; i < M; i++) {
    solucion[i].resize(M);
  }

  // Dimensiona matriz solucion
  for (int i = 0; i < M; i++) {
    solucionBB[i].resize(M);
  }

  // Colocar valores en la matriz e imprimirla
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cout << " [ " << i << " "
           << "] [ " << j << " ]: ";
      valor = ValidateBool(valor);
      matriz[i][j] = valor;
    }
  }

  cout << "\nMaze \n" << endl;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cout << "  " << matriz[i][j] << "  ";
    }
    cout << endl;
  }

  //----------------------------------------------------------------------------------------------------------

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      solucion[i][j] = 0;
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      solucionBB[i][j] = 0;
    }
  }

  findPath(matriz, solucion, 0, 0, M);
  cout << endl;
  RamiPoda(matriz, solucion, 0, 0, M, 0, Max_pasos);

  return 0;
}