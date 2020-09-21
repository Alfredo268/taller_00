#include "funciones.h"
#include <string.h> 
#include <list>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;


void polinomios(char *cadena){


    
    cout << cadena << endl;

    int i, p=0, posicion=0, valor=0, exponente=0;

    for(i=0; i<strlen(cadena); i++) //busca si hay potencia en la cadena
    {
        if(cadena[i] == '*')
        {
            p=1;
            break;
        }
    }
    if(p=1) // busco el mayor exponente para definir tamaño de arreglo
    {   
        for(i=3; i<strlen(cadena); i++)
        {
            if(cadena[i-2]=='*' && cadena[i-1]=='*')
            {
                if(cadena[i]>exponente)exponente = cadena[i];
            }
        }
        exponente = exponente-48;
    }
    
    int *polinomio;
    polinomio = new int [exponente]; //creamos un arreglo con tamaño del exponente encontrado y asignamos valores 0
    for(i=0; i<=exponente; i++)polinomio[i]=0;

    evalua(cadena,i,valor,posicion,polinomio);
    
    cout<<endl;
    for(i=0; i<=exponente; i++) //ver polinomio
    {
        cout << "el valor del polinomio["<<i<<"] es "<<polinomio[i] <<endl;
    }
    delete[] polinomio;
    
}

void evalua(char cadena[], int i, int valor, int posicion, int *polinomio) //funcion para llenar arreglo de enteros (polinomio)
{
    for(i=0; i<strlen(cadena); i++) //se pasaran los valores de cadena en el arreglo de polinomios
    {
//evaluar si comienza con numero negativo
        if(cadena[i]=='-') //numero negativo
        {
            i=i+2;
            if(cadena[i]>=48 && cadena[i]<=57) //si es un numero
            {
                valor=valor+cadena[i]-48;
                while(i+1<strlen(cadena)) //evalua el siguiente caracter
                {
                    i++;
                    if(cadena[i]==' ')break; //es un numero solo (-3)
                    if(cadena[i-1]=='*')break;
                    if(cadena[i]>=48 && cadena[i]<=57)valor=valor*10+cadena[i]-48; //si es numero se adiciona al valor
                    if(cadena[i]=='x') //si es x
                    {
                        if(i+1==strlen(cadena))//ultimo valor
                        {
                            posicion=1;
                        }
                        if(i+1<strlen(cadena))
                        {
                            i++;
                            if(cadena[i]==' ') //sigue un espacio
                            {
                                posicion=1;
                                break;
                            }
                            if(cadena[i]=='*') //es un ax**n
                            {   
                                posicion=cadena[i+2]-48;
                                i=i+2;
                                break;
                            }
                        }
                    }
                }
                polinomio[posicion]=valor*-1;
            }

            if(cadena[i]=='x' && cadena[i-1]==' ') //comienza con x
            {
                valor=1;
                if(i+1==strlen(cadena))posicion=1; //ultimo valor
                if(i+1<strlen(cadena))
                {
                    i++;
                    if(cadena[i]==' ')posicion=1; //sigue un espacio
                    if(cadena[i]=='*') //es un x**n
                    {   
                        posicion=cadena[i+2]-48;
                        i=i+2;
                    }
                }
                polinomio[posicion]=valor*-1;
            }
        }
//evaluar si comienza con numero positivo
        if(cadena[i]=='+') //numero positivo
        {
            i=i+2;
            if(cadena[i]>=48 && cadena[i]<=57) //si es un numero
            {
                valor=valor+cadena[i]-48;
                while(i+1<strlen(cadena)) //evalua el siguiente caracter
                {
                    i++;
                    if(cadena[i]==' ')break; //es un numero solo (3)

if(cadena[i-1]=='*')break;
                    if(cadena[i]>=48 && cadena[i]<=57)valor=valor*10+cadena[i]-48; //si es numero se adiciona al valor
                    if(cadena[i]=='x') //si es x
                    {
                        if(i+1==strlen(cadena))posicion=1; //ultimo valor
                        if(i+1<strlen(cadena))
                        {
                            i++;
                            if(cadena[i]==' ') //sigue un espacio
                            {
                                posicion=1;
                                break;
                            }
                            if(cadena[i]=='*') //es un ax**n
                            {   
                                posicion=cadena[i+2]-48;
                                i=i+2;
                                break;
                            }
                        }
                    }
                }
                polinomio[posicion]=valor;
            }

            if(cadena[i]=='x' && cadena[i-1]==' ') //comienza con x
            {
                valor=1;
                if(i+1==strlen(cadena))posicion=1; //ultimo valor
                if(i+1<strlen(cadena))
                {
                    i++;
                    if(cadena[i]==' ')posicion=1; //sigue un espacio
                    if(cadena[i]=='*') //es un x**n
                    {   
                        posicion=cadena[i+2]-48;
                        i=i+2;
                    }
                }
                polinomio[posicion]=valor;
            }
        }
//comienza sin signos (primer valor)
        if(i==0)
        {
            if(cadena[i]>=48 && cadena[i]<=57)//si es numero
            {
                valor=valor+cadena[i]-48;
                while(i+1<strlen(cadena)) //evalua el siguiente caracter
                {
                    i++;
                    if(cadena[i]==' ')break; //es un numero solo (3)
                    if(cadena[i-1]=='*')break;
                    if(cadena[i]>=48 && cadena[i]<=57)valor=valor*10+cadena[i]-48; //si es numero se adiciona al valor
                    if(cadena[i]=='x') //si es x
                    {
                        if(i+1==strlen(cadena))posicion=1; //ultimo valor
                        if(i+1<strlen(cadena))
                        {
                            i++;
                            if(cadena[i]==' ') //sigue un espacio
                            {
                                posicion=1;
                                break;
                            }
                            if(cadena[i]=='*') //es un ax**n
                            {   
                                posicion=cadena[i+2]-48;
                                i=i+2;
                                break;
                            }
                        }
                    }
                }
                polinomio[posicion]=valor;
            }
            if(cadena[i]=='x') //comienza con x
            {
                valor=1;
                if(i+1==strlen(cadena))posicion=1; //ultimo valor
                if(i+1<strlen(cadena))
                {
                    i++;
                    if(cadena[i]==' ')posicion=1; //sigue un espacio
                    if(cadena[i]=='*') //es un x**n
                    {   
                        posicion=cadena[i+2]-48;
                        i=i+2;
                    }
                }
                polinomio[posicion]=valor;
            }
        }
        posicion=0;
        valor=0;
    }
}


void participantes() {
    std::cout << std::endl << "=== Taller 00 ===" << std::endl;
    std::cout << std::endl << "Alfredo Garcés Ulloa"; // Reemplazar por su nombre
    std::cout << std::endl << "Daniel Hernandez Calfuqueo"; // Reemplazar por su nombre
    std::cout << std::endl << "Francisco Pinochet Morales" << std::endl; // Reemplazar por su nombre
}
