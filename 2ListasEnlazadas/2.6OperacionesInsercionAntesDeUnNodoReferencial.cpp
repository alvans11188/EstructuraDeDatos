/*2.6 INSERCION ANTES DE UN NODO REFERENCIAL
-Se usa 2 punteros auxiliares
se inserta antes de un nodo especifcio
Para esto seguiremos las siguientes instrucciones
1- verificar si esta la lista vacia comprobando si p=null
2- verificar si r->sig!=null si es verdad que q salte r, pero antes anexar el nodo auxiliar s
3- si lo encuentra se crea un nuevo nodo
4- se carga la informacion
5- se engancha ese nuevo nodo
* se usara r cuando el refrencial se entre al inicio
*/
#include<iostream>
using namespace std;

struct nodo
{
	int inf; //campo de informacion
	nodo *sig;	//campo de enlace
};
nodo *crea_i(nodo *);
nodo *inserta_i(nodo *);
nodo *inserta_f(nodo *);
void recorre(nodo *);
nodo *inserta_ad(nodo *, int);

int main()
{
	int op,ref;
	nodo *p=NULL;
	do
	{
		system("cls");
		cout<<"\t\tPROGRAMA DE OPERACIONES EN UNA LISTA ENLAZADA\n"<<endl;
		cout<<"\t1-  Crear por el inicio"<<endl;
		cout<<"\t2-  Insertar por el inicio"<<endl;
		cout<<"\t3-  Insertar por el final"<<endl;
		cout<<"\t4-  Mostrar"<<endl;
		cout<<"\t5-  Insertar antes de un nodo referencial"<<endl;
		cout<<"\t13- S A L I R"<<endl;
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
			case 5:
				{
					system("cls");
					cout<<"Valor buscado para la insercion anterior al buscado: ";
					cin>>ref;
					p=inserta_ad(p,ref);
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
	}while(op!=13);
	
	
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
	system("cls");
	cout<<"Insertando dato al inicio"<<endl;
	cout<<"Ingrese el dato que desea inserta: "<<endl;
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
	return p; 
}
nodo* inserta_ad(nodo *p,int ref)
{
	nodo *q,*s,*r;
	int cen;
	if(p!=NULL)
	{
		r=p;
		cen=0;
		while((r->inf!=ref)&&(cen==0))
		{
			if(r->sig!=NULL)
			{
				s=r;
				r=r->sig;
			}
			else
				cen=1;
		}
		if(cen==0)
		{
			q=new(nodo);
			system("cls");
			cout<<"VALOR REFERENCIAL ENCONTRADO"<<endl;
			cout<<"Ingrese un valor que quiere que vaya antes del referencial"<<endl;
			cin>>q->inf;
			if(p==r)
				p=q;
			else
				s->sig=q;
			q->sig=r;
		}
		else
			cout<<"No existe el dato referencial"<<endl;
	}
	else
	{
		system("cls");
		cout<<"La lista esta vacia"<<endl;		
	}

	return p;
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