#include <iostream>
#include <string>
#define MAX 6
using namespace std;

class Pila{
	private:
		string elementos[MAX];
		int tope;
	public:
		Pila();
		
		bool pilaVacia();
		bool pilaLlena();
		void agregarPila(string dato);
		string sacarPila();
		

};

//constructor
Pila::Pila(){
	tope=-1; //pila vacia
}
//metodo para verificar si la pila esta vacia
bool Pila::pilaVacia(){
	if(tope==-1){
		return true;
	}else{
		return false;
	}
}
//metodo para verificar si la pila esta llena
bool Pila::pilaLlena(){
	if(tope == MAX -1){
		return true;
	}else{
		return false;
	}
}
//metodo para agregar un elemento a la pila (push)
void Pila::agregarPila(string dato){
	if(pilaLlena()){
		cout<<"Desbordamiento - pila llena. no se puede agregar mas elementos."<<endl;
		return;
	}else{
		tope++;
		elementos[tope] = dato;
	}
}

//metodo para eliminar el elemento superior de la pila(pop)
string Pila::sacarPila(){
	if(pilaVacia()){
		cout<<"Subdesbordamiento - pila vacia. no se puede sacar elemento"<<endl;
		return (0);
	}else{
		string dato = elementos[tope];
		tope--;
		return dato;
	}
}

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
		void invertirElementos();
		void eliminarDeterminado(string dato);
		
		void duplicarElementosCola();
		void ordenarElementosCola();
		void desplazarElementoCola();
		
		//COLAS CIRCULARES
		//bool colaVaciaCircular();
		bool colaLlenaCircular();
		void insertaCircular(string dato);
		string eliminarCircular();
		void mostrarCircular();
		int contarCircular();
		bool buscarCircular(string dato);
		void eliminarParesCircular();
		void eliminarImparesCircular();
		void eliminarRepetidosCircular();
		void duplicarElementosColaCircular();
		void rotarPosicionesCircular(int posiciones);
		void ordenarElementosColaCircular();
		void rotarPosiciones2Circular(int posiciones);
		
		//PRU
		void insertarPares(string dato);
		void eliminarPares();
		void eliminarImpares();
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
		//cout << dato << " agregado a la cola. "<< endl;  // solo lo coloque como comentario porque no necesito imprimirlo
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
		//cout<<"La cola esta vacia\n";
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
// invertir elementos en la cola
void cola::invertirElementos(){
	string dato;
	Pila pila1;
	
	if(colaVacia()==false){
		while(colaVacia()!=true){
			dato=eliminarCola();
			pila1.agregarPila(dato);
		}
		frente=-1;
		final=-1;
		
		while(pila1.pilaVacia()==false){
			dato=pila1.sacarPila();
			insertarCola(dato);
		}
		
	}else{
		cout<<"La cola esta vacia"<<endl;
	}
}
//eliminar un determinado elemento 
void cola::eliminarDeterminado(string dato){
	string elemento;
	cola temp;
	if(colaVacia()==false){
		while(colaVacia()!=true){
			elemento=eliminarCola();
			if(elemento!=dato){
				temp.insertarCola(elemento)	;
			}
		}
		frente=-1;
		final=-1;
		while(temp.colaVacia()!=true){
			elemento=temp.eliminarCola();
			insertarCola(elemento);
		}
	}else{
		cout<<"La cola esta vacia"<<endl;
	}
}
//PRUB
void cola::insertarPares(string dato){
	// Convertimos el string a int
    int numero = stoi(dato);

    // Verificamos si es par
    if (numero % 2 == 0) {
        if(!colaLlena()){
            if(colaVacia()){
                frente = 0;
                final = 0;
            } else {
                final++;
            }
            elementos[final] = dato;
        } else {
            cout << "Desbordamiento - La cola esta llena \n";
        }
    } else {
        cout << "El numero no es par, no se insertara.\n";
    }
}
void cola::eliminarImpares(){
    string elemento;
    cola temporal;
    int numero;

    if(colaVacia()){
        cout << "La cola está vacía, no hay elementos para eliminar." << endl;
        return;
    }

    while(!colaVacia()){
        elemento = eliminarCola();
        numero=stoi(elemento);
        
        // Si es impar, lo conservamos
        if (numero % 2 != 0) {
            temporal.insertarCola(elemento);
        }
    }

    // Restauramos la cola original con solo impares
    while(!temporal.colaVacia()){
        insertarCola(temporal.eliminarCola());
    }
}
void cola::eliminarPares(){
    string elemento;
    cola temporal;
    int numero;

    if(colaVacia()){
        cout << "La cola está vacía, no hay elementos para eliminar." << endl;
        return;
    }

    while(!colaVacia()){
        elemento = eliminarCola();
        numero=stoi(elemento);
        
        // Si es impar, lo conservamos
        if (numero % 2 == 0) {
            temporal.insertarCola(elemento);
        }
    }

    // Restauramos la cola original con solo impares
    while(!temporal.colaVacia()){
        insertarCola(temporal.eliminarCola());
    }
}
void cola::eliminarRepetidosCircular(){
    if (colaVacia()) {
        cout << "La cola circular está vacía.\n";
        return;
    }

    cola auxiliar;
    string actual, comparado;
    bool duplicado;

    int cantidad = contarCircular();

    for (int i = 0; i < cantidad; i++) {
        actual = eliminarCircular();
        duplicado = false;

        // Verificamos si ya fue insertado en auxiliar
        int cantidadAux = auxiliar.contarCircular();
        for (int j = 0; j < cantidadAux; j++) {
            comparado = auxiliar.eliminarCircular();
            if (actual == comparado) {
                duplicado = true;
            }
            auxiliar.insertaCircular(comparado);  // Restauramos elemento
        }

        if (!duplicado) {
            auxiliar.insertaCircular(actual);
        }
    }

    // Restauramos los elementos sin duplicados a la cola original
    while (!auxiliar.colaVacia()) {
        insertaCircular(auxiliar.eliminarCircular());
    }

    cout << "Elementos repetidos eliminados correctamente.\n";
}
void cola::duplicarElementosCola() {
    if (colaVacia()) {
        cout << "La cola esta vacia" << endl;
        return;
    }

    cola aux;
    string elemento;

    while (!colaVacia()) {
        elemento = eliminarCola();
        aux.insertarCola(elemento); // duplicado
        aux.insertarCola(elemento);
    }

    // Restaurar elementos a la cola original
    while (!aux.colaVacia()) {
        insertarCola(aux.eliminarCola());
    }
}
void cola::ordenarElementosCola(){
    if(colaVacia()){
        cout << "La cola está vacía." << endl;
        return;
    }

    int total = contarElementos();
    int datos[MAX];
    string temp;

    // Paso 1: Copiar elementos a un arreglo
    for(int i = 0; i < total; i++){
        temp = eliminarCola();
        datos[i] = stoi(temp); // convertir a int
    }

    // Paso 2: Ordenar el arreglo (burbuja)
    for(int i = 0; i < total - 1; i++){
        for(int j = 0; j < total - i - 1; j++){
            if(datos[j] > datos[j + 1]){
                int aux = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = aux;
            }
        }
    }

    // Paso 3: Insertar ordenados en la cola (como string)
    for(int i = 0; i < total; i++){
        insertarCola(to_string(datos[i]));
    }

    cout << "Cola ordenada correctamente." << endl;
}

