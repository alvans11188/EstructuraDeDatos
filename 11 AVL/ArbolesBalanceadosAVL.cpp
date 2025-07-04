#include<iostream>
#include<iomanip>
#include<string>
#include<windows.h>
#include <cmath>
#include <cstdlib> 
#include <ctime>
using namespace std;
class Nodo{
	public:
		int info;
		string info2;
		int fe;
		Nodo* izq;
		Nodo* der;
		Nodo(int valor){
			info=valor;
			fe=0;
			izq=der=NULL;
		}
};

class Arbol {
	private:
	    Nodo* raiz; // apuntador al inicio del arbol
	public:
	    Arbol(); // constructor
	
	    Nodo* regresaRaiz();
	    Nodo*& obtenerRaiz(); // referencia a la raiz
	
	    void insertaBalanceado(Nodo*& apnodo, bool& BO, int dato);
	    void muestraArbol(Nodo* apnodo, int nivel);
	    void gotoxy(int x, int y);
		void graficarArbol(Nodo* apnodo,int x, int y, int n);
	    void inorden(Nodo* apnodo);
};

//constructor
Arbol::Arbol(){
	raiz=NULL;
}
//regresa el apuntador a la raiz
Nodo *Arbol::regresaRaiz(){
	return raiz;
}

Nodo*& Arbol::obtenerRaiz() {
    return raiz;
}
void Arbol::gotoxy(int x, int y){
	COORD coord;
	coord.X= x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Arbol::graficarArbol(Nodo* apnodo, int x, int y, int n){
	if(apnodo==NULL){
		return;
	}
	gotoxy(x,y); 
	cout<<apnodo->info;
	graficarArbol(apnodo->izq, x-15+n*6,y+2,n+1);
	graficarArbol(apnodo->der, x+15-n*6,y+2,n+1);
}
//Recorrido en inorden: subarbol izquierda - raiz - subarbol derecho
void Arbol::inorden(Nodo* apnodo){
	if(apnodo !=NULL){
		inorden(apnodo->izq);
		cout<<apnodo->info<<" - ";
		inorden(apnodo->der);
	}
}
void Arbol::muestraArbol(Nodo* apnodo, int nivel){
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
void Arbol::insertaBalanceado(Nodo*& apnodo, bool& BO, int dato) {
    Nodo* nodo1;
    
	if (apnodo == NULL) {
        apnodo = new Nodo(dato);
        BO = true;
    } else if (dato < apnodo->info) {
        insertaBalanceado(apnodo->izq, BO, dato);
        if (BO) {
            switch (apnodo->fe) {
                case 1:
                    apnodo->fe = 0;
                    BO = false;
                    break;
                case 0:
                    apnodo->fe = -1;
                    //BO = true;
                    break;
                case -1: {
                    nodo1 = apnodo->izq;
                    if (nodo1->fe == -1) {
                        // Rotación simple derecha (II)
                        apnodo->izq = nodo1->der;
                        nodo1->der = apnodo;
                        apnodo->fe = 0;
                        apnodo = nodo1;
                        cout<<"Se realizo una rotacion simple derecha"<<endl;
                    } else {
                        // Rotación doble izquierda-derecha (ID)
                        Nodo* nodo2 = nodo1->der;
                        nodo1->der = nodo2->izq;
                        nodo2->izq = nodo1;
                        apnodo->izq = nodo2->der;
                        nodo2->der = apnodo;

                        if (nodo2->fe == -1) {
                            apnodo->fe = 1;
                            nodo1->fe = 0;
                        } else if (nodo2->fe == 1) {
                            apnodo->fe = 0;
                            nodo1->fe = -1;
                        } else {
                            apnodo->fe = nodo1->fe = 0;
                        }

                        apnodo = nodo2;
                    	cout<<"Se realizo una rotacion doble izquierda-derecha"<<endl;
                    }
                    apnodo->fe = 0;
                    BO = false;
                    break;
                }
            }
        }
    } else if (dato > apnodo->info) {
        insertaBalanceado(apnodo->der, BO, dato);
        if (BO) {
            switch (apnodo->fe) {
                case -1:
                    apnodo->fe = 0;
                    BO = false;
                    break;
                case 0:
                    apnodo->fe = 1;
                    BO = true;
                    break;
                case 1: {
                    Nodo* nodo1 = apnodo->der;
                    if (nodo1->fe == 1) {
                        // Rotación simple izquierda (DD)
                        apnodo->der = nodo1->izq;
                        nodo1->izq = apnodo;
                        apnodo->fe = 0;
                        apnodo = nodo1;
                        cout<<"Se realizo una rotacion simple izquierda"<<endl;
                    } else {
                        // Rotación doble derecha-izquierda (DI)
                        Nodo* nodo2 = nodo1->izq;
                        nodo1->izq = nodo2->der;
                        nodo2->der = nodo1;
                        apnodo->der = nodo2->izq;
                        nodo2->izq = apnodo;

                        if (nodo2->fe == 1) {
                            apnodo->fe = -1;
                            nodo1->fe = 0;
                        } else if (nodo2->fe == -1) {
                            apnodo->fe = 0;
                            nodo1->fe = 1;
                        } else {
                            apnodo->fe = nodo1->fe = 0;
                        }

                        apnodo = nodo2;
                        cout<<"Se realizo una rotacion doble derecha-izquierda"<<endl;
                    }
                    apnodo->fe = 0;
                    BO = false;
                    break;
                }
            }
        }
    } else {
        cout << "La información ya se encuentra en el árbol." << endl;
        BO = false;
    }
}

void menu(){
	Arbol arbol, arbol2, arbol3;
	Nodo* raiz= arbol.regresaRaiz();
	Nodo* a;
	int b;
	int opcion, dato;
	do{
		cout<<"\n==== MENU DE OPCIONES - ARBOL BINARIO ===="<<endl;
		cout<<"1. Insercion balanceadao"<<endl;
		cout<<"2. Mostrar arbol"<<endl;
		cout<<"3. Mostrar arbol (cls)"<<endl;
		cout<<"4. Mostrar recorrido inorden"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1: {
				    cout << "Ingrese dato a insertar balanceado: ";
				    cin >> dato;
				    bool BO = false;
				    arbol.insertaBalanceado(raiz, BO, dato);
				    arbol.muestraArbol(raiz,0);
				    break;
				}
			case 2:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else
					arbol.muestraArbol(raiz,0);
				break;
			case 3:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	system("cls");
			        arbol.graficarArbol(raiz,45,2,0);
			        cout<<"\n\n\n\n\n\n\n\n\n";
			        system("pause");
			    }
			    break;
			case 4:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else{
					cout<<"Recorrido Inorden: ";
					arbol.inorden(raiz);
					cout<<endl;	
				}
				break;
			case 0:
				cout<<"Saliendo del programa...\n";
				break;
			default:
				cout<<"Opcion invalida. Intente nuevamente.\n";
		}
	}while(opcion!=0);
}

int main(){
	menu();
	return 0;
}