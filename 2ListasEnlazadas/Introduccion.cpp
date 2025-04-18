/*LISTAS ENLAZADAS

Es una estructura linea, dinamica, homogenea
		lineal, porque sus datos estan uno a continuacion de otro
		dinemica, porque su tamaño cambia en el momento de ejecucion
		homogenea, contienen un mismo tipo de dato ya sea int, string, char pero solo de un tipo
PARTES:
	Puntero de cabecera: señala el primer nodo de la lista, este puntero almacela la direccion de memoria del primer nodo
	Segmento de informacion: sirve para la colocacion de la informacion que va a contener el nodo
	Segmento de enlace: sirve como un puntero(es una variable que almacena direccion de memoria) de enlace
		
*/
#include <iostream>
using namespace std;
//se dinen los datos que contendra el nodo
struct nodo
{
	int inf; //campo de informacion
	nodo *sig;	//campo de enlace
};

int main()
{
	char op;
	cout<<"CREAR UNA LISTA ENLAZADA"<<endl;
	nodo *p,*q;	//se definen valores para crear posibles nodos a futuro
	p=NULL; // siempre el nodo p (nodo cabecera ) tiene q apuntar a null
	do
	{
		q=new(nodo);
		cin>>q->inf;
		q->sig=p;
		p=q;
		cout<<"Mas datos?(S/N)";
		cin>>op;
	}while((op=='s'||op=='S'));
	//funcion para obtener la lista de datos 
	q=p;
	cout<<"\n\n\tLISTA DE DATOS: \n";
	cout<<"\t===============";
	while(q!=NULL)
	{
		cout<<"\n\n\t\t"<<q->inf;
		q=q->sig;
	}
	cout<<"\n\n\t\t\t";
	
	return 0;
}