#include <stdio.h> // se incluye las bibliotecas para las variables y los numeros random
#include <stdlib.h>
#include <time.h>

#define NUM_INSUMOS 30// definimos las constantes con el numero meses e insumos
#define NUM_MESES 12


struct RegistroMes { // definición de estructura para almacenar los registros de ingresos y egresos
    int ingresos;
    int egresos;
};

void GenerarValoresAleatorios(struct RegistroMes registros[][NUM_MESES]) { // creamos la funcion con void para que no de valor de retorno
    srand(time(NULL)); // establecemos la semilla para la generación de números aleatorios basada en el tiempo actual
    for (int i = 0; i < NUM_INSUMOS; i++) { // creamos el primer for para la columna de insumos
        for (int j = 0; j < NUM_MESES; j++) { // creamos el segundo for para la columa de meses
            registros[i][j].ingresos = rand() % 100 + 1; // Genera números aleatorios entre 1 y 100 para ingresos
            registros[i][j].egresos = rand() % 50 + 1;  // Genera números aleatorios entre 1 y 50 para egresos
        }
    }
}