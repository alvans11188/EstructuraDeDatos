#include<iostream>

using namespace std;

struct nodo{
	int inf;
	nodo *sig;	
};

nodo *crea_i(nodo *p){
	nodo *q;
	q=new nodo();
	cout<<"Ingrese un dato: ";
	cin>>q->inf;
	q->sig=p;
	p=q;
	return(p);
}
void mostrar(nodo *p){
	nodo *q;
	q=p;
	while(q!=NULL){
		cout<<q->inf<<" ";
		q=q->sig;
	}
}
nodo *crea_f(nodo *p){
	nodo *q,*r;
	
	q= new nodo();
	cin>>q->inf;
	q->sig=NULL;
	if(p==NULL){
		p=q;
		
	}else{
		r=p;
		while(r->sig!=NULL){
			r=r->sig;
		}
		r->sig=q;
	}
	r=q;
		
	return(p);
}

nodo *insercion_i(nodo *p){
	nodo *q,*r;
	q=new nodo();
	cin>>q->inf;
	q->sig=p;
	p=q;
	
	return(p);
}

nodo *insercion_f(nodo *p){
	nodo *q,*r;
	//lo mismo que crear por el final
	q= new nodo();
	cin>>q->inf;
	q->sig=NULL;
	if(p==NULL){
		p=q;
		
	}else{
		r=p;
		while(r->sig!=NULL){
			r=r->sig;
		}
		r->sig=q;
	}
	r=q;
	return(p);
	
}
nodo *referencial_ad(nodo *p, int ref){
	nodo *q,*r,*t;
	int cen;
	if(p!=NULL){
		q=p;
		cen=0;
		while(q!=NULL&&q->inf!=ref){
			r=q;
			if(q->sig!=NULL){
				q=q->sig;
			}else{
				cen=1;
			}
		}
		if(cen==0){
			cout<<"Dato referencial encontrado: ";
			t=new nodo();
			cin>>t->inf;
			if(q==p){
				t->sig=q;
				p=t;
			}else{
				t->sig=q;
				r->sig=t;
			}
		}
	}else{
		cout<<"La lista esta vacia"<<endl;
		return(p);
	}
	return(p);
}
nodo *referencial_dd(nodo *p,int ref){
	nodo *q,*r,*t;
	int cen;
	if(p!=NULL){
		q=p;
		cen=0;
		while(q!=NULL&&q->inf!=ref){
			r=q;
			if(q->sig!=NULL){
				q=q->sig;
			}else{
				cen=1;
			}
		}
		if(cen==0){
			cout<<"Dato referencial encontrado: ";
			t=new nodo();
			cin>>t->inf;
			
			t->sig=q->sig;
			q->sig=t;
		}else{
			cout<<"Dato referencial no encotnrado"<<endl;
		}
	}else{
		cout<<"La lista esta vacia"<<endl;
		return(p);
	}
	return(p);
}
nodo *eliminar_p(nodo *p){
	nodo *q;
	if(p!=NULL){
		q=p;
		p=q->sig;
		delete(q);
	
	}else{
		cout<<"Lista vacia"<<endl;
	}

	return(p);
}
nodo *eliminar_u(nodo *p){
	nodo *q,*r;
	q=p;
	if(q!=NULL){
		
		while(q->sig!=NULL){
			r=q;
			q=q->sig;
		}
		if(q==p){
			p=NULL;
			
		}else{
			r->sig=NULL;
			
		}
		delete(q);
	}else{
		cout<<"La lista esta vacia"<<endl;	
	}
	
	return(p);
}

nodo *eliminar_x(nodo *p, int dato){
	nodo *q,*r;
	q=p;
	
	if(p!=NULL){
		
		while(q!=NULL&&q->inf!=dato){
			r=q;
			q=q->sig;
		}
		
		if(q==p){
			cout<<"El dato a eliminar fue el primero"<<endl;
			p=q->sig;
			delete(q);
		}else{
			if(q->inf==dato){
			cout<<"Se encontro el dato a eliminar"<<endl;
			r->sig=q->sig;
			delete(q);
			
			}else{
				cout<<"dato no encontrado en la lista"<<endl;
			}
		}	
	}else{
		cout<<"LA LISTA ESTA VACIA"<<endl;
	}
	return(p);
}
nodo *eliminar_concurrencias(nodo *p,int dato){
	nodo *q,*r,*s;
	if(p!=NULL){
		q=p;
		s=NULL;
		while(q!=NULL){
			if(q->inf==dato){
				r=q;
				if(s==NULL){
					p=q->sig;
					q=p;
				}else{
					s->sig=q->sig;
					q=q->sig;
				}
				delete(r);
				cout<<"se elimino el nodo "<<endl;
			}else{
				s=q;
				q=q->sig;
			}
		}
		
	}else{
		cout<<"La lista esta vacia"<<endl;
	}
	return(p);
}
int main(){
	nodo *p;
	p=NULL;
	int op,ref,i=0,dato;
	//FUNCION APRA PRUEBAS
	//insercion por el final
	do{
		p=insercion_f(p);
		i++;
		mostrar(p);
	}while(i!=5);
	
	
	//eliminar concurrencias
	cout<<"Ingrese el dato a eliminar"<<endl;
	cin>>dato;
	p=eliminar_concurrencias(p,dato);
	mostrar(p);
	system("pause");
	
	//eliminar nodo con informacion X
	cout<<"Ingrese el dato a eliminar"<<endl;
	cin>>dato;
	p=eliminar_x(p,dato);
	cout<<"\nvalor eliminado"<<endl;
	mostrar(p);
	cout<<"Ingrese el dato a eliminar"<<endl;
	cin>>dato;
	p=eliminar_x(p,dato);
	cout<<"\nvalor eliminado"<<endl;
	mostrar(p);
	
	
	//eliminar el ultimo nodo
	p=eliminar_u(p);
	cout<<"\nvalor eliminado"<<endl;
	mostrar(p);
	
	//Eliminar el primer nodo
	p=eliminar_p(p);
	cout<<"\nvalor eliminado"<<endl;
	mostrar(p);
	
	
	//insercion despues de un referencial
	do{
		cout<<"Referencial: ";
		cin>>ref;
		p=referencial_dd(p,ref);
		i++;
		mostrar(p);
	}while(i!=5);
	
	
	//insercion antes de un referencial
	do{
		cout<<"Referencial: ";
		cin>>ref;
		p=referencial_ad(p,ref);
		i++;
		mostrar(p);
	}while(i!=5);
	
	//insercion por el final
	do{
		p=insercion_f(p);
		i++;
		mostrar(p);
	}while(i!=5);
	
	//insercion por el inicio
	do{
		p=insercion_i(p);
		i++;
		mostrar(p);
	}while(i!=5);
	
	//crear por el final
	do{
		p=crea_f(p);
		i++;
		mostrar(p);
	}while(i!=5);
	
	mostrar(p);
	
	
	//crear por el inicio
	do{
		p=crea_i(p);
		i++;
	}while(i!=5);
	
	mostrar(p);
	
	
	
	
	
	return 0;
}