/*
Codigo trabajado por: Monserrat Karime Moreno Casas 
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;


int main() {
  string n;
  cout << "Ingresa el string: ";
  cin >> n;
  
  vector<string> suffixes;  // GENERA EL VECTOR DE SUFIJOS

  for(int i =n.size(); i >= 0 ; i--){ // FOR DEL TAMAÑO DEL STRING
    suffixes.push_back(n.substr(i, n.size())); // HACE UN PUSH DE LOS CARACTERES SUBSTRAIDOS
  }

  sort(suffixes.begin(), suffixes.end()); // ORDENA LOS CARACTERES 

  for(int i =0; i < suffixes.size(); i++){
      cout<< suffixes[i] << endl; // IMPRIME LOS SUBSTRINGS
  }

}