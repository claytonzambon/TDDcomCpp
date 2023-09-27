#include "Avaliador.hpp"
#include <iostream>

int main() {

	// ArrangeActAssert (Triple A)
	// GivenWhenThen

	// Arrange or Given (Dado) -> Preparando ambiente para os testes
	Lance primeiroLance(Usuario("Clayton Zambon"), 1000);
	Lance segundoLance(Usuario("Karine Zambon"), 2000);
	Leilao leilao("Fiat 147 0Km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);

	Avaliador leiloeiro;

	// Act or When (Quando) -> Executando o código a ser testado
	leiloeiro.avalia(leilao);

	// Assert or Then (Então) -> Verificando se tudo deu certo
	float valorEsperado = 2000;

	if (valorEsperado == leiloeiro.recuperaMaiorValor()) {
		std::cout << "TESTE OK" << std::endl;
	}
	else {
		std::cout << "TESTE FALHOU" << std::endl;
	}
	

	return 0;
}