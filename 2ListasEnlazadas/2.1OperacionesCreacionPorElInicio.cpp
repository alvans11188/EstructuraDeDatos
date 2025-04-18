/*2.1Creacion por el inicio
Primero se crea un punto de cabecera que apunte a null indicando que esta vacio
q->inf // es un atributo
Los pasos a seguir son los siguientes 
 1- Creo mi variable cabecera para asegurarme que apunte a null
 2- despues de crear q se creara un nuevo nodo
 3- luego de crear el nodo se carga la informacion 
 4- haremos que q->sig = p
 5- y hacer que p=q
 6- escribir si quieres mas datos S/N
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