void intercalarColas(cola A, cola B, cola& resultado) {
    while (!A.colaVacia() || !B.colaVacia()) {
        if (!A.colaVacia()) {
            resultado.insertarCola(A.eliminarCola());
        }
        if (!B.colaVacia()) {
            resultado.insertarCola(B.eliminarCola());
        }
    }
}	
void cola::desplazarElementoCola() {
    if (colaVacia()) {
        cout << "La cola está vacía, no se puede desplazar.\n";
        return;
    }
	
    string primero = eliminarCola();
    //string elemento;
	cola temp;
	
    while (!colaVacia()) {
        temp.insertarCola(eliminarCola());
    }
	while(!temp.colaVacia()){
		
		insertarCola(temp.eliminarCola());
	}
    insertarCola(primero);
    cout << "Desplazamiento completado.\n";
}


// COLAS CIRCULARES
//verificar si esta vacia la cola circula
/*
bool cola::colaVaciaCircular(){
	return (frente==-1);
}
*/

//verificar si esta llena la cola circula
bool cola::colaLlenaCircular(){
	if((final+1)==frente || (frente == 0 && final == MAX-1)){
		return true;
	}else{
		return false;
	}
}

//insertar un elemento en una cola circular
void cola::insertaCircular(string dato){
	if(colaLlenaCircular()){
		cout<<"Desbordamiento - cola llena";
	}else{
		if(colaVacia()==true){
			frente=0;
			final=0;
		}else{
			if(final==MAX-1){
			final=0;
			}else{
				final++;
			}
		}
		elementos[final]=dato;
	}
}

