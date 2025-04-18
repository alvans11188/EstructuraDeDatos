/*2.1Creacion por el inicio
Primero se crea un punto de cabecera que apunte a null indicando que esta vacio
q->inf // es un atributo
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
	nodo *p,*q;
	char op;
	cout<<"CREACION DE LISTA POR EL INICIO"<<endl;
	p=NULL;
	do
	{
		q=new(nodo);
		cin>>q->inf;
		q->sig=p;
		p=q;
		cout<<"Desea ingresar mas dato?(S/N) ";
		cin>>op;
	}while((op=='s'||op=='S'));
	recorre(p);
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