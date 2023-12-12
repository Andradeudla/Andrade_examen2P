#include <stdio.h> // se incluye las bibliotecas para las variables y los numeros random
#include <stdlib.h>
#include <time.h>

#define NUM_INSUMOS 30// definimos las constantes con el numero meses e insumos
#define NUM_MESES 12


struct RegistroMes { // definición de estructura para almacenar los registros de ingresos y egresos
    int ingresos;
    int egresos;
};