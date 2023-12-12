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

void ImprimirDetalleInsumosMes(struct RegistroMes registros[][NUM_MESES]) { // creamos la funcion con void para que no de valor de retorno la misma que usaremos para inprimir los detalles de insumo por mes
    for (int i = 0; i < NUM_INSUMOS; i++) { // primer for para la columna de insumos
        printf("Insumo %d:\n", i + 1); // imprimimos el encabezado indicando el número del insumo
        for (int j = 0; j < NUM_MESES; j++) { // segundo for sobre cada mes para un insumo dado
            printf("Mes %d - Ingresos: %d, Egresos: %d\n", j + 1, registros[i][j].ingresos, registros[i][j].egresos); // imprimimos el detalle de ingresos y egresos para el mes actual del insumo actual, Se utiliza j + 1 para mostrar el número del mes comenzando desde 1 en lugar de 0, registros[i][j].ingresos y registros[i][j].egresos acceden a los valores almacenados en la matriz de registros
        }
        printf("\n"); // utilizamos esto para que la siguiente linea se inprima con espacio
    }
}

void ImprimirTotalIngresosEgresosAnual(struct RegistroMes registros[][NUM_MESES]) { // creamos la funcion con void para que no de valor de retorno la misma que usaremos para inprimir el total de ingresos y egresos anuales
    for (int i = 0; i < NUM_INSUMOS; i++) { // primer for para la columna de insumos
        int totalIngresos = 0;// igualamos a cero los ingresos y egresos para que el conteo sea correcto
        int totalEgresos = 0;
        for (int j = 0; j < NUM_MESES; j++) { // segundo for sobre cada mes para un insumo dado
            totalIngresos += registros[i][j].ingresos; // acumula los valores para obtener el total
            totalEgresos += registros[i][j].egresos;
        }
        printf("Insumo %d - Total Ingresos: %d, Total Egresos: %d\n", i + 1, totalIngresos, totalEgresos); // imprimimos el total de ingresos y egresos para el insumo actual
    }
}
int main() { // declaramos la funcion principal
    
    struct RegistroMes registros[NUM_INSUMOS][NUM_MESES];// Declaración de la matriz de registros

    GenerarValoresAleatorios(registros); // llamamos a la función para llenar la matriz registros con valores aleatorios para ingresos y egresos

    int opcion; // creamos el menu para el usuario usando opcion para almacenar la eleccion del usuario.

    do {
        // Menú de opciones
        printf("\nSeleccione una opción:\n");
        printf("1. Imprimir Detalle de Ingresos y Egresos\n");
        printf("2. Imprimir Total de Ingresos y Egresos Anual\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);

    }