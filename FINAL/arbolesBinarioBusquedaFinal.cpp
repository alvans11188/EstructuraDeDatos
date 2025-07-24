#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Nodo{
	public:
		int info;
		string info2;
		Nodo* izq;
		Nodo* der;
};

class Arbol{
	private:
		Nodo* raiz; //apuntador al inicio del arbol
	public:
		Arbol(); //constructor
		
		Nodo* regresaRaiz();
		void insertarNodo(Nodo*& apnodo, int dato);
		void insertarNodo2(Nodo*& apnodo, int dato);
		void insertarNodoIterativo(Nodo*& apnodo, int dato);
		bool busquedaABB(Nodo* apnodo, int dato);
		bool busquedaABB2(Nodo* apnodo, int dato);
		bool busquedaABBIterativa(Nodo* apnodo, int dato);
		void muestraArbol(Nodo* apnodo, int nivel);
		bool busquedav1ABB(Nodo* apnodo,int dato);
		
		void mostrarHojas(Nodo* apnodo);
		
		//metodos de recorrido
		void preorden(Nodo* apnodo);
		void inorden(Nodo* apnodo);
		void posorden(Nodo* apnodo);
		
		int altura(Nodo* apnodo);
		int contarNodos(Nodo* apnodo);
		int contarHojas(Nodo* apnodo);
		
		//valor maximo y minimo
		int valorMaximo(Nodo* apnodo);
		int valorMinimo(Nodo* apnodo);
		
