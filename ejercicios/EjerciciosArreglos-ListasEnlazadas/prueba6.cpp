#include<iostream>

using namespace std;

struct nodo{
	int inf;
	nodo *liga;
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
			nodo *q;
			q=new nodo();
			q->inf=dato;
			q->liga=tope;
			tope=q;
		}
		void mostrar(){
			if(tope!=NULL){
				nodo *q;
				q=tope;
				while(q!=NULL){
					cout<<q->inf<<" ";
					q=q->liga;
				}
			}else{
				cout<<"Pila vacia"<<endl;
			}
		}
};
int main(){
	
	Pila pila1;
	Pila pila2;
	int i=0,dato;
	//agregar  a la pila
	do{
		cin>>dato;
		pila1.agregarPila(dato);
		i++;
		pila1.mostrar();
	}while(i!=3);
	
	
	
	
	
	return 0;
}