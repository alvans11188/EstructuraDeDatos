#include <iostream>
#include <string.h>
#include <chrono>
using namespace std;
#define MAX 100
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(int val) {
        dato = val;
        izq = der = NULL;
    }
};

class Arbol {
private:
    Nodo* raiz;

public:
    Arbol() {
        raiz = NULL;
    }

    Nodo*& obtenerRaiz() {
        return raiz;
    }

    void insertar(Nodo*& nodo, int dato) {
        if(nodo!=NULL){
			if(dato<nodo->dato){
				insertar(nodo->izq,dato);
			}else{
				if(dato>nodo->dato){
					insertar(nodo->der,dato);
				}else{
					cout<<"El dato ya se encuentra en el arbol"<<endl;
				}
			}
		}else{
			Nodo* otro=new Nodo(dato);
			otro->dato=dato;
			otro->izq=NULL;
			otro->der=NULL;
			nodo=otro;
		}
    }

    void mostrar(Nodo* nodo, int nivel = 0) {
        if (nodo != NULL) {
            mostrar(nodo->der, nivel + 1);
            for (int i = 0; i < nivel; i++)
                cout << "  ";
            cout << nodo->dato << endl;
            mostrar(nodo->izq, nivel + 1);
        }
    }
    // BFS con ABIERTO y CERRADO visibles
    void BFS(int objetivo) {

        Nodo* abierto[MAX];
        Nodo* cerrado[MAX];
        int frente = 0, fin = -1;
        int tamCerrado = 0;
        bool encontrado = false;

        abierto[++fin] = raiz;

        while (frente <= fin && !encontrado) {
            cout << "\nABIERTO: ";
            for (int i = frente; i <= fin; i++) {
                cout << abierto[i]->dato;
                cout << " | ";
            }
            cout << endl;

            Nodo* X = abierto[frente++];
            cerrado[tamCerrado++] = X;

            if (X->dato == objetivo) {
                encontrado = true;
                cout << "Nodo objetivo " << objetivo << " encontrado.\n";
                break;
            }

            if (X->izq != NULL) {
            	abierto[++fin] = X->izq;
			}
            if (X->der != NULL) {
            	abierto[++fin] = X->der;
			}
        }
        if (!encontrado){
        	cout << "Nodo objetivo " << objetivo << " no se encontro.\n";
		}  
        cout << "\nCERRADO (nodos explorados): ";
        for (int i = 0; i < tamCerrado; i++) {
            cout << cerrado[i]->dato;
            if (i < tamCerrado - 1) cout << " -> ";
        }
        cout << endl;
    }
};

void menu() {
    Arbol arbol;
    int opcion, dato;
    Nodo*& raiz=arbol.obtenerRaiz();

    do {
        cout << "\n===== MENU ARBOL BINARIO =====\n";
        cout << "1. Insertar nodo\n";
        cout << "2. Mostrar arbol\n";
        cout << "3. Buscar nodo (BFS)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el dato a insertar: ";
                cin >> dato;
                arbol.insertar(raiz, dato);
                break;
            case 2:
            	if(raiz==NULL){
            		cout<<"El arbol esta vacio";
				}else{
					cout << "Arbol:\n";
                	arbol.mostrar(raiz);	
				}
                break;
            case 3:
            	if(raiz==NULL){
            		cout<<"El arbol esta vacio";
				}else{
					cout << "Ingrese nodo objetivo a buscar: ";
	                cin >> dato;
					auto inicio = chrono::high_resolution_clock::now();
	                arbol.BFS(dato);
					auto fin = chrono::high_resolution_clock::now();
					auto duracion_ns = chrono::duration_cast<chrono::nanoseconds>(fin - inicio);
					auto duracion_ms = chrono::duration_cast<chrono::microseconds>(fin - inicio);
					auto duracion_s = chrono::duration_cast<chrono::duration<double>>(fin - inicio);
					
					cout << "Tiempo de insercion (iterativa):\n";
					cout << " - " << duracion_ns.count() << " nanosegundos\n";
					cout << " - " << duracion_ms.count() << " microsegundos\n";
					cout << " - " << duracion_s.count()  << " segundos\n";
				}
                break;

            case 0:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}
int main() {
    menu();
    return 0;
}
