//
#include <iostream>
using namespace std;
int buscar(int [],int,int);
int main()
{
	const int max=10;
	int x[max] = {-5,7,23,31,47};
	int i,dato,pos;
	int n=5;
	//n=n-1;
	cout<<"VALOR A BUSCA: ";
	cin>>dato;
	
	//funcion
	pos = buscar(x,n,dato);
	cout<<pos;
	return 0;	
}
int buscar(int x[],int n,int dato)
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