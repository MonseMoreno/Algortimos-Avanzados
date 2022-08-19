//Codigo trabajado por Monserrat Karime Moreno Casas 
//Actividad 1.3 Implementación de la técnica de programación "Programación dinámica" y "algoritmos avaros"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Complejidad del algoritmo: O(n*m)

void AlgoritmoDinamico(int monedas[], int monto, int Array_Size) {

    int max = monto + 1;
    int dp[monto + 1];

    for (int i = 0; i < monto + 1; i++) {
        dp[i] = max;
    }

    dp[0] = 0;

    for (int i = 1; i <= monto; i++) {

        for (int j = 0; j < Array_Size; j++) {

            if (monedas[j] <= i) {
                dp[i] = min(dp[i], dp[i - monedas[j]] + 1);
            }

        }

    }

    int num_monedas = (dp[monto] > monto) ? -1 : dp[monto];

    if (num_monedas != -1) {
        cout << "\nNúmero mínimo de monedas de cambio del producto: " << num_monedas << endl;
    }
    else {
        cout << "\nCambio insuficiente!! :c" << endl;
    }

}


//Complejidad del algoritmo: O(n*m)



void AlgoritmoAvaro(int monedas[], int monto, int Array_Size) {

    sort(monedas, monedas + Array_Size); // Ordena monedas
    vector<int> ans;

    for (int i = Array_Size - 1; i >= 0; i--) {

        while (monto >= monedas[i]) {

            monto -= monedas[i];
            ans.push_back(monedas[i]);

        }

    }

    int num_monedas = ans.size();

    if (num_monedas != 0) {

        if (monto == 0) {

            cout << "\nNúmero mínimo de monedas de cambio del producto: " << num_monedas << endl;
            cout << "\n- Monedas que se dan de cambio -\n" << endl;

            for (int i = 0; i < ans.size(); i++) {
                cout << "Moneda " << i + 1 << ": $" << ans[i] << endl;
            }

        }
        else {
            cout << "\nEn este algoritmo no existe solución" << endl;
        }

    }
    else {
        cout << "\nCambio insuficiente!!!" << endl;
    }

}

int main() {
    cout << "************************************************************" << endl;
    cout << "*********************  Actividad 1.3  **********************" << endl;
    cout << "************************************************************" << endl;
  
    cout << "\nEscribe el número de monedas a ingresar: ";

    int n;
    cin >> n;
    int monedas[n];

    cout << "\n***** Escriba el valor de las monedas *****\n" << endl;

    for (int i = 0; i < n; i++) {

        cout << "Moneda " << i + 1 << ": $";

        int temp;
        cin >> temp;
        monedas[i] = temp;

    }

    int p, q, algorithm;

    cout << "\nEscribe el precio del producto: $";
    cin >> p; // Precio
    cout << "Escribe la cantidad con la que se pagará el producto: $";
    cin >> q; // Cantidad pagada

  
    cout << "\n************** Menú de Algoritmos ****************" << endl;
    cout << "1. Algoritmo de programación avara" << endl;
    cout << "2. Algoritmo de programación dinámica" << endl;
    cout << "**************************************************" << endl;

    do {

        cout << "\nElige el algoritmo de la solución: ";
        cin >> algorithm;

        if (algorithm == 1) {

            cout << "\nCambio: $" << q - p << endl;
            AlgoritmoAvaro(monedas, q - p, n);

        }
        else
            if (algorithm == 2) {

                cout << "\nCambio: $" << q - p << endl;
                AlgoritmoDinamico(monedas, q - p, n);

            }

    } while (algorithm != 1 && algorithm != 2);

    return 0;

}