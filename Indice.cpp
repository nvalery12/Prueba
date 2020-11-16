// Indice de grasa corporal C++

#include<iostream>

using namespace std;

float indice(int ps,float alte);

int main(){
	float alt,res;
	int peso;
	
	cout<<"Ingrese su estatura: Ejemplo: 1.76"<<endl;
	cin >> alt;
	
	cout<<"Ingrese peso: "<<endl;
	cin >> peso;
	
	res = indice(peso,alt);
	
	cout<<"Su indice de masa corporal es de: "<<res<<endl;
	cout<<"Su composicion corporal es: ";
	if(res<18.5) cout<<"Peso inferior al normal"<<endl;
	else
		if(res<25) cout<<"Peso normal"<<endl;
		else
			if(res<30) cout<<"Peso superior al normal"<<endl;
			else
				cout<<"Obesidad"<<endl;
				
	return 0;
	
}

float indice(int ps,float alte){
	return ps/(alte*alte);
}
