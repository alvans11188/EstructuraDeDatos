#include <iostream>
#include <string>
#define MAX 10
using namespace std;

class cola{
	private:
		string elementos[MAX];
		int frente;
		int final;
	public:
		cola();
		
		bool colaVacia();
		bool colaLlena();
		void insertarCola(string dato);
		string eliminarCola(string dato);
		string verFrente();
		void mostrarCola();
		int contarElementos();
		bool buscarElemento(string dato);
};
//constructor 
cola::cola(){
	frente =-1;
	final= -1;
}
//verifica si la cola esta vacia
bool cola::colaVacia(){
	if(frente==-1){
		return true;
	}else{
		return false;
	}	
}

//verifica si la cola esta llena
bool cola::colaLlena(){
	if(final == MAX - 1){
		return true;
	}else{
		return false;
	}
}
// agregar un elemento a la cola
void cola::insertarCola(string dato){
	if(!colaLlena()){ //verifica si hay espacio libre
		if(colaVacia()){ //se inserta en el primer elemento en la cola
			frente = 0;
			final = 0;
		}else{
			final++;
		}
		elementos[final] = dato;
		cout << dato << " agregado a la cola. "<< endl;
	}else{
		cout << "Desbordamiento - La cola esta llena \n";
		return;
	}
}
//eliminar un elemento de la cola
string cola::eliminarCola(string dato){
	if(!colaVacia()){	
		dato = elementos[frente];
		if(final==frente){
			frente = 0;
			final = 0;
		}else{
			frente = frente +1;
		}
		return dato;
	}else{
		cout<<"subdesbordamiento - la cola esta vacia"<<endl;
		return "";
	}
	
}
//muestra el primer elemento de la cola
string cola::verFrente(){
	if(!colaVacia()){
		return elementos[frente];
	}else{
		cout<<"La cola esta vacia";
		return "";
	}
}
//muestra todos los elementos de la cola
void cola::mostrarCola(){
	if(!colaVacia()){
		cout<<"Los elementos de la cola son: ";
		for(int i=frente;i<=final;i++){
			cout<<elementos[i]<<" ";
		}
	}else{
		cout<<"La cola esta vacia";
		
	}	
}
//retorna el numero de elementos de la cola
int cola::contarElementos(){
	
}
//buscar un elemento en la cla cola
bool cola::buscarElemento(string dato){
	
}
int main(){
	cola cola1;
	string dato;
	int opcion;
	
	do{
		cout<<"\n -- MENU DE COLOA -- \n";
		cout<<"1. Insertar elemento en la cola\n";
		cout<<"2. Eliminar elemento de la cola\n";
		cout<<"3. Ver frente\n";
		cout<<"4. Mostrar cola\n";
		cout<<"5. Contar elementos \n";
		cout<<"0. salir\n";
		cout<<"seleccione una opcion :";
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Ingrese dato a insertar en la cola: ";
				cin>>dato;
				cola1.insertarCola(dato);
				break;
			case 2:
				cout << "Ingrese el dato que desea eliminar: ";
				cin>>dato;
				dato = cola1.eliminarCola(dato);
				if(dato != ""){
					cout<<"Elemento eliminado: "<< dato << endl;
				}
				break;
			case 3:
				dato = cola1.verFrente();
				if(dato != ""){
					cout<<"Elemento en el frente: "<<dato<<endl;
				}
				break;
			case 4:
				cola1.mostrarCola();
				break;
			case 5:
				cout<<"Total de elementos en la cola: "<<cola1.contarElementos()<<endl;
				break;
			case 0:
				cout<<"Programa finalizado.\n";
				break;
			default:
				cout<<"Opcion incorrecta\n";
				
		}
	}while(opcion!=0);
	return 0;
}





















