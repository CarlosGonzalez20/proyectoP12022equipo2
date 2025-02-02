#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include<conio.h>
#include<math.h>

using namespace std;

class empresa{//funcion creada por Carlos Gonzalez
public:
    void mostrarLog();//funcion creada por Carlos Gonzalez
    void menuPrincipal();//funcion creada por Carlos Gonzalez
    void menuMantenimiento();//funcion creada por Carlos Gonzalez
    void menuEmpleados();//funcion creada por Carlos Gonzalez
    void registrarEmpleado();//funcion creada por Carlos Gonzalez
    void modificarEmpleado();//funcion creada por Carlos Gonzalez
    void eliminarEmpleado();//funcion creada por Carlos Gonzalez
    void mostrarDatosEmpleados();//funcion creada por Carlos Gonzalez
    void menuDepartamentos();//funcion creada por Carlos Gonzalez
    void registrarDepto();//funcion creada por Carlos Gonzalez
    void modificarDepto();//funcion creada por Carlos Gonzalez
    void eliminarDepto();//funcion creada por Carlos Gonzalez
    void mostrarDatosDepto();//funcion creada por Carlos Gonzalez
    void menuNomina();//funcion creada por Diego Culajay
    void displayNomina();//funcion creada por Diego Culajay
    void modifyNomina();//funcion creada por Diego Culajay
    void searchNomina();//funcion creada por Diego Culajay
    void deletNomina();//funcion creada por Diego Culajay
    void menuConceptoImpuestos();//funcion creada por William Mayen
    void registrarConceptoImpuestos();//funcion creada por William Mayen
    void modificarConceptoImpuestos();//funcion creada por William Mayen
    void eliminarConceptoImpuestos();//funcion creada por William Mayen
    void mostrarDatosConceptoImpuestos();//funcion creada por William Mayen
    void menuPoliza();//funcion creada por Carlos Montes
    bool verificar(string ced, string num);//funcion creada por Carlos Montes
    void agregar(ofstream &es);//funcion creada por Carlos Montes
    void VerPoliza(ifstream &Lec);//funcion creada por Carlos Montes
    void reclamaciones(ofstream &Esc, ifstream &Lec);//funcion creada por Carlos Montes
    void ModificarPlan(ifstream &Lec);//funcion creada por Carlos Montes
private:
    string documentoIdentificacion, puesto2,nombre, direccion, edad, correo, telefono, estudios, puesto, desicion, busquedaDatos, numDepto, nombreDepto, telefonoDepto, direccionDepto;
    string numeroid,choice, Id, nomConcep, montoConcep;
    int   hora,horaextra,totalhoras,horatr;
    float impuesto,sueldo1,bonificacion,isr,igss,irtra,totaldesc,sueldo,totalnominas,sueldototal,sueldo2;
};

const std::string currentDateTime() {//funcion creada por Carlos Gonzalez
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
};

void empresa::mostrarLog(){//funcion creada por Carlos Gonzalez
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro a mostrar bitacora, ";
    log.close();
    string line;
    log.open("bitacora.dat");
    if(log.is_open()){
        system("cls");
        while( getline(log, line)){
            cout << "\n"<<line << endl;
        }
        log.close();
    }
    cout<<"\n\n\t\tGRACIAS POR USAR EL RPOGRAMA DEL GRUPO 2 :)";
    cout << "\n\t\t";system("pause");
}

void empresa::menuPrincipal(){//funcion creada por Carlos Gonzalez
    system ("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu principal, ";
    log.close();
    int menu;
    cout << "\n\t\t\tBienvenido al programa de ==RECURSOS HUMANOS==";
    cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] Mantenimiento\n" << "\t\t[2] Nomina\n" << "\t\t[3] Poliza\n" << "\t\t[4] Impuestos\n" << "\t\t[6] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
    switch(menu){
    case 1:
        menuMantenimiento();
        break;
    case 2:
        menuNomina();
        break;
    case 3:
        menuPoliza();
        break;
    case 4:
        menuConceptoImpuestos();
        break;
    case 5:
        mostrarLog();
        break;
    case 6:
        cout << "\n\t\t�Quiere salir del programa? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            cout<<"\n\n\t\tGRACIAS POR USAR EL RPOGRAMA DEL GRUPO 2 :)";
            cout<<"\n\n\t\t";system("pause");
            return exit (1);
        }
        else {
            return menuPrincipal();
        break;
        }
    }
}

void empresa::menuMantenimiento(){//funcion creada por Carlos Gonzalez
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mantenimiento, ";
    log.close();
    int menu;
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Empleados\n" << "\t\t[2] Departamentos\n" << "\t\t[3] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        menuEmpleados();
        break;
    case 2:
        menuDepartamentos();
        break;
    case 3:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system("pause");
        return menuPrincipal();
        break;
    }
}

void empresa::menuEmpleados(){//funcion creada por Carlos Gonzalez
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu empleados, ";
    log.close();
    int menu;
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO EMPLEADO--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Empleados\n" << "\t\t[2] Modificar Empleados\n" <<  "\t\t[3] Eliminar Empleado\n" << "\t\t[4] Mostrar Datos Empleados\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarEmpleado();
        break;
    case 2:
        modificarEmpleado();
        break;
    case 3:
        eliminarEmpleado();
        break;
    case 4:
        mostrarDatosEmpleados();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU MANTENIMIENTO--" << endl;
        cout<<"\t";system ("pause");
        return menuMantenimiento();
        break;
    }
}

