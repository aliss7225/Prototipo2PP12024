#include "admi.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

admi::admi(string usuario, string contrasena)
{
    this -> usuarios=usuarios;
    this -> contrasena=contrasena;
}

string admi::setUser(string usuarios)
{
    this -> usuarios=usuarios;
}

string admi::getUser()
{
    return this->usuarios;
}

string admi::setContrasena(string contrasena)
{
    this -> contrasena=contrasena;
}

string admi::getContrasena()
{
    return this->contrasena;
}

bool admi::VerificarUsuario()
{
    string usuario,contrasena;
    int contador= 0;
    bool encontrado =false;

    while(contador<3 && !encontrado)
    {
         system("cls");
    cout <<"\t-------------------------------"<<endl;
    cout <<"\t| Autentificacion de Usuarios  |"<<endl;
    cout <<"\t-------------------------------"<<endl;
    cout <<"\t    3 intentos disponibles"<<endl;


    cout << "\t\t\t\nUsuario:         ";
    cin >> usuario;
    cout << "\t\t\t\nContrasena:      ";
    char caracter;
    caracter = getch();

    contrasena="";
        while (caracter!=13)
        {
        if(caracter !=8)
            {
                contrasena.push_back(caracter);
                cout<<".";
            }
        else
            {
                if(contrasena.length()>0)
                {
                    cout<<"\b \b";
                    contrasena=contrasena.substr(0,contrasena.length()-1);
                }
            }
            caracter=getch();
        }

    ifstream fileU_P;
    fileU_P.open("contrasena2.txt",ios::in);

    if (!fileU_P)
    {
        cout<<"No es posible abrir el archivo."<<endl;
        fileU_P.close();
        return false;
    }
    string user,pass;
    while (fileU_P>>user>>pass)
    {
        if (user==usuario && pass==contrasena)
        {
            encontrado=true;
            break;
        }
    }
     fileU_P.close();

    if(!encontrado)
    {
        cout << "\n\tEl usuario o la contraseña son incorrectos" << endl;
        cout << "\n\tPor favor intente nuevamente" << endl;
        contador++;
        system("pause");
    }
}
   if (encontrado)
    {
    cout << "\n\tBienvenido " << usuario << "!" << endl;
    return true;
    }
   else
    {
    cout << "\n\tHa excedido el limite de intentos" << endl;
    cout << "\n\tintentelo más tarde" << endl;
    return false;
    }
}
