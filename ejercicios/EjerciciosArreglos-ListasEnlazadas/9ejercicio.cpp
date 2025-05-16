/*9 EJERCICIO
 Se desea registrar los datos correspondientes al Código (dato tipo char) y Precio (dato tipo float) de 
un conjunto de libros en una estructura de datos estática lineal tipo arreglo unidimensional “X” de tal 
forma que el arreglo esté ORDENADO en forma DESCENDENTE respecto al Código.  
*/
#include<iostream>
#define MAX 10
using namespace std;

struct registro{
	char codigo[10];
	float precio;
};
/* 
//si funciona esta parte solo que estoy probando de otra manera, ordenandolo automaticamente, 
pero ingresando el codigo , sin verificar antes si esta o no lleno el arreglo

void insertaLibro(registro *x,int& n){
	int i,j,cen;
	char cod[10];
	if(n<MAX-1)
	{
		cen=0;
		i=0;
		cout<<"DATOS DEL REGISTRO A INSERTAR: "<<endl;
		cout<< "Codigo de registro: ";
		cin>>cod;
		if(n>-1)
		{
			while(i<=n&&cen==0)
			{
				if(strcmp(x[i].codigo,cod)==0)
				{
					cen=1;
				}
				else
				{
					i++;
				}
			}
		}
		if(cen==0)
		{
			n=n+1;
			strcpy(x[i].codigo,cod);
			cout<<"PRECIO: ";cin>>x[i].precio;
		}
		else
		{
			cout<<"EL DATO YA ESTA REGISTRADO"<<endl;
		}
	}
	else
	{
		cout<<"EL ARREGLO YA ESTA LLENO"<<endl;
	}
	
}
*/
void mostrarLibro(registro *x,int& n){
	int i;
	for(i=1;i<=n;i++)
	{
		cout<<"\tx["<<i<< "]: \n"		;
		cout<<"\tCODIGO: "<<x[i].codigo<<endl;
		cout<<"\tPRECIO: "<<x[i].precio<<" S/."<<endl;
	}
	cout<<"\n\n";
}
int buscar(registro *x,int n, const char* codi)
{
	int i=0, pos;
	while((i<=n)&&(strcmp(x[i].codigo,codi)<0))
	{
		i++;
	}
	if(i>n)
	{
		pos=-1*i;
	}
	else
	{
		if((strcmp(x[i].codigo,codi)==0))
		{
			pos=i;
		}
		else
		{
			pos=-1*i;
		}
		
	}
	return pos;
	
}

void insertaLibro(registro *x,int &n,const char *codi){
	int i,pos;
	if(n<MAX)
	{
		pos=buscar(x,n,codi);
		if(pos<=0)
		{
			n++;
			pos=-1*pos;
			for(i=n;i>pos;i--)
			{
				x[i]=x[i-1];
			}
			strcpy(x[pos].codigo,codi);cout<<"\t\t";
			cout<<"PRECIO: ";cin>>x[i].precio;
		}
		else
		{
			cout<<"EL DATO YA ESTA REGISTRADO"<<endl;
			system("pause");
		}
	}
	else
	{
		cout<<"EL ARREGLO YA ESTA LLENO"<<endl;
		system("pause");
	}	
	
}

void ordenarLibros(registro *x,int& n){
	
}
int main(){
	registro x[MAX];
	char codi[10];
	int n=0;
	int op;
	do{
		cout<<"\n\n\tMENU DE BIBLIOTECA"<<endl;
		cout<<"\t1. Agregar libro"<<endl;
		cout<<"\t2. Mostrar libros"<<endl;
		cout<<"\t3. Ordenar libros"<<endl;
		cout<<"\t0. Salir"<<endl;
		cout<<"\t\t OPCION: "<<endl;
		cout<<"\t\t";
		cin>>op;
		switch(op){
			/*
			case 1:
				insertaLibro(x,n);
				break;
			*/
			case 1:
				cout<<"\t\tIngrese el codigo del libro"<<endl;cout<<"\t\t";
				cin>>codi;
				insertaLibro(x,n,codi);
				break;
			case 2:
				mostrarLibro(x,n);
				break;
			case 3:
				ordenarLibros(x,n);
				break;
			case 0:
				cout<<"\tS A L I E N D O  D E L  P R O G R A M A"<<endl;
				break;
			default:
				cout<<"\tOpcion incorrecta"<<endl;
		}
	}while(op!=0);
	return 0;
}