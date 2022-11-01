#include <vector>

using std::vector;

/**
 * @brief Devuelve la cantidad máxima de valor que se puede transportar dados los vectores de peso y valor, así como un límite de peso.
  * Complejidad: O(NW), donde N es el número de items y W es el peso máximo a llevar.
 */
int KnapsackAlgorith(vector<int> elementValues, vector<int> elementWeights, int maxWeight)
{
    int value1 = 0, value2 = 0, value = 0;
    //Inicie nuestra matriz de soluciones de Programación Dinámica.
    vector<vector<int>> optimalValues(elementValues.size() + 1, vector<int>(maxWeight + 1));

    // Llena nuestra matriz.
    for (int item = 0; item <= elementValues.size(); item++) // el ítem actual será i - 1, debido a llenar la primera fila y columna con ceros.
    {
        for (int weightValue = 0; weightValue <= maxWeight; weightValue++) // Iterar a través de cada peso máximo del subproblema.
        {
            if (item == 0 || weightValue == 0) // Complete con cero para el items 0 y el peso 0.
            {
                optimalValues[item][weightValue] = 0;
            } else if (elementWeights[item - 1] <= weightValue) // Si nuestro item encaja, vea si usamos solo su valor o su valor con el valor del último item.
            {
                value1 = optimalValues[item - 1][weightValue];
                value2 = elementValues[item - 1] + optimalValues[item - 1][weightValue - elementWeights[item - 1]];
                if (value1 > value2)
                {
                    optimalValues[item][weightValue] = value1;
                }
                else
                {
                    optimalValues[item][weightValue] = value2;
                }
            }
            else // Si el elemento tiene un peso mayor que nuestro peso máximo actual del subproblema, usamos el valor del último elemento en ese peso.
            {
                optimalValues[item][weightValue] = optimalValues[item - 1][weightValue];
            }
            // Actualizar nuestro valor máximo.
            if (optimalValues[item][weightValue] >= value)
            {
                value = optimalValues[item][weightValue];
            }
        }
    }
    return value;
}