/*3.3 INSERTAR DESDE EL PRINCIPIO

*/
#include<iostream>
using namespace std;
struct nodo
{
	int inf;
	nodo *ligaizq;
	nodo *ligader;	
};

void recorre_desde_inicio(nodo *);
void recorre_desde_final(nodo *);
void inserta_principio(nodo *&,nodo *&, int);
void inserta_final(nodo *&,nodo *&, int);
void inserta_antes_x(nodo *&,nodo *&,int,int);

int main() 
{
    nodo *p=NULL;
    nodo *f=NULL;
    int op,dato,x;
    p=NULL;
	f=NULL;
	
    do
	{
    	cout<<"\n\n\t\tLISTAS DOBLEMENTE ENLAZADAS ";
		cout<<"\n\t\t=================================";
		cout<<"\n\n\t1. RECORRER DESDE EL INICIO";
		cout<<"\n\n\t2. RECORRER DESDE EL FINAL";
		cout<<"\n\n\t3. INSERTAR DESDE EL PRINCIPIO";
		cout<<"\n\n\t4. INSERTAR DESDE EL FINAL";
		cout<<"\n\n\t5. INSERTAR ANTES DE UN NODO REFERENCIAL";
		cout<<"\n\n\t13. SALIR";
		cout<<"\n\n\tOPCION:\t\t";
		cin>>op;
		switch(op)
		{
			case 1:
				
				recorre_desde_inicio(p);
				system("cls");
				break;
			case 2:
				recorre_desde_final(f);
				system("cls");
				break;
			case 3:
				cout<<"Ingrese el dato a insertar"<<endl;
				cin>>dato;
				inserta_principio(p,f,dato);
				break;
			case 4:
				cout<<"Ingrese el dato a insertar"<<endl;
				cin>>dato;
				inserta_final(p,f,dato);
				break;
			case 5:
				cout<<"Ingrese el dato referencial"<<endl;
				cin>>dato;
				cout<<"Ingrese el valor a ingresar antes del referencial"<<endl;
				cin>>x;
				inserta_antes_x(p,f,dato,x);
				break;
			case 13:
				system("cls");
				cout<<"\n\n\t\tSALIENDO DEL PROGRAMA"<<endl;
				break;
			default:
				cout<<"OBCION INVALIDA"<<endl;
				break;
		}
	
	} while (op!=13);
    
    
    return 0;
}
void recorre_desde_inicio(nodo *p)
{
	nodo *q;
	system("cls");
	q=p;
	cout<<"\n\n\t\tLA LISTA DOBLEMENTE ENLAZADA ES: ";
	cout<<"\n\n\t\t ";
	if(q==NULL)
	{
		cout<<"La lista se encuentra vacia"<<endl;
		system("pause");
	}
	else
	{
		while(q!=NULL)
		{
			cout<<q->inf<< " ";
			q=q->ligader;
		}
		cout<<"\n\n\t\t ";
		system("pause");
		system("cls");	
	}

	
}

void recorre_desde_final(nodo *p)
{
	nodo *q;
	system("cls");
	q=p;
	cout << "\n\n\t\tLA LISTA EN ORDEN INVERSO ES: ";
	cout << "\n\n\t\t ";
	while(q!=NULL)
	{
		cout<<q->inf<<" ";
		q=q->ligaizq;
	}
	cout<<"\n\n\t\t ";
	system("pause");
	system("cls");
	
}
void inserta_principio(nodo *&p,nodo *&f,int dato)
{
	nodo *q;
	q=new(nodo);
	q->inf=dato;
	q->ligader=p;
	p->ligaizq=q;
	p=q;
	q->ligaizq=NULL;
	
}
void inserta_final(nodo *&p,nodo *&f,int dato)
{
	nodo *q;
	q=new(nodo);
	q->inf=dato;
	q->ligaizq=f;
	f->ligader=q;
	f=q;
	q->ligader=NULL;
	
}
void inserta_antes_x(nodo *&p, nodo *&f, int dato, int x)
{
	nodo *q = p, *t, *r;
	while ((q != NULL) && (q->inf != x))
	{
		q = q->ligader;
	}
	if (q != NULL) // se encontro el nodo con valor x
	{
		t = new(nodo);
		t->inf = dato;
		t->ligader = q;
		
		r = q->ligaizq;
		q->ligaizq = t;

		if (p == q) // insertar al inicio
		{
			p = t;
			t->ligaizq = NULL;
		}
		else
		{
			r->ligader = t;
			t->ligaizq = r;
		}
	}
	else
	{
		cout << "El elemento no se encuentra en la lista" << endl;
		system("pause");
	}
}
