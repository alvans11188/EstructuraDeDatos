/*8 EJERCICIO
Diseñar un algoritmo que elimine un dato localizado DESPUÉS DE un dato referencial en un arreglo 
ordenado. 
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
void eliminaDespuesDe(int x[],int &n, int ref){
	int pos;
	ordenarArreglo(x,n);
	if(n<0){
		cout<<"Mi arreglo esta vacio"<<endl;
	}else{
		pos=buscar(x,n,ref);
		if(pos<=0){
			pos=-1*pos;
			cout<<"Indice: "<<pos<<"\n"<<endl;;
			if(pos==n){
				cout<<"El dato despues del referencial no existe"<<endl;
			}else{
				pos=pos+1;
				for(int i=pos;i<n;i++){
						x[i]=x[i+1];
				}
				n--;
			}	
		}else{
			cout<<"El dato referencial no existe"<<endl;
		}
		mostrar(x,n);
	}
}

int main(){
	int x[MAX] = {3,2,1,6,5};
	int n=4;
	
	eliminaDespuesDe(x,n,2);
	//insertaDespuesDe(x,n,2);
	//insertaDespuesDe(x,n,3);
	//insertaDespuesDe(x,n,5);

	
	return 0;
}