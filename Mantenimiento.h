
class Mantenimiento{
	private:
		short int opc;
		char aux;
		void mantSO();
		void mantHDD();
	public:
		void menu();
};

void Mantenimiento::mantSO(){
	system("cls");
	system("sfc /scannow");
	system("DISM /Online /Cleanup-Image /CheckHealth");
	system("DISM /Online /Cleanup-Image /ScanHealth");
	system("DISM /Online /Cleanup-Image /RestoreHealth");
	system("pause");
}

void Mantenimiento::menu(){
	do{
		system("cls");
		cout<<"\n\tMantenimiento: (Es necesario ejecutar como administrador)\n\n\t1.-Sistema\n\t2.-Unidad de almacenamiento (C:)";
		cout<<"\n\t3.-Regresar";
		cout<<"\n\n\t>> ";
		cin>>aux;
		
		switch(aux){
			case 49:
				opc = 1;
				break;
			
			case 50:
				opc = 2;
				break;
				
			case 51:
				opc = 3;
				break;
				
			default:
				opc = 10;
		}
		
		switch(opc){
			case 1:
				mantSO();
			break;
			case 2:
				mantHDD();
			break;
		}
	}while(opc<1 || opc>3);
}

void Mantenimiento::mantHDD(){
	system("cls");
	system("chkdsk C: /F /R");
	system("pause");
}



