//codigo de laboratorio 3 Listas doblemente enlazadas, adaptado al historial clinico , de la practica 1

#include<iostream>
using namespace std;

struct paciente
{
	char hc[15],nomb[20];
	float peso, talla, imc;
	paciente *sigder;
	paciente *sigizq;
};

void recorrerDesdeInicio(paciente *);
void recorrerDesdeFinal(paciente *);
void insertar_principio(paciente *&, paciente *&, int);
void insertar_final(paciente *&, paciente *&, int);
void insertar_antes_x(paciente *&, const char [] );

void insertar_despues_x(paciente *& , const char[] );

void contar_concurrencias(paciente *&,int );
void invertir(paciente *&,paciente *&);

int main()
{
	paciente *p=NULL;
	paciente *f=NULL;
	int opcion, dato;
	char x[15];
	
	do
	{
		system("cls");
		cout<<"\n---MENU---"<<endl;
		cout<<"1. Insertar al inicio "<<endl;
		cout<<"2. Insertar al final "<<endl;
		cout<<"3. Insertar antes de un paciente con dato X"<<endl;
		cout<<"4. Insertar despues de un paciente con dato X"<<endl;
		cout<<"5. mostrar lista de inicio a fin"<<endl;
		cout<<"6. Mostrar lisa de fin a inicio"<<endl;
		cout<<"7. Contar concurrencias"<<endl;
		cout<<"8. Invertir elementos"<<endl;
		cout<<"0. salir "<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch (opcion)
		{
			case 1:
				system("cls");
				/*
				cout<<"Dato a insertar al inicio: ";
				cin>>dato;
				*/
				insertar_principio(p,f,dato);
				break;
				
			case 2:
				system("cls");
				/*
				cout<<"Dato a insertar al final: ";
				cin>>dato;
				*/
				insertar_final(p,f,dato);
				break;
				
			case 3:
				system("cls");
				
				cout<<"Antes del historial clinico numero: ";
				cin>>x;
				insertar_antes_x(p,x);
				break;
			case 4:
				
				cout<<"Despues del  con dato: ";
				cin>>x;
				insertar_despues_x(p,x);
				break;
			case 5:
				system("cls");
				recorrerDesdeInicio(p);
				system("pause");
				break;
			case 6:
				system("cls");
				recorrerDesdeFinal(f);
				system("pause");
				break;
			case 7:
				system("cls");
				cout<<"Dato a buscar sus concurrencias: ";
				cin>>dato;
				contar_concurrencias(p,dato);
				system("pause");
				break;
			case 8:
				system("cls");
				invertir(p,f);
				system("pause");
				break;
			case 0:
				cout<<"Programa finalizado."<<endl;
				break;
			default:
				cout<<"Opcion invalida. "<<endl;
		}
	} while (opcion!=0);	
	return 0;
}

void recorrerDesdeInicio(paciente *p)
{
	paciente *q;
	int i=0;
	system("cls");
	q=p;
	cout<<"\n\n\tLISTA DE DATOS: \n";
	cout<<"\t===============";
	while(q!=NULL)
	{
		i=i+1;
		cout<<"\nx["<<i<<"] : \n\n";
		cout<<"\n\n\t\tHISTORIA CLINICA		:"<<q->hc;
		cout<<"\n\n\t\tNOMBRE	: "<<q->nomb;
		cout<<"\n\n\t\tPESO 	: "<<q->peso<<" kg.";
		cout<<"\n\n\t\tTALLA	: "<<q->talla<<" cm.";
		cout<<"\n\n\t\tINDICE DE MASA CORPORAL	: "<<q->imc;
		q=q->sigder;	
	}
	cout<<"\n\n";
}
//recorrido de la lista desde el final
void recorrerDesdeFinal(paciente *f)
{
	paciente *q;
	int i=0;
	system("cls");
	q=f;
	cout<<"\n\n\tLISTA DE DATOS: \n";
	cout<<"\t===============";
	while(q!=NULL)
	{
		i=i+1;
		cout<<"\nx["<<i<<"] : \n\n";
		cout<<"\n\n\t\tHISTORIA CLINICA		:"<<q->hc;
		cout<<"\n\n\t\tNOMBRE	: "<<q->nomb;
		cout<<"\n\n\t\tPESO 	: "<<q->peso<<" kg.";
		cout<<"\n\n\t\tTALLA	: "<<q->talla<<" cm.";
		cout<<"\n\n\t\tINDICE DE MASA CORPORAL	: "<<q->imc;
		q=q->sigizq;	
	}
	cout<<"\n\n";
}
void insertar_principio(paciente *&p, paciente *&f, int dato)
{
    paciente *q = new paciente();
    system("cls");
    cout<<"\n\nHISTORIAL CLINICO:  "; cin>>q->hc;
    cout<<"\n\nNOMBRE:   "; cin>>q->nomb;
    cout<<"\n\nPESO:    "; cin>>q->peso;
    cout<<"\n\nTALLA:    "; cin>>q->talla;
    q->imc = (q->peso / (q->talla * q->talla));

    q->sigder = p;    
    q->sigizq = NULL; 

    if (p != NULL)
        p->sigizq = q; 

    p = q; 

    if (f == NULL)
        f = q; 
}

void insertar_final(paciente *&p, paciente *&f, int dato)
{
	paciente *q;
	q=new paciente();
	system("cls");
    cout<<"\n\nHISTORIAL CLINICO:  "; cin>>q->hc;
    cout<<"\n\nNOMBRE:   "; cin>>q->nomb;
    cout<<"\n\nPESO:    "; cin>>q->peso;
    cout<<"\n\nTALLA:    "; cin>>q->talla;
    q->imc = (q->peso / (q->talla * q->talla));
	
	if(f==NULL)
	{
		p=f=q;
	}
	else
	{
		f->sigder=q;
		q->sigizq=f;
		q->sigder=NULL;
		f=q;
	}
	
}
//insercion antes de un paciente con dota X
void insertar_antes_x(paciente *&p,int dato, const char x[])
{
	paciente *q=p;
	while(q->sigder!=NULL&&(strcmp(q->hc,x)!=0))
	{
		q=q->sigder;
	}
	if((strcmp(q->hc,x)==0))
	{
		paciente *t=new paciente();
		system("cls");
	    cout<<"\n\nHISTORIAL CLINICO:  "; cin>>t->hc;
	    cout<<"\n\nNOMBRE:   "; cin>>t->nomb;
	    cout<<"\n\nPESO:    "; cin>>t->peso;
	    cout<<"\n\nTALLA:    "; cin>>t->talla;
	    t->imc = (t->peso / (t->talla * t->talla));
		strcpy(t->hc,dato);

		t->sigder=q;
		
		paciente *r=q->sigizq;
		q->sigizq=t;
		
		if(p==q)
		{
			p=t;
			t->sigizq=NULL;
		}
		else
		{
			r->sigder=t;
			t->sigizq=r;
		}
	}
	else
	{
		cout<<"No se encontro el dato "<< x << "en la lista. "<<endl;
		return;
	}
}
//insercion despues de un paciente con dota X
void insertar_despues_x(paciente *&p,int dato, int x)
{

}
void contar_concurrencias(paciente *&p,int dato)
{

}
void invertir(paciente *&p, paciente *&f)
{

}