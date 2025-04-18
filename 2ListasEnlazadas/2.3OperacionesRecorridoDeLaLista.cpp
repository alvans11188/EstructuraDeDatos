/*2.3 RECORRIDO DE LA LISTA
Se usara un puntero auxiliar, nunca debera ser movido este y debera estar enganchado a la cabecera
hay que ir recorriendo la lista con un nodo auxiliar
si apunta a null acaba la lista sino sala a q
la cabecera nose modifica es un recorrido iterativo
*/
#include<iostream>
using namespace std;

struct nodo
{
	int inf; //campo de informacion
	nodo *sig;	//campo de enlace
};
void recorre(nodo *);
int main()
{
	nodo *p,*q,*r;
	char op;
	cout<<"CREACION DE LISTA POR EL FINAL"<<endl;
	p=NULL;
	do
	{
		q=new(nodo); 
		
		cout<<"Ingresa otro numero"<<endl;
		cin>>q->inf;
		q->sig=NULL;
		if(p==NULL)
			p=q;
		else
			r->sig=q;
		r=q;
		
		cout<<"Desea ingresar mas dato?(S/N) ";
		cin>>op;
	}while((op=='s'||op=='S'));
	
	recorre(p); //Funcion para recorrer la lista
	
	return 0;
}

void recorre(nodo *p)
{
	nodo *q;
	
	q=p;
	cout<<"\n\n\tLISTA DE DATOS: \n";
	cout<<"\t===============";
	while(q!=NULL)
	{
		cout<<"\n\n\t\t"<<q->inf;
		q=q->sig;
	}
	cout<<"\n\n\t\t\t";
}