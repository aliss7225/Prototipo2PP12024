#include "general.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

general::general(string id, string nombre, string precio, string cantidad)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
}

string general::setId( string id)
{
    this-> id=id;
}
string general::getId()
{
    return this -> id;
}

string general::setNombre(string nombre)
{
    this->nombre=nombre;
}

string general::getNombre()
{
    return this->nombre;
}

string general::setPrecio(string precio)
{
    this->precio=precio;
}

string general::getPrecio()
{
    return this->precio;
}

string general::setCantidad(string cantidad)
{
    this->cantidad=cantidad;
}

string general::getCantidad()
{
    return this->cantidad;
}

void general::menuPrincipal()
{
        bool salir = false;
    int opcion;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|              CATALOGO          |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. CRUD "<<endl;
	cout<<"\t\t\t 2. INFORMES"<<endl;
	cout<<"\t\t\t 3. Salir"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        submenu();
		break;
	case 2:

		desplegar();
		system("pause");
        system ("cls");
		break;
	case 3:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
    }while(opcion!= 3);
}

void general::submenu()
{
int opcion;
    char x;
    bool repetir=true;
    system("cls");
   do
   {

     cout <<"\t\t\t--------------------------------------------"<<endl;
    cout <<"\t\t\t |                 CRUD                     |"<<endl;
    cout <<"\t\t\t--------------------------------------------_"<<endl;
	cout<<"\t\t\t 1. Ingreso de producto"<<endl;
	cout<<"\t\t\t 2. Modificar producto "<<endl;
	cout<<"\t\t\t 3. Borrar producto"<<endl;
	cout<<"\t\t\t 4. SALIR"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";

    cin>>opcion;

    switch(opcion)
    {

    case 1:
        do
            {  insertar();
                cout<<"\n\tAgregar otro producto (Si=s/No=n)"<<endl;
                cin>>x;
            } while(x=='s'|| x=='S');
            system("cls");
        break;

    case 2:
        modificar();
        system("pause");
        system ("cls");
        break;
    case 3:
         borrar();
         system("pause");
        system ("cls");
        break;

    case 4:
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    break;}
        }while(opcion!= 4);

}
void general::desplegar()
{
   system("cls");
int total=0;


cout<<"\nIngreso Inventario"<<endl;
fstream fileDesplegar;
fileDesplegar.open("inventario.txt",ios::in);

if(!fileDesplegar)
    {
    cout<<"\n\tNo hay información...";
		fileDesplegar.close();
    }
else
    {
        fileDesplegar >> id>> nombre>>precio>>cantidad;
        while(!fileDesplegar.eof())
        {
         total++;

         cout<<"\t\t\t Codigo "<<id<<endl;
         cout<<"\t\t\t Nombre: "<<nombre<<endl;
         cout<<"\t\t\t Precio: "<<precio<<endl;
         cout<<"\t\t\t Cantidad: "<<cantidad<<endl<<endl<<endl;
        fileDesplegar >> id>> nombre>>precio>>cantidad;
        }

        if(total==0)
        {
            cout<<"\n\t\t\tinformacion no encontrada";
        }
    }
    fileDesplegar.close();
}

void general::insertar()
{
    system("cls");
    string id,nombre,precio,cantidad;

    cout<<"\n\tAgregar producto"<<endl;
    cout << "\t\nIngrese el codigo del producto:         ";
    cin >> id;
      cout << "\t\t\t\nIngrese el nombre del producto:         ";
    cin >> nombre;
      cout << "\t\t\t\nIngrese el precio del producto:         ";
    cin >> precio;
      cout << "\t\t\t\nIngrese la cantidad de productos:         ";
    cin >> cantidad;


    fstream fileIngresar;
    fileIngresar.open("inventario.txt",ios::app| ios:: out);
    fileIngresar<<std::left<<std::setw(15)<< id <<std::left <<std::setw(15)<< nombre<<std::left <<std::setw(15)<< precio<<std::left <<std::setw(15)<< cantidad<<"\n";
    fileIngresar.close();

    cout << "\t\t\Producto inventariado correctamete\t"<<endl;

}

void general::modificar()
{

	system("cls");
    fstream fileOri, fileModif;
    string productoModificar;

    int contador=0;
    cout<<"\n/t/tModificacion de Producto"<<endl;
    fileOri.open("inventario.txt",ios::in);

    if(!fileOri)
    {
        cout<<"\n\t\tNo se encontro el producto..,";
        fileOri.close();
    }
    else
    {
        cout<<"\n Ingrese el nombre del producto que quiere modificar: ";
        cin>>productoModificar;
        fileModif.open("modifica2.txt",ios::app | ios::out);
        fileOri >> id>> nombre>>precio>>cantidad;

        while(!fileOri.eof())
        {
            if(productoModificar!=nombre)
                {
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
                //cout << "\t\t\t\nproducto no encontrado.";

                }

            else
                {
                cout << "\t\t\t\nIngrese el nuevo codigo del producto:         ";
                cin >> id;
                cout << "\t\t\t\nIngrese el nuevo nombre del producto:         ";
                cin >> nombre;
                cout << "\t\t\t\nIngrese el nuevo precio del producto:         ";
                cin >> precio;
                cout << "\t\t\t\nIngrese la nueva cantidad de productos disponibles:         ";
                cin >> cantidad;
                fileModif<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";
                contador++;
                cout << "\t\t\t\nProducto modificado exitosamente";
                }

                    fileOri >> id>> nombre>>precio>>cantidad;
        }

        fileModif.close();
        fileOri.close();

        remove("inventario.txt");
        rename("modifica2.txt","inventario.txt");


    }
}

void general::borrar()
{
   	system("cls");

	fstream file, file1;
	string partcipante;
	int encontrados= 0;


	cout << "\nproducto que sera eliminado" << endl;

	file.open("inventario.txt", ios::in);

	if (!file)
	{
		cout << "\n\t\t\tNo hay informacion...";

		file.close();
	}
	else
	{

		cout << "\n Ingrese el nombre del producto que quiere Borrar: ";
		cin >> partcipante;

		file1.open("modifica2.txt", ios::app | ios::out);

		file >> id>> nombre>>precio>>cantidad;
		while (!file.eof())
		{
			if (partcipante != nombre)
			{
                file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre<<std::left<<std::setw(15)<< precio<<std::left<<std::setw(15)<< cantidad<<"\n";  // Escribe en el archivo temporal el usuario y contraseña sin modificar
			}
			else
			{
				encontrados++;

				cout << "\n\t\t\tBorrado de informacion exitoso";
			}

                file >> id>> nombre>>precio>>cantidad;

		}

		if (encontrados == 0)
		{
			cout << "\n\t\t\t Nombre del producto no encontrado...";
		}

		file1.close();
		file.close();

		remove("inventario.txt");

		rename("modifica2.txt", "inventario.txt");
	}
}

