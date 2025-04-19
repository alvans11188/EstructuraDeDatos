#include <iostream>
#include <string.h>
#define MAX 5
using namespace std;

struct paciente
{
	char hc[15], nomb[20];
	float peso, talla, imc;
};
void inserta_d(paciente *,int &);
void elimina_d(paciente *,int &);
void modifica_d(paciente *,int &);
//int buscar_o(paciente *,int);
int buscar_o(paciente *, int , const char* );
void inserta_o(paciente *,int &, const char*);
void elimina_o(paciente *,int &,const char*);
void modifica_o(paciente *, int &, const char*);
void mostrar(paciente *, int );
void ordenar_o(paciente *, int );
int main()
{
	paciente x[MAX];
	int op,opc,n=-1,i;
	char dato[10];

	do
	{
		system("cls");
	
		cout<<"\nM E N U";
		cout<<"\n\n1. ARRAY DESORDENADO...";
		cout<<"\n\n2. ARRAY ORDENADO...";
		cout<<"\n\n3. SALIR...";
		cout<<"\n\n\t\t\t OPCION:	";
		cin>>op;
		switch(op)
		{
			case 1:
				do
				{
					system("cls");
					cout<<"\n\nARREGLOS DESORDENADO";
					cout<<"\n\n1. INSERTAR";
					cout<<"\n\n2. ELIMINAR";
					cout<<"\n\n3. MODIFICAR";
					cout<<"\n\n4. MOSTRAR";
					cout<<"\n\n5. SALIR";
					cout<<"\n\n\t\t OPCION:";
					cin>>opc;
					system("cls");
					switch(opc)
					{
						case 1:
							inserta_d(x,n);
							mostrar(x,n);
							break;
						case 2:
							elimina_d(x,n);
							mostrar(x,n);
							break;
						case 3:
							modifica_d(x,n);
							mostrar(x,n);
							break;
						case 4:
							mostrar(x,n);
							break;
						case 5:	
							break;
					}
				}
				while(opc>0&&opc<5);
				break;
			case 2:
				do
				{
					system("cls");
					cout<<"\n\n\nARREGLOS ORDENADOS";
					cout<<"\n==================";
					cout<<"\n\n1. INSERTAR";
					cout<<"\n\n2. ELIMINAR";
					cout<<"\n\n3. MODIFICAR";
					cout<<"\n\n4. MOSTRAR";
					cout<<"\n\n5. SALIR";
					cout<<"\n\n\t\t OPCION:";
					cin>>opc;
					system("cls");
					switch(opc)
					{
						case 1:
							cout<<"\n\t\tDATO A INSERTAR : ";cin>>dato;
							inserta_o(x,n,dato);
							
							break;
						case 2:
							cout<<"\n\t\tDATO A ELIMINAR : ";cin>>dato;
							elimina_o(x,n,dato);
							
							break;
						case 3:
							cout<<"Ingrese la historia clinica que desea modificar: ";cin>>dato;
							modifica_o(x,n,dato);
							
							break;
						case 4:
							mostrar(x,n);
							break;
						case 5:	
							break;
					}
				}
				while(opc>0&&opc<5);
				break;
			case 3:
					break;
		}
	}
	while(op>0&&op<3);
	return 0;
}
void inserta_d(paciente *x,int &n)
{
	int i,j,cen;
	char hclinica[10];
	if(n<MAX-1)
	{
		cen=0;
		i=0;
		cout<<"\n\n\nDATOS DEL REGISTRO A INSERTAR:	";cout<<"\n\n\t\tHISTORIA CLINICA		: ";
		cin>>hclinica;
		if(n>-1)
		{
			while((i<=n)&&(cen==0))
			{
				if(strcmp(x[i].hc,hclinica)==0)
					cen = 1;
				else
					i++;
			}
		}
		if(cen==0)
		{
			n=n+1;
			strcpy(x[i].hc,hclinica);
			cout<<"\n\n\t\tNOMBRE	: ";cin>>x[i].nomb;
			cout<<"\n\n\t\tPESO 	: ";cin>>x[i].peso;
			cout<<"\n\n\t\tTALLA	: ";cin>>x[i].talla;
			x[i].imc=x[i].peso/((x[i].talla/100)*(x[i].talla/100));
			cout<<"\n\n\t\tINDICE DE MASA CORPORAL	: "<<x[i].imc;
		}
		else
			cout<<"\n\n\n\nEL DATO YA ESTA REGISTRADO EN LA BASE DE DATOS. No se realizo la insercion";			
	}
	else
		cout<<"\n\n\t\tEL ARREGLO ESTA LLENO, PELIGRO DE DESBORDAMIENTO. Nose inserto ningun dato..";
}
void elimina_d(paciente *x,int &n)
{
	int i,j,cen;
	char hclinica[10];
	cout<<"\n\t\tDATO A ELIMINAR  :\n\n";
	cout<<"HISTORIA CLINICA   : ";cin>>hclinica;
	if(n>-1)
	{
		i=0;
		cen=0;
		while((i<=n)&&(cen==0))
		{
			if(strcmp(x[i].hc,hclinica)==0)
			{
				cen=1;
				n--;
				for(j=i;j<=n;j++)
					x[j]=x[j+1];
			}
			else
				i++;
		}
		if(cen==0)
			cout<<"\n\n\t\t"<<hclinica<<"NO ESTA EN EL ARREGLO\n\n";
	}
	else
	{
		cout<<"\n\n\nEL ARREGLO ESTA VACIO...\n\n\n";
		system("pause");
	}	
}
void modifica_d(paciente *x,int &n)
{
	int i,cen,op;
	char hc1[10];
	cout<<"\n\t\tCODIGO DEL REGISTRO A MODIFICAR  :  \n\n";
	cout<<"\tHISTORIA   : ";cin>>hc1;
	if(n>-1)
	{
		i=0;
		cen=0;
		while((i<=n)&&(cen==0))
		{
			if(strcmp(x[i].hc,hc1)==0)
			{
				cen=1;
				cout<<"\n\n\tQUE CAMPO DESEA MODIFICAR? \n\n";
				cout<<"1. HISTORIA CLINICA	2. NOMBRE	3. PESO		4.TALLA  \n\n";
				cout<<"OPCION : ";cin>>op;
				switch(op)
				{
					case 1:
						cout<<"\nINGRESA LA HISTORIA CLINICA CORRECTA : ";cin>>x[i].hc;
						break;
					case 2:
						cout<<"\nINGRESA EL NOMBRE CORRECTO : ";cin>>x[i].nomb;
						break;
					case 3:
						cout<<"\nINGRESA EL PESO CORRECTO : ";cin>>x[i].peso;
						x[i].imc=x[i].peso/(x[i].talla*x[i].talla);
						break;
					case 4:
						cout<<"\nINGRESA LA TALLA CORECTA : ";cin>>x[i].talla;
						x[i].imc=x[i].peso/(x[i].talla*x[i].talla);
						break;
						
				}
			}
			else
				i++;
		}
		if(cen==0)
		{
			cout<<"\n\n\nLA HISTORIA CLINICA "<<hc1<<" NO ESTA EN EL ARREGLO\n\n";
			system("pause");
		}
	}
	else
	{
		cout<<"\n\n\nEL ARREGLO ESTA VACIO...\n\n\n";
		system("pause");
	}
}
int buscar_o(paciente *x, int n, const char* dato)
{
    int i = 0, pos;

    while ((i <= n) && (strcmp(x[i].hc, dato) < 0)) 
	{
        i++;
    }

    if (i > n)  
	{
        pos = -1 * i; 
    }
    else if((strcmp(x[i].hc, dato) == 0))
    {
    	pos = i;
	}
	 
	 else {
        pos = -1*i;       
    }

    return pos;
}
void inserta_o(paciente *x,int &n, const char*dato)
{
	int i, pos;
	if(n<MAX)
	{
		pos=buscar_o(x,n,dato);
		if(pos<=0)
		{
			n=n+1;
			pos=-1*pos;
			for(i=n;i>pos;i--)
			{
				x[i]=x[i-1];
			}
			strcpy(x[pos].hc,dato);
			cout << "\n\n\t\tNOMBRE: "; cin >> x[pos].nomb;
            cout << "\n\n\t\tPESO  : "; cin >> x[pos].peso;
            cout << "\n\n\t\tTALLA : "; cin >> x[pos].talla;
            x[pos].imc = x[pos].peso / ((x[pos].talla / 100) * (x[pos].talla / 100));
		}
		else
		{
			cout<<"El dato ya existe"<<endl;
			system("pause");
		}
	}
	else
	{
		cout<<"El arreglo esta lleno, peligro de desbordamiento"<<endl;
		system("pause");
	}
}

