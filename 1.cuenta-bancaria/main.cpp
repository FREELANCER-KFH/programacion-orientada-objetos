#include <iostream>
#include <iomanip>

class CuentaBancaria {
private:
    // Atributo privado (Encapsulamiento)
    double saldo;

public:
    CuentaBancaria(double saldoInicial = 0.0) {
        saldo = (saldoInicial >= 0) ? saldoInicial : 0.0;
    }

    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            std::cout << "Deposito exitoso: +$" << std::fixed << std::setprecision(2) << monto << "\n";
        } else {
            std::cout << "El monto a depositar debe ser mayor a 0.\n";
        }
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            std::cout << "Retiro exitoso: -$" << std::fixed << std::setprecision(2) << monto << "\n";
        } else {
            std::cout << "Retiro rechazado: Fondos insuficientes o monto invalido.\n";
        }
    }

    double obtenerSaldo() const {
        return saldo;
    }
};

int main() {
    CuentaBancaria miCuenta(100.0);
    miCuenta.depositar(50.0);
    miCuenta.retirar(30.0);
    miCuenta.retirar(200.0);
    std::cout << "Saldo final: $" << std::fixed << std::setprecision(2) << miCuenta.obtenerSaldo() << "\n";

    return 0;
}