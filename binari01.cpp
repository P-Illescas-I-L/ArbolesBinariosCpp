
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>

struct persona{
       char nombre[30];
       int edad;
       float altura;
};

int main(){

    struct persona xval, xva;
    ofstream salida;
    ifstream entrada;
    salida.open("prueba.txt",ios::in | ios::out | ios::binary);
    entrada.open("prueba.txt", ios::in | ios::binary);

    cout<<"creación de un archivo binario de acceso directo. ";
    strcpy(xval.nombre,"nombrex  xxxx   ");
    xval.edad=40;
    xval.altura=1.75;
    salida.write((char*)(&xval), sizeof(struct persona));
    salida.close();

    //lee el contenido del archivo y lo despliega
    if(!entrada.eof()){
         entrada.read((char*)(&xva), sizeof(struct persona));
         cout<<"\n  NOMBRE: "<<xva.nombre<<endl;
         cout<<"    EDAD: "<<xva.edad<<endl;
         cout<<"ESTATURA: "<<xva.altura<<endl;
    }
    entrada.close();
    cin.get();
    return 0;
}



