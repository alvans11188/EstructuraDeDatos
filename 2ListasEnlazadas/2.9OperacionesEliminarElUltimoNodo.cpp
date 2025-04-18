/*2.9 ELIMINAR EL ULTIMO NODO
pasos:
1- existe un caso particular cuando solo se tiene 1 nodo
2- verificar si !=null, significa que hay nodos y por lo tanto es necesario recorrer la lista hasta encontrar el ultimo y eliminarlo
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
nodo *inserta_dd(nodo *, int);
nodo *elimina_p(nodo *);
nodo *elimina_u(nodo *);

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
		cout<<"\t6-  Insertar despues de un nodo referencial"<<endl;
		cout<<"\t7-  Eliminar el primer nodo"<<endl;
		cout<<"\t8-  Eliminar el ultimo nodo"<<endl;
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
			case 6:
				{
					system("cls");
					cout<<"Valor buscado para la insercion despues al buscado: ";
					cin>>ref;
					p=inserta_dd(p,ref);
					system("pause");
					break;
				}
			case 7:
				{
					system("cls");
					p=elimina_p(p);
					system("pause");
					break;
				}
			case 8:
				{
					system("cls");
					p=elimina_u(p);
					system("pause");
					break;
				}
			case 13:
				{
					cout<<"\n\t\tS A L I E N D O   D E L   P R O G R A M A "<<endl;
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
nodo *inserta_dd(nodo *p,int ref)
{
	nodo *r,*q;
	int cen;
	if(p!=NULL)
	{
		r=p;
		cen=0;
		while((r->inf!=ref)&&(cen==0))
		{
			if(r->sig!=NULL)
				r=r->sig;
			else
				cen=1;
		}
		if(cen==0)
		{
			q=new(nodo);
			cout<<"VALOR REFERENCIAL ENCONTRADO"<<endl;
			cout<<"Ingrese un valor: ";
			cin>>q->inf;
			q->sig=r->sig;
			r->sig=q;
		}
		else
			cout<<"El dato referencial no existe"<<endl;
	}
	else
		cout<<"La lista esta vacia"<<endl;
	return p;
}
nodo *elimina_p(nodo *p)
{
	nodo *q;
	if(p!=NULL)
	{
		q=p;
		p=p->sig;
		delete(q);
	}
	else
		cout<<"Lista vacia"<<endl;
	return p;
}
nodo *elimina_u(nodo *p)
{
	nodo *q,*r;
	if(p!=NULL)
	{
		q=p;
		if(q->sig==NULL)
		{
			p=NULL;
		}
		else
		{
			while(q->sig!=NULL)
			{
				r=q;
				q=q->sig;
			}
			r->sig=NULL;
		}
	}
	else
	{
		cout<<"Lista vacia"<<endl;
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