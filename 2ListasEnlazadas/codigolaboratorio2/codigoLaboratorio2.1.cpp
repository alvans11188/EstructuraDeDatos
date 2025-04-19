//Codigo de laboratorio 2 adaptado al codigo de laboratorio 1, usando un historial clinico
#include<iostream>
using namespace std;
struct paciente
{
	char hc[15], nomb[20];
	float peso, talla, imc;
	paciente *sig;
};

paciente *crea_i(paciente *);

void recorre(paciente *);
int main()
{	
	char codigo[20];
	paciente *p=NULL;
	int op;
	do
	{
		system("cls");
		cout<<"\nLISTAS ENLAZADAS HISTORIAL CLINICO";
		cout<<"\n================";
		cout<<"\n\n1. CREAR POR EL INICIO";
		cout<<"\n\n2. CREAR POR EL FINAL";
		cout<<"\n\n3. INSERTAR AL INICIO";
		cout<<"\n\n4. INSERTAR AL FINAL";
		cout<<"\n\n5. INSERTAR ANTES DE";
		cout<<"\n\n6. INSERTAR DESPUES DE";
		cout<<"\n\n7. ELIMINAR EL PRIMER NODO";
		cout<<"\n\n8. ELIMINAR EL ULTIMO NODO";
		cout<<"\n\n9. ELIMINAR UN NODO ESPECIFICO";
		cout<<"\n\n10. ELIMINAR EL NODO ANTERIOR A ";
		cout<<"\n\n11. ELIMINAR EL NODO POSTERIOR A ";
		cout<<"\n\n12. M O S T R A R ";
		cout<<"\n\n13. S A L I R ";
		cout<<"\n\n\t\t\t OPCION: ";
		cin>>op;
		switch(op)
		{
			case 1:
				system("cls");
				p=NULL;
				p=crea_i(p);
				break;
			/*
			case 2:
				system("cls");
				p=NULL;
				p=crea_f(p);
				break;
			case 3:
				system("cls");
				p=inserta_f(p);
				break;
			case 4:
				system("cls");
				p=inserta_f(p);
				break;
			case 5:
				system("cls");
				cout<<"Ingrese un nombre referencial a buscar:";
				cin>>codigo;
				p=inserta_ad(p,codigo);
				break;
			case 6:
				system("cls");
				cout<<"Ingrese un nombre referencial a buscar :";
				cin>>codigo;
				p=inserta_dd(p,codigo);
				break;
			case 7:
				system("cls");
				p=eliminar_p(p);
				break;
			case 8:
				system("cls");
				p=eliminar_u(p);
				break;
			case 9:
				system("cls");
				cout<<"Ingrese un nombre a eliminar :";
				cin>>codigo;
				p=eliminar_x(p,codigo);
				break;
			case 10:
				system("cls");
				cout<<"Ingrese un nombre referencial a eliminar anteriormente :";
				cin>>codigo;
				p=eliminar_ad(p,codigo);
				break;
			case 11:
				system("cls");
				cout<<"Ingrese un nombre referencial a eliminar posteriormente :";
				cin>>codigo;
				p=eliminar_dd(p,codigo);
				break;
			*/
			case 12:
				system("cls");
				recorre(p);
				system("pause");
				break;
			
			case 13:
				cout<<" S A L I E N D O   D E L   P R O G R A M A  \n"<<endl;
				break;
		}
	}
	while(op>0&&op<13);	
	return 0;
}

paciente *crea_i(paciente *p)
{
	paciente *q;
	char op;
	do
	{
		system("cls");
		q=new(paciente);
		cout<<"\n\nHISTORIAL CLINICO:  "; cin>>q->hc;
		cout<<"\n\nNOMBRE:   "; cin>>q->nomb;
		cout<<"\n\nPESO:    "; cin>>q->peso;
		cout<<"\n\nTALLA:    "; cin>>q->talla;
		q->imc=(q->peso/(q->talla*q->talla));
		q->sig=p;
		p=q;
		cout<<"\n\n\t\t\tMAS DATOS (S/N)?   ";
		cin>>op;
	}
	while(op=='s'||op=='S');
	return(p);
}
void recorre(paciente *p)
{
	paciente *q;
	int i=0;
	system("cls");
	q=p;
	cout<<"\n\n\tLISTA DE DATOS: \n";
	cout<<"\t===============";
	while(q!=NULL)
	{
		cout<<"\nx["<<i+1<<"] : \n\n";
		cout<<"\n\n\t\tHISTORIA CLINICA		:"<<q->hc;
		cout<<"\n\n\t\tNOMBRE	: "<<q->nomb;
		cout<<"\n\n\t\tPESO 	: "<<q->peso<<" kg.";
		cout<<"\n\n\t\tTALLA	: "<<q->talla<<" cm.";
		cout<<"\n\n\t\tINDICE DE MASA CORPORAL	: "<<q->imc;
		q=q->sig;
	}
	cout<<"\n\n";
	system("pause");
}
