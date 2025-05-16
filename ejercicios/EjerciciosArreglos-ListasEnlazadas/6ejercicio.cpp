/*6 EJERCICIO
	Diseñar un algoritmo que inserte un dato DESPUÉS DE un dato referencial en un arreglo ordenado  
*/

#include<iostream>
#define MAX 5
#include <algorithm>
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

void ordenarArreglo(int x[],int n){
	int aux,i,j;
	for(i=0;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(x[j]<x[i]){
				aux=x[i];
				x[i]=x[j];
				x[j]=aux;
			}
		}
	}
	
}
void insertaDespuesDe(int x[],int &n, int ref){
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
				pos=pos+1;
				n=n+1;
				for(int i=n;i>pos;i--){
						x[i]=x[i-1];
				}
				x[pos]=dato;
				
				mostrar(x,n);
				cout<<endl;
				ordenarArreglo(x,n);
				cout<<endl;
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
	
	insertaDespuesDe(x,n,1);
	//insertaDespuesDe(x,n,2);
	//insertaDespuesDe(x,n,3);
	//insertaDespuesDe(x,n,5);

	
	return 0;
}