class CuentaBancaria:
    def __init__(self, saldo_inicial: float = 0.0):
        # Atributo privado (Encapsulamiento)
        self.__saldo = saldo_inicial if saldo_inicial >= 0 else 0.0

    def depositar(self, monto: float) -> None:
        if monto > 0:
            self.__saldo += monto
            print(f"Depósito exitoso: +${monto:.2f}")
        else:
            print("El monto a depositar debe ser mayor a 0.")

    def retirar(self, monto: float) -> None:
        if 0 < monto <= self.__saldo:
            self.__saldo -= monto
            print(f"Retiro exitoso: -${monto:.2f}")
        else:
            print("Retiro rechazado: Fondos insuficientes o monto inválido.")

    def obtener_saldo(self) -> float:
        return self.__saldo


# Prueba de la clase
mi_cuenta = CuentaBancaria(100.0)
mi_cuenta.depositar(50.0)
mi_cuenta.retirar(30.0)
mi_cuenta.retirar(200.0)
print(f"Saldo final: ${mi_cuenta.obtener_saldo():.2f}")