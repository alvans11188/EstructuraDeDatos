/*2.4 INSERCION AL INICIO DE LA LISTA
*Cuando se va a insertar va a ser por la cabecera
1- con un puntero q crearemos un nodo y su direccion la copiaremos a la cabecera
2- p retorna para saber adonde esta apuntando su ultima insercion

¿PORQUE SE ESTUDIAN??
- porque es una forma de apilamiento de datos, en sistemas operativos
-Pila ,cumplen una caracteristica el ultimo dato ingresado sera el primero en salir, la unica fomra de acceder es por la cabecera
- en la cola el primero que llega es el ultimo en atenderse

Por estas razones es por las que se estudiante, cuando epnsamos en crear un programa por ejemplo de..
CAJERO PARA EL CINE
las personas al momento de llegar van formando filas y se van atendiendo del primero hacia atras y las siguientes personas que van 
llegando se van posicionando al final por loque la mejor estructura sera una de COLA
*/
#include<iostream>
using namespace std;

struct nodo
{
	int inf; //campo de informacion
	nodo *sig;	//campo de enlace
};
nodo *inserta_i(nodo *);
void recorre(nodo *);
nodo *crea_i(nodo *);
int main()
{
	int op;
	nodo *p;
	do
	{
		system("cls");
		cout<<"\t\tPROGRAMA DE OPERACIONES EN UNA LISTA ENLAZADA"<<endl;
		cout<<"\t1- Crearpor el inicio"<<endl;
		cout<<"\t2- Insertar por el inicio"<<endl;
		cout<<"\t3- Mostrar"<<endl;
		cout<<"\t4- S A L I R "<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				{
					system("cls");
					p=NULL;
					p=crea_i(p);
					break;
				}
			case 2:
				{
					system("cls");
					p=NULL;
					p=inserta_i(p);
					break;
				}
			case 3:
				{
					system("cls");
					
					recorre(p);
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
	}while(op!=4);
	
	
	return 0;
}
nodo* crea_i(nodo *p)
{
	nodo *q;
	char op;
	cout<<"CREACION DE LISTA POR EL INICIO"<<endl;
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
	cin>>q->inf;
	q->sig=p;
	p=q;
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