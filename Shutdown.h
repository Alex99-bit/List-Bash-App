#include <string.h>

// Esta clase es para los comandos de shutdown
class Shutdown{
	private:
		int time;
		char aux;
		string comand;
	public:
		void apaga();
		void cancela();
		void setTime();
		void timePersonalizado();
};

void Shutdown::setTime(){
	do{
		system("cls");
		cout<<"\n\tIngresa una opcion de apagado:\n\n";
		cout<<"\t1.- 15 min\n\t2.- 30 min\n\t3.- 1 hora\n\t4.- Ingresar manual\n\t5.- Regresar\n\n\n\t>> ";
		cin>>aux;
		
		/*cout<<"aux = "<<int(aux)<<endl;
		system("pause");*/
		
		// Con el este bloque de codigo se evita que se buguee en caso de introducir un caracter y no un numero
		// Se hace la conversion para el time
		switch(aux){
			case 49:
				time = 1;
				break;
			case 50:
				time = 2;
				break;
			case 51:
				time = 3;
				break;
			case 52:
				time = 4;
				break;
			case 53:
				time = 5;
				break;
			default:
				time = 10;
		}
	}while(time<1 || time>5);
}

void Shutdown::apaga(){
	char var[15];
	
	strcpy(var, "shutdown /s /t 900 ");
	switch(time){
		case 1: // 15 min = 900s
			system(var);
			cout<<"\n\tSe establecio el apagado en 15 min";
		break;
		case 2: // 30 min = 1800s
			system("shutdown /s /t 1800 ");
			cout<<"\n\tSe establecio el apagado en 30 min";
		break;
		case 3: // 1h = 3600s
			system("shutdown /s /t 3600 ");
			cout<<"\n\tSe establecio el apagado en 60 min";
		break;
		case 4: // Lo ingresa manual
			cout<<"\n\tIngrese el tiempo en minutos: ";
			cin>>time;
			//time = time*60;
			timePersonalizado();
		break;
		case 5:
			system("call Lista_comandos.exe");
			exit(0);
		break;
	}
}

void Shutdown::timePersonalizado(){
	// time ya esta en minutos
	char var[50];
	int auxTime = 0;
	auxTime = time * 60;
	sprintf(var, "shutdown /s /t %d", auxTime);
	
	system(var);
	
	for(int i=(time-1);i>=0;i--){
		for(int j=59;j>0;j--){
			
			// Esto es solo para darle mayor detalle al timer
			if(j<10 && i<10){
				cout<<"\n\n\tTiempo para apagar: 0"<<i<<":0"<<j<<endl;
			}else{
				if(j<10 && i>=10){
					cout<<"\n\n\tTiempo para apagar: "<<i<<":0"<<j<<endl;
				}else{
					if(j>=10 && i<10){
						cout<<"\n\n\tTiempo para apagar: 0"<<i<<":"<<j<<endl;
					}else{
						cout<<"\n\n\tTiempo para apagar: "<<i<<":"<<j<<endl;
					}
				}
			}
			
			cout<<"\n\t**NOTA: Si cierra el programa, se cancelara la operacion**";
			Sleep(1000);
			system("cls");
		}
	}
}

void Shutdown::cancela(){
	system("shutdown /a");
	cout<<"\n\tSe cancelo el apagado";
}
