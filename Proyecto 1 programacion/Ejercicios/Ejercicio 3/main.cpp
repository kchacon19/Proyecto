#include <iostream>
using namespace std;

// Funci�n para invertir un n�mero
int invertirNumero(int num) {
    int inverso = 0;
    while (num > 0) {
        inverso = inverso * 10 + num % 10;
        num /= 10;
    }
    return inverso;
}

int main() {
    char continuar;
    
    do {
        int numero;
        cout << "Ingrese un numero entero de hasta 5 digitos: ";
        cin >> numero;

        // Validar que el n�mero tenga hasta 5 d�gitos
        if (numero < 0 || numero > 99999) {
            cout << "El numero ingresado no es valido. Debe ser un entero de hasta 5 digitos." << endl;
        } else {
            int inverso = invertirNumero(numero);
            cout << "Numero ingresado: " << numero << endl;
            cout << "Numero inverso: " << inverso << endl;
        }

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
