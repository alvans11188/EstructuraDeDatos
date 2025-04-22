/*3.1 RECORRE DESDE EL INCIO
Para poder recorrer primer tendremos que insertar datos a mi lista doblemente enlzada por lo que tendremos que hacer primero la funcion inserta
*/
#include<iostream>
using namespace std;
struct nodo
{
	int inf;
	nodo *ligaizq;
	nodo *ligader;	
};

void crearLista(nodo* &p, nodo* &f) {
	int valores[] = {1, 3, 5, 7};
	p = NULL;
	f = NULL;

	for (int i = 0; i < 4; i++) {
		nodo* nuevo = new nodo;
		nuevo->inf = valores[i];
		nuevo->ligader = NULL;
		nuevo->ligaizq = f;  // conecta hacia atrás

		if (p == NULL) {
			p = nuevo;       // primer nodo
		} else {
			f->ligader = nuevo;  // conecta hacia adelante
		}

		f = nuevo; // actualiza el final
	}
}

void recorre_desde_inicio(nodo *);
void recorre_desde_final(nodo *);

int main() 
{
    nodo *p=NULL;
    nodo *f=NULL;
    int op;
    p=NULL;
	f=NULL;
	crearLista(p,f);
    do
	{
    	cout<<"\n\n\t\tLISTAS DOBLEMENTE ENLAZADAS ";
		cout<<"\n\t\t=================================";
		cout<<"\n\n\t1. RECORRER DESDE EL INICIO";
		cout<<"\n\n\t2. RECORRER DESDE EL FINAL";
		cout<<"\n\n\t13. SALIR";
		cout<<"\n\n\tOPCION:\t\t";
		cin>>op;
		switch(op)
		{
			case 1:
				
				recorre_desde_inicio(p);
				break;
			case 2:
				recorre_desde_final(f);
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
	while(q!=NULL)
	{
		cout<<q->inf<< " ";
		q=q->ligader;
	}
	cout<<"\n\n\t\t ";
	system("pause");
	system("cls");
	
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