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
//inserta desde el final
void inserta_final(nodo *&p, nodo *&f, int dato){
	nodo *q;
	
	q=new nodo();
	q->inf=dato;
	if(f==NULL){
		p=f=q;
	}else{
		f->der=q;
		q->izq=	f;
		q->der=NULL;
		f=q;
	}
	
}
//mostrar por el final
void mostrar_f(nodo *&p, nodo *&f){
	nodo *q;
	q=f;
	if(q!=NULL)	{
		while(q=NULL){
			cout<<q->inf<< " ";
			q=q->izq;
		}
	}else{
		cout<<"El arregloe sta vacio"<<endl;
	}
}

//mostrar por el inicio
void mostrar_i(nodo *&p, nodo *&f){
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

//inserta antes de x
void inserta_antes_x(nodo *&p, int dato, int x){
	nodo *q,*t,*r;
	
	q=p;
	while(q->der!=NULL && q->inf!=x){
		q=q->der;
	}
	if(q->inf==x){
		t=new nodo();
		
		t->inf=dato;
		t->der=q;
		
		r=new nodo();
		r=q->izq;
		q->izq=t;
		if(p==q){
			p=t;
			t->izq=NULL;
		}else{
			r->der=t;
			t->izq=r;
		}

	}else{
		cout<< "No se encontro el dato  referencial ingresado"<<endl;
	}
}
int main(){
	nodo *p=NULL;
	nodo *f=NULL;
	int dato, i=0,x;
	//inserta desde el final
	do{
		cin>>dato;
		inserta_final(p,f,dato);
		i++;
		mostrar_i(p,f);
	}while(i!=4);
	
	//inserta antes de x
	cin>>x; //dato referencial
	cin>>dato; //dato que voy a insertar
	inserta_antes_x(p,dato,x);
	
	mostrar_i(p,f);
	
	
	//inserta desde el principio
	do{
		cin>>dato;
		inserta_principio(p,f,dato);
		i++;
		mostrar_i(p,f);
	}while(i!=3);
	
	//inserta desde el final
	do{
		cin>>dato;
		inserta_final(p,f,dato);
		i++;
		mostrar_i(p,f);
	}while(i!=3);
	
	//mostar por el final
	mostrar_f(p,f);
	
	//mostrar por el inicio
	mostrar_i(p,f);
	return 0;
}