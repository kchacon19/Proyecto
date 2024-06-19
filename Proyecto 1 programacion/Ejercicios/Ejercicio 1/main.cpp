#include <stdio.h>

// Función para verificar si un número es primo
 esPrimo(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int num, mayor = 0, posicionMayor = 0, posicion = 0;
    int sumatoriaPrimos = 0, sumatoriaNoPrimos = 0;
    int cantidadPrimos = 0, cantidadNoPrimos = 0;
    char continuar;

    do {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        posicion++;

        if (esPrimo(num)) {
            sumatoriaPrimos += num;
            cantidadPrimos++;
            printf("El numero %d es un Numero Primo\n", num);
        } else {
            sumatoriaNoPrimos += num;
            cantidadNoPrimos++;
            printf("El numero %d No es un Numero Primo\n", num);
        }

        if (posicion == 1 || num > mayor) {
            mayor = num;
            posicionMayor = posicion;
        }

        printf("Desea ingresar otro numero? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    if (posicion > 0) {
        printf("Numero Mayor Ingresado: %d en la posicion %d\n", mayor, posicionMayor);
    }

    double promedioPrimos = cantidadPrimos ? (double)sumatoriaPrimos / cantidadPrimos : 0;
    double promedioNoPrimos = cantidadNoPrimos ? (double)sumatoriaNoPrimos / cantidadNoPrimos : 0;

    printf("Cantidad de Numeros Primos: %d\n", cantidadPrimos);
    printf("Sumatoria de Numeros Primos: %d\n", sumatoriaPrimos);
    printf("Promedio de Numeros Primos: %.2f\n", promedioPrimos);
    printf("Cantidad de Numeros No Primos: %d\n", cantidadNoPrimos);
    printf("Sumatoria de Numeros No Primos: %d\n", sumatoriaNoPrimos);
    printf("Promedio de Numeros No Primos: %.2f\n", promedioNoPrimos);

    return 0;
}

    
