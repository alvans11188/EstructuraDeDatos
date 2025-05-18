//LISTAS DOBLEMENTE ENLAZADAS
#include<iostream>
using namespace std;

struct nodo{
	int inf;
	nodo *der;
	nodo *izq;	
};
//inserta desde el principio
void inserta_principio(nodo *&p, nodo *&f, int dato){
	nodo *q;
	q=new nodo();
	q->inf=dato;
	if(p==NULL){
		p=f=q;
	}else{
		q->der=p;
		p->izq=q;
		q->izq=NULL;
		p=q;
	}
}

//mostrar por el final

//mostrar por el inicio
void mostrar(nodo *&p, nodo *&f){
	nodo *q;
	q=p;
	if(q!=NULL){
		while(q!=NULL){
			cout<<q->inf<< " ";
			q=q->der;
		}
		
	}else{
		cout<<"EL arreglo esta vacio"<<endl;
	}
}


int main(){
	nodo *p=NULL;
	nodo *f=NULL;
	int dato, i=0;
	
	//inserta desde el principio
	do{
		cin>>dato;
		inserta_principio(p,f,dato);
		i++;
		mostrar(p,f);
	}while(i!=3);
	//mostar por el final
	mostrar_f(p,f);
	
	//mostrar por el inicio
	mostrar(p,f);
	return 0;
}