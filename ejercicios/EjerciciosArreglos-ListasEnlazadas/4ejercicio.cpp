/*4 EJERCICIO
Diseñar un algoritmo que elimine un dato localizado DESPUÉS DE un dato referencial en un arreglo 
desordenado. 
*/
#include<iostream>
#define MAX 5
using namespace std;

void mostrar(int x[],int n){
	for(int i=0;i<=n;i++){
	cout<<	x[i]<<" ";
	}
}
int buscar(int x[], int n, int ref){
	int i=0;
	while(i<=n&&x[i]!=ref){
		i++;
	}
	if(i>n&&x[i]!=ref){
		return i;
	}else{
		return -i;
	}
}
void eliminarDespuesDe(int x[],int& n, int ref){
	int pos;
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
		
	}
}
int main(){
	int x[MAX]={1,2,3};
	int n=2;
	//eliminarDespuesDe(x,n,1);
	//eliminarDespuesDe(x,n,2);
	eliminarDespuesDe(x,n,3);
	mostrar(x,n);
	return 0;
}