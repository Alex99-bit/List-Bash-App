#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

#include "Shutdown.h"
#include "Mantenimiento.h"

void apagado();
void mantenimiento();

int main(){
	short int opc;
	do{
		system("cls");
		cout<<"\n\t<<<< Lista de comandos >>>>\n\n"<<endl;
		cout<<"\t1.-Shutdown\n\t2.-Mantenimiento\n\t3.-Cerrar\n\n\t";
		cout<<">> ";
		cin>>opc;
		
		switch(opc){
			case 1:
				apagado();
			break;
			case 2:
				mantenimiento();
			break;
			case 3:
				exit(0);
			break;
		}
	}while(opc<0 || opc>1);
	return 0;
}

void mantenimiento(){
	Mantenimiento com;
	com.menu();
	main();
}

void apagado(){
	short int opc;
	Shutdown comand;
	do{
		system("cls");
		cout<<"\n\tShutdown:\n";
		cout<<"\n\t1.-Apagar\n\t2.-Cancelar apagado\n\t3.-Regresar\n\n\t>> ";
		cin>>opc;
		switch(opc){
			case 1:
				comand.setTime();
				comand.apaga();
			break;
			case 2:
				comand.cancela();
			break;
			case 3:
				main();
			break;
			default:
				cout<<"\n\n\tOpcion invalida\n\n\t"<<endl;
				system("pause");
		}
	}while(opc<1 || opc>3);
	cout<<"\n\n\t";
	system("pause");
	main();
}