		void muestraArbol2(Nodo* apnodo, int nivel);
		void insertarNodoz(Nodo*& apnodo, string dato);
};
//constructor
Arbol::Arbol(){
	raiz=NULL;
}
//regresa el apuntador a la raiz
Nodo *Arbol::regresaRaiz(){
	return raiz;
}
void Arbol::insertarNodo(Nodo*& apnodo, int dato){
	if(dato<apnodo->info){
		if(apnodo->izq==NULL){
			Nodo* otro = new Nodo();
			otro->info=dato;
			otro->izq=NULL;
			otro->der=NULL;
			apnodo->izq=otro;
		}else{
			insertarNodo(apnodo->izq,dato);
		}
	}else{
		if(dato>apnodo->info){
			if(apnodo->der==NULL){
				Nodo* otro = new Nodo();
				otro->info=dato;
				otro->izq=NULL;
				otro->der=NULL;
				apnodo->der=otro;
			}else{
				insertarNodo(apnodo->der,dato);
			}
		}
	}
}
void Arbol::insertarNodo2(Nodo*& apnodo, int dato){
	if(apnodo!=NULL){
		if(dato<apnodo->info){
			insertarNodo2(apnodo->izq,dato);
		}else{
			if(dato>apnodo->info){
				insertarNodo2(apnodo->der,dato);
			}else{
				cout<<"La informacion ya se encuentra en el arbol"<<endl;
			}
		}
	}else{
		Nodo* otro=new Nodo();
		otro->info=dato;
		otro->izq=NULL;
		otro->der=NULL;
		apnodo=otro;
	}
}
void Arbol::insertarNodoIterativo(Nodo*& apnodo, int dato){
	Nodo* otro=new Nodo();
	otro->info=dato;
	otro->izq=NULL;
	otro->der=NULL;
	if(apnodo==NULL){
		apnodo=otro;
	}else{
		Nodo* h=apnodo;
		Nodo* p=NULL;
		while(h!=NULL){
			p=h;
			if(dato<h->info){
				h=h->izq;
			}else{
				h=h->der;
			}
		}
		if(p->info>dato){
			p->izq=otro;
		}else{
			p->der=otro;
		}
	}
}
bool Arbol::busquedaABB(Nodo* apnodo, int dato){
	if(dato<apnodo->info){
		if(apnodo->izq==NULL){
			//cout<<"La informacion no se encuentra en el arbol"<<endl;
			return false;
		}else{
			return busquedaABB(apnodo->izq,dato);
		}
	}else{
		if(dato>apnodo->info){
			if(apnodo->der==NULL){
				//cout<<"La informacion no se encuentra en el arbol"<<endl;
				return false;
			}else{
				return busquedaABB(apnodo->der,dato);
			}
		}else{
			//cout<<"La informacion esta en el arbol"<<endl;
			return true;
		}
	}
}
bool Arbol::busquedaABB2(Nodo* apnodo, int dato){
	if(apnodo!=NULL){
		if(dato<apnodo->info){
			return busquedaABB2(apnodo->izq, dato);
		}else{
			if(dato>apnodo->info){
				return busquedaABB2(apnodo->der,dato);
			}else{
				return true;
			}
		}
	}else{
		return false;
	}
}
bool Arbol::busquedaABBIterativa(Nodo* apnodo, int dato){
	while(apnodo!=NULL&&apnodo->info!=dato){
		if(apnodo->info>dato){
			apnodo=apnodo->izq;
		}else{
			apnodo=apnodo->der;
		}
	}
	if(apnodo!=NULL){
		//cout<<"La informacion se encuentra en el arbol"<<endl;
		return true;
	}else{
		//cout<<"La informacion NO se encuentra en el arbol"<<endl;
		return false;
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
//ARBOL DEL ZOODIACO
void Arbol::muestraArbol2(Nodo* apnodo, int nivel){
	if(apnodo==NULL){
		return ;
	}else{
		muestraArbol2(apnodo->der, nivel+1);
		for(int i=0;i<nivel;i++){
			cout<<"  ";
		}
		cout<<apnodo->info2<<endl;
		muestraArbol2(apnodo->izq,nivel+1);
	}	
}
void Arbol::insertarNodoz(Nodo*& apnodo, string dato){
    if (apnodo != NULL) {
		if(dato<apnodo->info2){
			insertarNodoz(apnodo->izq,dato);
		}else{
			if(dato>apnodo->info2){
				insertarNodoz(apnodo->der,dato);
			}else{
				cout<<"La informacion ya se encuentra en el arbol"<<endl;
			}
		}
    } else {
        Nodo* otro = new Nodo();
        otro->info2 = dato;
        otro->izq = NULL;
        otro->der = NULL;
        apnodo = otro;
    }	
}
//RECORIDDO DE ARBOLES
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
	
	if(apnodo->izq == NULL && apnodo->der == NULL){
		return 1;
	}
	
	return contarHojas(apnodo->izq) + contarHojas(apnodo->der);
}
bool Arbol::busquedav1ABB(Nodo* apnodo,int dato){
	if(apnodo!=NULL){
		if(dato<apnodo->info){
			return busquedav1ABB(apnodo->izq,dato);
		}else{
			if(dato>apnodo->info){
				return busquedav1ABB(apnodo->der,dato);
			}else{
				return true;
			}
		}
	}else{
		return false;
	}
}

//MAXIMOS Y MINIMOS DEL ARBOL
int Arbol::valorMaximo(Nodo* apnodo){
	while(apnodo->der!=NULL){
		apnodo=apnodo->der;
	}
	return apnodo->info;
}
int Arbol::valorMinimo(Nodo* apnodo){
	while(apnodo->izq!=NULL){
		apnodo=apnodo->izq;
	}
	return apnodo->info;
}
/*
int Arbol::valorMaximo(Nodo* apnodo){
	Nodo* h;
	if(apnodo!=NULL){
		Nodo* h=apnodo;
		valorMaximo(apnodo->der);
	}else{
		return (h->info);
	}
}

int Arbol::valorMinimo(Nodo* apnodo){
	Nodo* h;
	if(apnodo!=NULL){
		Nodo* h=apnodo;
		valorMinimo(apnodo->izq);
	}else{
		return (h->info);
	}
}
*/

void menu(){
	Arbol arbol, arbol2;
	Nodo* raiz= arbol.regresaRaiz();
	int opcion, dato;
	do{
		cout<<"\n==== MENU DE OPCIONES - ARBOL BINARIO ===="<<endl;
		cout<<"1. Insertar nodo(insertarNodo)"<<endl;
		cout<<"2. Insertar nodo(insertarNodo2)"<<endl;
		cout<<"3. Insertar nodo (insertarNodoIterativo)"<<endl;
		cout<<"4. Mostrar arbol (forma estructurada)"<<endl;
		cout<<"5. Recorrido en Preorden"<<endl;
		cout<<"6. Recorrido en Inorden"<<endl;
		cout<<"7. Recorrido en Posorden"<<endl;
		cout<<"8. Buscar dato (busquedaABB)"<<endl;
		cout<<"9. Altura del arbol"<<endl;
		cout<<"10. Contar todos los nodos"<<endl;
		cout<<"11. Contar nodo hoja"<<endl;
		cout<<"12. Buscar el valor maximo"<<endl;
		cout<<"13. Buscar el valor minimo"<<endl;
		cout<<"14. Construccion del arbol del zodiaco"<<endl;
		cout<<"15. buscar un nodo con cierta informacion"<<endl;
		cout<<"16. Busqueda ABB2"<<endl;
		cout<<"17. Busqueda iterativa"<<endl;
		cout<<"18. Mostrar Hojas"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Ingrese dato a insertar (insertarNodo): ";
				cin>>dato;
				if(raiz==NULL){
					raiz=new Nodo{dato,"", NULL, NULL};
				}else{
					arbol.insertarNodo(raiz,dato);
				}
				break;
			case 2:
				cout<<"Ingrese dato a insertar (insertarNodo2): ";
				cin>>dato;
				arbol.insertarNodo2(raiz, dato);
				break;
			case 3:
				cout<<"Ingrese dato a insertar (insertarNodoIterativo): ";
				cin>>dato;
				arbol.insertarNodoIterativo(raiz, dato);
				break;
			case 4:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else
					arbol.muestraArbol(raiz,0);
				break;
			case 5:
				if(raiz==NULL)
					cout<<"El rabol esta vacio.\n";
				else{
					cout<<"Recorrido Preorden: ";
					arbol.preorden(raiz);
					cout<<endl;
				}
				break;
			case 6:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else{
					cout<<"Recorrido Inorden: ";
					arbol.inorden(raiz);
					cout<<endl;	
				}
				break;
			case 7:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else{
					cout<<"Recorrido Posorden: ";
					arbol.posorden(raiz);
					cout<<endl;	
				}
				break;
			case 8:
				cout<<"Ingrese el dato a buscar: ";
				cin>>dato;
				if(arbol.busquedaABB(raiz,dato))
					cout<<"Dato encontrado en el arbol.\n";
				else
					cout<<"Dato NO encontrado. \n";
				break;
			case 9:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else
					cout<<"Altura del arbol: "<<arbol.altura(raiz)<<endl;
				break;
			case 10:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else
					cout<<"Cantidad total de nodos: "<<arbol.contarNodos(raiz)<<endl;
				break;
			case 11:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else
					cout<<"Cantidad de nodos hoja: "<<arbol.contarHojas(raiz)<<endl;
				break;
			case 12:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else
					cout<<"El valor MAXIMO del Arbol es: "<<arbol.valorMaximo(raiz)<<endl;
				break;
			case 13:
				if(raiz==NULL)
					cout<<"El arbol esta vacio.\n";
				else
					cout<<"El valor MINIMO del Arbol es: "<<arbol.valorMinimo(raiz)<<endl;
				break;
			case 14:{
				Nodo* raiz2 = arbol2.regresaRaiz(); 
			    string dato2;
			    char op;
			    cout << "INGRESE LOS DATOS AL ARBOL DEL ZODIACO" << endl;
			
			    do {
			        cout << "Signo: ";
			        cin >> dato2;
			        arbol2.insertarNodoz(raiz2, dato2);
			        cout << "Mas datos? (S/N): ";
			        cin >> op;
			    } while (op == 's' || op == 'S');
			    cout << "\nArbol del Zodiaco:\n";
			    arbol2.muestraArbol2(raiz2, 0);	

				break;
				}
			case 15:
				cout<<"Que dato desea buscar?: ";
				cin>>dato;
				if(arbol.busquedav1ABB(raiz,dato)){
					cout<<"Elemento encontrado"<<endl;
				}else{
					cout<<"NO se encontro el elemento"<<endl;
				}
				break;
			case 16:
				cout<<"Ingrese el dato a buscar: ";
				cin>>dato;
				if(arbol.busquedaABB2(raiz,dato))
					cout<<"Dato encontrado en el arbol.\n";
				else
					cout<<"Dato NO encontrado. \n";
				break;
			case 17:
				cout<<"Ingrese el dato a buscar: ";
				cin>>dato;
				if(arbol.busquedaABBIterativa(raiz,dato))
					cout<<"Dato encontrado en el arbol.\n";
				else
					cout<<"Dato NO encontrado. \n";
				break;
			case 18{
				cout << "Las hojas son: "<<endl;
				arbol.mostrarHojas(raiz);
				break;
			}
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