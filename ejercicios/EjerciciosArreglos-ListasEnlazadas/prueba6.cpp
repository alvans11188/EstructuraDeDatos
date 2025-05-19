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
		void contarElementos(){
			nodo *q;
			q=tope;
			int i=0;
			while(q!=NULL){
				i++;
				q=q->liga;
			}
			cout<<"El numero de elementos eS: "<< i <<endl;
		}
		void buscar_elemento(int dato){
			nodo *q;
			q=tope;
			while(q->liga!=NULL&&q->inf!=dato){
				q=q->liga;
			}
			if(q->inf==dato){
				cout<<"El dato "<< dato << " si se encuentra en la pila"<<endl;
			}else{
				cout <<"El dato no se encuentra"<<endl;
			}
		}
		void compararPilas(Pila& pila1, Pila& pila2){
			nodo *q,*s;
			q=pila1.tope;
			s=pila2.tope;
			while(q!=NULL&&s!=NULL){
				if(q->inf!=s->inf){
					cout<<"Las pilas son diferentes"<<endl;
					return;
				}
				q=q->liga;
				s=s->liga;
			}
			
			if(q==NULL&&s==NULL){
				cout<<"Las pilas son iguales"<<endl;
			}else{
				cout<<"Las pilas son diferentes"<<endl;
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
		pila2.agregarPila(dato);
		i++;
		
	}while(i!=3);
	pila1.agregarPila(5);
	pila1.mostrar(); cout<<endl;
	pila2.mostrar();
	//comparar con la otra pila
	pila1.compararPilas(pila1,pila2);
	
	//buscar elemento pila
	do{
		cin>>dato;
		pila1.buscar_elemento(dato);
	}while(true);
	

	// contar elementos
	pila1.contarElementos();
	//mostrar pila
	pila1.mostrar();
	
	
	
	return 0;
}