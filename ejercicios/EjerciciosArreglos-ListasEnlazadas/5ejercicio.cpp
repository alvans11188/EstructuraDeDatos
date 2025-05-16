/*5 EJERCICIO
Diseñar un algoritmo que inserte un dato ANTES DE un dato referencial en un arreglo ordenado. 
*/
#include<iostream>
#define MAX 5
using namespace std;
void mostrar(int x[],int n){
	for(int i=0;i<=n;i++){
	cout<<	x[i]<<" ";
	}
}
int buscar(int x[],int n,int ref){
	int i=0;
	while(i<=n&&x[i]<ref){
		i=i+1;
	}
	if(i>n||x[i]>ref){
		return i;
	}else{
		return -i;
	}
}

void insertaAntesDe(int x[],int& n, int ref){
	int pos,dato;
	if(n==0){
		cout<<"Mi arreglo esta vacio"<<endl;
	}else{
		
		if(n<MAX){
			mostrar(x,n);
			cout<<endl;
			
			pos=buscar(x,n,ref);
			cout<<pos<<endl;
			if(pos>n){
				cout<<"El dato referencial no existe"<<endl;
			}else{
				
				cout<<"Ingrese el dato que desea insertar"<<endl;
				cin>>dato;
				pos=-1*pos;
				n=n+1;
				for(int i=n;i>=pos;i--){
					x[i+1]=x[i];
				}
				x[pos]=dato;
				
				mostrar(x,n);
			}
			
				
		}else{
			cout<<"Ya no hay espepacios para ingresar datos"<<endl;
		}
	}
}

int main(){
	int x[MAX] = {1,2,3,4,5};
	int n=4;
	
	insertaAntesDe(x,n,5);
	
	return 0;
}