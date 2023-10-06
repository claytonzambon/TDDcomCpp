#include "Leilao.hpp"

Leilao::Leilao(std::string descricao): descricao(descricao)
{
    
}

const std::vector<Lance>& Leilao::recuperaLances() const
{
    return lances;
}

void Leilao::recebeLance(const Lance& lance)
{
    if (lances.size() == 0 || comparaLances(lance)) {
        lances.push_back(lance);
    }
}

bool Leilao::comparaLances(const Lance& lance) {
    return lances.back().recuperaNomeUsuario() != lance.recuperaNomeUsuario();
}
