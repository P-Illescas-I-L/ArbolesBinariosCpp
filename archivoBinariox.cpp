
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

class Persona{
private: char nombre[30];
         int edad;
         float altura;

         ifstream  entrada;
         ofstream  salida;

public:  Persona(){
            strcpy(nombre, "\0");
            edad=0;
            altura=0.0;
            entrada==NULL;
            salida==NULL;
          }
          int creaFile(ofstream & salida, Persona *, int);
          void listaFile(ifstream &, Persona *);
};


int Persona::creaFile( ofstream & salida, Persona *r, int N){
    int  i=0,b;

      do{
       cout<<"ingrese nombre: "; gets(r->nombre);
       cout<<"edad: "; cin>>r->edad;
       cout<<"estatura: "; cin>>r->altura;
       fflush(stdin);
       salida.write((char*)(r), sizeof(Persona));
       i++; b++;
    }while(i<N);
    return b;
}

void Persona::listaFile(ifstream & entrada, Persona *r){

      cout<<"\n\ndespliega archivo..";

    // primero leemos el archivo y enseguida se despliega la información
    do{
        entrada.read((char*)(r), sizeof(Persona));
        cout<<"\n  NOMBRE: "<<r->nombre<<endl;
        cout<<"    EDAD: "<<r->edad<<endl;
        cout<<"ESTATURA: "<<r->altura<<endl;
    }while(!entrada.eof());
    getch();
}

int main(){
    Persona s, *r, xval[10]; int i=0,b, N;
    ofstream salida;
    ifstream entrada;
    r=xval;
    salida.open("prueba.bin",ios::out | ios::binary);
    entrada.open("prueba.bin", ios::in | ios::binary);

    cout<<"creación de un archivo binario de acceso directo. ";
    cout<<"\ncuantos registros deseas ? "; cin>>N;

    b=s.creaFile(salida, r, N);
    s.listaFile(entrada, r);
    cout<<"total de registros: "<<b;
    system("pause");
    salida.close();
    entrada.close();
    cin.get();
    return 0;
}



