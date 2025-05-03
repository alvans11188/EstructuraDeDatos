#include<iostream>
using namespace std;

struct nodo 
{
	int inf;
	nodo *sigder;
	nodo *sigizq;
};

void recorrerDesdeInicio(nodo *p)
{
	nodo *q = p;
	cout << "Recorrido de inicio a fin: ";
	while (q!= NULL)
	{
		cout << q->inf<< " ";
		q=q->sigder;
	}
	cout << endl;
}

//recorrido de la lista desde el final
void recorrerDesdeFinal(nodo *f)
{
	nodo *q=f;
	cout<<"recorrido de fin a inicio: ";
	while(q!=NULL)
	{
		cout<<q->inf<<" ";
		q=q->sigizq;
	}
	cout<<endl;
}

void insertar_principio(nodo *&p,nodo *&f,int dato)
{
	nodo *q = new nodo();
	q->inf=dato;
	if(p==NULL)
	
		p=f=q;
	
	else
	{
		q->sigder=p;
		p->sigizq=q;
		q->sigizq=NULL;
		p=q;
	}
}
void inserta_final(nodo *&p, nodo *&f, int dato)
{
	nodo* q=new nodo();
	q->inf=dato;
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
//insercion antes de un nodo con dota X
void inserta_antes_x(nodo *&p,int dato, int x)
{
	nodo *q=p;
	while(q->sigder!=NULL&&q->inf!=x)
	{
		q=q->sigder;
	}
	if(q->inf==x)
	{
		nodo *t=new nodo();
		t->inf=dato;
		t->sigder=q;
		
		nodo *r=q->sigizq;
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
//insercion despues de un nodo con dota X
void inserta_despues_x(nodo *&p,int dato, int x)
{
	nodo *q=p;
	while(q->sigder!=NULL&&q->inf!=x)
	{
		q=q->sigder;
	}
	if(q->inf==x)
	{
		nodo *t=new nodo();
		t->inf=dato;
		t->sigizq=q;
		
		nodo *r=q->sigder;
		q->sigder=t;
		
		if(p==q)
		{
			p=t;
			t->sigder=NULL;
		}
		else
		{
			r->sigizq=t;
			t->sigder=r;
		}
	}
	else
	{
		cout<<"No se encontro el dato "<< x << "en la lista. "<<endl;
		
	}
}
void contar_concurrencias(nodo *&p,int dato)
{
	nodo *q;int i=0;
	q=p;
	while(q!=NULL)
	{
		if(q->inf==dato)
			i++;
		q=q->sigder;
	}
	cout<<"Datos contados con el valor ["<<dato <<"] repetidor: "<<i<<" veces"<<endl;;
}
void invertir(nodo *&p, nodo *&f)
{
	nodo *temp;
	nodo *q;
	q=p;
	temp=NULL;
	while(q!=NULL)
	{
		temp=q->sigizq;
		q->sigizq=q->sigder;
		q->sigder=temp;
		q=q->sigizq;
	}
	temp=p;
	p=f;
	f=temp;
}
void elimina_inicio(nodo *&p,nodo *&f)
{
	
}
void elimina_ultimo(nodo *&p,nodo *&f)
{
	
}
void elimina_x(nodo *&p,nodo *&f,int x)
{
	
}
void elimina_antes_x(nodo *&p,nodo *&f,int x)
{
	
}
void menu()
{
	nodo *p=NULL;
	nodo *f=NULL;
	int opcion, dato, x;
	
	do
	{
		system("cls");
		cout<<"\n---MENU---"<<endl;
		cout<<"1. Insertar al inicio "<<endl;
		cout<<"2. Insertar al final "<<endl;
		cout<<"3. Insertar antes de un nodo con dato X"<<endl;
		cout<<"4. Insertar despues de un nodo con dato X"<<endl;
		cout<<"5. mostrar lista de inicio a fin"<<endl;
		cout<<"6. Mostrar lisa de fin a inicio"<<endl;
		cout<<"7. Contar concurrencias"<<endl;
		cout<<"8. Invertir elementos"<<endl;
		cout<<"9. Elimina el primer nodo"<<endl;
		cout<<"10. Eliminar el ultimo nodo"<<endl;
		cout<<"11. Eliminar el nodo con informacion x"<<endl;
		cout<<"12. Eliminar el nodo anterior al nodo con informacion X"<<endl;
		cout<<"0. salir "<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch (opcion)
		{
			case 1:
				system("cls");
				cout<<"Dato a insertar al inicio: ";
				cin>>dato;
				insertar_principio(p,f,dato);
				break;
				
			case 2:
				system("cls");
				cout<<"Dato a insertar al final: ";
				cin>>dato;
				inserta_final(p,f,dato);
				break;
				
			case 3:
				system("cls");
				cout<<"Dato a insertar: ";
				cin>>dato;
				cout<<"Antes del nodo con dato: ";
				cin>>x;
				inserta_antes_x(p,dato,x);
				break;
			case 4:
				cout<<"Dato a insertar: ";
				cin>>dato;
				cout<<"Despues del nodo con dato: ";
				cin>>x;
				inserta_despues_x(p,dato,x);
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
			case 8:
				system("cls");
				invertir(p,f);
				system("pause");
				break;
			case 9:
				system("cls");
				elimina_inicio(p,f);
				system("pause");
				break;
			case 10:
				system("cls");
				elimina_ultimo(p,f);
				system("pause");
				break;
			case 11:
				system("cls");
				cout<<"Ingrese el valor que desea eliminar"<<endl;
				cin>>x;
				elimina_x(p,f,x);
				system("pause");
				break;
			case 12:
				system("cls");
				cout<<"Ingrese el valor referencial para eliminar su anterior"<<endl;
				cin>>x;
				elimina_antes_x(p,f,x);
				system("pause");
				break;
			case 0:
				cout<<"Programa finalizado."<<endl;
				break;
			default:
				cout<<"Opcion invalida. "<<endl;
		}
	} while (opcion!=0);	
}

int main()
{
	menu();
	/*
	nodo *p=NULL;
	nodo *f=NULL;
	inserta_principio(p,f,1);
	inserta_principio(p,f,3);
	inserta_principio(p,f,4);
	inserta_principio(p,f,5);
	recorrerDesdeInicio(p);
	*/
	/*
	int ocurrencias = 0;
	nodo *p=NULL;
	nodo *f=NULL;
	inserta_final(p,f,1);
	inserta_final(p,f,3);
	inserta_final(p,f,5);
	inserta_final(p,f,7);
	recorrerDesdeInicio(p);
	invertir(p,f);
	recorrerDesdeInicio(p);
	inserta_principio(p,f,1);
	recorrerDesdeInicio(p);
	int nro=1;
	ocurrencias = contar_ocurrencias(p,nro);
	cout<<"El numero "<<nro<<" se repite: "<< ocurrencias <<" veces.";
	
	*/
	return 0;
}

	
	
	