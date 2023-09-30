#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"



TEST_CASE("Deve recuperar maior lance de leil�o em ordem Crescente") {

	// ArrangeActAssert (Triple A)
	// GivenWhenThen

	// Arrange or Given (Dado) -> Preparando ambiente para os testes
	Lance primeiroLance(Usuario("Clayton Zambon"), 1000);
	Lance segundoLance(Usuario("Karine Zambon"), 2000);
	Leilao leilao("Fiat 147 0Km");
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(primeiroLance);

	Avaliador leiloeiro;

	// Act or When (Quando) -> Executando o c�digo a ser testado
	leiloeiro.avalia(leilao);

	// Assert or Then (Ent�o) -> Verificando se tudo deu certo
	REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}
