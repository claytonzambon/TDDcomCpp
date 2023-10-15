#include "Leilao.hpp"
#include <iostream>

Leilao::Leilao(std::string descricao): descricao(descricao)
{
    
}

const std::vector<Lance>& Leilao::recuperaLances() const
{
    return lances;
}

void Leilao::recebeLance(const Lance& lance)
{
    std::cout << "[L-value]" << std::endl;
    if (lances.size() == 0 || comparaSeLancesDeDiferentesUsuarios(lance)) {
        lances.push_back(lance);
    }
}

bool Leilao::comparaSeLancesDeDiferentesUsuarios(const Lance& lance) {
    return lances.back().recuperaNomeUsuario() != lance.recuperaNomeUsuario();
}

void Leilao::recebeLance(Lance&& lance)
{
    std::cout << "[R-value]" << std::endl;
    if (lances.size() == 0 || comparaSeLancesDeDiferentesUsuarios(lance)) {
        lances.push_back(lance);
    }
}
