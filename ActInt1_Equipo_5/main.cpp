// =========================================================
//Código trabajado por: 
// Monserrat Karime Moreno Casas - A01276775
// Erick Alfredo García Huerta - A01708119
// =========================================================
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

/**
 * Abre un archivo, lo lee y devuelve el contenido del archivo como una cadena
 */
string open_file(string filename)
{

  ifstream file(filename);
  char c;
  string myfile;

  if (file.is_open())
  { //leer los caracteres del archivo mientras esté abierto - complejidad computacional O(n)
    while (!file.eof())
      {
      file.get(c);
      myfile += c;
    }
  }

  myfile.pop_back();
  return myfile;
}

/**
 * La función toma una cadena como entrada y devuelve el índice inicial y
 * longitud del palíndromo más largo de la cadena
 */
pair<int, int> manacher(string myText)
{
  vector<char> myNewText;
  vector<int> myVector;
  pair<int, int> mySol; // resultados de inicio y fin del palíndromo

  int c = 0;
  int r = 0;
  int mirror = 0;
  int max_pal = 0;
  int c_idx;

  myNewText.push_back(' ');

  for (int i = 0; i < myText.size(); i++)
  { //separando  ' ' - Complejidad computacional de O(n)
    myNewText.push_back(myText[i]);
    myNewText.push_back(' ');
  }

  for (int j = 0; j < myNewText.size(); j++)
  { 
    myVector.push_back(0);
  }

  for (int i = 1; i < myNewText.size(); i++)
  {                
    mirror = c - (i - c); //índice de la posición actual

    if (r > i)
    {
      myVector[i] = MIN(r - i, myVector[mirror]);
    }

    while (myNewText[i + 1 + myVector[i]] == myNewText[i - 1 - myVector[i]])
    { 
      myVector[i] = myVector[i] + 1;
    }

    if (i + myVector[i] > r)
    { 
      c = i;
      r = i + myVector[i];
    }
  }

  for (int i = 1; i < myNewText.size(); i++)
  { 
    if (max_pal < myVector[i])
    {
      max_pal = myVector[i];
      c_idx = i;
    }
  }

  mySol.first = ((c_idx - 1 - max_pal) / 2) + 1; // índice de inicio del palíndromo
  mySol.second = (max_pal);                      // índice de la última posición del palíndromo.

  return mySol;
}

/**
 * La función toma una cadena y devuelve un vector de enteros. El entero en
 * el índice i en el vector es la longitud del prefijo más largo de la cadena
 * que también es un sufijo de la subcadena que comienza en el índice i
 */
vector<int> preprocessing(string myString)
{
  int i = 1;
  int j = 0;
  vector<int> myVector; 
  for (int i = 0; i < myString.size(); i++)
  { 
    myVector.push_back(0);
  }

  while (i < myString.size())
  { 
    if (myString[j] == myString[i])
    {
     
      myVector[i] = j + 1;
      i += 1;
      j += 1;
    }
    else
    {
      if (j == 0)
      {
        myVector[i] = 0;
        i += 1;
      }
      else
      {
        j = myVector[j - 1];
      }
    }
  }
  return myVector;
}

/**
 */
int kmp(string myPattern, string myText)
{
  int i = 0;
  int j = 0;
  vector<int> myVector = preprocessing(myPattern + "X" + myText); // vector preprocesado

  while (i < myText.size())
  { // ciclo para recorrer el texto a analizar
    if (myPattern[j] == myText[i])
    { // condicional para verificar si el caracter del prefijo es igual al del texto
      i++;
      j++;
    }
    if (j >= myPattern.size())
    { // condicional para regresar e índice de la posición en la que inicia el prefijo
      return i - j;
    }
    if (i < myText.size() && myPattern[j] != myText[i])
    {

      if (j != 0)
      {
        j = myVector[j - 1];
      }
      else
      {
        i++;
      }
    }
  }

  return -1; // si no se encuentra el prefijo dentro de la cadena se regresa -1
}

