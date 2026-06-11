#pragma once 
#include <stdio.h>
#include <math.h>

class simulacro {
    private:
    int tam;
    
    double S;
    double P;//lo voy a necesitar para el calculo

    double *C;
    double *V;
    double *T;//es puntero porque no se sabe el tamaño del archivo

    public:
    //constructor 
    simulacro (FILE *f) {
        //quiero averiguar el tamaño del archivo 
        fseek(f, 0, SEEK_END); //esto se hace en binario 
        tam = ftell(f); //esto me da el tamaño en bytes 
        tam = tam / sizeof(double); //esto me da la cant de doubles 
        tam = tam / 3; //cantidad de muestras 

        rewind(f); // me devuelve al inicio ya con tam

        C = new double[tam];//creo vectores dinamicos
        V = new double[tam];
        T = new double[tam];

        for (int i = 0; i < tam; i++) {//leo los datos del archivo
            fread(&V[i], sizeof(double), 1, f);
            fread(&C[i], sizeof(double), 1, f);
            fread(&T[i], sizeof(double), 1, f);
        }
    }

~simulacro() {
    delete[]C;
    delete[]V;
    delete[]T;
}

//ya declare variables es privado, tengo los punteros, tengo el tamaño, tengo los vectores cargados con los datos, ahora voy a hacer la cuenta 

double potenciaActiva() {//esto me devuelve potenciaActiva{
    double suma = 0;
    for (int i =0; i<tam ; i++){
        suma = suma + (V[i] * C[i]);
    }
    double potenciaact;
    potenciaact = (suma /((tam -1) - (0)));
    return potenciaact;
}

//ahora calculo potencia apartente 

double potenciaAparente() {
    double RMS_V = 0;
    double RMS_C = 0;
    double sumatoriav = 0;
    double sumatoriac = 0;
    for (int i = 0; i < tam; i++) {
        sumatoriav = sumatoriav + (V[i] * V[i]);
    }
    for (int i = 0; i < tam; i++) {
        sumatoriac = sumatoriac + (C[i] * C[i]);
    }
    RMS_V = sqrt(sumatoriav / ((tam -1)- 0));
    RMS_C = sqrt(sumatoriac / ((tam -1)- 0));

    double potenciaaparente;
    potenciaaparente = RMS_V * RMS_C;
    return potenciaaparente;
}
};