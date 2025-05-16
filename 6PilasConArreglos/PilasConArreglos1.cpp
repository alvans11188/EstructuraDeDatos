#include<iostream>
#include<string>
#include<cctype>
using namespace std;
#define MAX 100 // capacidad maxima de la pila

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
		bool buscarElementoPila(int valor);
		bool compararCon(Pila& otra);
		bool infijaApostfijaOperacionMatematica(const string& expmatematica);
		bool revisarApostfijaOperacionMatematica(const string& expmatematica);
		
};

//constructor
Pila::Pila(){
	tope=-1; //pila vacia
}
//metodo para verificar si la pila esta vacia
bool Pila::pilaVacia(){
	if(tope==-1){
		return true;
	}else{
		return false;
	}
}
//metodo para verificar si la pila esta llena
bool Pila::pilaLlena(){
	if(tope == MAX -1){
		return true;
	}else{
		return false;
	}
}
//metodo para agregar un elemento a la pila (push)
void Pila::agregarPila(char dato){
	if(pilaLlena()){
		cout<<"Desbordamiento - pila llena. no se puede agregar mas elementos."<<endl;
		return;
	}else{
		tope++;
		elementos[tope] = dato;
	}
}

//metodo para eliminar el elemento superior de la pila(pop)
char Pila::sacarPila(){
	if(pilaVacia()){
		cout<<"Subdesbordamiento - pila vacia. no se puede sacar elemento"<<endl;
		return (0);
	}else{
		char dato = elementos[tope];
		tope--;
		return dato;
	}
}
//metodo para ver el elemento en la cima de la pila (peek)
char Pila::cima(){
	if(!pilaVacia()){
		return elementos[tope];
	}else{
		cout<<"Pila vacia"<<endl;
		return -1;
	}
	
}
//metodo para mostrar todos los elementos de la pila
void Pila::mostrarPila(){
	if(pilaVacia()){
		cout<<"Pila vacia"<<endl;
		return;
	}else{
		cout<<"Elementos de la pila (de arriba hacia abajo):"<<endl;
		for(int i=tope;i>=0;i--){
			cout<<elementos[i]<<" ";
		}
		cout<<endl;
	}
}
//metodo para contar elementos
int Pila::contarElementosPila(){
	if(pilaVacia()){
		cout<<"La pila esta vacia"<<endl;
	}
	return tope+1;
}
//metodo para buscar un elemento en la pila
bool Pila::buscarElementoPila(int dato){
	int cen=0;
	if(pilaVacia()){
		cout<<"La pila esta vacia"<<endl;
		return false;
	}else{
		for(int i=0;i<=tope;i++){
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
//metodo para comparar con otra pila
bool Pila::compararCon(Pila& pila2){
	int cen=0;
	int i;
	if(pilaVacia()){
		cout<<"La pila esta vacia"<<endl;
		return false;
	}else{
		if(tope!=pila2.tope){
			cout<<"Las pilas son de diferentes tamanios"<<endl;
			return false;
		}else{
			for(i=0;i<=tope;i++){
				if(elementos[i]!=pila2.elementos[i]){
					return false;
				}
			}
		}		
	}
	return true;
}

int prioridad(char op) {
    if (op == '^')              return 3;
    if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
    return 0;
}

bool Pila::infijaApostfijaOperacionMatematica(const string& expmatematica){
	Pila pila;
	int tope=0;
	string EPOS="";
	char simbolo,dato;
	int i;
	for(i=0;i<expmatematica.length();i++){
		simbolo=expmatematica[i];
		if(simbolo == '('){
			pila.agregarPila(simbolo); 
		}else{
			if(simbolo==')'){
				while(!pila.pilaVacia() && pila.cima() != '('){
					dato = pila.sacarPila();
					EPOS = EPOS + dato;
				}
				pila.sacarPila();
			}else{
				if(isalnum(simbolo)){
					EPOS=EPOS+simbolo;
				}else{
					while(!pila.pilaVacia()&&prioridad(pila.cima()>=prioridad(simbolo))){
						dato = pila.sacarPila();
						EPOS =EPOS + dato;
					}
					pila.agregarPila(simbolo);
				}
			}
		}
	}
	while(!pila.pilaVacia()){
		dato=pila.sacarPila();
		EPOS=EPOS+dato;
	}
	cout<<"EXPRESION POSTFIJA"<<EPOS<<endl;
	return true;
}
bool Pila::revisarApostfijaOperacionMatematica(const string& expmatematica){
	Pila temp;
	int tope;
	string EPOS="";
	char simbolo, dato;
	int i;
	int cont=0;
	int cont2=0;
	bool cen=true;
	for(i=0;i<expmatematica.length();i++){
		
		simbolo=expmatematica[i];
		
		if(simbolo=='('){
			cont=cont+1;
		}else{
			if(simbolo==')'){
				cont2=cont2+1;
				if(cont2>cont){
					cen=false;
				}
			}
		}

	}
	return (cen&&(cont==cont2));

}
bool esPalindromo(const string& palabra){
	Pila temp;
	int i, tamanio;
	
	tamanio = palabra.length() ;
	for(i=0;i<tamanio;i++){
		temp.agregarPila(palabra[i]);
	}
	for(i=0;i<tamanio;i++){
		if(palabra[i]!=temp.sacarPila()){
			return false;
		}
	}
	return true;
}

//menu
void menu(){
	Pila pila1;
	Pila pila2;
	int opcion;
	char dato;
	string palabra,operacion;
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
		cout<<"11. Determinar si una expresion matematica es correcta"<<endl;
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
				cout<<"Ingresa una operacion matematica"<<endl;
				cin>>operacion;
				pila1.infijaApostfijaOperacionMatematica(operacion);
				break;
				
			case 11:
				cout<<"Ingresa una operacion matematica"<<endl;
				cin>>operacion;
				cout<<"¿La operacion matematica "<<operacion<<" es correcta ?"<<( pila1.revisarApostfijaOperacionMatematica(operacion)?"Si":"No")<<endl;
				;
				break;
				
			case 0:
				cout<<"Programa finalizado."<<endl;
				break;
			default:
				cout<<"opcion invalida"<<endl;
		}
	} while(opcion != 0);
}
//funcion principal para probar la clase pila
int main(){
	setlocale(LC_ALL, "");
	//menu();
	Pila pila;
	
	cout<<"Agregando elementos a,b,c.."<<endl;
	pila.agregarPila('a');
	pila.agregarPila('b');
	pila.agregarPila('c');
	
	pila.mostrarPila();
	
	cout<<"Elemento en la cima: "<<pila.cima()<<endl;
	
	cout<<"Contiene el a?"<<(pila.buscarElementoPila('a')?"Si": "No")<<endl;
	cout<<"Contiene el b?"<<(pila.buscarElementoPila('b')?"Si": "No")<<endl;
	
	cout<<"Sacando un elemento..."<<endl;
	pila.sacarPila();
	
	pila.mostrarPila();
	
	cout<<"TOTAL DE ELEMENTOS: "<<pila.contarElementosPila()<<endl;
	
	//probar comparacion
	
	Pila pila2;
	pila2.agregarPila('a');
	pila2.agregarPila('b');
	pila2.mostrarPila();
	
	cout<<"Las pilas son iguales ? "<<(pila.compararCon(pila2)?"Si":"No")<<endl;
	
	string expresion;
	//cout<<"ingrese la operacion matematica: ;
	//cin<<expresion;
	
	expresion= "((3+4)*(8+3**2))";
	//exprecion = "(3+4)*(8+3**2));
	
	if(pila.revisarApostfijaOperacionMatematica(expresion)){
		cout<<"LA EXPRESION MATEMATICA"<<expresion << " es correcta"<<endl;
	}else{
		cout<<"La expresion matematica"<<expresion<<"es incorrecta"<<endl;
	}
	return 0;
}