/*2- EJERCICIO
Crear una función que invierta completamente el orden de la lista.
*//* 1- EJERCICIO
Defina un algoritmo para insertar, si es posible, un elemento antes de otro nodo dado como referencia en una lista ordenada
*/

#include <iostream>
using namespace std;
struct nodo
{
	int num;
	nodo *sig;	
};
nodo *crear_i(nodo *);
void mostrar(nodo *);
int main()
{
	int n,op;
	nodo *p;
	do
	{
		cout<<"\t\t EJERCICIO 1"<<endl;
		cout<<"\n\t 1- Crear lista por el inicio "<<endl;
		cout<<"\n\t 2- Insertar antes de un nodo referencial"<<endl;
		cout<<"\n\t 3- Invertir lista"<<endl;
		cout<<"\n\t 9- Mostrar"<<endl;
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














