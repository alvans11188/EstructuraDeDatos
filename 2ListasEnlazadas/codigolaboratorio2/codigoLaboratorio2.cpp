#include<iostream>
using namespace std;
struct nodo
{
	char nomb[20];
	nodo *sig;
};
nodo *crea_i(nodo *);
nodo *crea_f(nodo *);
void recorre(nodo *);
nodo *inserta_i(nodo *);
nodo *inserta_f(nodo *);
nodo *inserta_ad(nodo *, char *);
nodo *inserta_dd(nodo *,char *);
nodo *eliminar_p(nodo *);
nodo *eliminar_u(nodo *);
nodo *eliminar_x(nodo *,char *);
nodo *eliminar_ad(nodo *,char *);
nodo *eliminar_dd(nodo *,char *);
int main()
{	
	char codigo[20];
	nodo *p=NULL;
	int op;
	do
	{
		system("cls");
		cout<<"\nLISTAS ENLAZADAS";
		cout<<"\n================";
		cout<<"\n\n1. CREAR POR EL INICIO";
		cout<<"\n\n2. CREAR POR EL FINAL";
		cout<<"\n\n3. INSERTAR AL INICIO";
		cout<<"\n\n4. INSERTAR AL FINAL";
		cout<<"\n\n5. INSERTAR ANTES DE";
		cout<<"\n\n6. INSERTAR DESPUES DE";
		cout<<"\n\n7. ELIMINAR EL PRIMER NODO";
		cout<<"\n\n8. ELIMINAR EL ULTIMO NODO";
		cout<<"\n\n9. ELIMINAR UN NODO ESPECIFICO";
		cout<<"\n\n10. ELIMINAR EL NODO ANTERIOR A ";
		cout<<"\n\n11. ELIMINAR EL NODO POSTERIOR A ";
		cout<<"\n\n12. M O S T R A R ";
		cout<<"\n\n13. S A L I R ";
		cout<<"\n\n\t\t\t OPCION: ";
		cin>>op;
		switch(op)
		{
			case 1:
				system("cls");
				p=NULL;
				p=crea_i(p);
				break;
			case 2:
				system("cls");
				p=NULL;
				p=crea_f(p);
				break;
			case 3:
				system("cls");
				p=inserta_f(p);
				break;
			case 4:
				system("cls");
				p=inserta_f(p);
				break;
			case 5:
				system("cls");
				cout<<"Ingrese un nombre referencial a buscar:";
				cin>>codigo;
				p=inserta_ad(p,codigo);
				break;
			case 6:
				system("cls");
				cout<<"Ingrese un nombre referencial a buscar :";
				cin>>codigo;
				p=inserta_dd(p,codigo);
				break;
			case 7:
				system("cls");
				p=eliminar_p(p);
				break;
			case 8:
				system("cls");
				p=eliminar_u(p);
				break;
			case 9:
				system("cls");
				cout<<"Ingrese un nombre a eliminar :";
				cin>>codigo;
				p=eliminar_x(p,codigo);
				break;
			case 10:
				system("cls");
				cout<<"Ingrese un nombre referencial a eliminar anteriormente :";
				cin>>codigo;
				p=eliminar_ad(p,codigo);
				break;
			case 11:
				system("cls");
				cout<<"Ingrese un nombre referencial a eliminar posteriormente :";
				cin>>codigo;
				p=eliminar_dd(p,codigo);
				break;
			case 12:
				system("cls");
				recorre(p);
				system("pause");
				break;
			case 13:
				cout<<" S A L I E N D O   D E L   P R O G R A M A  \n"<<endl;
				break;
		}
	}
	while(op>0&&op<13);	
	return 0;
}

