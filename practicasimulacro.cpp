#include <stdio.h>
#include "practicasimulacro.h"
#include <iostream>

int main () {

    FILE *f1 = fopen ("motor1.dat","rb");
    FILE *f2 = fopen ("motor2.dat","rb");
    FILE *f3 = fopen ("motor3.dat","rb");

    if (f1 == NULL || f2 == NULL || f3 == NULL) {
        printf("error al abrir uno de los archivos\n");
        return 1; 
    }

    //ya tengo el calculo en la classe ahora debo crear objetos y llamar a la funcion 

    simulacro s1(f1);//el s1 es un obj, y el f1 archivo 
    simulacro s2(f2);
    simulacro s3(f3);

    //ya tengo los objetos ahora llamo a fx 

    double potencia1 = s1.potenciaActiva();
    double potencia2 = s2.potenciaActiva();
    double potencia3 = s3.potenciaActiva();//hay 3 porque hay 3 archivos 

    double potenciaaparente1 = s1.potenciaAparente();
    double potenciaaparente2 = s2.potenciaAparente();
    double potenciaaparente3 = s3.potenciaAparente();

    //ya llame ahora imprimo 

    std::cout << "La potencia activa del motor 1 es; " << potencia1 << std::endl;
    std::cout << "La potencia activa del motor 2 es; " << potencia2 << std::endl;
    std::cout << "La potencia activa del motor 3 es; " << potencia3 << std::endl;

    std::cout << "La potencia aparente del motor 1 es; " << potenciaaparente1 << std::endl;
    std::cout << "La potencia aparente del motor 2 es; " << potenciaaparente2 << std::endl;
    std::cout << "La potencia aparente del motor 3 es; " << potenciaaparente3 << std::endl;

    //ya imprimi ahora cierro 

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}