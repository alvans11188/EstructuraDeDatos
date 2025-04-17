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
void modifica_o(paciente *, int &);
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
							cout<<"\n\t\tDATO A MODIFICAR : ";
							modifica_o(x,n);
							
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

    if ((i > n) || (strcmp(x[i].hc, dato) != 0)) 
	{
        pos = -1 * i; 
    } else {
        pos = i;       
    }

    return pos;
}
void inserta_o(paciente *x,int &n, const char*dato)
{
	int i,pos;
	if(n<MAX-1)
	{
		pos = buscar_o(x,n,dato);
		if(pos<0)
		{
            n = n + 1;
            pos = -1 * pos;

            for (i=n;i>pos;i--)
            {
                x[i] = x[i - 1];  
            }

            // datos
            strcpy(x[pos].hc, dato);
            cout << "\n\t\tNOMBRE: "; cin >> x[pos].nomb;
            cout << "\n\t\tPESO (kg): "; cin >> x[pos].peso;
            cout << "\n\t\tTALLA (cm): "; cin >> x[pos].talla;

            // Calcular IMC
            x[pos].imc = x[pos].peso / ((x[pos].talla / 100) * (x[pos].talla / 100));

            cout << "\n\t\tINDICE DE MASA CORPORAL: " << x[pos].imc;
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

void elimina_o(paciente *x, int &n,const char* dato)
{

    if (n >= 0)
    {
        int pos = buscar_o(x, n, dato);
        if (pos >= 0)
        {
        	
            for (int i = pos; i < n; i++)
            {
                x[i] = x[i + 1];  // Desplaza los elementos hacia la izquierda
            }
            n=n-1;  // Reduce el número de elementos
            cout << "\n\n\t\tREGISTRO ELIMINADO CON EXITO.\n";
        }
        else
        {
            cout << "\n\n\t\tLA HISTORIA CLINICA NO EXISTE.\n";
        }
    }
    else
    {
        cout << "\n\n\t\tEL ARREGLO ESTA VACIO.\n";
    }
}

void modifica_o(paciente *x, int &n)
{
    if (n >= 0)
    {
        char hcBuscar[15];
        cout << "\n\t\tHISTORIA CLINICA A MODIFICAR : "; 
        cin >> hcBuscar;

        int pos = buscar_o(x, n, hcBuscar);

        if (pos >= 0)
        {
            int opcion;
            cout << "\n\tQUE CAMPO DESEA MODIFICAR?";
            cout << "\n1. HISTORIA CLINICA";
            cout << "\n2. NOMBRE";
            cout << "\n3. PESO";
            cout << "\n4. TALLA";
            cout << "\nOpcion: ";
            cin >> opcion;

            switch (opcion)
            {
                case 1:
                {
                    char hcNueva[15];
                    cout << "\nINGRESE LA NUEVA HISTORIA CLINICA: ";
                    cin >> hcNueva;

                    // Verifica que la nueva historia no exista
                    if (buscar_o(x, n, hcNueva) < 0)
                    {
                        strcpy(x[pos].hc, hcNueva);
                        ordenar_o(x, n);
                        cout << "\nHISTORIA CLINICA MODIFICADA Y ARREGLO ORDENADO.\n";
                    }
                    else
                    {
                        cout << "\nLA NUEVA HISTORIA CLINICA YA EXISTE. NO SE MODIFICO NADA.\n";
                    }
                    break;
                }
                case 2:
                    cout << "\nINGRESE EL NUEVO NOMBRE: ";
                    cin >> x[pos].nomb;
                    break;
                case 3:
                    cout << "\nINGRESE EL NUEVO PESO (kg): ";
                    cin >> x[pos].peso;
                    x[pos].imc = x[pos].peso / ((x[pos].talla / 100) * (x[pos].talla / 100));
                    break;
                case 4:
                    cout << "\nINGRESE LA NUEVA TALLA (cm): ";
                    cin >> x[pos].talla;
                    x[pos].imc = x[pos].peso / ((x[pos].talla / 100) * (x[pos].talla / 100));
                    break;
                default:
                    cout << "\nOPCION INVALIDA.\n";
                    break;
            }
        }
        else
        {
            cout << "\nLA HISTORIA CLINICA NO EXISTE.\n";
        }
    }
    else
    {
        cout << "\nEL ARREGLO ESTA VACIO.\n";
    }
}

void ordenar_o(paciente *x, int n)
{
    paciente aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (strcmp(x[j].hc, x[j + 1].hc) > 0)
            {
                aux = x[j];
                x[j] = x[j + 1];
                x[j + 1] = aux;
            }
        }
    }
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
		/*
	if(n>0)
	{
		
	}
	else
	{
		cout<<"ARREGLO VACIO";
		cout<<"\n\n";
		system("pause");
	}
	*/
	
}