void empresa::registrarEmpleado(){//funcion creada por Carlos Gonzalez
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu registrar empleado, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --REGISTRAR EMPLEADOS--\n" << endl;
    cout << "\n\t�Quires salir al --MENU EMPLEADO--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuEmpleados();
    }
    else {
        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
        cout << "\t\tIngrese el nivel de estudios de la persona a registrar: "; cin >> estudios;
        cout << "\t\tIngrese el puesto de la persona a registrar: "; cin>>puesto;
        cout<<  "\t\tIngresa las Horas Trabajadas de la persona a registrar "; cin>> horatr;
        cout<<  "\t\ttIngresa la Cantidad que Gana por Hora la persona a registrar  : "; cin>> hora;
        cout<<  "\t\tIngresa la Cantidad de Horas Extras Trabajadas de la persona a registrar (SI NO TIENE HORAS EXTRAS TRABAJADAS, INGRESE 0) : "; cin>> horaextra;
        cout << "\n\t--Registro completado--\n" << endl;
        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<< "registro a: "<<documentoIdentificacion<<", ";
        log.close();
        baseDatos.open("empleados.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
    cout<<"\n\t";system("pause");
    return menuEmpleados();
}

void empresa::modificarEmpleado(){//funcion creada por Carlos Gonzalez
    system("cls");
    fstream baseDatos, modBaseDatos, log;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR EMPLEADOS--" << endl;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu modificar empleados, ";
    log.close();
    baseDatos.open("empleados.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
        cout<<"\n\t";system("pause");
        return menuEmpleados();
    }
    else {
        cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalEmpleados.dat",ios::out|ios::binary);
        baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>horatr>>hora>>horaextra;
        while (!baseDatos.eof()){
            if (busquedaDatos!=documentoIdentificacion){
                modBaseDatos<<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
            }
            else {
                cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
                cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                cout << "\t\tIngrese el nivel de estudios de la persona a registrar: "; cin >> estudios;
                cout << "\t\tIngrese el puesto de la persona a registrar: "; cin>>puesto;
                cout << "\t\tIngresa las Horas Trabajadas de la persona a registrar "; cin>> horatr;
                cout << "\t\ttIngresa la Cantidad que Gana por Hora la persona a registrar  : "; cin>> hora;
                cout << "\t\tIngresa la Cantidad de Horas Extras Trabajadas de la persona a registrar (SI NO TIENE HORAS EXTRAS TRABAJADAS, INGRESE 0) : "; cin>> horaextra;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"busco a: "<<busquedaDatos<<" y la modificacion es: "<<documentoIdentificacion<<", ";
                log.close();
                modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
            }
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>horatr>>hora>>horaextra;

        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "empleados.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalEmpleados.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
    cout<<"\n\t";system("pause");
    return menuEmpleados();
}

void empresa::eliminarEmpleado(){//funcion creada por Carlos Gonzalez
    system("cls");
	fstream baseDatos,modBaseDatos,log;
	log.open("bitacora.dat",ios::app|ios::out|ios::binary);
  log<<"entro al menu eliminar empleado, ";
  log.close();
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR EMPLEADOS--" << endl;
	baseDatos.open("empleados.dat",ios::in|ios::binary);
	if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
		baseDatos.close();
	}
	else
	{
		cout << "\n\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
		modBaseDatos.open("temporalEmpleados.dat", ios::app | ios::out | ios::binary);
		baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>horatr>>hora>>horaextra;

		while(!baseDatos.eof())
		{
			if(busquedaDatos!=documentoIdentificacion)
			{
				modBaseDatos<<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< estudios << std::left<<std::setw(15)<< puesto << std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
			}
			else
			{
				found++;
				log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<<"elimino a: "<<busquedaDatos<<", ";
        log.close();
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>horatr>>hora>>horaextra;

		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...\a";
		}
		baseDatos.close();
		modBaseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "empleados.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalEmpleados.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
    cout<<"\n\t";system("pause");
    return menuEmpleados();
}

void empresa::mostrarDatosEmpleados(){//funcion creada por Carlos Gonzalez
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mostrar datos empleado, ";
    log.close();
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR DATOS EMPLEADOS--";
    cout << "\n\n\t\t�Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("empleados.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
            cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>horatr>>hora>>horaextra;

            while(!baseDatos.eof()){
                if(busquedaDatos==documentoIdentificacion){
                    cout<<"\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tNivel de estudios: "<< estudios;
                    cout<<"\n\t\tPuesto o cargo: "<< puesto;
                    sueldo=(horatr+horaextra)*hora;
                    cout<<"\n\t\tSueldo: "<< sueldo;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU EMPLEADO--";
                    cout<<"\n\t";system("pause");
                    return menuEmpleados();
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS--";
                cout<<"\n\t";system("pause");
                return mostrarDatosEmpleados();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS EMPLEADOS"<<endl;
        baseDatos.open("empleados.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
            cout<<"\n\t";system("pause");
            return menuEmpleados();
        }
        else
        {
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>horatr>>hora>>horaextra;

            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                cout<<"\n\t\tNombre: " << nombre;
                cout<<"\n\t\tEdad: "<< edad;
                cout<<"\n\t\tCorreo Electronico: "<< correo;
                cout<<"\n\t\tTelefono: "<< telefono;
                cout<<"\n\t\tDireccion: "<< direccion;
                cout<<"\n\t\tNivel de estudios: "<< estudios;
                cout<<"\n\t\tPuesto o cargo: "<< puesto;
                sueldo=(horatr+horaextra)*hora;
                cout<<"\n\t\tSueldo: "<< sueldo;
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>sueldo;
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\tRegresando al --MENU EMPLEADOS--";
            cout<<"\n\t";system("pause");
            return menuEmpleados();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}

void empresa::menuDepartamentos(){//funcion creada por Carlos Gonzalez (porque ya no esta MELANNY SECAIDA)
    system("cls");
    int menu;
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu departamentos, ";
    log.close();
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO DEPPARTAMENTOS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Departamento\n" << "\t\t[2] Modificar Departamento\n" << "\t\t[3] Eliminar Departamento\n" << "\t\t[4] Mostrar Datos Departamentos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarDepto();
        break;
    case 2:
        modificarDepto();
        break;
    case 3:
        eliminarDepto();
        break;
    case 4:
        mostrarDatosDepto();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system("pause");
        return menuMantenimiento();
        break;
    }
}

void empresa::registrarDepto(){//funcion creada por Carlos Gonzalez (porque ya no esta MELANNY SECAIDA)
    system("cls");
    fstream baseDatos, log;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR DEPARTAMENTOS--\n" << endl;
    cout << "\n\t�Quires salir al --MENU DEPARTAMENTOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuDepartamentos();
    }
    else {
        cout << "\n\t\tIngrese el numero del Departamento a registrar: "; cin >>numDepto;
        cout << "\t\tIngrese el nombre del Departamento a registrar: "; cin >> nombreDepto;
        cout << "\t\tIngrese el numero telefonico del Departamento a registrar: "; cin >> telefonoDepto;
        cout << "\t\tIngrese la direccion del Departamento a registrar: "; cin >> direccionDepto;
        cout << "\n\t--Registro completado--\n" << endl;
        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<<"registro el Depto: "<<numDepto<<", ";
        log.close();
        baseDatos.open("departamentos.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto <<"\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
    cout<<"\n\t";system("pause");
    return menuDepartamentos();
}

void empresa::modificarDepto(){//funcion creada por Carlos Gonzalez (porque ya no esta MELANNY SECAIDA)
    system("cls");
    fstream baseDatos, modBaseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu modificar Depto, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --MODIFICAR DEPARTAMENTOS--" << endl;
    baseDatos.open("departamentos.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU DEPARTAMENTOS--";
        cout<<"\n\t";system("pause");
        return menuDepartamentos();
    }
    else {
        cout << "\n\t\t\tIngrese el numero del Departamento que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalDeptos.dat",ios::out|ios::binary);
        baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
        while (!baseDatos.eof()){
            if (busquedaDatos!=documentoIdentificacion){
                modBaseDatos <<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto <<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero del Departamento a registrar: "; cin >>numDepto;
                cout << "\t\tIngrese el nombre del Departamento a registrar: "; cin >> nombreDepto;
                cout << "\t\tIngrese el numero telefonico del Departamento a registrar: "; cin >> telefonoDepto;
                cout << "\t\tIngrese la direccion del Departamento a registrar: "; cin >> direccionDepto;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"modifico el Depto: "<<busquedaDatos<<", ahora es: "<<numDepto<<", ";
                log.close();
                modBaseDatos <<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto <<"\n";
            }
            baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "departamentos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalDeptos.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
    cout<<"\n\t";system("pause");
    return menuDepartamentos();
}

void empresa::eliminarDepto(){//funcion creada por Carlos Gonzalez (porque ya no esta MELANNY SECAIDA)
    system("cls");
	fstream file,file1,log;
	log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu eliminar Depto, ";
    log.close();
	int found=0;
	cout<<"\n\t\t\tEntrando al --MENU ELIMINAR DEPARTAMENTO--"<<endl;
	file.open("departamentos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el numero de Departamento que quiere borrar: ";cin>>busquedaDatos;
		file1.open("temporalDeptos.dat",ios::binary|ios::app | ios::out);
		file >> numDepto >> nombreDepto >> telefonoDepto >> direccionDepto;
		while(!file.eof())
		{
			if(busquedaDatos!=numDepto)
			{
				file1<<std::left<<std::setw(15)<< numDepto <<std::left<<std::setw(15)<< nombreDepto <<std::left<<std::setw(15)<< telefonoDepto <<std::left<<std::setw(15)<< direccionDepto << "\n";
			}
			else
			{
				found++;
				log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"elimino el Depto: "<<busquedaDatos<<", ";
                log.close();
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> numDepto >> nombreDepto  >> telefonoDepto >> direccionDepto;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t numero de Departamento no encontrado...";
		}
		file1.close();
		file.close();
    if (file.is_open())
        file.close();
    if (file1.is_open())
        file1.close();

    if( remove( "departamentos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalDeptos.dat","empleados.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
	cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
    cout<<"\n\t";system("pause");
    return menuDepartamentos();
}

void empresa::mostrarDatosDepto(){//funcion creada por Carlos Gonzalez (porque ya no esta MELANNY SECAIDA)
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mostrar datos Depto, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --MOSTRAR DATOS DEPARTAMENTOS--";
    cout << "\n\n\t\t�Quiere buscar a un Departamento en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("departamentos.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
            cout << "\n\t\tIngrese el numero del Departamento a buscar: "; cin >> busquedaDatos;
            baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
            while(!baseDatos.eof()){
                if(busquedaDatos==numDepto){
                    cout<<"\n\t\tNumero de Departamento: "<< numDepto;
                    cout<<"\n\t\tNombre del Departamento: " << nombreDepto;
                    cout<<"\n\t\tTelefono del Departamento: "<< telefonoDepto;
                    cout<<"\n\t\tDireccion del Departamento: "<< direccionDepto;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU DEPARTAMENTOS--";
                    cout<<"\n\t";system("pause");
                    return menuDepartamentos();
                }
                baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS--";
                cout<<"\n\t";system("pause");
                return mostrarDatosDepto();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS DEPARTAMENTOS"<<endl;
        baseDatos.open("departamentos.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU DEPARTAMENTOS--";
            cout<<"\n\t";system("pause");
            return menuDepartamentos();
        }
        else
        {
            baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\t\tNumero de Departamento: "<< numDepto;
                cout<<"\n\t\tNombre del Departamento: " << nombreDepto;
                cout<<"\n\t\tTelefono del Departamento: "<< telefonoDepto;
                cout<<"\n\t\tDireccion del Departamento: "<< direccionDepto;
                baseDatos>>numDepto>>nombreDepto>>telefonoDepto>>direccionDepto;
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\tRegresando al --MENU DEPARTAMENTOS--";
            cout<<"\n\t";system("pause");
            return menuDepartamentos();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}

void empresa::menuNomina()//funcion creada por Diego Culajay
{
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro al MENU NOMINA ";
log.close();

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |  SISTEMA DE NOMINA EMPLEADOS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Mostrar"<<endl;
	cout<<"\t\t\t 2. Buscar"<<endl;
	cout<<"\t\t\t 3. Salir al --MENU PRINCIPAL--"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		displayNomina();
    		cout<<"\n\t\t\t Agrega otro empleado a la nomina (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		searchNomina();
		break;
	case 3:
		return menuPrincipal();
		break;
	case 4:
		deletNomina ();
		break;
	case 5:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 3);
}

void empresa::displayNomina()//funcion creada por Diego Culajay
{
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro MOSTRAR EMPLEADOS EN NOMINA ";
log.close();

	system("cls");
	fstream baseDatos;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Empleados -------------------------"<<endl;
	baseDatos.open("empleados.dat",ios::in|ios::binary);
	if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion......";
		baseDatos.close();
	}
	else
	{
		baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>estudios>>puesto>>horatr>>hora>>horaextra;
        cout<<"\t\nNOMBRES  | "<<"CARGO             |"<<"HORASTRABAJADAS"<<"   |"<<"CANTIDADPORHORA"<<"   |"<<"HORASEXTRAS"<<"   |"<<"BONIFICACION"<<" "<<" "<<"    |"<<"ISR"<<"      |"<<"IGSS"<<"         |"<<"IRTRA"<<"          |"<<"TOTALDESCUENTOS"<<"|       "<<"SALARIOTOTAL\t\t\n ";
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		while(!baseDatos.eof())
		{

			sueldo1 = horatr+horaextra;
			sueldo= sueldo1*hora;



			isr = sueldo*0.05;
			igss = sueldo*0.0483;
			irtra= sueldo*0.01;
			totaldesc=isr+igss+irtra;

			sueldo2=sueldo-totaldesc;
			bonificacion=sueldo2+250;

			cout<<nombre<<" "<<" "<<"|"<<puesto<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<" "<<" "<<" "<<" "<<horatr<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<hora<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<" "<<" "<<" "<<" "<<horaextra<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<"250"<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<isr<<" "<<" "<<"|"<<igss<<"|"<<irtra<<" "<<"|"<<" "<<" "<<totaldesc<<" "<<" "<<" "<<" "<<" "<<" "<<"|"" "<<" "<<bonificacion;
			cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			baseDatos>>nombre>>puesto>>horatr>>hora>>horaextra>>sueldo1>>sueldo>>isr>>igss>>irtra>>totaldesc>>sueldo2>>bonificacion;
			total++;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	baseDatos.close();
}

void empresa::modifyNomina()//funcion creada por Diego Culajay
{
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro MODIFICAR EMPLEADOS EN NOMINA ";
log.close();

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Empleado-------------------------"<<endl;
	file.open("empleados.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Empleado que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.dat",ios::app|ios::out|ios::binary);
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id!=numeroid)
			{
			 file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << "\n";
			}
			else
			{
				cout<<"\t\t\tIngresa Id Empleado        : ";
	            cin>>numeroid;
                cout<<"\t\t\tIngresa Nombre del Empleado     : ";
	            cin>>nombre;
	            cout<<"\t\t\tIngresa Telefono del Empleado   : ";
	            cin>>telefono;
	            cout<<"\t\t\tIngresa las Horas Trabajadas: ";
	            cin>>horatr;
	            cout<<"\t\t\tIngresa la Cantidad que Gana por Hora  : ";
	            cin>>hora;
	            cout<<"\t\t\tIngresa la Cantidad de Horas Extras Trabajadas (si no tiene horas extras ingrese 0) : ";
                cin>>horaextra;
                sueldo1 = horatr+horaextra;
			    sueldototal= sueldo1*hora;
			    bonificacion= sueldototal+250;
			    cout<<"\t\t\t Bonificacion Incentiva de Q250.00 "<<endl;
			    cout<<"\t\t\t Sueldo total a recibir "<< bonificacion<<endl;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"registro a: "<<numeroid<<", ";
                log.close();
				file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora << std::left<<std::setw(15)<< horaextra << std::left<<std::setw(15)<< sueldototal << std::left<<std::setw(15)<< bonificacion <<"\n";
				found++;
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra >> sueldototal >> bonificacion;

		}

		file1.close();
		file.close();
		remove("empleados.dat");
		rename("Record.dat","Empleados.dat");
	}
}

void empresa::searchNomina()//funcion creada por Diego Culajay
{
    fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro BUSCAR EMPLEADOS EN NOMINA ";
log.close();
	system("cls");
	fstream file;
	int found=0;
	file.open("empleados.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Empleado buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Empleado buscada------------------------"<<endl;
		cout<<"\nIngrese Id del Empleado que quiere buscar: ";
		cin>>participant_id;
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id==numeroid)
			{
				cout<<"\n\n\t\t\t Id del Empleado: "<<numeroid<<endl;
			    cout<<"\t\t\t Nombre del Empleado: "<<nombre<<endl;
			    cout<<"\t\t\t Telefono del Empleado: "<<telefono<<endl;
			    cout<<"\t\t\t Horas Trabajadas del Empleado: "<<horatr<<endl;
			    cout<<"\t\t\t Cantidad que Gana por Hora: "<<hora<<endl;
			    cout<<"\t\t\t Horas extas trabajadas: "<<horaextra<<endl;
				found++;
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
}

void empresa::deletNomina()//funcion creada por Diego Culajay
{
    fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro ELIMINAR EMPLEADOS EN NOMINA ";
log.close();

	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles de Empleado a Borrar-------------------------"<<endl;
	file.open("empleados.dat",ios::in|ios::binary);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Empleado que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.dat",ios::app|ios::out|ios::binary);
		file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		while(!file.eof())
		{
			if(participant_id!=numeroid)
			{
				file1<<std::left<<std::setw(15)<< numeroid <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< horatr <<std::left<<std::setw(15)<< hora <<std::left<<std::setw(15)<< horaextra << "\n";
			}
			else
			{
               log.open("bitacora.dat",ios::app|ios::out|ios::binary);
               log<<"registro a: "<<numeroid<<", ";
               log.close();

				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> numeroid >> nombre >> telefono >> horatr >> hora >> horaextra;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}

		file1.close();
		file.close();
		remove("empleados.dat");
		rename("Record.dad","Empleados.dad");
	}
}

void empresa::menuConceptoImpuestos(){//funcion creada por William Mayen
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu Impuestos, ";
    log.close();
    int menu;
    cout << "\n\t\tBienvenido al --MENU MANTENIMIENTO IMPUESTOS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] Registrar Concepto Impuestos\n" << "\t\t[2] Modificar Concepto Impuestos\n" <<  "\t\t[3] Eliminar Concepto Impeustos\n" << "\t\t[4] Mostrar Datos ConceptoImpuestos\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarConceptoImpuestos();
        break;
    case 2:
        modificarConceptoImpuestos();
        break;
    case 3:
        eliminarConceptoImpuestos();
        break;
    case 4:
        mostrarDatosConceptoImpuestos();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system ("pause");
        return menuPrincipal();
        break;
    }
}

void empresa::registrarConceptoImpuestos(){//funcion creada por William Mayen
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu Registrar Concepto Impuesto ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --REGISTRAR CONCEPTO IMPUESTOS--\n" << endl;
    cout << "\n\t�Quires salir al --MENU IMPUESTOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuConceptoImpuestos();
    }
    else {
        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> Id;
        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
        cout << "\t\tIngrese el nombre del concepto: "; cin >> nomConcep;
        cout << "\t\tIngrese monto del concepto: "; cin >> montoConcep;
        cout << "\t\tIngrese el sueldo de la persona a registrar: "; cin>>sueldo;
        cout << "\n\t--Registro completado--\n" << endl;
        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<<"registro el impuesto: "<<Id<<", ";
        log.close();
        baseDatos.open("impuestos.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(15)<< Id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< nomConcep << std::left<<std::setw(15)<< montoConcep << std::left<<std::setw(15)<< sueldo <<"\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU CONCEPTO IMPUESTOS--";
    cout<<"\n\t";system("pause");
    return menuConceptoImpuestos();
}

void empresa::modificarConceptoImpuestos(){//funcion creada por William Mayen
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu Modificar Concepto Impuestos ";
    log.close();
    fstream baseDatos, modBaseDatos;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR CONCEPTO IMPUESTOS--" << endl;
    baseDatos.open("impuestos.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU IMPUESTOS--";
        cout<<"\n\t";system("pause");
        return menuConceptoImpuestos();
    }
    else {
        cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalImpuestos.dat",ios::out|ios::binary);
        baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
        while (!baseDatos.eof()){
            if (busquedaDatos!=Id){
                modBaseDatos <<std::left<<std::setw(15)<< Id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< nomConcep << std::left<<std::setw(15)<< montoConcep << std::left<<std::setw(15)<< sueldo <<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> Id;
                cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                cout << "\t\tIngrese el nombre del concepto: "; cin >> nomConcep;
                cout << "\t\tIngrese monto del concepto: "; cin >> montoConcep;
                cout << "\t\tIngrese el sueldo de la persona a registrar: "; cin>>sueldo;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"modifico el Concepto impuesto: "<<Id<<", ";
                log.close();
                modBaseDatos <<std::left<<std::setw(15)<< Id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< nomConcep << std::left<<std::setw(15)<< montoConcep << std::left<<std::setw(15)<< sueldo <<"\n";
            }
            baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "impuestos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalImpuestos.dat","impuestos.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }

    cout <<"\n\n\t\tRegresando al --MENU IMPUESTOS--";
    cout<<"\n\t";system("pause");
    return menuConceptoImpuestos();
}

void empresa::eliminarConceptoImpuestos(){//funcion creada por William Mayen
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu Eliminar CONCEPTO Impuestos ";
    log.close();
	fstream baseDatos,modBaseDatos;
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR CONCEPTO IMPUESTOS--" << endl;
	baseDatos.open("impuestos.dat",ios::in|ios::binary);
	if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
		baseDatos.close();
	}
	else
	{
		cout << "\n\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
		modBaseDatos.open("temporalImpuestos.dat", ios::app | ios::out | ios::binary);
		baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
		while(!baseDatos.eof())
		{
			if(busquedaDatos!=Id)
			{
				modBaseDatos <<std::left<<std::setw(15)<< Id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< nomConcep << std::left<<std::setw(15)<< montoConcep << std::left<<std::setw(15)<< sueldo <<"\n";
			}
			else
			{
				found++;
				log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"elimino el concepto impuesto: "<<Id<<", ";
                log.close();
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...\a";
		}
		modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "impuestos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalImpuestos.dat","impuestos.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }

    cout <<"\n\n\t\t\tRegresando al --MENU IMPUESTOS--";
    cout<<"\n\t";system("pause");
    return menuConceptoImpuestos();
}

void empresa::mostrarDatosConceptoImpuestos(){//funcion creada por William Mayen
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu Mostrar Datos concepto Impuestos, ";
    log.close();
    fstream baseDatos;
    cout << "\n\t\t\tEntrando al menu --MOSTRAR DATOS CONCEPTO IMPUESTOS--";
    cout << "\n\n\t\t�Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("impuestos.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR CONCEPTO IMPUESTOS--"<<endl;
            cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
            baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
            while(!baseDatos.eof()){
                if(busquedaDatos==Id){
                    cout<<"\n\t\tDocumento de Identificacion: "<< Id;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tNombre del concepto: "<< nomConcep;
                    cout<<"\n\t\tMonto del concepto: "<< montoConcep;
                    cout<<"\n\t\tSueldo: "<< sueldo;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}

                    cout<<"\n\n\t\t\tRegresando al --MENU IMPUESTOS--";
                    cout<<"\n\t";system("pause");
                    return menuConceptoImpuestos();
                    baseDatos.close();
                }
                baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS CONCEPTO IMPUESTOS--";
                cout<<"\n\t";system("pause");
                return mostrarDatosConceptoImpuestos();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}


            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}

    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS CONCEPTO IMPUESTOS"<<endl;
        baseDatos.open("impuestos.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}


            cout <<"\n\n\t\t\tRegresando al --MENU IMPUESTOS--";
            cout<<"\n\t";system("pause");
            return menuConceptoImpuestos();
        }
        else
        {
            baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\n\t\tDocumento de Identificacion: "<< Id;
                cout<<"\n\t\tNombre: " << nombre;
                cout<<"\n\t\tEdad: "<< edad;
                cout<<"\n\t\tCorreo Electronico: "<< correo;
                cout<<"\n\t\tTelefono: "<< telefono;
                cout<<"\n\t\tDireccion: "<< direccion;
                cout<<"\n\t\tNombre del concepto: "<< nomConcep;
                cout<<"\n\t\tMonto del concepto: "<< montoConcep;
                cout<<"\n\t\tSueldo: "<< sueldo;
                baseDatos>>Id>>nombre>>edad>>correo>>telefono>>direccion>>nomConcep>>montoConcep>>sueldo;
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}

            cout <<"\n\n\t\tRegresando al --MENU IMPUESTOS--";
            cout<<"\n\t";system("pause");
            return menuConceptoImpuestos();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}


    }
    if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}

}

 void empresa::menuPoliza(){//funcion creada por Carlos Montes
 	int opt;
	fstream log;
      log.open("bitacora.dat",ios::app|ios::out|ios::binary);
      log<<"ingreso a menu Poliza, ";
      log.close();
 	system("cls");
 	cout<<"+----------------------------------+\n";
 	cout<<"|          MENU POLIZA             |\n";
 	cout<<"+----------------------------------+\n";
 	cout<<"| 1) Ver reclamaciones acumuladas  |\n";
 	cout<<"| 2) Reclamaciones pendientes      |\n";
 	cout<<"| 3) Modificar plan                |\n";
 	cout<<"| 4) Registrar reclamante          |\n";
 	cout<<"| 5) Salir                         |\n";
 	cout<<"+----------------------------------+\n";
 	cout<<"Opcion:  ";
 	cin>>opt;
 	ofstream Esc, es;
	ifstream Lec;
    switch(opt){
        case 1:
            VerPoliza(Lec);
            break;
        case 2:
            reclamaciones(Esc, Lec);
            break;
        case 3:
            ModificarPlan(Lec);
            break;
        case 4:
            agregar(es);
            break;
        case 5:
            menuPrincipal();
            break;
    }
 }

  bool empresa::verificar(string ced, string num){ //funcion creada por Carlos Montes
 	ifstream leer("poliza.dat", ios::in|ios::binary);
	fstream log;
      log.open("bitacora.dat",ios::app|ios::out|ios::binary);
      log<<"ingreso a verificar Poliza, ";
      log.close();
 	string Num, Nom, Ape, Ced, Plan;
 	leer>>Num;
 	while(!leer.eof()){
 		leer>>Nom;
 	    leer>>Ape;
 	    leer>>Ced;
 	    leer>>Plan;
 	    if(Ced == ced || Num == num){
 	    	cout<<"Este registro ya existe.\n";
 		system("pause");
 		leer.close();
 		return false;
		 }
	 }
 	leer.close();
 	return true;
 }

 void empresa::agregar(ofstream &es){//funcion creada por Carlos Montes
	system("cls");
	fstream log;
      log.open("bitacora.dat",ios::app|ios::out|ios::binary);
      log<<"ingreso a agregar reclamante en Poliza, ";
      log.close();
	cout<<"<--------- nuevo registro de reclamante ---------->\n";
	string num, nom, ape, ced, plan;
	es.open("poliza.dat", ios::out | ios::app|ios::binary);
	cout<<"Numero de poliza: ";
	cin>>num;
	cout<<"Nombre: ";
	cin>>nom;
	cout<<"Apellido: ";
	cin>>ape;
	cout<<"Cedula: ";
	cin>>ced;
	system("cls");
	cout<<"A) Plan A tiene deducible de $100 y restar copago de 40% de la reclamacion\n";
	cout<<"B) Plan B tiene deducible de $50 y restar copago de 60% de la reclamacion\n";
	cout<<"C) No quiero plan";
	cout<<"Selecciona un plan: ";
	cin>>plan;
	if(verificar(ced, num))
	es<<num<<" "<<nom<<" "<<ape<<" "<<ced<<" "<<plan<<"\n";
	es.close();
}

void empresa::VerPoliza(ifstream &Lec){//funcion creada por Carlos Montes
	system("cls");
	fstream log;
      log.open("bitacora.dat",ios::app|ios::out|ios::binary);
      log<<"ingreso a Mostrar Reclamaciones de poliza, ";
      log.close();
	string num, nom, ape, ced, plan;
	Lec.open("acumulada.dat", ios::in|ios::binary);
	cout<<"+----------------------------------------+\n";
	cout<<"|       Reclamaciones acumuladas         |\n";
	cout<<"+----------------------------------------+\n";
	if(Lec.is_open()){
		Lec>>num;
		while(!Lec.eof()){
			Lec>>nom;
			Lec>>ape;
			Lec>>ced;
			Lec>>plan;
			cout<<"Numero de poliza--: "<<num<<endl;
			cout<<"Nombre------------: "<<nom<<endl;
			cout<<"Apellido----------: "<<ape<<endl;
			cout<<"Cedula------------: "<<ced<<endl;
			cout<<"Plan de poliza----: "<<plan<<"\n\n";
			Lec>>num;
		}
		Lec.close();
		system("pause");
	}else{
		cout<<"No se pudo acceder a la base de datos\n";
		system("pause");
	}
}

void empresa::reclamaciones(ofstream &Esc, ifstream &Lec){//funcion creada por Carlos Montes
	system("cls");
	fstream log;
      log.open("bitacora.dat",ios::app|ios::out|ios::binary);
      log<<"ingreso a reclamaciones de poliza, ";
      log.close();
	string num, nom, ape, ced, plan, numaux;
	Lec.open("poliza.dat", ios::in|ios::binary);
	bool encontrado = false;
	cout<<"Digite el numero de poliza: ";
	cin>>numaux;
	if(Lec.is_open()){
		Lec>>num;
		while(!Lec.eof() && !encontrado){
			Lec>>nom;
			Lec>>ape;
			Lec>>ced;
			Lec>>plan;
			if(num == numaux){
				if(plan =="A" || plan =="a" || plan == "B" || plan == "b"){
					Esc.open("acumulada.dat", ios::out | ios::app|ios::binary);
					Esc<<num<<" "<<ape<<" "<<ced<<" "<<plan<<"\n";
					Esc.close();
					cout<<"Se a�adio una reclamacion acumulada\n";
					system("pause");
					encontrado = true;
				}else{
					cout<<"ERROR: Usted no cuenta con un plan para su poliza\n";
					system("pause");
					encontrado = true;
				}
			}
			Lec>>num;
		}
		Lec.close();
		if(!encontrado){
			cout<<"Registro no encontrado.\n";
			system("pause");
			system("cls");
			agregar(Esc);
		}
	}else{
		cout<<"No se pudo acceder a la base de Datos\n";
		system("pause");
	}
}

void empresa::ModificarPlan(ifstream &Lec){//funcion creada por Carlos Montes
	system("cls");
      fstream log;
      log.open("bitacora.dat",ios::app|ios::out|ios::binary);
      log<<"ingreso a Modificar Plan de Poliza, ";
      log.close();
	string num, nom, ape, ced, plan, numaux, planaux;
	Lec.open("poliza.dat", ios::in|ios::binary);
	ofstream aux("auxiliar.dat", ios::out|ios::binary);
	if(Lec.is_open()){
		cout<<"Digite el numero de poliza a modificiar: ";
		cin>>numaux;
		Lec>>num;
		while(!Lec.eof()){
			Lec>>nom;
			Lec>>ape;
			Lec>>ced;
			Lec>>plan;
			if(num == numaux){
				system("cls");
				cout<<"A) Plan A tiene deducible de RD$100 y restar copago de 40% de la reclamacion\n";
				cout<<"B) Plan B tiene deducible de RD$50 y restar copago de 60% de la reclamacion\n";
				cout<<"Seleccione un plan: ";
				cin>>planaux;
				aux<<num<<" "<<nom<<" "<<ape<<" "<<ced<<" "<<planaux<<"\n";
			}else{
				aux<<num<<" "<<nom<<" "<<ape<<" "<<ced<<" "<<plan<<"\n";
			}
			Lec>>num;
		}
		Lec.close();
		aux.close();
	}else{
		cout<<"No se pudo acceder a la base de datos\n";
		system("pause");
	}
	remove("poliza.dat");
	rename("auxiliar.dat", "poliza.dat");
}

 int main(){//funcion creada por Carlos Gonzalez

     //bitacora, log in, creado por Carlos Gonzalez

    system ("cls");
    int contador=0;
    bool ingresa=false;
    string usuario, config0, config1, config2, contra, numU;
    fstream config, log;
    int datos=0;
    config.open("seguridad.dat",ios::in|ios::binary);
    if(!config){
        cout<<"\n\n\t\tError, no se encuentra un archivo escencial del programa...\a\n\n";
        exit(1);
    }
    else{
        cout << "\n\t\t\tBIENVENIDO AL PROGRAMA DE RECURSOS HUMANOS DEL GRUPO 2\n" << endl;
        cout << "\n\t\tIngrese el numero de usuario asignado: "; cin >> numU;
        config>>config0>>config1>>config2;
        while(!config.eof()){
            if(numU==config0){
                do{
                    cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
                    cout << "\n\t\tIngrese su contrasena: ";
                    char caracter;
                    caracter = getch();
                    contra="";
                    while (caracter != 13) //ASCII TECLA ENTER
                    {
                        if (caracter != 8) //ASCII TECLA RETROCESO
                        {
                            contra.push_back(caracter);
                            cout<<"*";
                        } else
                        {
                            if (contra.length() > 0)
                            {
                                cout<<"\b \b"; //Efecto caracter borrado en pantalla
                                contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                            }
                        }
                        caracter = getch();
                    }
                    //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña
                    if (usuario==config1 && contra==config2){
                        system("cls");
                        ingresa=true;
                    } else {
                        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                        log<<"\n\n\nUsuario: " << usuario <<", El usuario y/o contrasena son incorrectos, ";
                        log.close();
                        cout<<"\n\t\tEl usuario y/o contrasena son incorrectos\a"<<endl;
                        cin.get();
                        contador++;
                        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                        log<<"intentos: "<<contador<<", ";
                        log.close();
                    }
                } while (ingresa==false && contador<3);
                if (ingresa==false){
                    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                    log<<"\n\n\nUsuario: " << usuario <<", Lo siento, no puede ingresar al sistema, agoto intentos. ";
                    log.close();
                    cout<<"\n\t\tLo siento, no puede ingresar al sistema, agoto intentos"<<endl;
                    cin.get();
                } else {
                    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                    log<<"\n\n\nUsuario: " << usuario <<"Fecha AAMMDD / Hora, minutos, segundos: " <<currentDateTime() <<", ";
                    log.close();
                    fstream bienvenida;
                    string line, desicion;
                    bienvenida.open("bienvenidos.txt");
                    if(bienvenida.is_open()){
                        cout << "\n";
                        while( getline(bienvenida, line)){
                            cout << "\t"<<line << endl;
                        }
                        cout<<"\n\t\t";system("pause");
                        bienvenida.close();
                    }
                    bienvenida.close();
                    empresa empleado;
                    empleado.menuPrincipal();
                    cin.get();
                }
                return ingresa;
                datos++;
                config.close();
            }
            config>>config0>>config1>>config2;
            config.close();
        }
        config.close();
    }
    config.close();
};
