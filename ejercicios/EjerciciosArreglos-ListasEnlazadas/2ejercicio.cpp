/*EJERCICIO 1
Diseñar un algoritmo que inserte un dato ANTES DE un dato referencial en un arreglo desordenado.
*/
#include<iostream>
#define MAX 10
using namespace std;
void mostrar(int x[],int n){
	for(int i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
}
int buscar(int x[],int n, int ref){
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
void insertarAntesDe(int x[],int &n,int ref){
	int dato,pos;
	if(n>=MAX){
		cout<<"El arreglo esta lleno"<<endl;
		
	}else{
		pos=buscar(x,n,ref);
		cout<<pos;
		cout<<"Ingrese el dato"<<endl;
		cin>>dato;
		if(pos<=0){
			n=n+1;
			pos=-1*pos;
			for(int i=n;i>pos;i--){
				x[i]=x[i-1];
				mostrar(x,n);
				cout<<endl;
			}
			
			x[pos]=dato;
			
		}else{
			cout<<"El dato no existe referencial no existe"<<endl;
		}
	}
}

int main(){
	int x[MAX]={1,2,3,4,5};
	int i;
	int n=4;
	
	
	for(i=0;i<=n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
	
	insertarAntesDe(x,n,5);
	for(i=0;i<=n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
	return 0;
}

