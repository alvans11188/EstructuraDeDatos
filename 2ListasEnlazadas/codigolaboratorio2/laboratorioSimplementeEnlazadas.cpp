#include <iostream>
using namespace std;

struct nodo{
	int inf;
	nodo *sig;	
};

nodo *insertaInicio(nodo *p,int dato){
	nodo *q;
	q=new nodo();
	q->inf=dato;
	q->sig=p;
	p=q;
	return(p);
}
void recorreIterativo(nodo *p){
	nodo *q;
	q=p;
	if(q!=NULL){
		while(q!=NULL){
			cout<<q->inf<< " ";
			q=q->sig;
		}
	}else{
		cout<<"La lista esta vacia"<<endl;
	}
	
}
nodo *insertaFinal(nodo *&p,int dato){
	nodo *q,*r;
	q=p;
	if(p==NULL){
		q=new nodo();
		q->inf=dato;
		q->sig=p;
		p=q;
	}else{
		while(q->sig!=NULL){
			q=q->sig;
		}
		r=new nodo();
		r->inf=dato;
		r->sig=NULL;
		q->sig=r;	
	}
	return(p);
}
int buscar(nodo *p, int ref){
	nodo *q;
	int i=0;
	int pos;
	q=p;
	while(q!=NULL&&q->inf!=ref){
		q=q->sig;
		i++;
	}
	if(q!=NULL||q->inf==ref){
		pos=-1*i;
	}else{
		pos=i;
	}
	return(pos);
	
}

nodo *inserta_antes_X(nodo *&p,int dato,int ref){
	nodo *q,*r;
	if(p!=NULL){
		q=p;
		
		while(q!=NULL&&q->inf!=ref){
			r=q;
			q=q->sig;
		}
		if(q==p){
			nodo *t;
			t=new nodo();
			t->inf=dato;
			t->sig=q;
			p=t;
		}else{
			if(q->inf==ref){
				nodo *t;
				t=new nodo();
				t->inf=dato;
				t->sig=q;
				r->sig=t;
			}else{
				cout<<"Dato referencial no encontrado"<<endl;
			}
		}	
	}else{
		cout<<"La lista esta vacia"<<endl;
	}
	return(p);
}
nodo *inserta_despues_X(nodo *&p,int dato,int ref){
	nodo *q,*r,*t;
	if(p!=NULL){
		q=p;
		r=q;
		while((r!=NULL&&q!=NULL)&&r->inf!=ref){
			r=q;
			q=q->sig;
		}
		if(r->inf==ref&&q==NULL){
			t=new nodo();
			t->inf=dato;
			t->sig=NULL;
			r->sig=t;
		}else{
			if(r->inf==ref){
				t=new nodo();
				t->inf=dato;
				t->sig=q;
				r->sig=t;
			}else{
				cout<<"Dato referencial no encontrado"<<endl;
			}
		}
	}else{
		cout<<"Lista vacia"<<endl;
	};
	return(p);
}

nodo *recorreInvertido(nodo *p){
	nodo *temp;
	
	
}

void menu(){
	nodo *p=NULL;
	p=insertaFinal(p, 1);
	p=insertaFinal(p, 2);
	p=insertaFinal(p, 3);
	recorreIterativo(p);
   
    int opcion, dato, ref;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar antes de un nodo con dato X" << endl;
        cout << "4. Insertar después de un nodo con dato X" << endl;
        cout << "5. Mostrar lista de inicio a fin" << endl;
        cout << "6. Mostrar lista de fin a inicio" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "dato a insertar al inicio: ";
                cin >> dato;
                p=insertaInicio(p, dato);
                break;
            case 2:
                cout << "dato a insertar al final: ";
                cin >> dato;
                p=insertaFinal(p, dato);
                break;
            case 3:
                cout << "dato a insertar: ";
                cin >> dato;
                cout << "Antes del nodo con dato: ";
                cin >> ref;
                inserta_antes_X(p, dato, ref);
                break;
            case 4:
                cout << "dato a insertar: ";
                cin >> dato;
                cout << "Después del nodo con dato: ";
                cin >> ref;
                inserta_despues_X(p, dato, ref);
                break;
            case 5:
                recorreIterativo(p);
                break;
            case 6:
                recorreInvertido(p);
                break;
            
            case 0:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);
}



int main(){
	
	
	menu();
	return 0;
}