//eliminar un elemento en una cola circular
string cola::eliminarCircular(){
	string dato;
	if(colaVacia()==true){
		return "";
	}else{
		dato=elementos[frente];
		if(frente==final){
			frente=-1;
			final=-1;
		}else{
			if(frente==MAX-1){
				frente=0;
			}else{
				frente++;
			}
		}
	}
	
	return dato;
}
//mostrar cola circular
void cola::mostrarCircular(){
    if (colaVacia()) {
        cout << "La cola esta vacia\n" << endl;
        return;
    }

    cout << "Los elementos de la cola circular son: ";

    if (frente <= final) {
        
        for (int i = frente; i <= final; i++) {
            cout << elementos[i] << " ";
        }
    } else {
        
        for (int i = frente; i < MAX; i++) {
            cout << elementos[i] << " ";
        }
        for (int i = 0; i <= final; i++) {
            cout << elementos[i] << " ";
        }
    }

    cout << endl;
}
//contar elementos de una cola circular
/*
int cola::contarCircular(){
	int total;
	if(colaVacia()){
		return 0;
	}else{
		if(frente<=final){
			total=(final-frente);
		}else{
			for (int i = frente; i < MAX; i++) {
            	total++;
	        }
	        for (int i = 0; i <= final; i++) {
	            total++;
	        }
		}
	}
	total++;
	return total;
}
*/
int cola::contarCircular(){
    if (colaVacia()) return 0;
    if (frente <= final)
        return final - frente + 1;
    else
        return (MAX - frente) + (final + 1);
}

