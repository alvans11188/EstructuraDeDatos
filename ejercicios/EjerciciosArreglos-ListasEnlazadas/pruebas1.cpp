#include <iostream>
#define MAX 5
using namespace std;
struct arreglo{
	int inf;
};

void insertar(arreglo *,int&, int);
void mostrar(arreglo *, int );
void insertarAntesDe(arreglo *,int& ,int );
int  buscar(arreglo *,int& ,int );
int main(){
	arreglo x[MAX]={1,2,3,4,5};
	int n=0;
	//insertar(x,n,1);
	//insertar(x,n,2);
	mostrar(x,n);
	return 0;
}
void insertar(arreglo *x,int& n, int dato){
	int i=0;
	
	if(n>=MAX){
		cout<<"El arreglo esta lleno"<<endl;
	}else{
		x[n].inf=dato;	
		n++;
	}
}

void mostrar(arreglo *x, int& n){
	int i=0;
	for(i=0;i<n;i++){
		cout<<x[i].inf<<" ";
	}
}

int buscar(arreglo *x,int n,int ref){
	int i,pos;
	i=0;
	while ((i<n)&&(x[i].inf<ref))
	{
		i=i+1;
	}
	if ((i>n)||(x[i].inf>ref))
	{
		pos = -1*i;
	} 
	else
	{
		pos = i;
	}
	return pos;
}

void insertarAntesDe(arreglo *x,int& n,int ref){
	
	if(n<0){
		cout <<"El arregloe esta vacio"<<endl;
		
	}else{
		if(n>=MAX){
			cout<<"El arreglo esta lleno"<<endl;
		}else{
	int i,pos;
	if(n<MAX)
	{
		pos = buscar(x,n,ref);
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
	}
}