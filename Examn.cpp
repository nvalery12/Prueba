// Temperatura a dos sistemas

#include<iostream>
#include<unistd.h>

using namespace std;

float cAf(float c);
float cAk(float c);
float fAc(float f);
float kAc(float k);

int main(){
	float temp,res;
	int opc;
	
	cout<<"Ingrese temperatura"<<endl;
	cin >> temp;
	
	cout<<"Ingrese en que sistema esta:"<<endl;
	cout<<"[0] Kelvin"<<endl;
	cout<<"[1] Celsius"<<endl;
	cout<<"[2] Fahrenheit"<<endl;
	cin >> opc;
	
	int id=fork();
	if(id<0){
		cout<<"Error al crear proceso"<<endl;
	}else{
		if(id==0){
			if(opc==0){
				res=kAc(temp);
				cout<<"Temperatura es "<<res<<" celsius"<<endl;
			}
			if(opc==1){
				res=cAk(temp);
				cout<<"Temperatura es "<<res<<" kelvin"<<endl;
			}
			if(opc==2){
				res=fAc(temp);
				cout<<"Temperatura es "<<res<<" celsius"<<endl;
			}
		}else{
			if(opc==0){
				res=cAf(kAc(temp));
				cout<<"Temperatura es "<<res<<" fahrenheit"<<endl;
			}
			if(opc==1){
				res=cAf(temp);
				cout<<"Temperatura es "<<res<<" fahrenheit"<<endl;
			}
			if(opc==2){
				res=cAk(fAc(temp));
				cout<<"Temperatura es "<<res<<" kelvin"<<endl;
			}
		}
	}
	
}

float kAc(float k){
return k-273.15;
}

float cAk(float c){
return c+273.15;
}

float cAf(float c){
return (c*9/5) + 32;
}

float fAc(float f){
return (f-32)*5/9;
}
