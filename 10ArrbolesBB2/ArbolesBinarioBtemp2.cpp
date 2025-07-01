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
		void eliminarABB(Nodo*& apnodo, int dato);
		void podarArbol(Nodo*& apnodo);
		Nodo* removerRaiz(Nodo*& apnodo);
		void gotoxy(int x, int y);
		void graficarArbol(Nodo* apnodo,int x, int y, int n);
		
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
		
		//extras
		void generarArbol(Nodo*& apnodo, int niveles);
		int nivelDelNodo(Nodo* apnodo, int dato);
		void mostrarPadres(Nodo* apnodo, int dato);
		void nodosPorNivel(Nodo* apnodo);
		void verReflejo(Nodo* apnodo);
		void clonarArbol(Nodo* apnodo);
		int sumarArbol(Nodo* apnodo, int total);
		void mostrarPares(Nodo* apnodo, int nivel);
		void mostrarImpares(Nodo* apnodo, int nivel);
		void podarHojas(Nodo*& apnodo, Nodo* apnodo2);
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
void Arbol::eliminarABB(Nodo*& apnodo, int dato){
	if(apnodo!=NULL){
		if(dato<apnodo->info){
			eliminarABB(apnodo->izq, dato); //buscar en subarbol izquierdo
		}else if(dato>apnodo->info){
			eliminarABB(apnodo->der,dato); // buscar en usbarbol derecho
		}else{
			Nodo* otro = apnodo;
			//caso 1: es una hoja
			if(apnodo->izq==NULL && apnodo->der==NULL){
				apnodo=NULL;
			//caso 2 tiene solo hijo izquierdo
			}else if(apnodo->der ==NULL){
				apnodo=otro->izq;
			//caso 2: tiene solo un hijo derecho
			}else if(apnodo->izq==NULL){
				apnodo=otro->der;
			}else{
				//caso 3 : tiene dos hijos
				Nodo* aux=apnodo->izq;
				Nodo* aux1=NULL;
				bool bo=false;
				//buscar el mayor de los menores (extremo derecho del suarbolizquierdo
				while(aux->der!=NULL){
					aux1=aux;
					aux=aux->der;
					bo=true;
				}
				apnodo->info=aux->info; //remplazar info del nodp a eliminar
				otro=aux;
				//reconectar el subarbol izquierdo
				if(bo==true){
					aux1->der=aux->izq;
				}else{
					apnodo->izq=aux->izq;
				}
			}
			delete otro; //eliminar nodo
			
		}
	}else{
		cout<<"La informacion a eliminar no se encuentra en el arbol"<<endl;
		return;
	}
}
//forma de tu primo
void Arbol::podarArbol(Nodo*& apnodo){
	if(apnodo!=NULL){
		//poda del subarbol izquierdo
		podarArbol(apnodo->izq);
		//poda del subarbol derecho
		podarArbol(apnodo->der);
		//eliminacion de la raiz
		delete apnodo;
		apnodo=NULL;	
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
Nodo* Arbol::removerRaiz(Nodo*& apnodo){
	Nodo*  temp = apnodo;
	Nodo* p;
	Nodo* q;
	if(apnodo->izq==NULL){
		q=apnodo->der;
		
		delete apnodo;
		apnodo = q;
		return temp;
	}
	p=apnodo;
	q=apnodo->izq;
	while(q->der!=NULL){
		p=q;
		q=q->der;
	}
	if(p!=apnodo){
		p->der=q->izq;
		q->izq=apnodo->izq;
	}
	q->der=apnodo->der;
	delete apnodo;
	apnodo = q;
	return temp;
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
//EXTRAS
void Arbol::generarArbol(Nodo*& apnodo,int cantidad){
	int i,dato;
	srand(time(0));
	for(i=0;i<cantidad;i++){
		dato= rand() % 100 +1; //numero randon entre 1 y 100
		Arbol::insertarNodoIterativo(apnodo, dato);
	}
}
/*
void Arbol::generarArbolPorNivel(Nodo*& apnodo,int niveles){
	int i,dato;
	int repetir;
	repetir = pow(2,niveles)-1;
	for(i=0;i<repetir;i++){
		dato= rand() % 100 +1; //numero randon entre 1 y 100
		Arbol::insertarNodoIterativo(apnodo, dato);
	}
}
*/
int Arbol::nivelDelNodo(Nodo* apnodo, int dato){
	int i=1;
	while(apnodo!=NULL&&apnodo->info!=dato){
		i++;
		if(apnodo->info>dato){
			apnodo=apnodo->izq;
		}else{
			apnodo=apnodo->der;
		}
	}
	if(apnodo!=NULL){
		//cout<<"La informacion se encuentra en el arbol"<<endl;
		return i;
	}else{
		//cout<<"La informacion NO se encuentra en el arbol"<<endl;
		return 0;
	}
}
void Arbol::mostrarPadres(Nodo* apnodo, int dato){
	
	if(busquedav1ABB(apnodo, dato)){
		cout<<"Sus antepasados son: ";
		while(apnodo!=NULL&&apnodo->info!=dato){
				cout<<apnodo->info<<" ";
				if(apnodo->info>dato){
					apnodo=apnodo->izq;
				}else{
					apnodo=apnodo->der;
				}
			}
	}else{
		cout<<"El dato no existe"<<endl;
	}
}
void Arbol::nodosPorNivel(Nodo* apnodo){
	//falta agregar :V
}
void Arbol::verReflejo(Nodo* apnodo){
	if (apnodo == NULL){
		return;
	}
    // Intercambiar los hijos izquierdo y derecho
    Nodo* temp = apnodo->izq;
    apnodo->izq = apnodo->der;
    apnodo->der = temp;

    // Aplicar recursivamente a los subárboles
    verReflejo(apnodo->izq);
    verReflejo(apnodo->der);
}
int Arbol::sumarArbol(Nodo* apnodo, int total){
	
	if(apnodo !=NULL){
		total=sumarArbol(apnodo->izq,total);
		
		total=apnodo->info+total;
		total= sumarArbol(apnodo->der,total);
	}
	return total;
}
void Arbol::mostrarPares(Nodo* apnodo, int nivel){
	if(apnodo==NULL){
		return ;
	}else{
		mostrarPares(apnodo->der, nivel+1);
		for(int i=0;i<nivel;i++){
			
		}
		if(apnodo->info % 2 == 0 ){
			cout<<apnodo->info<<" ";
		}
		mostrarPares(apnodo->izq,nivel+1);
	}
}
void Arbol::mostrarImpares(Nodo* apnodo, int nivel){
	if(apnodo==NULL){
		return ;
	}else{
		mostrarImpares(apnodo->der, nivel+1);
		for(int i=0;i<nivel;i++){
			
		}
		if(apnodo->info % 2 != 0 ){
			cout<<apnodo->info<<" ";
		}
		mostrarImpares(apnodo->izq,nivel+1);
	}
}
void Arbol::podarHojas(Nodo*& apnodo, Nodo* apnodo2){
    if (apnodo == NULL){
    	return;	
	} 

    // Si es una hoja, la eliminamos
    if (apnodo->izq == NULL && apnodo->der == NULL &&apnodo!=apnodo2) {
        delete apnodo;
        apnodo = NULL;
        return;
    }

    // Si no es hoja, seguimos con sus hijos
    podarHojas(apnodo->izq, apnodo2);
    podarHojas(apnodo->der, apnodo2);
}
void menu(){
	Arbol arbol, arbol2, arbol3;
	Nodo* raiz= arbol.regresaRaiz();
	Nodo* a;
	int b;
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
		cout<<"18. Eliminar dato especifico de un arbol"<<endl;
		cout<<"19. Poda del arbol"<<endl;
		cout<<"20. Remover raiz"<<endl;
		cout<<"21. Graficar arbol"<<endl;
		cout<<"22. Generar un arbol aleatorio"<<endl;
		cout<<"23. Indicar el nivel de un nodo"<<endl;
		cout<<"24. Mostrar parientes "<<endl;
		cout<<"25. Contar nodos por nivel"<<endl; //falta agregar
		cout<<"26. Mostrar reflejo del Arbol"<<endl;
		cout<<"27. Sumar todos los valores del arbol"<<endl;
		cout<<"28. Mostrar solo nodos pares"<<endl;
		cout<<"29. Mostrar solo nodos impares"<<endl;
		cout<<"30. Podar solo hojas"<<endl;
		cout<<"31. Mostrar Padre y hermano"<<endl;
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
			case 18:
				if(raiz==NULL){
					cout<<"El arbol esta vacio\n";
				}else{
					cout<<"Ingrese el dato que desea eliminar"<<endl;
					cin>>dato;
					arbol.eliminarABB(raiz,dato);
				}
				break;
			case 19:
				if(raiz==NULL){
					cout<<"El arbol esta vacio\n";
				}else{
					arbol.podarArbol(raiz);
				}
				break;
			case 20:
			    if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			        cout << "La raiz " << raiz->info << " fue eliminada" << endl;
			        arbol.removerRaiz(raiz);
			    }
			    break;
			case 21:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	system("cls");
			        arbol.graficarArbol(raiz,45,2,0);
			        cout<<"\n\n\n\n\n\n\n\n\n";
			        system("pause");
			    }
			    break;
			case 22:
				int cantidad;
				cout<<"Ingrese la cantidad de valores a generar"<<endl;
				cin>>cantidad;
				arbol.generarArbol(raiz,cantidad);
				break;
			case 23:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	cout<<"Ingrese el dato que desea buscar su nivel"<<endl;
			    	cin>>dato;
			    	if(arbol.nivelDelNodo(raiz,dato)==0){
			    		cout<<"El dato no se encontro"<<endl;
					}else{
						cout << "El nivel del nodo es " << arbol.nivelDelNodo(raiz,dato) << endl;  
					}
			    }
			    break;
			case 24:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	cout<<"Ingrese el dato que desea buscar sus Antepasados"<<endl;
			    	cin>>dato;
			        arbol.mostrarPadres(raiz,dato);
			        
			    }
			    break;
			case 25:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	cout<<"Los nodos por nivel son: "<<endl;
			    }
			    break;
			case 26:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	Nodo* raiz2= arbol.regresaRaiz();
			    	
			    	arbol.verReflejo(raiz);
			    }
				break;
			case 27:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	int total=0;
			    	cout<<"La suma de todos los nodos del arbol es: "<<arbol.sumarArbol(raiz,total)<<endl;
			    }
				break;
			case 28:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	arbol.mostrarPares(raiz,0);
			    }
				break;
			case 29:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	arbol.mostrarImpares(raiz,0);
			    }
				break;
			case 30:
				if(raiz == NULL){
			        cout << "El arbol esta vacio\n";
			    } else {
			    	arbol.podarHojas(raiz,raiz);
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