nodo *crea_i(nodo *p)
{
	nodo *q;
	char op;
	do
	{
		system("cls");
		q=new(nodo);
		cout<<"\n\nNOMBRE   :  ";
		cin>>q->nomb;
		q->sig=p;
		p=q;
		cout<<"\n\n\t\t\tMAS DATOS (S/N)?   ";
		cin>>op;
	}
	while(op=='s'||op=='S');
	return(p);
}
nodo *crea_f(nodo *p)
{
	nodo *q,*r;
	char op;
	do
	{
		system("cls");
		q=new(nodo);
		cout<<"\n\nNOMBRE   :  ";
		cin>>q->nomb;
		q->sig=NULL;
		if(p==NULL)
			p=q;
		else
		{
			r->sig=q;
		}
		r=q;
		cout<<"\n\n\t\t\t MAS DATOS (S/N)?   ";
		cin>>op;
	}
	while(op=='s'||op=='S');
	return(p);
}
nodo *inserta_i(nodo *p)
{
	nodo *q;
	system("cls");
	cout<<"\n\nINSERTANDO DATO POR EL INICIO ... ";
	q=new(nodo);
	cout<<"\n\nNOMBRE   :  ";
	cin>>q->nomb;
	q->sig=p;
	p=q;
	return(p);
}
nodo *inserta_f(nodo *p)
{
	nodo *q,*r;
	system("cls");
	cout<<"\n\nINSERTANDO DATO POR EL FINAL   . ..";
	q=new(nodo);
	cout<<"\n\nNOMBRE   :  ";
	cin>>q->nomb;
	q->sig=NULL;
	r=p;
	if(p==NULL)
		p=q;
	else
	{
		while(r->sig!=NULL)
			r=r->sig;
		r->sig=q;
	}
	return(p);
}
nodo *inserta_ad(nodo *p,char *ref)
{
	nodo *q,*r,*s;
	int cen;
	if(p!=NULL)
	{
		r=p;
		cen=0;
		while((strcmp(r->nomb,ref))&&(cen==0))
		{
			if(r->sig!=NULL)
			{
				s=r;
				r=r->sig;
			}
			else
			{
				cen=1;
			}
		}
		if(cen==0)
		{
			q=new(nodo);
			cout<<"Ingrese el nombre que desea insertar despues del nombre referencial"<<endl;
			cin>>q->nomb;
			if(p==r)
			{
				p=q;
			}
			else
			{
				s->sig=q;
			}
			q->sig=r;
		}
		else
		{
			cout<<"No existe el nombre referencial"<<endl;
			system("pause");
		}
	}
	else
	{
		cout<<"LA LISTA ESTA VACIA"<<endl;
		system("pause");
	}
	return(p);
}
nodo *inserta_dd(nodo *p,char *ref)
{
	nodo *q,*r,*s;
	int cen;
	if(p!=NULL)
	{
		r=p;
		cen=0;
		while((strcmp(r->nomb,ref)&&(cen==0)))
		{
			if(r->sig!=NULL)
			{
				r=r->sig;
			}
			else
			{
				cen=1;
			}
		}
		if(cen==0)
		{
			q=new(nodo);
			cout<<"Ingrese el nombre que desea ingresar despues del nombre referencial"<<endl;
			cin>>q->nomb;
			q->sig=r->sig;
		}
		r->sig=q;
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
		system("pause");
	}
	return(p);
}
nodo *eliminar_p(nodo *p)
{
	nodo *q,*r,*s;
	int cen;
	if(p!=NULL)
	{
		q=p;
		p=p->sig;
		cout<<"Se esta eliminando ["<< q->nomb << " ]de la lista enlazada"<<endl;
		delete(q);
		system("pause");
		
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
		system("pause");
	}
	return(p);
}
nodo *eliminar_u(nodo *p)
{
	nodo *q,*r,*s;
	int cen;
	if(p!=NULL)
	{
		q=p;
		if(p->sig==NULL)
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
		cout<<"Se esta eliminando el nombre ( "<<q->nomb<<" ) de la lista enlazada"<<endl;
		delete(q);
		system("pause");
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
		system("pause");
	}
	return(p);
}
nodo *eliminar_x(nodo *p,char *ref)
{
	nodo *q,*r,*s;
	int cen;
	if(p!=NULL)
	{
		q=p;
		cen=0;
		while((strcmp(q->nomb,ref)&&(cen==0)))
		{
			if(q->sig!=NULL)
			{
				r=q;
				q=q->sig;
			}
			else
			{
				cen=1;
			}
		}
		if(cen==0)
		{
			if(p=q)
			{
				p=q->sig;
			}
			else
			{
				r->sig=q->sig;
			}
			cout<<"Se esta eliminando el nombre ( "<<q->nomb<<" ) de la lista enlazada"<<endl;
			delete(q);
			system("pause");
		}
		else
		{
			cout<<"El dato ("<<ref<<") no existe en la lista enlazada"<<endl;
			system("pause");
		}
		
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
		system("pause");
	}
	return(p);
}
nodo *eliminar_ad(nodo *p,char *ref)
{
	nodo *q,*r,*t;
	int cen;
	if(p!=NULL)
	{
		if(strcmp(p->nomb,ref)==0)
		{
			cout<<"No existe un nodo que precede al valor de "<<ref<<endl;;
			system("pause");
		}
		else
		{
			q=p;
			t=p;
			cen=1;
			while((strcmp(q->nomb,ref)&&(cen=1)))
			{
				if(q->sig!=NULL)
				{
					r=t;
					t=q;
					q=q->sig;
				}
				else
				{
					cen=0;
				}
			}
			if(cen==0)
			{
				cout<<"No existe el valor de x"<<endl;
				system("pause");
			}
			else
			if(p->sig==q)
			{
				p=q;
			}
			else
			{
				r->sig=q;
			}
			cout<<"Se esta eliminando el nombre ( "<<t->nomb<<" ) de la lista enlazada"<<endl;
			delete(t);
			system("pause");
		}
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
		system("pause");
	}
	return(p);
}
nodo *eliminar_dd(nodo *p,char *ref)
{
	nodo *q,*r,*t;
	int cen;
	if(p!=NULL)
	{
		q=p;
		t=p;
		cen=1;
		while(strcmp(q->nomb,ref)&&(cen==1))
		{
			if(q->sig!=NULL)
			{
				q=q->sig;
				t=q;
			}
			else
			{
				cen=0;
			}
		}
		if(cen==0)
		{
			cout<<"El dato ("<<ref<<") no existe en la lista enlazada"<<endl;
			system("pause");
		}
		else
		{
			if(q->sig!=NULL)
			{
				t=q->sig;
				if(t->sig!=NULL)
				{
					q->sig=t->sig;
				}
				else
				{
					q->sig=t->sig;
				}
				cout<<"Se esta eliminando el nombre ( "<<t->nomb<<" ) de la lista enlazada"<<endl;
				delete(t);
				system("pause");
			}
			else
			{
				cout<<"No existe un nodo posterior a "<<ref<<endl;
				system("pause");
			}
		}
	}
	else
	{
		cout<<"La lista esta vacia"<<endl;
		system("pause");
	}
	return(p);
}
void recorre(nodo *p)
{
	nodo *q;
	system("cls");
	q=p;
	cout<<"\n\n\tLISTA DE DATOS: \n";
	cout<<"\t===============";
	while(q!=NULL)
	{
		cout<<"\n\n\t\t"<<q->nomb;
		q=q->sig;
	}
	cout<<"\n\n\t\t\t";
}