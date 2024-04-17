#ifndef ADMI_H
#define ADMI_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class admi
{
    public:
        admi(string usuarios,string contrasena);

        string setUser(string usuarios);
        string getUser();

        string setContrasena(string contrasena);
        string getContrasena();


        bool VerificarUsuario();

        void MenuUser();

    private:
        string usuarios,contrasena;
};

#endif // ADMI_H
