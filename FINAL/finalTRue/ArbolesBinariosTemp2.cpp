#include <iostream>
#include <iomanip>
#include <cmath>
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
		void mostrarHoja(Nodo* apnodo);
		bool verificarArbol(Nodo* apnodo);
		bool buscarArbol(Nodo* apnodo, int dato);
		void medianaArbol(Nodo* apnodo, Nodo* raiz);
		Nodo* generarArbol();
		Nodo* eliminarArbol(Nodo* apnodo,int dato);
		bool simetricoArbol(Nodo* apnodo);
};

Arbol::Arbol(){
	raiz=NULL;
}
void Arbol::muestraArbol(Nodo *apnodo, int nivel){
	if(apnodo==NULL){
		return ;
	}else{
		muestraArbol(apnodo->der, nivel+1);
		for(int i=0;i<nivel;i++){
			cout<<"  ";
		}
		cout<<apnodo->info<<endl;
		muestraArbol(apnodo->izq,nivel+1);
	}
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
		inorden(apnodo->izq);
		cout<<apnodo->info<<" - ";
		inorden(apnodo->der);
	}
}
//recorrido posorden: subarbol izquierdo - subarbol derecho - raiz
void Arbol::posorden(Nodo* apnodo){
	if(apnodo !=NULL){
		posorden(apnodo->izq);
		posorden(apnodo->der);
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
	if(apnodo == NULL){
		return 0;
	}
	// Si no tiene hijos, es una hoja
	if(apnodo->izq == NULL && apnodo->der == NULL){
		return 1;
	}
	// Llamada recursiva a subárbol izquierdo y derecho
	return contarHojas(apnodo->izq) + contarHojas(apnodo->der);
}

void Arbol::mostrarHoja(Nodo* apnodo){
	if(apnodo == NULL){
		return;
	}
	
	if(apnodo->izq == NULL && apnodo->der == NULL){
		cout<<"La hoja es: "<<apnodo->info<< endl;
		return;
	}

	mostrarHoja(apnodo->izq);
	mostrarHoja(apnodo->der);
}
bool Arbol::verificarArbol(Nodo* apnodo){
	int h,tamanio;
	h=altura(apnodo);
	tamanio=pow(2,h)-1;
	if(tamanio==contarNodos(apnodo)){
		return true;
	}else{
		return false;
	}
}
bool Arbol::buscarArbol(Nodo* apnodo, int valor){
	if(apnodo == NULL){
		return false;
	}
	if(apnodo->info == valor){
		return true;
	}
	// Buscar en el subárbol izquierdo o derecho
	return buscarArbol(apnodo->izq, valor) || buscarArbol(apnodo->der, valor);
}
void Arbol::medianaArbol(Nodo* apnodo, Nodo* raiz){
	const int MAX = 100;
	int arreglo[MAX];
	int i = 0;

	// Recorrido en preorden, guardando nodos que no son raíz ni hojas
	Nodo* pila[MAX];
	int tope = -1;

	if(apnodo == NULL){
		cout << "Árbol vacío.\n";
		return;
	}

	// Algoritmo iterativo tipo preorden con pila manual
	pila[++tope] = apnodo;

	while(tope >= 0){
		Nodo* actual = pila[tope--];

		// Si no es raíz y no es hoja
		if(actual != raiz && !(actual->izq == NULL && actual->der == NULL)){
			if(i < MAX){
				arreglo[i++] = actual->info;
			}
		}

		// Primero derecha (por LIFO) luego izquierda
		if(actual->der != NULL){
			pila[++tope] = actual->der;
		}
		if(actual->izq != NULL){
			pila[++tope] = actual->izq;
		}
	}

	// Mostrar resultados
	if(i == 0){
		cout << "No hay nodos medianos en el árbol.\n";
	} else {
		for(int j = 0; j < i; j++){
			cout << arreglo[j] << " - ";
		}
		cout << endl;
	}
}

Nodo* Arbol::generarArbol(){
		// Crear nodos manualmente
	Nodo* n1 = new Nodo(); n1->info = 1;
	Nodo* n2 = new Nodo(); n2->info = 2;
	Nodo* n3 = new Nodo(); n3->info = 3;
	Nodo* n4 = new Nodo(); n4->info = 4;
	Nodo* n5 = new Nodo(); n5->info = 5;
	Nodo* n6 = new Nodo(); n6->info = 6;
	Nodo* n7 = new Nodo(); n7->info = 7;

	// Establecer conexiones (estructura del árbol)
	n1->izq = n2;  n1->der = n3;
	n2->izq = n4;  n2->der = n5;
	n3->izq = n6;  n3->der = n7;
	n4->izq = NULL; n4->der = NULL;
	n5->izq = NULL; n5->der = NULL;
	n6->izq = NULL; n6->der = NULL;
	n7->izq = NULL; n7->der = NULL;

	return n1; // raíz del árbol
}

Nodo* Arbol::eliminarArbol(Nodo* apnodo, int valor){
    if(apnodo == NULL) return NULL;

    // Si el nodo actual es el que debe eliminarse
    if(apnodo->info == valor){
        // Caso 1: sin hijos
        if(apnodo->izq == NULL && apnodo->der == NULL){
            delete apnodo;
            return NULL;
        }
        // Caso 2: un hijo
        else if(apnodo->izq == NULL){
            Nodo* temp = apnodo->der;
            delete apnodo;
            return temp;
        }
        else if(apnodo->der == NULL){
            Nodo* temp = apnodo->izq;
            delete apnodo;
            return temp;
        }
        // Caso 3: dos hijos
        else {
            // Buscamos el nodo más a la izquierda del subárbol derecho
            Nodo* sucesor = apnodo->der;
            Nodo* padreSucesor = apnodo;

            while(sucesor->izq != NULL){
                padreSucesor = sucesor;
                sucesor = sucesor->izq;
            }

            apnodo->info = sucesor->info; // Reemplaza el valor
            // Elimina el sucesor recursivamente (es seguro porque está más abajo)
            if(padreSucesor->izq == sucesor)
                padreSucesor->izq = eliminarArbol(sucesor, sucesor->info);
            else
                padreSucesor->der = eliminarArbol(sucesor, sucesor->info);

            return apnodo;
        }
    }

    // Buscar en subárbol izquierdo y derecho
    apnodo->izq = eliminarArbol(apnodo->izq, valor);
    apnodo->der = eliminarArbol(apnodo->der, valor);
    return apnodo;
}

bool sonEspejo(Nodo* a, Nodo* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return (a->info == b->info) &&
           sonEspejo(a->izq, b->der) &&
           sonEspejo(a->der, b->izq);
}

bool Arbol::simetricoArbol(Nodo* apnodo) {
    if (apnodo == NULL) return true; // arbol vacío es simétrico
    return sonEspejo(apnodo->izq, apnodo->der);
}


void menu(){
	Arbol arbol;
	Nodo* raiz=NULL;
	int opcion,dato;
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
		cout<<"9. Verificar si es un arbol completo"<<endl;
		cout<<"10. Buscar un nodo especifico"<<endl;
		cout<<"11. Mostrar mediana del arbol"<<endl;
		cout<<"12. Generar Arbol "<<endl;
		cout<<"13. Eliminar dato "<<endl;
		cout<<"14. Determinar si el arbol es simetrico"<<endl;
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
					arbol.mostrarHoja(raiz);
					cout<<"La cantidad de nodos hojas son: "<<arbol.contarHojas(raiz)<<endl;
				}
				break;
			case 9:
				if(arbol.verificarArbol(raiz)){
					cout<<"El arbol es compleo"<<endl;
				}else{
					cout<<"El arbol NO esta completo"<<endl;
				}
				break;
			case 10:
				if(raiz==NULL){
					cout<<"El arbol esta vacio.\n";
				}else{
					cout<<"Ingrese que dato desea buscar "<<endl;
					cin>>dato;
					if( arbol.buscarArbol(raiz,dato)){
						cout<<"El dato : "<< dato << " SI se encuentra en el arbol "<<endl;
					}else{
						cout<<"El dato : "<< dato << " NO se encuentra en el arbol "<<endl;
					};
				}
				break;
			case 11:{
				if(raiz==NULL){
					cout<<"El arbol esta vacio"<<endl;
				}else{
					//cout<<"Los datos de la mediana del arbol son"<<endl;
					arbol.medianaArbol(raiz,raiz);
				}
				break;
			}
			case 12:{
				raiz=arbol.generarArbol();
				break;
			}
			case 13:{
				if(raiz==NULL){
					cout<<"El arbol esta vacio"<<endl;
				}else{
					cout<<"Ingrese el dato que quiere eliminar"<<endl;
					cin>>dato;
					raiz=arbol.eliminarArbol(raiz,dato);
					arbol.muestraArbol(raiz,0);
				}
				break;
			}
			case 14:{
				if(arbol.simetricoArbol(raiz)){
					cout<<"El arbol si es simetrico"<<endl;
				}else{
					cout<<"El arobl NO es simetrico"<<endl;
				}
				break;
			}
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