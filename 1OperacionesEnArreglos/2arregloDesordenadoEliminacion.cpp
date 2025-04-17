#include <iostream>
using namespace std;

int main(){
	int n=3;
	int i=0;
	int cen=1;
	int j=0;
	const int max=10;
	int x[max]={2,4,7};
	int dato;
	
	for (i=0;i<n;i++){
		cout << x[i] << " ";
	}
	cout << "Ingrese el dato a eliminar"<<endl;
	cin>>dato;
	
	if (n!=0){
		cen = 0;
		i = 0;
		while ( (i<n) && (cen==0)){
			if (dato == x[i]){
				n = n-1;
				for (j=i;j<n;j++){
					x[j]=x[j+1];
				}
				cen = 1;
			} else {
				i=i+1;
			}
		}
		if (cen==0){
			cout << "El dato no existe"<<endl;
		}
	} else {
		cout << "array vacio"<<endl;
	}
	
	for (i=0;i<n;i++){
		cout << x[i] << " ";
	}
	
	return 0;
}