/*En una lista simplemente enlazada con los valores de 
ingrse un dato despues de una posicon
1 3 5 7
pos = 3
dato = 6
1 3 5 6 7
*/
#include<iostream>
using namespace std;

struct nodo{
	int inf;
	nodo *sig;	
};

nodo *insertarDespues(nodo *p, int pos ,int dato){
	int i=1;
	if(p!=NULL){
		nodo *q;
		q=p;
		
		while(q!=NULL&&i!=pos){
			i++;
			q=q->sig;
		}
		if(q==NULL){
			cout<<"La posicon ingresada no existe en la lista"<<endl;
		}else{
			nodo *r;
			r=new nodo();
			r->inf=dato;
			r->sig=q->sig;
			q->sig=r;
		}
		
	}else{
		cout<<"La lista esta vacia"<<endl;
	}
	return(p);
}

nodo *insertarFinal(nodo *p, int dato){
	nodo *q,*t;
	q=p;
	if(p==NULL){
		t=new nodo();
		t->inf=dato;
		t->sig=p;
		p=t;
	}else{
		while(q->sig!=NULL){
			q=q->sig;
		}
		
		t=new nodo();
		t->inf=dato;
		t->sig=q->sig;
		q->sig=t;
	}
	
	return(p);
}
void mostrar(nodo *p){
	nodo *q;
	q=p;
	if(q!=NULL){
		while(q!=NULL){
			cout<<q->inf<<" ";
			q=q->sig;
		}
		
	}else{
		cout<<"La lista esta vacia"<<endl;
	}

}
int main(){
	nodo *p=NULL;
	p=insertarFinal(p,1);
	p=insertarFinal(p,2);
	p=insertarFinal(p,5);
	p=insertarDespues(p,3,4);
	mostrar(p);
	p=insertarDespues(p,3,4);
	mostrar(p);
	system("pause");
	
	
	return 0;
}
