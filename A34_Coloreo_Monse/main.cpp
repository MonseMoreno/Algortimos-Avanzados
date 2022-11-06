/*
Actividad 3.4 Implementación de "Graph coloring"
Codigo trabajado por: Monserrat Karime Moreno Casas
*/

#include <iostream>
#include <vector>
using namespace std;
int conteo=0;
void imprimir(vector<int> matrizColor, int n);

bool safe(int nodo, int color,int n,vector<vector<int>> matriz,vector<int> matrizColor){
	for(int i=0;i<n;i++){
		if(matriz[nodo][i]==1 && color==matrizColor[i]){
			return false;
		}
	}
	return true;
}


void GraphColoring(int k,int n,vector<vector<int>> matriz,	vector<int> matrizColor){
  //Matriz donde se almacena los colores
	for(int color=1;color<=3;color++){ //Asignación de un color de 1 a 3
    if(safe(k,color,n,matriz,matrizColor))
    {
      matrizColor[k]=color;
      if(conteo==0 && k==n-1)
      {
        imprimir(matrizColor, n);
        conteo++;
      }
      if(k+1<n)
      { //Llamada recursiva
        GraphColoring(k+1,n,matriz,matrizColor);
      } else {
          return;
      }
		}
	}
}

void imprimir(vector<int> matrizColor, int n){
	for(int i=0;i<n;i++){
		 cout<<"Nodo: "<<i<<" Color asignado "<<matrizColor[i]<<endl;

	}

}

int main() {
    /*
    La entrada al programa es un grafo no dirigido, en forma de matriz de adyacencias.
    Si no es posible asignar colores diferentes a cada nodo,
    se despliega el mensaje "No es posible asignar colores a los nodos".
    Si es posible asignar colores diferentes a nodos adyacentes,
    el output es una lista de colores asignados a cada nodo (lista mínima) .  
    */


    int n;//número de nodos/dimensión matriz
    cout<<"Nodos: ";
    cin>>n;

    //valida que la entreda n sea un número positivo
    while(n<=0){
        cout<<"No puedes ingresar números negativos o iguales que 0, vuelve a intentarlo"<<endl;
        cout<<"\nNodos: ";
        cin>>n;
    }


    //se declara la matriz 
    vector<vector<int>> matriz (n);
    //inicializar la matriz 
    for ( int i = 0 ; i < n ; i++ ){
        matriz[i].resize(n);
    }
		//Inicializando matriz para guardar los colores
		vector<int> matrizColor(n,0);


    //valores en matriz de adyacencias
    int valor;
    cout<<"Ingresa los valores de la matriz de adyacencias "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>valor;
            while(valor<0 || valor>1){
                cout<<"Solo puedes ingresar 1 ó 0, vuelve a intentarlo"<<endl;
                cin>>valor;
            }
            matriz[i][j]=valor; 
        }
    }


    //imprime matriz original
    cout<<"\nEntrada"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"[ "<<matriz[i][j]<<" ] ";
        }
        cout<<endl;
    }

  cout<<"\nSalida"<<endl;
  //llamado a funcion
	GraphColoring(0,n,matriz,matrizColor);
    
  
  return 0;
}