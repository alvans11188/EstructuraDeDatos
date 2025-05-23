#include <iostream>
#define MAX 10
using namespace std;

class Pila{
	private:
		char elementos[MAX];
		int tope;
	public:
		Pila();
		bool pilaVacia();
		bool pilaLlena();
		void agregarPila(char dato);
		char sacarPila();
		char cima();
		void mostrarPila();
		int contarElementosPila();
		bool buscarElementoPila(int dato);
};

Pila::Pila(){
	tope=-1; //pial vacia
}
bool Pila::pilaVacia(){
	if (tope==-1){
		return true;
	}else{
		return false;
	}
}
bool Pila::pilaLlena(){
	if(tope== MAX - 1){
		return true;
	}else{
		return false;
	}
}
void Pila::agregarPila(char dato){
	if(pilaLlena()){
		cout<<"Desbordamiento de datos"<<endl;
	}else{
		tope++;
		elementos[tope]=dato;
	}
}
char Pila::sacarPila(){
	if(pilaVacia()){
		cout<<"La pila esta vacia"<<endl;
		return (0);
	}else{
		char dato = elementos[tope];
		tope--;
		return dato;
	}
}

void Pila::mostrarPila(){
	if(pilaVacia()){
		cout<<"La pila esta vacia"<<endl;
	}else{
		cout<<"Los elementos d ela pila son"<<endl;
		for(int i=tope;i>=0;i--){
			cout<<elementos[i]<<" ";
		}
	}
}

int Pila::contarElementosPila(){
	if(pilaVacia()){
		cout<<"La pila esta vacia"<<endl;
	}
	return tope+1;
	
}
bool Pila::buscarElementoPila(int dato){
	int cen=0;
	if(pilaVacia()){
		cout<<"La pila esta vacia"<<endl;
		return false;
	}else{
		for( int i=0;i<tope;i++){
			if(elementos[i]==dato){
				cen=1;
			}
		}
	}
	if(cen==1){
		return true;
	}else{
		return false;
	}
}
int main(){
	Pila pila1;
	Pila pila2;
	int opcion;
	char dato;
	do{
		cout<<"\n--MENU PILA--"<<endl;
		cout<<"1. Apilar en Pila 1"<<endl;
		cout<<"2. Desapilar en Pila 1 "<<endl;
		cout<<"3. Mostrar Pila 1"<<endl;
		cout<<"4. Contar elementos de Pila 1 "<<endl;
		cout<<"5. Buscar un elemento en Pila 1"<<endl;
		cout<<"6. Apilar en Pila 2 "<<endl;
		cout<<"7. Mostrar Pila 2"<<endl;
		cout<<"8. Comparar Pila 1 con Pila 2"<<endl;
		cout<<"9. Determinar si una palabra es palindroma"<<endl;
		cout<<"10. Expresar una expresion infija como postfija"<<endl;
		cout<<"11. Expresar una expresion infija a prefija"<<endl;
		cout<<"12. Determinar si una expresion matematica es correcta"<<endl;
		cout<<"0. Salir "<<endl;
		cout<<"Opcion:  "<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Ingrese dato a apilar en pila 1:";
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
				cout<<"\nLa cantidad de elementos en Pila 1 es:"<<pila1.contarElementosPila()<<endl;
				break;
				
			case 5:
				cout<<"Ingrese el elemento a buscar en Pila 1:";
				cin>>dato;
				cout<<"¿Esta el  "<<dato<<" ?"<<(pila1.buscarElementoPila(dato)?"Si":"No")<<endl;
				break;
				/*
			case 6:
				cout<<"Ingrese dato a apilar ne Pila 2: ";
				cin>>dato;
				pila2.agregarPila(dato);
				break;
			case 7:
				pila2.mostrarPila();
				break;
			
			case 8:
				cout<<"Los elementos de la Pila 1 y 2 son iguales ?"<<(pila1.compararCon(pila2)?"Si son iguales":"No son iguales")<<endl;
				break;
			case 9:
				cout<<"Ingrese la palabra:";
				cin>>palabra;
				cout<<"¿La palabra "<<palabra<<" es palindroma ?"<<(esPalindromo(palabra)?"Si":"No")<<endl;
				break;
			case 10:
				cout<<"Ingresa una operacion matematica INFIJA A POSTFIJA"<<endl;
				cin>>operacion;
				pila1.infijaApostfijaOperacionMatematica(operacion);
				break;
			case 11:
				cout<<"Ingresa una operacion matematica INFIJA A PREFIJA"<<endl;
				cin>>operacion;
				pila1.infijaAprefijaOperacionMatematica(operacion);
				break;
				
			case 12:
				cout<<"Ingresa una operacion matematica"<<endl;
				cin>>operacion;
				cout<<"¿La operacion matematica "<<operacion<<" es correcta ?"<<( pila1.revisarApostfijaOperacionMatematica(operacion)?"Si":"No")<<endl;
				;
				break;
				*/
			case 0:
				cout<<"Programa finalizado."<<endl;
				break;
			default:
				cout<<"opcion invalida"<<endl;
		}
	} while(opcion != 0);

	return 0;
}