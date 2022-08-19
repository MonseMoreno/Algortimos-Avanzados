#include "CAlgoritmos.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


CAlgoritmos::CAlgoritmos() {

}; 

CAlgoritmos::CAlgoritmos(int _monedas[50], int _monto, int _Array_Size) {
    _monedas[50] = monedas[50];
    _monto = monto;
    _Array_Size = Array_Size;

}



//Complejidad: O(n*m)
void CAlgoritmos::AlgoritmoDinamico(){

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
        cout << "\nN�mero m�nimo de monedas de cambio del producto: " << num_monedas << endl;
    }
    else {
        cout << "\nEl cambio no puede ser exacto :(" << endl;
    }


}




//Complejidad: O(n*m)


void CAlgoritmos::AlgoritmoAvaro() {
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

            cout << "\nN�mero m�nimo de monedas de cambio del producto: " << num_monedas << endl;
            cout << "\n- Monedas que se dan de cambio -\n" << endl;

            for (int i = 0; i < ans.size(); i++) {
                cout << "Moneda " << i + 1 << ": $" << ans[i] << endl;
            }

        }
        else {
            cout << "\nEn este algoritmo no existe soluci�n" << endl;
        }

    }
    else {
        cout << "\nEl cambio no puede ser exacto!! :( " << endl;
    }
}