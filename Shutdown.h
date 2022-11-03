
// Esta clase es para los comandos de shutdown
class Shutdown{
	private:
		int time;
		string comand;
	public:
		void apaga();
		void cancela();
		void setTime();
};

void Shutdown::setTime(){
	do{
		system("cls");
		cout<<"\n\tIngresa una opcion de apagado:\n\n";
		cout<<"\t1.- 15 min\n\t2.- 30 min\n\t3.- 1 hora\n\t4.- Ingresar manual\n\t5.- Regresar\n\n\n\t>> ";
		cin>>time;
	}while(time<1 || time>5);
}

void Shutdown::apaga(){
	
	switch(time){
		case 1: // 15 min = 900s
			system("shutdown /s /t 900 ");
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
			time = time*60;
			cout<<"\n\n\t**NOTA: Si cierra el programa, se cancelara la operacion**";
			Sleep(time*1000);
			system("shutdown /s");
		break;
		case 5:
			system("call Lista_comandos.exe");
			exit(0);
		break;
	}
}

void Shutdown::cancela(){
	system("shutdown /a");
	cout<<"\n\tSe cancelo el apagado";
}
