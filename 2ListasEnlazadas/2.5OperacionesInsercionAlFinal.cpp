/*2.5 INSERCION AL FINAL DE LA LISTA
1-Existe 2 obciones que la lista este cargada o que este vacio(si esta vacio no pasara al while)
2-crearemos el nodo
3- cargamos informacion con el operador cin>>q->inf
4- aremos que q->sig apunte a null
5- siempre podria  ser dejar un puntero al final, solo para insercion
*/
#include<iostream>
using namespace std;

struct nodo
{
	int inf; //campo de informacion
	nodo *sig;	//campo de enlace
};
nodo *inserta_i(nodo *);
void recorre(nodo *);
nodo *crea_i(nodo *);
nodo *inserta_f(nodo *);
int main()
{
	int op;
	nodo *p=NULL;
	do
	{
		system("cls");
		cout<<"\t\tPROGRAMA DE OPERACIONES EN UNA LISTA ENLAZADA\n"<<endl;
		cout<<"\t1- Crearpor el inicio"<<endl;
		cout<<"\t2- Insertar por el inicio"<<endl;
		cout<<"\t3- Insertar por el final"<<endl;
		cout<<"\t4- Mostrar"<<endl;
		cout<<"\t5- S A L I R "<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				{
					system("cls");
					//p=NULL;
					p=crea_i(p);
					break;
				}
			case 2:
				{
					system("cls");
					//p=NULL;
					p=inserta_i(p);
					break;
				}
			case 3:
				{
					system("cls");
					
					p=inserta_f(p);
					system("pause");
					break;
				}
			case 4:
				{
					system("cls");
					
					recorre(p);
					system("pause");
					break;
				}
			default:
				{
					system("cls");
					cout<<"OBCION INVALIDA INGRESE UN NUEVO VALOR";
					system("pause");
					break;
				}
		}
	}while(op!=5);
	
	
	return 0;
}
nodo* crea_i(nodo *p)
{
	nodo *q;
	char op;
	cout<<"CREACION DE LISTA POR EL INICIO"<<endl;
	cout<<"Ingrese un valor: "<<endl;
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
	return p;
}
nodo* inserta_i(nodo *p)
{
	nodo *q;
	q=new(nodo);
	cin>>q->inf;
	q->sig=p;
	p=q;
	return p;
}
nodo* inserta_f(nodo *p)
{
	nodo *r, *q;
	q=new(nodo);
	system("cls");
	cout<<"Insertando dato al final"<<endl;
	cout<<"Ingrese el dato que desea inserta: "<<endl;
	cin>>q->inf;
	q->sig=NULL;
	r=p;
	if(r==NULL)
		p=q;
	else
		while(r->sig!=NULL)
			r=r->sig;
	r->sig=q;
	return p; //retorna p porque la direccion adonde apunta va a cambia
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