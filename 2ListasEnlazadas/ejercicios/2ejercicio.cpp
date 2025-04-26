/*2- EJERCICIO
Crear una función que invierta completamente el orden de la lista.
*/

#include <iostream>
using namespace std;
struct nodo
{
	int num;
	nodo *sig;	
};
nodo *crear_i(nodo *);
nodo *inserta_antes_x(nodo *, int);
nodo *invertir(nodo *);
void mostrar(nodo *);
int main()
{
	int n,op,dato;
	nodo *p;
	do
	{
		cout<<"\t\t EJERCICIO 1"<<endl;
		cout<<"\n\t 1- Crear lista por el inicio "<<endl;
		cout<<"\n\t 2- Insertar antes de un nodo referencial"<<endl;
		cout<<"\n\t 3- Invertir"<<endl;
		cout<<"\n\t 9-mostrar"<<endl;
		cout<<"\n\t 13-SALIR"<<endl;
		cout<<"\t OPCION: \t"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				p=NULL;
				p=crear_i(p);
				break;
			case 2:
				cout<<"Ingrese el dato que desea usar como referencial"<<endl;
				cin>>dato;
				p=inserta_antes_x(p,dato);
				break;
			case 3:
				p=invertir(p);
				break;
			case 9:
				mostrar(p);
			default:
				cout<<"Ingrese un valor valido"<<endl;
				break;
		}
	}while(n<13);
	
	return 0;
}

nodo *crear_i(nodo *p)
{
	nodo *q;
	
	
	char op;
	do
	{
		q=new(nodo);
		cout<<"Ingrese un valor"<<endl;
		cin>>q->num;
		cout<<"Desea ingresar otro valor? (S/N)"<<endl;
		cin>>op;
		q->sig=p;
		p=q;
		
	} while (op=='s'||op=='S');
	cout<<"Lista creara correctamente"<<endl;
	//system("cls");
	system("pause");
	return(p);
}

nodo *inserta_antes_x(nodo *p, int dato)
{
	nodo *q,*r,*s;
	int cen;
	if(p!=NULL)
	{
		r=p;
		cen=0;
		while(r->num!=dato&&cen==0)
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
			cout<<"Valor encontrado, que valor desea ingresar antes"<<endl;
			cin>>q->num;
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
			cout<<"No existe el dato referencial"<<endl;
		}
	}
	else
	{
		cout<<"La lista esta vacia";
		
	}
	return(p);
}
nodo *invertir(nodo *p)
{
    nodo *q = p;      // q recorre la lista (actual)
    nodo *t = NULL;   // t sera el nuevo inicio (anterior)
    nodo *s;          // s guarda el siguiente

    while (q != NULL)
    {
        s = q->sig;   // guardo el siguiente nodo
        q->sig = t;   // invierto el enlace
        t = q;        // muevo t al nodo actual
        q = s;        // avanzo al siguiente
    }

    p = t;  // actualizo p al nuevo comienzo
    return p;
}
void mostrar(nodo *p)
{
	nodo *q;
	q=p;
	cout<<"La lista es P-> ";
	while(q!=NULL)
	{
		cout<< q->num;
		cout<<"->";
		q=q->sig;
	}
	cout<<"\n";
}

