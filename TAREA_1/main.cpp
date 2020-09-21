#include <iostream>
#include "funciones.h"

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {

    std::cout << std::endl;
    polinomios(argv[1]);

    participantes();
    std::cout << std::endl;
    
    return 0;
}