int LongCommonSubstring(string pattern1, string pattern2)
{
  const int patt1_size = pattern2.size();
  const int patt2_size = pattern1.size();

  int maxlen = 0;            
  int endingIndex = patt2_size;

  int lookup_table[patt2_size + 1][patt1_size + 1];


  memset(lookup_table, 0, sizeof(lookup_table));


  for (int i = 1; i <= patt2_size; i++)
  {
    for (int j = 1; j <= patt1_size; j++)
    {

      if (pattern1[i - 1] == pattern2[j - 1])
      {
        lookup_table[i][j] = lookup_table[i - 1][j - 1] + 1;


        if (lookup_table[i][j] > maxlen)
        {
          maxlen = lookup_table[i][j];
          endingIndex = i;
        }
      }
    }
  }
  // devuelve la subcadena común más larga que tiene la longitud de maxlen
  int common_substring_size =
      (pattern1.substr(endingIndex - maxlen, maxlen)).size();
  return common_substring_size;
}

int main(int argc, char *argv[])
{

  string extension = ".txt";
  string file1;
  string file2;

  cout << "\n ------------ ARCHIVOS DE TRANSMISIÓN ------------ \n" << endl ;
  cout << "Por favor escriba el nombre de su archivo (sin la extension): "; 
  cin >> file1 ;
  file1 += extension;
  

   cout << "\nPor favor escriba el nombre de su segundo archivo (sin la extension): "; 
  cin >> file2;
  file2 += extension;
  
  

  string transmission1 = open_file(file1);
  string transmission2 = open_file(file2);

//------------------------------------------------------------


  cout << "\n --------------- ARCHIVOS MALICIOSOS -------------- \n" << endl ;
  
  string badFile1;
  string badFile2;
  string badFile3;

    cout << "Por favor escriba el nombre de el archivo malicioso 1 (sin la extension): "; 
  cin >> badFile1 ;
  badFile1 += extension;
  

   cout << "\nPor favor escriba el nombre de el archivo malicioso 2 (sin la extension): "; 
  cin >> badFile2;
  badFile2 += extension;

     cout << "\nPor favor escriba el nombre de el archivo malicioso 3 (sin la extension): "; 
  cin >> badFile3;
  badFile3 += extension;
  
  string mcode1 = open_file(badFile1);
  string mcode2 = open_file(badFile2);
  string mcode3 = open_file(badFile3);

  vector<string> malware;

  malware.push_back(mcode1);
  malware.push_back(mcode2);
  malware.push_back(mcode3);

  vector<int> preprocessedVector = preprocessing(mcode1 + "X" + transmission1);

  pair<int, int> myPair = manacher(transmission2);

  vector<string> transmissions;

  transmissions.push_back(transmission1);
  transmissions.push_back(transmission2);


  cout << "\n ------------ RESULTADOS ------------" << endl ;

  for (int i = 0; i < transmissions.size(); i++)
  {
    cout << "\ntransmission" << i + 1 << ".txt:" << endl;
    for (int j = 0; j < malware.size(); j++)
    {
      cout << "mcode" << j + 1 << ".txt - ";
      if (kmp(malware[j], transmissions[i]) != -1)
      {
        cout << "true, start at position " 
          << kmp(malware[j], transmissions[i]) 
          << " , end at position " 
          << kmp(malware[j], transmissions[i]) + (malware.size() - 1) << endl;
      }
      else
      {
        cout << "false" << endl;
      }
    }
    cout << endl;
  }  

  for (int i = 0; i < transmissions.size(); i++)
  {
    cout << "\ntransmission" << i + 1 << ".txt:" << endl;
    pair<int, int> myPair = manacher(transmissions[i]);
    cout << "mirrored code found, start at " << myPair.first << ", ended at "
         << myPair.first + myPair.second << endl;
    cout << endl;
  }
  cout << "the longest common substring between transmission1.txt and transmission2.txt is ";
  cout << LongCommonSubstring(transmission1, transmission2) << " characters long" << endl;
}