//buscar elementos en una cola circula
bool cola::buscarCircular(string dato){
	bool band;
	if(colaVacia()){
		return false;
	}else{
	  	for (int i = frente; i < MAX; i++) {
            if(elementos[i]==dato){
            	return true;
			}
        }
        for (int i = 0; i <= final; i++) {
            if(elementos[i]==dato){
            	return true;
			}
        }
	}
	return false;
}
//eliminar impares circular
void cola::eliminarParesCircular(){
    cola aux;
    string dato;
    int valor;

    int cantidad = contarCircular();

    for (int i = 0; i < cantidad; i++) {
        dato = eliminarCircular();
        if (dato != "") {
            valor = stoi(dato);
            if (valor % 2 == 0) {
                aux.insertaCircular(dato);
            }
        }
    }

    while (!aux.colaVacia()) {
        insertaCircular(aux.eliminarCircular());
    }
}
//eliminar pares circular
void cola::eliminarImparesCircular(){
    cola aux;
    string dato;
    int valor;

    int cantidad = contarCircular();

    for (int i = 0; i < cantidad; i++) {
        dato = eliminarCircular();
        if (dato != "") {
            valor = stoi(dato);
            if (valor % 2 != 0) {
                aux.insertaCircular(dato);
            }
        }
    }

    while (!aux.colaVacia()) {
        insertaCircular(aux.eliminarCircular());
    }
}
void cola::duplicarElementosColaCircular() {
    if (colaVacia()) {
        cout << "La cola está vacía" << endl;
        return;
    }

    cola aux;
    string dato;
    int cantidad = contarCircular();

    // Extraer todos los elementos, duplicarlos en aux
    for (int i = 0; i < cantidad; i++) {
        dato = eliminarCircular();
        aux.insertaCircular(dato);
        aux.insertaCircular(dato);
    }

    // Restaurar los elementos duplicados a la cola original
    while (!aux.colaVacia()) {
        insertaCircular(aux.eliminarCircular());
    }

    cout << "Elementos duplicados correctamente.\n";
}
/*
void cola::rotarPosicionesCircular(int posiciones) {
    if (colaVacia()) {
        cout << "La cola circular esta vacia.\n";
        return;
    }

    int cantidad = contarCircular();

    // Aseguramos que no rote más veces que el número de elementos
    posiciones = posiciones % cantidad;

    for (int i = 0; i < posiciones; i++) {
        string dato = eliminarCircular();
        insertaCircular(dato);
    }

    cout << "Rotacion completada.\n";
}
*/
void cola::ordenarElementosColaCircular() {
    if (colaVacia()) {
        cout << "La cola circular esta vacía, no se puede ordenar.\n";
        return;
    }

    int cantidad = contarCircular();
    int arreglo[MAX]; // Arreglo auxiliar (máximo MAX elementos)

    // Paso 1: Copiar elementos en arreglo auxiliar
    for (int i = 0; i < cantidad; i++) {
        arreglo[i] = stoi(eliminarCircular()); // Convertimos de string a int
    }

    // Paso 2: Ordenar arreglo (burbuja)
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }

    // Paso 3: Insertar de nuevo en la cola circular (convertir de int a string)
    for (int i = 0; i < cantidad; i++) {
        insertaCircular(to_string(arreglo[i]));
    }

    cout << "Cola circular ordenada correctamente.\n";
}

