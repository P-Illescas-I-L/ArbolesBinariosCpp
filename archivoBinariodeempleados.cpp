
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Persona{
            char nombre[20];
            char apellidos[20];
            char departamento[20];
            float sueldo;
}Templeado;

//using namespace std;

//  AL EDITAR   empleados.dat  SE CREA EL ARCHIVO,  EN EL APARECEN CARACTERES ALFANUMÉRICOS POR SER BINARIO Y SOLO SE
//  VISUALIZAN LOS CARACTERES ALFABÉTICOS.


int main(){
       Templeado registro;
       int tamanyo = sizeof(Templeado); // Tamaño de un registro
       ofstream f;
       ifstream in;
       char resp;
       int conta = 0;
              //se abre el archivo para añadir datos al final
       f.open("empleados.dat", ios::out|ios::app|ios::binary);
       if (f.fail()){
             cout << "Error al crear el archivo empleados.dat" << endl;
             system("pause");
             exit(1);
       }
       // Entrada de datos
       cout << "Entrada de datos. F6(CTRL^Z) para finalizar\n\n";
       cout << "Nombre: ";
       cin.getline(registro.nombre, 20);
       while (!cin.eof()){
                  cout << "Apellidos: ";
                  cin.getline(registro.apellidos, 20);
                  cout << "Departamento: ";
                  cin.getline(registro.departamento, 20);
                  cout << "Sueldo: ";
                  cin >> registro.sueldo;
                  // Se escribe la estructura en el fichero
                  f.write((char *)&registro, sizeof(Templeado));
                  cin.ignore(); //(numeric_limits<int>::max(),'\n');
                  cout << "Nombre: ";
                  cin.getline(registro.nombre, 20);
        }
        cin.clear();
        f.close();

        do{
           cout << "Mostrar empleados(S/N)? ";
           cin.get(resp);
           cin.ignore();//(numeric_limits<int>::max(),'\n');
        }while (toupper(resp) != 'S' && toupper(resp) != 'N');
        
        // Listado de datos
        if (toupper(resp) == 'S'){
                 in.open("empleados.dat", ios::binary);
                 if(in.fail()){
                       cout << "Error al abrir el archivo empleados.dat" << endl;
                       system("pause");
                       exit(1);
                 }


            // Leemos el primer registro
            in.read((char *) &registro, sizeof(Templeado));
            while(!in.eof()){
                cout << "\nEMPLEADO: " << ++conta << endl;
                cout << "Nombre: " << registro.nombre << endl;
                cout << "Apellidos: " << registro.apellidos << endl;
                cout << "Departamento: " << registro.departamento << endl;
                cout << "Sueldo: " << registro.sueldo << endl;
                // Leemos el siguiente registro
                in.read((char *) &registro, sizeof(Templeado));
            }
           in.close(); // Cerramos el archivo
           system("pause");
        }
        return 0;
}
