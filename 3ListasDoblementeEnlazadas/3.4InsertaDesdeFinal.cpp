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
void inserta_principio(nodo *&, int);
void inserta_final(nodo *&, int);

int main() 
{
    nodo *p=NULL;
    nodo *f=NULL;
    int op,dato;
    p=NULL;
	f=NULL;
	crearLista(p,f);
    do
	{
    	cout<<"\n\n\t\tLISTAS DOBLEMENTE ENLAZADAS ";
		cout<<"\n\t\t=================================";
		cout<<"\n\n\t1. RECORRER DESDE EL INICIO";
		cout<<"\n\n\t2. RECORRER DESDE EL FINAL";
		cout<<"\n\n\t3. INSERTAR DESDE EL PRINCIPIO";
		cout<<"\n\n\t4. INSERTAR DESDE EL FINAL";
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
			case 3:
				cout<<"Ingrese el dato a insertar"<<endl;
				cin>>dato;
				inserta_principio(p,dato);
				break;
			case 4:
				cout<<"Ingrese el dato a insertar"<<endl;
				cin>>dato;
				inserta_final(f,dato);
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
void inserta_principio(nodo *&p,int dato)
{
	nodo *q;
	q=new(nodo);
	q->inf=dato;
	q->ligader=p;
	p->ligaizq=q;
	p=q;
	q->ligaizq=NULL;
	
}
void inserta_final(nodo *&f,int dato)
{
	nodo *q;
	q=new(nodo);
	q->inf=dato;
	q->ligaizq=f;
	f->ligader=q;
	f=q;
	q->ligader=NULL;
	
}