
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct persona{
       char nombre[30];
       int edad;
       float altura;
}Empleado;

int main(){

    Empleado xval[10], *r, xva; int i=0, N;
    ofstream salida;
    ifstream entrada;
    r=xval;
    

    // se escribe y se lee con el mismo formato(estructura)

    salida.open("prueba.bin",ios::out | ios::binary);
    entrada.open("prueba.bin", ios::in | ios::binary);

    cout<<"creación de un archivo binario de acceso directo. ";
    cout<<"\ncuantos registros deseas ? "; cin>>N;

    do{
       cout<<"ingrese nombre: "; gets(r->nombre);
       cout<<"edad: "; cin>>r->edad;
       cout<<"estatura: "; cin>>r->altura;
       fflush(stdin);
       salida.write((char*)(r), sizeof(Empleado));
       i++;
    }while(i<N);
    salida.close();
    cout<<"\n\ndespliega archivo..";

    // primero leemos el archivo y enseguida se despliega la información
    do{
        entrada.read((char*)(r), sizeof(Empleado));
        cout<<"\n  NOMBRE: "<<r->nombre<<endl;
        cout<<"    EDAD: "<<r->edad<<endl;
        cout<<"ESTATURA: "<<r->altura<<endl;
    }while(!entrada.eof());
    getch();
    entrada.close();
    cin.get();
    return 0;
}



