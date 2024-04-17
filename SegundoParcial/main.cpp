#include <iostream>
#include<admi.h>
using namespace std;

int main()
{
    string user,contrasena;
    admi ingreso(user,contrasena);


     string id, nombre, precio, cantidad;
        general catalogos(id, nombre, precio, cantidad);

    bool UsuarioCorrecto=ingreso.VerificarUsuario();

    if(UsuarioCorrecto)
    {
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout <<"\t\t\t--------------------------------------------"<<endl;
    cout <<"\t\t\t |            Menu General                  |"<<endl;
    cout <<"\t\t\t--------------------------------------------"<<endl;
	//cout<<"\t\t\t 1. Menu General"<<endl;
	cout<<"\t\t\t 2. Catalogo"<<endl;
	cout<<"\t\t\t 3. Salir"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion Disponibles:[1/2]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"¿Que opcion desea utilizar?: ";
    cin>>opcion;
    switch(opcion){
    case 1:
        catalogos.menuPrincipal();
        break;
    case 2:
        exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida, intentelo nuevamente";
        break;}
        }while(opcion!= 2);

    }
    return 0;
}
