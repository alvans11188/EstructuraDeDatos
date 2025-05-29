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
		string eliminarCola();
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
string cola::eliminarCola(){
	string dato;
	if(!colaVacia()){	
		dato = elementos[frente];
		if(final==frente){
			frente = -1;
			final = -1;
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
		cout<<"La cola esta vacia\n";
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
		cout<<endl;
	}else{
		cout<<"La cola esta vacia";
		
	}	
}
//retorna el numero de elementos de la cola
int cola::contarElementos(){
	if(!colaVacia()){
		return (final - frente +1);
	}else{
		cout<<"La cola esta vacia";
		return 0;
	}	
}
//buscar un elemento en la cla cola
bool cola::buscarElemento(string dato){
	if(!colaVacia()){
		int i=0;
		while(elementos[i]!=dato&&i<=final){
			i=i+1;
		}
		if(i<=final&&elementos[i]==dato){
			return true;
		}else{
			return false;
		}
	}else{
		cout<<"La cola esta vacia";
		return false;
	}	
}

void evacuacion(){
	//Acaba de ocurrir un accidente y se debe evacuar a todos los pasajeros. Para evacuar de forma ordenada 
    //creas las siguientes colas:
	cola pasajeros_prioritarios;
	cola pasajeros;
	cola tripulacion;
	string persona;
	string opcion;
	
	pasajeros_prioritarios.insertarCola("Juan-pas.prioritario");
	pasajeros.insertarCola("pedro-pasajero");
	tripulacion.insertarCola("Alex - tripulacion");
	pasajeros_prioritarios.insertarCola("Meppo-pas.prioritario");
	pasajeros.insertarCola("Slark-pasajero");
	tripulacion.insertarCola("Clinz - tripulacion");
	cout<<"PASAJEROS ABORDO"<<endl;
	
	pasajeros_prioritarios.mostrarCola();
	pasajeros.mostrarCola();
	tripulacion.mostrarCola();
	
	cout<<"RETIRA LOS PASAJEROS DE FORMA ORDENADA "<<endl;
	
	while(!pasajeros_prioritarios.colaVacia()||!pasajeros.colaVacia()||!tripulacion.colaVacia()){
		
		if(!pasajeros_prioritarios.colaVacia()){
			persona = pasajeros_prioritarios.verFrente();
			cout<<"Desea evacuar a "<<persona<< "? S/N";
			cin>>opcion;
			if((opcion=="s")||(opcion=="S") ){
				cout<<"Evacuando pasajero "<< pasajeros_prioritarios.eliminarCola()<<endl;
			}else{
			}
		}
		if(!pasajeros.colaVacia()){
			persona = pasajeros.verFrente();
			cout<<"Desea evacuar a "<<persona<< "? S/N";
			cin>>opcion;
			if(opcion=="s"||opcion=="s"){
				if(!pasajeros_prioritarios.colaVacia()){
					//opcion="N";
					cout<<"Necesita evacuar a los PASAJEROS PRIORITARIOS PRIMERO"<<endl;
				}else{
					
						cout<<"Evacuando pasajero "<< pasajeros.eliminarCola()<<endl;
					
				}	
			}
		}
		if(!tripulacion.colaVacia()){
			persona = tripulacion.verFrente();
			cout<<"Desea evacuar a "<<persona<< "? S/N";
			cin>>opcion;
			if(opcion=="s"||opcion=="s"){
				if(!pasajeros_prioritarios.colaVacia()||!pasajeros.colaVacia()){
					//opcion="N";
					cout<<"Necesita evacuar a los PASAJEROS PRIORITARIOS PRIMERO y PASAJEROS"<<endl;
				}else{
				
						cout<<"Evacuando pasajero "<< tripulacion.eliminarCola()<<endl;
					
				}	
			}	
		}
	}
	cout<<"TODOS SE SALVARON :V"<<endl;
	cout<<"PROGRAMA FINALIZADO "<<endl;
}

int main(){
	cola cola1;
	string dato;
	int opcion;
	//ingreso de datos 1 2 3
	cola1.insertarCola("1");
	cola1.insertarCola("2");
	cola1.insertarCola("3");
	do{
		cout<<"\n -- MENU DE COLOA -- \n";
		cout<<"1. Insertar elemento en la cola\n";
		cout<<"2. Eliminar elemento de la cola\n";
		cout<<"3. Ver frente\n";
		cout<<"4. Mostrar cola\n";
		cout<<"5. Contar elementos \n";
		cout<<"6. Buscar elemento \n";
		cout<<"7. EVACUACIONNN\n";
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
				
				dato = cola1.eliminarCola();
				if(dato != ""){
					cout<<"Elemento eliminado: "<< dato << endl;
				}else{
					cout<<"No hay elementos en la cola"<<endl;
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
			case 6:
				cout<<"Que elemento desea buscar"<<endl;
				cin>>dato;
				
				if(cola1.buscarElemento(dato)){
					cout<<"Elemento encontrado"<<endl;
				}else{
					cout<<"No se encontro el elemento"<<endl;
				}
				break;
			case 7:
				evacuacion();
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





















