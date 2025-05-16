/*EJERCICIO 3
Diseñar un algoritmo que elimine un dato localizado ANTES DE un dato referencial en un arreglo 
desordenado. 
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
	while(i<=n&&x[i]!=ref){
		i=i+1;
	}
	if(i>n||x[i]!=ref){
		return i;
	}else{
		return -i;
	}
	
}
void eliminaAntesDe(int x[],int &n,int ref){
	int dato,pos;
	if(n<0){
		cout<<"No existes elementos en la lista"<<endl;
	}else{
		pos=buscar(x,n,ref);
		cout<<"Indice: "<<pos<<"\n"<<endl;
		
		if(pos>0){
				cout<<"El dato no existe"<<endl;
		}else{
		
			if(x[0]==ref){
				cout<<"NO ES POSIBLE ELIMINAR EL ANTERIOR AL REFERENCIAL PORQUE ES EL PRIMER"<<endl;
			}else{
				pos=-1*pos; //importante para determinar el lugar donde sera eliminado
				n=n-1;
				pos=pos-1;
				for(int i=pos;i<=n;i++){
					x[i]=x[i+1];
				}	
			}	
		}
	}
}

int main(){
	int x[MAX]={8,2,10};
	int i;
	int n=2;
	int op;
	
	for(i=0;i<=n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
	//cin>>op;
	//eliminaAntesDe(x,n,1);
	//eliminaAntesDe(x,n,2);
	eliminaAntesDe(x,n,2);
	/*
	do{
		switch(op){
			case 1:
			eliminaAntesDe(x,n,1);
	
			break;
		case 2:
			eliminaAntesDe(x,n,2);
			break;
		case 3:
			eliminaAntesDe(x,n,4);
			break;
			
		default:
			break;
			
		}
		
	}while(op!=0);
	*/
	
	for(i=0;i<=n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
	return 0;
}

