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
//inserta despues de un rato referencial
void inserta_despues_x(nodo *&p, nodo *&f, int dato, int x){
	nodo *q,*t,*r;
	q=p;
	while(q->der!=NULL && q->inf!=x){
		q=q->der;
	}
	if(q->inf==x){
		t=new nodo();
		
		t->inf=dato;
		t->izq=q; //cabmia aca de der a izq
		
		
		r=q->der; //cambia aca de izq a der
		q->der=t; //cambia de izq a der 
		if(f==q){
			f=t;
			t->der=NULL; //igual cambia
		}else{
			r->izq=t;
			t->der=r;
		}

	}else{
		cout<< "No se encontro el dato  referencial ingresado"<<endl;
	}
}
void invertir(nodo *&p, nodo *&f){
	nodo *temp,*q;
	q=p;
	temp=NULL;
	while(q!=NULL){
		temp=q->izq;
		q->izq=q->der;
		q->der=temp;
		q=q->izq;
	}
	temp=p;
	p=f;
	f=temp;
}
//elimina el inicio de la lsita
void elimina_i(nodo *&p,nodo*&f){
	nodo *q;
	q=p;
	if(q->der!=NULL){
		p=q->der;
		p->izq=NULL;
		
	}else{
		p=NULL;
		f=NULL;
	}
	delete(q);
	
}
//elimina el ultimo de la lsita
void elimina_u(nodo *&p,nodo*&f){
	nodo *q;
	q=f;
	if(q->izq!=NULL){
		f=q->izq;
		f->der=NULL;
		
	}else{
		p=NULL;
		f=NULL;
	}
	delete(q);
}
//elimina un nodo con dato x
void elimina_x(nodo *&p,nodo *&f,int x){
	nodo *q,*t,*r;
	q=p;
	while(q->der!=NULL&&q->inf!=x){
		q=q->der;
	}
	if(q->inf==x){
		if(q==p&&q==f){
			p=NULL;
			f=NULL;
		}else{
			if(q==p){
				p=q->der;
				p->izq=NULL;
			}else{
				if(q==f){
					f=q->izq;
					f->der=NULL;
				}else{
					t=q->izq;
					r=q->der;
					t->der=r;
					r->izq=t;
				}
				
			}
		}
	}else{
		cout<<"El elemento no se encontro en la lista"<<endl;
	}
}
void elimina_antes_x(nodo *&p, nodo*&f,int x){
	nodo *q,*r,*t;
	q=p;
	while(q->der!=NULL&&q->inf!=x){
		q=q->der;
	}
	if(q->inf==x){
		if(p==q){
			cout<<"No existe nodo anterior al primero"<<endl;
		}else{
			t=q->izq;
			if(t==p){
				p=q;
				p->izq=NULL;
			}else{
				r=t->izq;
				q->izq=r;
				r->der=q;
			}
		}
		delete(t);
	}else{
		cout<<"El elemento no se encontro en la lista"<<endl;
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
	}while(i!=3);
	//elimina un nodo antes de x
	cin>>x;
	elimina_antes_x(p,f,x);
	mostrar_i(p,f);
	
	//elimina un nodo con informacion x
	cin>>x;
	elimina_x(p,f,x);
	mostrar_i(p,f);
	
	//eliminar ultimo
	elimina_u(p,f); cout<<endl;
	mostrar_i(p,f);
	system("pause");
	//eliminia el inicio de la lista
	elimina_i(p,f); cout<<endl;
	mostrar_i(p,f);
	system("pause");
	
	//invertir una lista
	
	invertir(p,f);
	mostrar_i(p,f);
	
	//insercion despues de un nodo con dato x
	cin>>x;
	cin>>dato;
	inserta_despues_x(p,f,dato,x);
	mostrar_i(p,f);
	
	
	
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