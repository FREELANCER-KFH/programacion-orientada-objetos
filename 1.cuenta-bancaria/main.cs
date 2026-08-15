using System;

public class CuentaBancaria
{
    // Atributo privado (Encapsulamiento)
    private decimal _saldo;

    public CuentaBancaria(decimal saldoInicial = 0)
    {
        _saldo = saldoInicial >= 0 ? saldoInicial : 0;
    }

    public void Depositar(decimal monto)
    {
        if (monto > 0)
        {
            _saldo += monto;
            Console.WriteLine($"Depósito exitoso: +${monto:F2}");
        }
        else
        {
            Console.WriteLine("El monto a depositar debe ser mayor a 0.");
        }
    }

    public void Retirar(decimal monto)
    {
        if (monto > 0 && monto <= _saldo)
        {
            _saldo -= monto;
            Console.WriteLine($"Retiro exitoso: -${monto:F2}");
        }
        else
        {
            Console.WriteLine("Retiro rechazado: Fondos insuficientes o monto inválido.");
        }
    }

    public decimal ObtenerSaldo()
    {
        return _saldo;
    }
}

class Program
{
    static void Main()
    {
        CuentaBancaria miCuenta = new CuentaBancaria(100m);
        miCuenta.Depositar(50m);
        miCuenta.Retirar(30m);
        miCuenta.Retirar(200m);
        Console.WriteLine($"Saldo final: ${miCuenta.ObtenerSaldo():F2}");
    }
}