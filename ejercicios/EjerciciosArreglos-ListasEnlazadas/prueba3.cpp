//EN UN ARREGLO DESORDENADO
#include <iostream>
#define MAX 10

using namespace std;

void inserta(int x[],int &n, int dato){
	
	if(n>MAX){
		cout<<"El arreglo esta lleno"<<endl;
	}else{
		n++;
		x[n]=dato;
		
		
	}
	
}
void mostrar(int x[], int n){
	for(int i=0;i<=n;i++){
		cout<<x[i]<<" ";
	}
}
int buscar(int x[],int &n,int dato){
	int i=0;
	int pos;
	while(i<n&&x[i]!=dato){
		i++;
	}
	if(i>n||x[i]!=dato){
		return i;
	}
	return -i;
}
void eliminar(int x[],int &n,int dato){
	int i,pos;
	if(n==0){
		cout<<"La lista esta vacio"<<endl;
	}else{
		pos=buscar(x,n,dato);
		cout<<"El indice es: "<<pos<<endl;
		
		if(pos<n){ //si es negativo el dato se encontro en el arreglo
			pos=-1*pos;
			for(i=pos;i<n;i++){
				x[i]=x[i+1];
			}
			n--;
		}else{
			cout<<"El dato no se encontro"<<endl;
		}
	}
	
}
int buscar_d(int x[], int n, int dato){
	int i=0;
	while(i<n&&x[i]!=dato){
		i=i+1;
	}
	
	if(x[i]!=dato){
		cout<<"El dato buscado no se encuentra"<<endl;
	}else{
		cout<<"El dato buscando se encuenta en la posicion "<< i+1 << " Del arreglo"<<endl;
	}
	return i;
}

int main(){
	int x[MAX]={1,2,3,4,10};
	int n=4;
	int dato,op;
	int pos;
	inserta(x,n,22);
	/*
	inserta(x,n,10);
	inserta(x,n,8);
	inserta(x,n,7);
	
	inserta(x,n,9);
	inserta(x,n,11); //obcion no valida por lo que deja de inrgesarse datos
	*/
	mostrar(x,n);
	
	cout<<"Que valor desea buscar?: ";
	cin>>dato;
	modificar(x,n,dato);
	
	do{
		cout<<"Que valor desea buscar?: ";
		cin>>dato;
		pos=buscar_d(x,n,dato);
		
		mostrar(x,n);
		cin>>op;
		
	}while(op!=0);
	
		
	cout<<"Que valor desea eliminar?: ";
	cin>>dato;
	
	eliminar(x,n,dato);
	mostrar(x,n);
	
	
	
	
	
	return 0;
}