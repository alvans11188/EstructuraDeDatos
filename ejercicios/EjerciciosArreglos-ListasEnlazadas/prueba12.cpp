/*CREE UNA LISTA DE LIBROS CON LOS PARAMETROS DE char nombre, float (precio) y codigo
pase esta lista a una pila ordenada de mayor a menor
*/
#include<iostream>
#define MAX 20
using namespace std;

struct nodo{
	char nombre[MAX];
	float precio;
	char codigo[MAX];
	nodo *sig;
};

class Pila{
	private:
		int tope;
		char nombre[MAX];
		float precio;
		char codigo[MAX];
	public:
		Pila();	
		
		
		void agregarPila(nodo *);
		void mostrarPila();
};
Pila::Pila(){
	tope=-1;
}



void Pila::agregarPila(nodo *p){
	nodo *q;
	
	q=p;
	
	while(q!=NULL){
		
		tope++;
		strcpy(pila1.nombre[tope],q->nombre) ;
		
		q=q->sig;
	}
}

void 

nodo *agregarLista(nodo *p){
	nodo *q;
	q=p;
	if(p==NULL){
		q=new nodo();
		cout<<"Ingrese el nombre del libro: ";cin>>q->nombre;
		cout<<"Ingrese el precio: ";cin>>q->precio;
		cout<<"Ingrese el codigo: ";cin>>q->codigo;
		q->sig=p;
		p=q;
	}else{
		
		while(q->sig!=NULL){
			q=q->sig;
		}
		nodo *t=new nodo();
		cout<<"Ingrese el nombre del libro: ";cin>>t->nombre;
		cout<<"Ingrese el precio: ";cin>>t->precio;
		cout<<"Ingrese el codigo: ";cin>>t->codigo;
		t->sig=q->sig;
		q->sig=t;
	}
	return (p);
}
void mostrar(nodo *p){
	nodo *q;
	int i=0;
	q=p;
	if(p!=NULL){
		cout<<"Lista de libros"<<endl;
		while(q!=NULL){
			cout<<"LIBRO N# "<<i<<endl;
			cout<<"NOMBRE: "<<q->nombre<<endl;
			cout<<"PRECIO: "<<q->precio<<endl;
			cout<<"CODIGO: "<<q->codigo<<endl;
			q=q->sig;
			i++;
		}
	}else{
		cout<<"La lista esta vacia"<<endl;
	}
	
}

	



int main(){
	
	nodo *p=NULL;
	Pila pila1;
	int opcion;
	do{
		cout<<"\n--MENU --"<<endl;
		cout<<"1. Ingresar dato a lista"<<endl;
		
		cout<<"9.  Mostrar "<<endl;
		cout<<"0. Salir "<<endl;
		cout<<"Opcion:  "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				p=agregarLista(p);
				break;
			case 2:
				pila1.agregarPila(p);
				break;
			/*
			case 2:
				pila1.agregarPila(p);
				break;
			*/
			case 9:
				mostrar(p);
				break;
			case 0:
				cout<<"Porgrama finalizado. "<<endl;
				break;
			default:
				cout<<"Opcion invalida. "<<endl;
		}	
	} while(opcion!=0);
	return 0;
}