void elimina_o(paciente *x, int &n,const char* dato)
{
	int pos,i;
	if(n>=0)
	{
		pos=buscar_o(x,n,dato);
		if(pos>=0)
		{
			n=n-1;
			for(i=pos;i<=n;i++)
			{
				x[i]=x[i+1];
			}
			cout<<"El historial clinico numero : "<< dato << " a sido eliminado exitosamente"<<endl;
			system("pause");
		}
		else
		{
			cout<<"El dato no existe"<<endl;
			system("pause");
		}
	}
	else
	{
		cout<<"El arreglo esta vacio"<<endl;
		system("pause");
	}
}

void modifica_o(paciente *x, int &n, const char *dato)
{
 	int pos;
 	if(n>=0)
 	{
 		pos=buscar_o(x,n,dato);
 		if(pos>=0)
 		{
 			cout << "\n\n\t\tHISTORIA CLINICA: "; cin>>x[pos].hc;
			cout << "\n\n\t\tNOMBRE: "; cin >> x[pos].nomb;
            cout << "\n\n\t\tPESO  : "; cin >> x[pos].peso;
            cout << "\n\n\t\tTALLA : "; cin >> x[pos].talla;
            x[pos].imc = x[pos].peso / ((x[pos].talla / 100) * (x[pos].talla / 100));
		}
		else
		{
			cout<<"La hisotria clinica buscada no existe"<<endl;
			system("pause");
		}
	}
	else
	{
		cout<<"El arreglo esta vacio"<<endl;
		system("pause");
	}
}

void ordenar_o(paciente *x, int n)
{
	//el ordenamiento ya se esta realizando por medio de la funcion buscar_o, encontrando la posición donde debe ir el nuevo dato para mantener el arreglo ordenado alfabéticamente por hc	 
}
void mostrar(paciente *x,int n)
{
	int i;
	for (i=0;i<=n;i++)
		{
			cout<<"\nx["<<i+1<<"] : \n\n";
			cout<<"\n\n\t\tHISTORIA CLINICA		:"<<x[i].hc;
			cout<<"\n\n\t\tNOMBRE	: "<<x[i].nomb;
			cout<<"\n\n\t\tPESO 	: "<<x[i].peso<<" kg.";
			cout<<"\n\n\t\tTALLA	: "<<x[i].talla<<" cm.";
			cout<<"\n\n\t\tINDICE DE MASA CORPORAL	: "<<x[i].imc;
		}
		cout<<"\n\n";
		system("pause");

	
}
