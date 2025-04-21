#include<iostream>
using namespace std;
struct nodo
{
	int numero;
	nodo *sig;	
};
nodo *crear_i(nodo *);
nodo *eliminar_iguales(nodo *, int);
void mostrar(nodo *);
int main()
{
	int op,ref;
	nodo *p=NULL;
	do
	{
		system("cls");
		cout<<"\nLISTAS ENLAZADAS";
		cout<<"\n================";
		cout<<"\n\n1- Crear por el inicio";
		cout<<"\n\n2- Eliminar nodos con la misma informacion";
		cout<<"\n\n3- M O S T R A R ";
		cout<<"\n\n\t\t\t OPCION: ";
		cin>>op;
		switch(op)
		{
			case 1:
				p=crear_i(p);
				system("pause");
				break;
			case 2:
				cout<<"Ingrese el valor que desea eliminar : ";
				cin>>ref;
				p=eliminar_iguales(p,ref);
				system("pause");
				break;
			case 3:
				mostrar(p);
				system("pause");
				break;
			case 4:
				cout<<"SALIENDO DEL PROGRAMA";
				system("pause");
				break;
			default:
				cout<<"Opcion incorrecta";
				system("pause");
				break;
		}
	} while (op!=4);
	return 0;
}
nodo *crear_i(nodo *p)
{
	nodo *q,*r;
	char op;
	do
	{
		system("cls");
		q=new(nodo);
		cout<<"Ingrese un dato "<<endl;
		cin>>q->numero;
		q->sig=p;
		p=q;
		cout<<"Desea ingresar otro dato?(S/N)"<<endl;
		cin>>op;
	}while(op=='s'||op=='S');
	return(p);
}
nodo *eliminar_iguales(nodo *p,int ref)
{
	nodo *q,*r;
	
	if(p!=NULL)
	{
		q=p;
		while(q->sig!=NULL)
		if(q->numero==ref)
		{
			r=q;
			q=q->sig;
			p=q;
			cout<<"Se elimino el nodo "<<r->numero<< " de la lista enlazada "<<endl;
			delete(r);
			system("pause");
		}
		else
		{
			cout<<"No se logro encontrar el valor referencial en la lista enlazada"<<endl;
			system("pause");
		}
	}
	else
	{
		cout<<"La lista esta vacia";
		system("pause");
	}
	return(p);
}
void mostrar(nodo *p)
{
	nodo *q;
	system("cls");
	q=p;
	cout<<"\n\n\tLISTA DE DATOS: \n";
	cout<<"\t===============";
	while(q!=NULL)
	{
		cout<<"\n\n\t\t"<<q->numero;
		q=q->sig;
	}
	cout<<"\n\n\t\t\t";
}