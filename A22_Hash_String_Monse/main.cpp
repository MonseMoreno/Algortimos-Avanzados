// Código trabajado por: Monserrat Karime Moreno Casas
//----------------------------------------------------//
// Complejidad del codigo implementado: O(N) 
//----------------------------------------------------//
//----------------------------------------------------//


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int contarSimbolos(vector<char> caracter)
{


    int count = 0;
    for (int i = 0; i < caracter.size(); i++) // CONTAR LOS CARACTERES DEL VECTOR
    {
        count++;
    }
    return count;
}


bool Multiplos(int number, int multiple) // NÚMEROS MÚLTIPLOS
{
    if (number % multiple == 0) // VERIFICACIÓN
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Función para crear una tabla de caracteres
vector<vector<char>> CrearTabla(vector<char> caracter, int columns, bool Multiplos)
{
    vector<vector<char>> tabla;
    int count = 0;
    int rows = 0;
    if (Multiplos)
    {
        rows = caracter.size() / columns;
    }
    else
    {
        rows = (caracter.size() / columns) + 1;
    }
    for (int i = 0; i < rows; i++)
    {
        vector<char> row;
        for (int j = 0; j < columns; j++)
        {
            if (count < caracter.size())
            {
                row.push_back(caracter[count]);
                count++;
            }
            else
            {
                row.push_back(' ');
            }
        }
        tabla.push_back(row);
    }
    return tabla;
}


vector<vector<char>> insertCharacter(vector<vector<char>> tabla, char character, int row, int column)
{
    //AGREGAR Y DESPLAZAR CARACTERES 
    tabla[row][column] = character;
    return tabla;
}

vector<vector<int>> TransformarTabla(vector<vector<char>> tabla)
{
    vector<vector<int>> asciitabla;
    for (int i = 0; i < tabla.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < tabla[i].size(); j++)
        {
            if (int(tabla[i][j]) == 10)
            {
                row.push_back(int(tabla[i][j]));
                row.push_back(13);
            }
            else
            {
                row.push_back(int(tabla[i][j]));
            }
        }
        asciitabla.push_back(row);
    }
    return asciitabla;
}

vector<vector<char>> displacecaracter(vector<vector<char>> tabla, int row, int column)
{

    //AGREGAR Y DESPLAZAR CARACTERES 
    for (int i = tabla[row].size() - 1; i > column; i--)
    {
        tabla[row][i] = tabla[row][i - 1];
    }
    return tabla;
}

vector<int> SumaFilas(vector<vector<char>> tabla) //CONVERTIR EN ASCII 
{
    vector<int> sum;
    for (int i = 0; i < tabla.size(); i++)
    {
        int sumRow = 0;
        for (int j = 0; j < tabla[i].size(); j++)
        {

            sumRow += tabla[i][j];
        }
        sumRow = sumRow % 256;
        sum.push_back(sumRow);
    }

    return sum;
}

// funcion para checar si la ultima linea del vector esta llena y si no, agrega caracteres constantes
vector<vector<char>> checkLastRow(vector<vector<char>> tabla, char constant)
{
    if (tabla[tabla.size() - 1].size() < tabla[0].size())
    {
        for (int i = tabla[tabla.size() - 1].size(); i < tabla[0].size(); i++)
        {
            tabla[tabla.size() - 1].push_back(constant);
        }
    }
    return tabla;
}

// funcion para transformar de un vector de enteros a hexadecimal
vector<string> Hexadecimal(vector<int> numbers)
{
    vector<string> hexadecimal;
    for (int i = 0; i < numbers.size(); i++)
    {
        string hex = "";
        int number = numbers[i];
        while (number > 0)
        {
            int remainder = number % 16;
            if (remainder < 10)
            {
                hex = to_string(remainder) + hex;
            }
            else
            {
                switch (remainder)
                {
                case 10:
                    hex = "A" + hex;
                    break;
                case 11:
                    hex = "B" + hex;
                    break;
                case 12:
                    hex = "C" + hex;
                    break;
                case 13:
                    hex = "D" + hex;
                    break;
                case 14:
                    hex = "E" + hex;
                    break;
                case 15:
                    hex = "F" + hex;
                    break;
                }
            }
            number = number / 16;
        }
        if (hex.length() == 1)
        {
            hex = "0" + hex;
        }

        hexadecimal.push_back(hex);
    }
    return hexadecimal;
}

// Funcion que imprime el vector
template <class T>
void printVector(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// funcion pra imprimir la tabla de caracteres
template <class T>
void printtabla(vector<vector<T>> tabla)
{
    for (int i = 0; i < tabla.size(); i++)
    {
        for (int j = 0; j < tabla[i].size(); j++)
        {
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }
}

// funcion para transformar vector de chars a strings
string vectorToString(vector<char> v)
{
    string s = "";
    for (int i = 0; i < v.size(); i++)
    {
        s += v[i];
    }
    return s;
}



int main()
{
    char contentFile;
    string contentInside, nameFile;
    string extension = ".txt";
    int valueN = 0, numcaracter = 0;
    cout << "Escribe el nombre de tu archivo txt: ";
    cin >> nameFile;
    nameFile += extension;
    cout << "Ingresa el valor n de 4 entre 16 y 64: ";
    cin >> valueN;

    ifstream file(nameFile);
    if (!file.is_open())
    {
        cout << "ERROR: FILE NOT FOUND";
        return 1;
    }

    vector<char> v;
    while (file.get(contentFile))
    {
        v.push_back(contentFile);
    }

    // printVector(v);
    numcaracter = contarSimbolos(v);
    cout << "Numero de caracteres : " << numcaracter << endl;

  
    cout << "\n *********************************************** \n" << endl;
    vector<vector<char>> tabla = CrearTabla(v, valueN, Multiplos(numcaracter, valueN));
    printtabla(tabla);

    vector<vector<int>> asciitabla = TransformarTabla(tabla);
    cout << "\n *********************************************** \n" << endl;
    cout << "TABLA EN ASCII" << endl;
    printtabla(asciitabla);

    cout << "\n *********************************************** \n" << endl;
    cout << "Arreglo de longitud 'n' que muestra la suma de las columnas con el modulo 256: " << endl;

    char constant = char(valueN);

    vector<vector<char>> tablaWithLastRow = checkLastRow(tabla, constant);

    vector<int> sumPerRow;
    sumPerRow = SumaFilas(tablaWithLastRow);
    printVector(sumPerRow);

    system("pause");
    cout << "\n *********************************************** \n" << endl;
    cout << "Valores en Hexadecimal: " << endl;
    vector<string> hexadecimal = Hexadecimal(sumPerRow);
    printVector(hexadecimal);
    cout << endl;

    file.close();
    return 0;
}
