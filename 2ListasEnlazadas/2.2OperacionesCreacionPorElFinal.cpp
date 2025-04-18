/*2.2Creacion de la lista por el final
Los pasos a seguir seran:
1- apartir de null se creara la lista
2- crfeamos un nodo a q= new (nodo)
3- luego se le inserta informacion cin>>q->inf
4- el nodo apunta a null q->sig=null

si se aplica en un programa mas grande, se tiene que reportar P
retorna P debido a que al comienzo P apuntara hacia NULL pero despues de crear el primer valor pasara a apuntar a ese valor creado y asi sucesivamente
por lo tanto es necesario retornar P
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
		q=new(nodo); //apartir de aca cambia el condigo comparandolo con el de creacion por el inicio
		
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