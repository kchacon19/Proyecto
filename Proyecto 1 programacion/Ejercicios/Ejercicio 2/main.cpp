#include <stdio.h>
#include <string.h>

int main() {
    int _numero_factura = 1;
    char _cedula[20];
    char _nombre[50];
    int _tipo_cliente;
    int _tipo_tiquete;
    int _cantidad_tiquetes;
    double _monto_unitario;
    double _monto_venta;
    double _descuento;
    double _subtotal;
    double _impuesto;
    double _total_pagar;

    char _continuar;
    int _contador_factura = 1;
    int _ventas_registradas = 0;

    int _cantidad_galeria = 0;
    double _acumulado_galeria = 0;
    int _cantidad_palco = 0;
    double _acumulado_palco = 0;
    int _cantidad_general = 0;
    double _acumulado_general = 0;

    do {
        printf("Ingrese la cedula del cliente: ");
        scanf("%s", _cedula);
        printf("Ingrese el nombre del cliente: ");
        scanf(" %[^\n]", _nombre);
        do {
            printf("Tipo de cliente (1=Niño o adulto mayor, 2=Adulto): ");
            scanf("%d", &_tipo_cliente);
        } while (_tipo_cliente != 1 && _tipo_cliente != 2);
        do {
            printf("Tipo de tiquete (1=Galeria, 2=Palco): ");
            scanf("%d", &_tipo_tiquete);
        } while (_tipo_tiquete != 1 && _tipo_tiquete != 2);
        printf("Cantidad de tiquetes o entradas a comprar: ");
        scanf("%d", &_cantidad_tiquetes);

        if (_tipo_tiquete == 1) {
            _monto_unitario = 6000;
        } else {
            _monto_unitario = 12000;
        }

        _monto_venta = _cantidad_tiquetes * _monto_unitario;

        if (_tipo_cliente == 1) {
            _descuento = _monto_venta * 0.30;
        } else {
            _descuento = 0;
        }

        _subtotal = _monto_venta - _descuento;
        _impuesto = _subtotal * 0.13;
        _total_pagar = _subtotal + _impuesto;

        printf("Numero de factura: %d\n", _contador_factura);
        printf("Cedula del cliente: %s\n", _cedula);
        printf("Nombre del cliente: %s\n", _nombre);
        printf("Tipo de cliente: %s\n", _tipo_cliente == 1 ? "Niño o adulto mayor" : "Adulto");
        printf("Tipo de tiquete: %s\n", _tipo_tiquete == 1 ? "Galeria" : "Palco");
        printf("Cantidad de tiquetes o entradas: %d\n", _cantidad_tiquetes);
        printf("Monto unitario por tiquete: %.2f\n", _monto_unitario);
        printf("Monto de venta: %.2f\n", _monto_venta);
        printf("Descuento: %.2f\n", _descuento);
        printf("Subtotal de venta: %.2f\n", _subtotal);
        printf("Impuesto de venta: %.2f\n", _impuesto);
        printf("Total a pagar: %.2f\n", _total_pagar);

        if (_tipo_tiquete == 1) {
            _cantidad_galeria += _cantidad_tiquetes;
            _acumulado_galeria += _total_pagar;
        } else {
            _cantidad_palco += _cantidad_tiquetes;
            _acumulado_palco += _total_pagar;
        }

        _cantidad_general += _cantidad_tiquetes;
        _acumulado_general += _total_pagar;

        printf("Desea registrar otra venta? (s/n): ");
        scanf(" %c", &_continuar);
        _contador_factura++;

    } while (_continuar == 's' || _continuar == 'S');

    printf("\nEstadísticas finales:\n");
    printf("Cantidad de entradas Tiquetes Galería: %d\n", _cantidad_galeria);
    printf("Acumulado Dinero por Tiquetes Galería: %.2f\n", _acumulado_galeria);
    printf("Cantidad de entradas Tiquetes Palco: %d\n", _cantidad_palco);
    printf("Acumulado Dinero por Tiquetes Palco: %.2f\n", _acumulado_palco);
    printf("Cantidad General de Entradas: %d\n", _cantidad_general);
    printf("Acumulado General Dinero por Entradas: %.2f\n", _acumulado_general);
    printf("Promedio General por Ventas: %.2f\n", _ventas_registradas ? _acumulado_general / _ventas_registradas : 0);

    return 0;
}
