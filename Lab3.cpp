#include <iostream>
#include <string>
using namespace std;
//int** crearMatriz(int);
void calculoDias();
int main () {
	int opcion=0;
	do{
		cout<< "Menu\n1. Ejercicio 1:\n2. Ejercicio 2:\n3. Ejercicio 3:\n4. Salir\n";
		cin>>opcion;
		if(opcion==1){
			calculoDias();
		}//fin ejercicio 1
		if(opcion==2){
			int polinomio;
			cout<<endl<<"Ingrese el grado mas alto del polinomio:";
			cin>> polinomio;
			int numeros[polinomio+1];
			int contador = 0;
			for (int i = polinomio; i >= 0; --i)
			{
				cout<<endl<<"Ingrese el polinomio x^"<<i<<":";
				cin >> numeros[contador];
				contador++;
			}
			int a;
			cout<<endl<<"Ingrese a:";
			cin>>a;
			int **matriz;
			matriz = new int*[3];
			for (int i = 0; i < 3; i++){
				matriz[i] = new int[polinomio];
			}
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j <= polinomio; ++j)
				{
					matriz[i][j] =0;
				}
				cout<<endl;
			}
			for (int i = 0; i <= polinomio; ++i)
			{
				matriz[0][i] = numeros[i];
			}
			int respuestas[polinomio];
			for (int i = 0; i <= polinomio; ++i)
			{
				cout<<endl;
				respuestas[i] = matriz[0][i] + matriz[1][i];
				matriz[1][i+1] = respuestas[i] *a;
				matriz[2][i] = respuestas[i];
				cout<<endl;
				for (int t = 0; t < 3; ++t)
				{
					for (int j = 0; j <= polinomio; ++j)
					{
						cout<< matriz[t][j]<<" ";
					}
					cout<<endl;
				}
			}
			for (int i = 0; i <= polinomio; ++i)
			{
				matriz[2][i] = respuestas[i];
			}
			cout<<endl<<"El cociente es ";
			int contador2=0;
			for (int i = polinomio; i > 0; --i)
			{	
				if(i!=1){
					cout<< respuestas[contador2]<<"x^"<<i-1<<" + ";
				}else{
					cout<< respuestas[contador2];
				}
				contador2++;
			}
			cout<<endl<< "El residuo es: "<< respuestas[polinomio]<<endl;
		}//fin ejercicio 2
		if(opcion==3){
			int numeros[4];
			for (int i = 0; i < 4; ++i)
			{
				cout<<"Numero: ";
				cin>>numeros[i];
			}
			cout<<numeros[0]<<numeros[1]<<numeros[2]<<numeros[3]<<endl;
			cout<<numeros[0]<<numeros[1]<<numeros[3]<<numeros[2]<<endl;
			cout<<numeros[0]<<numeros[2]<<numeros[3]<<numeros[1]<<endl;
			cout<<numeros[0]<<numeros[2]<<numeros[1]<<numeros[3]<<endl;
			cout<<numeros[0]<<numeros[3]<<numeros[1]<<numeros[2]<<endl;
			cout<<numeros[0]<<numeros[3]<<numeros[2]<<numeros[1]<<endl;
			cout<<endl;
			cout<<numeros[1]<<numeros[2]<<numeros[3]<<numeros[0]<<endl;
			cout<<numeros[1]<<numeros[2]<<numeros[0]<<numeros[3]<<endl;
			cout<<numeros[1]<<numeros[3]<<numeros[0]<<numeros[2]<<endl;
			cout<<numeros[1]<<numeros[3]<<numeros[2]<<numeros[0]<<endl;
			cout<<numeros[1]<<numeros[0]<<numeros[2]<<numeros[3]<<endl;
			cout<<numeros[1]<<numeros[0]<<numeros[3]<<numeros[2]<<endl;
			cout<<endl;
			cout<<numeros[2]<<numeros[3]<<numeros[0]<<numeros[1]<<endl;
			cout<<numeros[2]<<numeros[3]<<numeros[1]<<numeros[0]<<endl;
			cout<<numeros[2]<<numeros[0]<<numeros[1]<<numeros[3]<<endl;
			cout<<numeros[2]<<numeros[0]<<numeros[3]<<numeros[1]<<endl;
			cout<<numeros[2]<<numeros[1]<<numeros[3]<<numeros[0]<<endl;
			cout<<numeros[2]<<numeros[1]<<numeros[0]<<numeros[3]<<endl;
			cout<<endl;
			cout<<numeros[3]<<numeros[0]<<numeros[1]<<numeros[2]<<endl;
			cout<<numeros[3]<<numeros[0]<<numeros[2]<<numeros[1]<<endl;
			cout<<numeros[3]<<numeros[1]<<numeros[2]<<numeros[0]<<endl;
			cout<<numeros[3]<<numeros[1]<<numeros[0]<<numeros[2]<<endl;
			cout<<numeros[3]<<numeros[2]<<numeros[0]<<numeros[1]<<endl;
			cout<<numeros[3]<<numeros[2]<<numeros[1]<<numeros[0]<<endl;
		}//fin ejercicio 3;

	}while(opcion!=4);
	return 0;
}
void calculoDias(){
	int contadordeDomingos=0, dias=1, diasMes;
	for (int i = 1901; i < 2000; ++i)
	{//for de los años
		for (int j = 1; j <= 12; ++j)
		{//for de los meses
			if(j==4||j==6||j==9||j==11){
				diasMes=30;
			}else if(j == 2){
				if(i%400==0 || (i%4==0 && i%100!=0)){
					diasMes=29;
				}else{
					diasMes=28;
				}
			} else {
				diasMes=31;
			}
			if(dias%7==0){
				contadordeDomingos++;
			}
				dias+=diasMes;
		}
	}
			cout<< "Hay un total de " << contadordeDomingos <<" entre 1900-1999"<< endl;
}