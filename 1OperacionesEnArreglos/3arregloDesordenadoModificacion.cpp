#include <iostream>
using namespace std;
void modificar_ad(int[],int,int,int);

void modificar_ad(int x[],int n, int dato1,int dato2){
	int i,j;
	int cen;
		if (n!=0){
		cen = 0;
		i = 0;
		while ( (i<n) && (cen==0)){
			if (dato1 == x[i]){
				x[i]=dato2;
				cen=1;
			
			} else {
				i=i+1;
			}
		}
		if (cen==0){
			cout << "El dato a modificar no existe"<<endl;
		}
	} else {
		cout << "array vacio"<<endl;
	}
}

int main(){
	int n=3;
	int i=0;
	int cen=1;
	int j=0;
	const int max=10;
	int x[max]={2,4,7};
	int dato1,dato2;
	
	for (i=0;i<n;i++){
		cout << x[i] << " ";
	}
	cout << "\nIngrese el primer dato"<<endl;
	cin>>dato1;
	cout << "\nIngrese el segundo dato"<<endl;
	cin>>dato2;
	
	modificar_ad(x,n,dato1,dato2);
	
	for (i=0;i<n;i++){
		cout << x[i] << " ";
	}
	
	return 0;
}