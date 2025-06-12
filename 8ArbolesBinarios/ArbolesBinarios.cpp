#include <iostream>
#include <iomanip>
using namespace std;

class Nodo{
	public:
		int info;
		Nodo* izq;
		Nodo* der;
};

class Arbol{
	private:
		Nodo* raiz; //apuntador al inicio del arbol
	public:
		Arbol(); // constructor
		
		Nodo* creaArbol();
		void muestraArbol(Nodo *apnodo, int nivel);
		
		//metodos de recorrido
		void preorden(Nodo* apnodo);
		void inorden(Nodo* apnodo);
		void posorden(Nodo* apnodo);
		
		int altura(Nodo* apnodo);
		int contarNodos(Nodo* apnodo);
		int contarHojas(Nodo* apnodo);
};

Arbol::Arbol(){
	raiz=NULL;
}
void Arbol::muestraArbol(Nodo *apnodo, int nivel){
	
}
Nodo* Arbol::creaArbol(){
	bool resp;
	Nodo* apnodo =new Nodo();
	
	cout<<"\nIngrese el valor del nodo: ";
	cin>>apnodo->info;
	
	cout<<"\nExiste nodo por la izquierda: 1(Si) - 0 (No)? ";
	cin>>resp;
	if(resp==1){
		apnodo->izq=creaArbol();
	}else{
		apnodo->izq=NULL;
	}
	cout<<"\n ¿Existe nodo por la derecha: 1(Si) - 0(No)? ";
	cin>>resp;
	if(resp==1){
		apnodo->der=creaArbol();
	}else{
		apnodo->der=NULL;
	}
	return apnodo;
}
//Recorrido en preorden: Raiz - Subarbol izquierda - subarbol Derecho
void Arbol::preorden(Nodo* apnodo){
	if(apnodo !=NULL){
		cout<<apnodo->info<<" - ";
		preorden(apnodo->izq);
		preorden(apnodo->der);
	}
}
//Recorrido en inorden: subarbol izquierda - raiz - subarbol derecho
void Arbol::inorden(Nodo* apnodo){
	if(apnodo !=NULL){
		preorden(apnodo->izq);
		cout<<apnodo->info<<" - ";
		preorden(apnodo->der);
	}
}
//recorrido posorden: subarbol izquierdo - subarbol derecho - raiz
void Arbol::posorden(Nodo* apnodo){
	if(apnodo !=NULL){
		preorden(apnodo->izq);
		preorden(apnodo->der);
		cout<<apnodo->info<<" - ";
	}
}
int Arbol::altura(Nodo* apnodo){
	if(apnodo==NULL){
		return 0;
	}else{
		return 1 + max(altura(apnodo->izq), altura(apnodo->der));
	}
}

int Arbol::contarNodos(Nodo* apnodo){
	if(apnodo==NULL){
		return 0;
	}else{
		return 1+ contarNodos(apnodo->izq)+contarNodos(apnodo->der);
	}
}

int Arbol::contarHojas(Nodo* apnodo){
	
}

void menu(){
	Arbol arbol;
	Nodo* raiz=NULL;
	int opcion;
	do{
		cout<<"\n ===MENU DE OPCIONES - ARBOL BINARIO === "<<endl;
		cout<<"1. Crear arbol "<<endl;
		cout<<"2. Mostrar arbol (forma estructurada)"<<endl;
		cout<<"3. Recorrido en Preorden"<<endl;
		cout<<"4. Recorrido en Inorden"<<endl;
		cout<<"5. Recorrido en Posorden"<<endl;
		cout<<"6. Altura del arbol"<<endl;
		cout<<"7. Contar todos los nodos "<<endl;
		cout<<"8. Contar nodos hoja"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione una opcion:";
		cin>>opcion;
		switch(opcion){
			case 1:
				raiz=arbol.creaArbol();
				break;
			case 2:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					arbol.muestraArbol(raiz,0);
				}
				break;
			case 3:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					cout<<"Recorrido Preorden : ";
					arbol.preorden(raiz);
					cout<<endl;
				}
				break;
			case 4:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					cout<<"Recorrido Inorden: ";
					arbol.inorden(raiz);
					cout<<endl;
				}
				break;
			case 5:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					cout<<"Recorrido Inorden: ";
					arbol.posorden(raiz);
					cout<<endl;
				}
				break;
			case 6:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					cout<<"Altura del arbol: "<< arbol.altura(raiz)<<endl;
				}
				break;
			case 7:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					cout<<"Cantidad total de nodos: "<< arbol.contarNodos(raiz)<<endl;
				}
				break;
			case 8:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					cout<<"Cantidad de nodos hoja: "<< arbol.contarHojas(raiz)<<endl;
				}
				break;
			case 0:
				cout<<"Saliendo del programa...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente nuevamente. \n";
				break;
		}
	} while(opcion != 0);
}
int main(){
	setlocale(LC_ALL,"");
	menu();
	return 0;
}