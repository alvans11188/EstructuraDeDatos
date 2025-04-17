//
#include <iostream>
using namespace std;
int buscar(int [],int,int);
void modifica(int [],int,int,int);
void ordenar(int [],int);
int main()
{
	const int max=10;
	int x[max] = {20,47,58,92,100};
	int i,dato1,pos,dato2;
	int n=5;
	//n=n-1;
	cout<<"BUSCAR EL DATO : ";
	cin>>dato1;
	cout<<"MODIFICARLO POR: ";
	cin>>dato2;
	
	//funcion
	modifica(x,n,dato1,dato2);
	for(i=0;i<n;i++)
	{
		cout<<x[i]<<" ";
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
void modifica(int x[],int n, int dato1, int dato2)
{
	if(n>0)
	{
		int i,pos;
		pos=buscar(x,n,dato1);
		if(pos>=0)
		{
			x[pos]=dato2;
			ordenar(x,n);
		}
		else
			cout<<"El dato no existe";
	}
	else
	{
		cout<<"El arreglo esta vacio";
	}

}
void ordenar(int x[], int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1]) {
                // Intercambio de valores
                aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;
            }
        }
    }
}