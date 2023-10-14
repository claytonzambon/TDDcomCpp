#include "Lance.hpp"
#include <iostream>

Lance::Lance(Usuario usuario, float valor): usuario(usuario), valor(valor)
{
}

float Lance::recuperaValor() const
{
    return valor;
}

std::string Lance::recuperaNomeUsuario() const
{
    return usuario.recuperaNome();
}

Lance::Lance(const Lance& outroLance) : 
    usuario(outroLance.usuario),
    valor(outroLance.valor)
{
    std::cout << "Executando c�pia de lance de valor " << valor << std::endl;
}