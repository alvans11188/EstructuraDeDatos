/*EJERCICIO 1
Diseñar un algoritmo que inserte un dato ANTES DE un dato referencial en un arreglo desordenado.
*/
#include<iostream>
#define MAX 10
using namespace std;

struct arreglo{
	int inf;	
};

void inserta(arreglo *,int&, int);
int buscar(arreglo *, int& ,int );
void insertaDespuesReferencial(arreglo *,int&, int);
void eliminarAntesDe(arreglo *, int&, int);
void mostrar(arreglo*, int);

int main(){
	arreglo x[MAX];
	int n=0;
	
	inserta(x,n,1);
	inserta(x,n,2);inserta(x,n,7);
	inserta(x,n,3);
	inserta(x,n,5);
	
	//insertaDespuesReferencial(x,n,7);
	eliminarAntesDe(x,n,7);
	mostrar(x,n);
	return 0;
}

void inserta(arreglo* x,int &n,int dato){
	//int dato;
	
	if(n>MAX){
		cout<<"El arreglo esta lleno"<<endl;
	}else{
		
		//cout<<"Ingrese el dato"<<endl;
		//cin>>dato;
		x[n].inf=dato;
		n=n+1;
	}
}
int buscar(arreglo *x, int& n,int dato){
	for(int i=0;i<n;i++){
		if(x[i].inf==dato){
			return i;
		}
	}
	return -1;
}
void insertaDespuesReferencial(arreglo *x,int &n, int ref){

}
void eliminarAntesDe(arreglo *x,int& n,int ref){
		if(n<0){
		cout<<"El arreglo esta vacio"<<endl;
		return;
	} else {
		int pos = buscar(x,n,ref);
		if(pos<0){
			cout<<"No se encontro el referencial"<<endl;
			return;
		}else{
			if(pos==0){
				cout<<"No existe un elemento antes del referencial"<<endl;
				return;
			}else{
				int dato2;
				//cout<<"Ingrese el dato "<<endl;
				//cin>>dato2;
				for(int j=pos-1;j<n-1;j++){
					x[j].inf=x[j+1].inf;
				}
				
				n=n-1;
			}
		}
	}
}
void mostrar(arreglo *x,int n){
	for(int i=0;i<n;i++){
		cout<<x[i].inf<<" ";
	}
}