void cola::rotarPosicionesCircular(int posiciones){
	if(!colaVacia()){
		cola temp;
		string elemento,elemento2;
		elemento=eliminarCola();
		
		while(!colaVacia()){
			elemento2=eliminarCola();
			temp.insertarCola(elemento2);
		}
		
		while(!temp.colaVacia()){
			elemento2=temp.eliminarCola();
			insertarCola(elemento2);
		}
		insertarCola(elemento);
	}else{
		cout<<"La cola esta vacia"<<endl;
	}
}
void cola::rotarPosiciones2Circular(int posiciones){
	if (colaVacia()) {
        cout << "La cola circular está vacía.\n";
        return;
    }

    int cantidad = contarCircular();
    posiciones = posiciones % cantidad;

    string arreglo[MAX];

    // Extraer todos los elementos
    for (int i = 0; i < cantidad; i++) {
        arreglo[i] = eliminarCircular();
    }

    // Rotar a la derecha
    for (int i = 0; i < posiciones; i++) {
        string ultimo = arreglo[cantidad - 1];
        for (int j = cantidad - 1; j > 0; j--) {
            arreglo[j] = arreglo[j - 1];
        }
        arreglo[0] = ultimo;
    }

    // Insertar los elementos rotados
    for (int i = 0; i < cantidad; i++) {
        insertaCircular(arreglo[i]);
    }

    cout << "Rotación inversa completada.\n";
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
void jugadores(){
	cola jugador;
	string opcion;
	int turno=0;
	jugador.insertarCola("Alex");
	jugador.insertarCola("Juan");
	jugador.insertarCola("Pepe");
	jugador.insertarCola("Joshua");
	while(!jugador.colaVacia()){
		turno++;
		cout<<"**TURNO "<< jugador.verFrente() << "**"<<endl;
		cout<<"Quieres seguir jugando?(S/N) Jugador: "<<jugador.verFrente()<<endl;
		cin>>opcion;
		if((opcion=="s")||(opcion=="S")){
			cout<<jugador.verFrente()<< "se retiro del juego"<<endl;
			jugador.eliminarCola();
		}else{
			jugador.insertarCola(jugador.verFrente());
			jugador.eliminarCola();
		}
	}
	cout<<"**TODOS LOS JUGADORES SALIERON DEL JUEGO**"<<endl;
	cout<<"El numero de turnos es de: "<<turno<<endl;
}


void menuCircular(){
	system("cls");
	int opcion;
	string dato;
	cola cir;
	int posiciones;
	cir.insertaCircular("1");
	cir.insertaCircular("2");
	cir.insertaCircular("3");
	
	do{
		cout<<"\n -- MENU DE COLAR CIRUCLARES -- \n";
		cout<<"1. Insertar elemento en la cola circular\n";
		cout<<"2. Eliminar elemento de la cola circular\n";
		cout<<"3. Ver frente\n";
		cout<<"4. Mostrar cola circular\n";
		cout<<"5. Contar elementos \n";
		cout<<"6. Buscar elemento \n";
		cout<<"7. Eliminar elementos repetidos/\n";
		cout<<"8. (PRUEBA) Eliminar elementos impares de la cola circular\n";
		cout<<"9. (PRUEBA) Eliminar elementos pares de la cola ciruclar\n";
		cout<<"10. Duplicar elementos cola circular\n";
		cout<<"11. Rotar elementos a X posiciones atras\n";
		cout<<"12. Ordenar elementos de la cola\n";
		cout<<"13. Rotar elementos a X posiciones adelantes\n";
		cout<<"0. salir\n";
		cout<<"seleccione una opcion :";
		
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Ingrese dato a insertar en la cola circular: ";
				cin>>dato;
				cir.insertaCircular(dato);
				break;
			
			case 2:
				dato = cir.eliminarCircular();
				cout<<dato;
				if(dato != ""){
					cout<<"Elemento eliminado: "<< dato << endl;
				}else{
					cout<<"No hay elementos en la cola"<<endl;
				}
				break;
		
			case 3:
				dato = cir.verFrente();
				
				if(dato != ""){
					cout<<"Elemento en el frente: "<<dato<<endl;
				}else{
					cout<<"La cola esta vacia"<<endl;
				}
				break;
			
			case 4:
				cir.mostrarCircular();
				break;
			
			case 5:
				cout<<"Total de elementos en la cola: "<<cir.contarCircular()<<endl;
				break;
			
			case 6:
				cout<<"Que elemento desea buscar"<<endl;
				cin>>dato;
				//cir.buscarElemento  // tambien funciona la funcion para colas normales 
				if(cir.buscarCircular(dato)){
					cout<<"Elemento encontrado"<<endl;
				}else{
					cout<<"No se encontro el elemento"<<endl;
				}
				break;
			case 7:
				cir.eliminarRepetidosCircular();
				cir.mostrarCircular();
				break;
			case 8:
				
				cir.eliminarParesCircular();
				cir.mostrarCircular();
				break;
			case 9:
				
				cir.eliminarImparesCircular();
				cir.mostrarCircular();
				break;
			case 10:{
				cir.duplicarElementosColaCircular();
				cir.mostrarCircular();
				break;
			}
			case 11:{
				//cout<<"Ingrese la cantidad de posiciones que desea rotar los elementos"<<endl;
				//cin>>posiciones;
				cir.rotarPosicionesCircular(posiciones);
				cir.mostrarCircular();
				break;
			}
			case 12:{
				cir.ordenarElementosColaCircular();
				cir.mostrarCircular();
				break;
			}
			case 13:{
				cir.rotarPosiciones2Circular(posiciones);
				cir.mostrarCircular();
				break;
			}
			case 0:
				cout<<"Programa finalizado.\n";
				break;
			default:
				cout<<"Opcion incorrecta\n";	
		}
	}while(opcion!=0);
	
}
int main(){
	cola cola1;
	cola cola2;
	cola temporal;
	string dato;
	int opcion;
	//ingreso de datos 1 2 3
	/*
	cola1.insertarCola("1");
	cola1.insertarCola("2");
	cola1.insertarCola("3");
	*/
	do{
		cout<<"\n -- MENU DE COLA -- \n";
		cout<<"1. Insertar elemento en la cola A\n";
		cout<<"2. Eliminar elemento de la cola\n";
		cout<<"3. Ver frente\n";
		cout<<"4. Mostrar cola\n";
		cout<<"5. Contar elementos \n";
		cout<<"6. Buscar elemento \n";
		cout<<"7. EVACUACIONNN\n";
		cout<<"8. Jugadores\n";
		cout<<"9. Menu Colas Circulares\n";
		cout<<"10. Funcion para invertir elementos en una cola\n";
		cout<<"11. Funcion para eliminar un elemento determinado de una cola\n";
		cout<<"12. (PRUEBA) Ingresar elementos solo impares\n";
		cout<<"13. (PRUBA) Eliminar los impares de la cola\n";
		cout<<"14. (PRUEBA) Eliminar los pares de la cola\n";
		cout<<"15. Duplicar elementos de al cola\n";
		cout<<"16. Ordenar elementos de la cola(menor a mayor)\n";
		cout<<"17. Invertir Cola\n";
		cout<<"18. Insertar elemento en la cola B\n";
		cout<<"19. Mostrar las 2 colas\n";
		cout<<"20. Intercalar las 2 colas\n";
		cout<<"21. Desplazar elementos de derecha a izquierda\n";
		cout<<"0. salir\n";
		cout<<"seleccione una opcion :";
		
		//cin>>opcion;
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
			case 8:
				jugadores();
				break;	
			case 9:
				menuCircular();
				break;
			case 10:
				cola1.invertirElementos();
				cola1.mostrarCola();
				break;
			case 11:
				cout<<"Ingrese el elemento que desea eliminar: ";
				cin>>dato;
				cola1.eliminarDeterminado(dato);
				cola1.mostrarCola();
				break;
			case 12:
				cout<<"Ingrese el elemento que desea eliminar: ";
				cin>>dato;
				cola1.insertarPares(dato);
				cola1.mostrarCola();
				break;
			case 13:
				cout<<"La cola resultante de la eliminacion de los pares es: ";
				
				cola1.eliminarPares();
				cola1.mostrarCola();
				break;
			case 14:
				cout<<"La cola resultante de la eliminacion de los impares es: ";
				cola1.eliminarImpares();
				cola1.mostrarCola();
				break;
			case 15:{
				cola1.duplicarElementosCola();
				cola1.mostrarCola();
				break;
			}
			case 16:{
				cola1.ordenarElementosCola();
				cola1.mostrarCola();
				break;
			}
			case 17:{
				cola1.invertirElementos();
				cola1.mostrarCola();
				break;
			}
			case 18:{
				cout<<"Ingrese dato a insertar en la cola: ";
				cin>>dato;
				cola2.insertarCola(dato);
				cola2.mostrarCola();
				break;
			}
			case 19:{
				cola1.mostrarCola();
				cola2.mostrarCola();
				break;
			}
			case 20:{
				if(cola1.colaVacia()&&cola2.colaVacia()){
					cout<<"Alguna cola o las dos colas estan vacias"<<endl;
				}else{
					intercalarColas(cola1,cola2,temporal);
					temporal.mostrarCola();
				}
				break;
			}
			case 21:{
				cola1.desplazarElementoCola();
				cola1.mostrarCola();
				break;
			}
			case 0:
				cout<<"Programa finalizado.\n";
				break;
			default:
				cout<<"Opcion incorrecta\n";	
		}
	}while(opcion!=0);
	return 0;
}