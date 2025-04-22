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

nodo* crearLista() {
	int valores[] = {1, 3, 5, 7};
	nodo* primero = NULL;
	nodo* ultimo = NULL;

	for (int i = 0; i < 4; i++) {
		nodo* nuevo = new nodo;
		nuevo->inf = valores[i];
		nuevo->ligader = NULL;
		nuevo->ligaizq = ultimo;

		if (primero == NULL)
			primero = nuevo;
		else
			ultimo->ligader = nuevo;

		ultimo = nuevo;
	}

	return primero;  // ¡CORREGIDO!
}

nodo *recorre_desde_inicio(nodo *);

int main() 
{
    nodo *p;
    nodo *f;
    int op;
	
    do
	{
    	cout<<"\n\n\t\tLISTAS DOBLEMENTE ENLAZADAS ";
		cout<<"\n\t\t=================================";
		cout<<"\n\n\t1. RECORRER DESDE EL INICIO";
		/*
		cout<<"\n\n2. RECORRER";
		*/
		cout<<"\n\n\t13. SALIR";
		cout<<"\n\n\tOPCION:\t\t";
		cin>>op;
		switch(op)
		{
			case 1:
				p=NULL;
				f=NULL;
				p=crearLista();
				p=recorre_desde_inicio(p);
				break;
			case 13:
				system("cls");
				cout<<"\n\n\t\tSALIENDO DEL PROGRAMA"<<endl;
				break;
		}
	
	} while (op!=13);
    
    
    return 0;
}
nodo *recorre_desde_inicio(nodo *p)
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
	return(p);
}