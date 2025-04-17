#include <iostream>
using namespace std;
int buscar(int [], int, int);
void insertar_ao(int [],int &,int,int);
int main()
{
	const int max=10;
	int x[max] = {-2,4,21,27,49,57};
	int i,dato,pos;
	int n=6;
	//n=n-1;
	cout<<"INSERTAR DATO: ";
	cin>>dato;
	
	insertar_ao(x,n,max,dato);
	
	cout <<"\n";
	for(i=0;i<n;i++){
		cout << x[i] << " ";
	}
	
	return 0;	
}
int buscar(int x[],int n,int dato)
{
	int i,pos;
	i=0;
	while ((i<n)&&(x[i]<dato))
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
void insertar_ao(int x[],int &n,int max, int dato)
{
	int i,pos;
	if(n<max)
	{
		pos = buscar(x,n,dato);
		if(pos<0)
		{
			n=n+1;
			pos=-1*pos;
			for(i=n;i>pos;i--)
			{
				x[i]=x[i-1];	
			}
			x[pos]=dato;
		}
		else
		{
			cout << "El dato ya existe";
		}
	}
	else
	{
		cout << "arreglo lleno";
	}
}