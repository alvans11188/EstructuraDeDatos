//
#include <iostream>
using namespace std;
int buscar(int [],int &,int);
void eliminar_ao(int [],int &,int);
int main()
{
	const int max=10;
	int x[max] = {-7,10,23,47,81};
	int i,dato,pos;
	int n=5;
	//n=n-1;
	cout<<"ELIMINAR DATO: ";
	cin>>dato;
	
	//funcion
	eliminar_ao(x,n,dato);
	for(i=0;i<n;i++){
		cout<<x[i]<<" ";
	}
	return 0;	
}
int buscar(int x[],int &n,int dato)
{
	int i,pos;
	i=0;
	while ((i<=n)&&(x[i]<dato))
	{
		i=i+1;
	}
	if ((i>n)||(x[i]>dato))
	{
		pos = -1*i;
	} 
	else
	{
		pos = i;
	}
	return pos;
}
void eliminar_ao(int x[],int &n,int dato)
{
	int i,pos;
	if(n>0)
	{
		pos=buscar(x,n,dato);
		if(pos>0)
		{
			n=n-1;
			for(i=pos;i<n;i++)
			{
				x[i]=x[i+1];
			}
		}
		else
		{
			cout<<"El dato no existe";
		}
	}
	else
	{
		cout<<"El arreglo esta vacio";
	}
}