class CuentaBancaria {
  // Atributo privado usando la sintaxis #
  #saldo;

  constructor(saldoInicial = 0) {
    this.#saldo = saldoInicial >= 0 ? saldoInicial : 0;
  }

  depositar(monto) {
    if (monto > 0) {
      this.#saldo += monto;
      console.log(`Depósito exitoso: +$${monto.toFixed(2)}`);
    } else {
      console.log("El monto a depositar debe ser mayor a 0.");
    }
  }

  retirar(monto) {
    if (monto > 0 && monto <= this.#saldo) {
      this.#saldo -= monto;
      console.log(`Retiro exitoso: -$${monto.toFixed(2)}`);
    } else {
      console.log("Retiro rechazado: Fondos insuficientes o monto inválido.");
    }
  }

  obtenerSaldo() {
    return this.#saldo;
  }
}

// Prueba de la clase
const miCuenta = new CuentaBancaria(100);
miCuenta.depositar(50);
miCuenta.retirar(30);
miCuenta.retirar(200);
console.log(`Saldo final: $${miCuenta.obtenerSaldo().toFixed(2)}`);