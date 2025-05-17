#include <iostream>
using namespace std;

struct nodo{
	int inf;
	nodo *sig;	
};

nodo *crea_i(nodo *p){
	int dato;
	nodo *q;
	char op;
	do{
		q=new nodo();
		cout<<"Ingrese el dato: ";
		cin>>q->inf;
		q->sig=p;
		p=q;
		cout<<"OTRO DATO (S/N)";
		cin>>op;
	}while(op=='s'||op=='S');
	
	return(p);
}

nodo *crea_f(nodo *p){
	nodo *q,*r;
	char op;
	do{
		q=new nodo();
	
		cout<<"Ingrese el dato: ";
		cin>>q->inf;
		q->sig=NULL;
		if(p==NULL){
			p=q;
		}else{
			r->sig=q;
		}
		r=q;
		cout<<"OTRO DATO (S/N)";
		cin>>op;
	}while(op=='s'||op=='S');
	
	
	return(p);
}

void mostrar(nodo *p){
	nodo *q;
	
	q=p;

	cout<<"P - >";
	while(q!=NULL){
		cout<<q->inf<<" - > ";
		q=q->sig;
	}
	cout<<" NULL "<<endl;
	
}
int main(){
	
	nodo *p;
	p=NULL;
	cout<<"LISTA 1"<<endl;
	p=crea_i(p);
	mostrar(p);
	p=NULL;
	cout<<"LISTA 2"<<endl;
	p=crea_f(p);
	mostrar(p);
	
	return 0;
}