#include<iostream>
#include<string>
using namespace std;
struct nodo {
	int info;
	char info2;
	nodo* liga;
};
class Pila{
	private:
		nodo* tope;
	public:
		Pila(){
			tope=NULL;
		}
		//metodo para agregar un elemento a la pila
		void agregarPila(int dato){
			nodo* q = new nodo;
			q->info=dato;
			q->liga=tope;
			tope=q;
		}
		//metodo para eliminar (sacar) el elemento superior de la pila
		void sacarPila(){
			if(tope!=NULL){
				nodo* q=tope;
				tope=q->liga;
				delete q;
			}
			else
			{
				cout<<"Pila vacia, no se puede sacar elemento. "<<endl;
				return;
			}
		}
		void mostrarPila(){
			if(tope!=NULL){
				nodo* q=tope;
				cout<<"Los elementos de la pila son: "<<endl;
				while(q!=NULL){
					cout<<q->info<<" ";
					q=q->liga;
				}
				cout<<endl;
			}
			else
			{
				cout<<"Pila vacia. "<<endl;
				return;
			}
			
		}
		
		int contarElementosPila(){
			nodo *q;
			int i=0;
			q=tope;
			while(q!=NULL){
				i=i+1;
				q=q->liga;
			}
			return i;
		}
		bool buscarElementoPila(int dato){
			int ban=0; 
			nodo *q;
			q=tope;
			if(q==NULL){
				cout<<"Pila vacia"<<endl;
			}
			else
			{
				while(q!=NULL){
					if(q->info==dato){
						ban=1;
					}
					q=q->liga;
				}
				if(ban==1){
					//cout<<"Se encontro el dato"<<endl;
				}
				else
				{
					//cout<<"No se encontro el dato"<<endl;
				}
			}
			return ban;
		}
		bool compararCon(Pila& pila1,Pila& pila2){
			nodo *q,*s;
			
			q=pila1.tope;
			s=pila2.tope;
			int ban=0;
			while((q!=NULL)||(s!=NULL)){
				if(q->info==s->info){
					ban=1;
				}
				q=q->liga;
				s=s->liga;
			}
			if(ban==1){
				return true;
			}
			return false;
		}
		
		bool palindromo(Pila& pila1){
			nodo *q,*r,*s;
			int ban=0;
			Pila temp;
			q=pila1.tope;
			
			while (q!=NULL){
				temp.agregarPila(q->info);
				q=q->liga;
			}
			r=temp.tope;
			while(r!=NULL){
				cout<<r->info<<" ";
				r=r->liga;
			}
			q=pila1.tope;
			r=temp.tope;
			while((q!=NULL&&r!=NULL)){
				if(q->info==r->info){
					ban=1;
				}
				else
				{
					ban=0;
				}
				q=q->liga;
				r=r->liga;
			}
			if(ban==1){
				return true;
			}
			else
			{
				return false;
			}
		}
		~Pila(){
			while(tope!=NULL){
				sacarPila();
			}
		}
		bool esPalindromo(const string& palabra1){
			nodo *q,*r;
			int ban=0;
			Pila letras;
			Pila letras2;
			
			for(int i=0;i<palabra1.length();i++){ //la parte de palabra1.lenght es para saber el tamaño del string
				q = new nodo;
				q->info2=palabra1[i];
				q->liga=letras.tope;
				letras.tope=q;
			}
			//insertando la cadena de testo palabra 1
			
			while(q!=NULL){
				r=new nodo;
				r->info2=q->info2;
				r->liga=letras2.tope;
				letras2.tope=r;
				q=q->liga;
			}
			q=letras.tope;
			r=letras2.tope;
			while((q!=NULL&&r!=NULL)){
				if(q->info2==r->info2){
					ban=1;
				}
				else
				{
					ban=0;
				}
				q=q->liga;
				r=r->liga;
			}
			if(ban==1){
				return true;
			}
			else
			{
				return false;
			}
	
		}
};
void menu(){
	Pila pila1;
	Pila pila2;
	Pila palabra1;
	string palabra;
	int opcion, dato,op;
	
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
				pila1.buscarElementoPila(dato);
				cout<<"¿Esta el "<<dato<<" ?: "<<(pila1.buscarElementoPila(dato)?"Si":"No")<<endl;
				break;
			case 6:
				cout<<"Ubgrese dato a apilar en Pila 2: ";
				cin>>dato;
				pila2.agregarPila(dato);
				break;
			case 7:
				pila2.mostrarPila();
				break;
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
			case 0:
				cout<<"Porgrama finalizado. "<<endl;
				break;
			default:
				cout<<"Opcion invalida. "<<endl;
		}	
	} while(opcion!=0);
}
int main(){
	setlocale(LC_ALL, "");
	menu();
	return 0;
}