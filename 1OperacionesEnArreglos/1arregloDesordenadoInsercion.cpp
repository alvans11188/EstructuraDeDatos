#include <iostream>
using namespace std;

int main(){
	int i,dato;
	const int max = 10;
	int x[max] = {2,4,7,2,3,4,5,6,9,10};
	
	cout << "Arreglo original"<<endl;
	for (i=0;i<max;i++){
			cout << x[i] << " ";
	}
	cout << endl;
	int n=0;
	for (i=0;i<max;i++){
		if (x[i]==0){
			n=n+1;
		}
	}
	cout << n << endl;
	n=9-n;
	cout << n << endl;
	cout << "Ingrese el dato a ingresar: " ;
	cin>> dato;
	
	if (n<max-1){
		n=n+1;
		x[n] = dato;
		for (i=0;i<max;i++){
			cout << x[i] << " ";
		}
	} else {
		cout << "Array lleno";
	}
	
	return 0;
}