//PILAS CON LISTAS ENLAZADAS
#include <iostream>
#include <string>
using namespace std;
struct nodo{
	int info;
	nodo *sig;
};

class Pila{
	private:
		nodo* tope;
	public:
		Pila(){
			tope=NULL;
		}
		void agregarPila(int dato){
			nodo *q;
			q= new nodo();
			q->info=dato;
			q->sig=tope;
			tope=q;
		}
		void sacarPila(){
			if(tope!=NULL){
				nodo *q;
				q=tope;
				tope=q->sig;
				delete(q);
			}else{
				cout<<"Pila vacia, no se puede sacar elemento. "<<endl;
				return;
			}
		}
		void mostrarPila(){
			if(tope!=NULL){
				nodo *q;
				q=tope;
				while(q!=NULL){
					cout<<q->info<< " ";
					q=q->sig;
				}
				
			}else{
				cout<<"Pila vacia, no se puede sacar elemento. "<<endl;
				return;
			}
		}
		int contarElementosPila(){
			int i=0;
			if(tope!=NULL){
				nodo *q;
				
				q=tope;
				while(q!=NULL){
					q=q->sig;
					i++;
				}
				
			}
			return i;
		}
		bool buscarElementoPila(int dato){
			int cen=0;
			nodo *q;
			q=tope;
			while(q!=NULL&&q->info!=dato){
				q=q->sig;
			}
			if(q==NULL){
				return false;
			}else{
				return true;
			}
		}
		
};

int main(){
	Pila pila1;
	Pila pila2;
	int opcion;
	int dato;
	do{
		
		cout<<"\n---MENU PILA---"<<endl;
		cout<<"1. Apilar en Pila 1"<<endl;
		cout<<"2. Desapilar en Pila 1"<<endl;
		cout<<"3. Mostrar Pila 1"<<endl;
		cout<<"4. Contar elementos de Pila 1"<<endl;
		cout<<"5. Buscar un elemento en Pila 1"<<endl;
		cout<<"6. Apilar en Pila 2"<<endl;
		cout<<"7. Mostrar Pila 2"<<endl;
		cout<<"8. Comparar Pila 1 con Pila 2"<<endl;
		cout<<"9. Verificando si la Pila 1 es palindroma"<<endl;
		cout<<"10. Verificar si una palabra es palindroma"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Ingrese dato a apilar en Pila1: ";
				cin>>dato;
				
				pila1.agregarPila(dato);
				break;
				
			case 2:
				pila1.sacarPila();
				break;
				
			case 3:
				pila1.mostrarPila();
				break;
				
			case 4:
				cout<<"Cantidad de elementos en Pila 1: "<<pila1.contarElementosPila()<<endl;
				break;
				
			case 5:
				cout<<"Ingrese el elemento a buscar en Pila 1: ";
				cin>>dato;
				if(pila1.buscarElementoPila(dato)){
					cout<<"Si se encuentra"<<endl;
				}else{
					cout<<"No se encuentra"<<endl;
				}
				break;
				
			case 6:
				cout<<"Ubgrese dato a apilar en Pila 2: ";
				cin>>dato;
				pila2.agregarPila(dato);
				break;
				
			case 7:
				pila2.mostrarPila();
				break;
				/*
			case 8:
				if(pila1.compararCon(pila1,pila2)){
					cout<<"Las pilas son iguales. "<<endl;
				}
				else{
					cout<<"Laas pilas son diferentes. "<<endl;
				}
				break;
			case 9:
				cout<<"Verificando si la pila 1 es palindroma"<<endl;
				if(pila1.palindromo(pila1)){
					cout<<"Es un palindromo"<<endl;
				}
				else
				{
					cout<<"NO ES UN PALINDROMO"<<endl;
				}
				break;
			case 10:
				cout<<"Ingrese la palabra"<<endl;
				cin>>palabra;
				if(palabra1.esPalindromo(palabra)){
					cout<<"Es una palabra palindromo"<<endl;
				}
				else
				{
					cout<<"NO ES UNA PALABRA PALINDROMO"<<endl;
				}
				break;
				*/
			case 0:
				cout<<"Porgrama finalizado. "<<endl;
				break;
			default:
				cout<<"Opcion invalida. "<<endl;
		}	
	} while(opcion!=0);
	return 0;
}