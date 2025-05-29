/*PROBLEMA 1 DEL EXAMEN
CREE UNA AMTRIZ DE TAMANIO N Y HAGA QUE LA DIAGONAL PRINCIPAL SEA 1 Y EL RESTO DE LA MATRIZ 0
*/
#include <iostream>

using namespace std;

int main(){
	int n;

	cout<<"Ingrese el tamanio de la matriz"<<endl;
	cin>>n;
	int tamanio=n*n;
	int x[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>x[i][j];
		}
	}	
	cout<<"MATRIZ ORIGINAL"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<x[i][j]<< " ";
		}
		cout<<endl;
	}
	cout<<"MATRIZ MODIFICADA"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				x[i][j]=1;
			}else{
				x[i][j]=0;
			}
		}
	
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<x[i][j]<< " ";
		}
		cout<<endl;
	}
	return 0;
}