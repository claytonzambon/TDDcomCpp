#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Avaliador.hpp"

Leilao emOrdemCrescente()
{
	// Arrange or Given (Dado) -> Preparando ambiente para os testes
	Lance primeiroLance(Usuario("Clayton Zambon"), 1000);
	Lance segundoLance(Usuario("Karine Zambon"), 2000);
	Leilao leilao("Fiat 147 0Km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	return leilao;
}

Leilao emOrdemDecrescente()
{
	// Arrange or Given (Dado) -> Preparando ambiente para os testes
	Lance primeiroLance(Usuario("Clayton Zambon"), 2000);
	Lance segundoLance(Usuario("Karine Zambon"), 1000);
	Leilao leilao("Fiat 147 0Km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);

	return leilao;
}

TEST_CASE("Deve recuperar maior lance de leilão") {

	// ArrangeActAssert (Triple A)
	// GivenWhenThen

	// Arrange or Given (Dado) -> Preparando ambiente para os testes
	Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());
	Avaliador leiloeiro;

	// Act or When (Quando) -> Executando o código a ser testado
	leiloeiro.avalia(leilao);

	// Assert or Then (Então) -> Verificando se tudo deu certo
	REQUIRE(2000 == leiloeiro.recuperaMaiorValor());
}

TEST_CASE("Deve recuperar menor lance de leilão") {

	// ArrangeActAssert (Triple A)
	// GivenWhenThen

	// Arrange or Given (Dado) -> Preparando ambiente para os testes
	Leilao leilao = GENERATE(emOrdemDecrescente(), emOrdemCrescente());
	Avaliador leiloeiro;

	// Act or When (Quando) -> Executando o código a ser testado
	leiloeiro.avalia(leilao);

	// Assert or Then (Então) -> Verificando se tudo deu certo
	REQUIRE(1000 == leiloeiro.recuperaMenorValor());
}

TEST_CASE("Deve recuperar os 3 maiores lances") {

	// ArrangeActAssert (Triple A)
	// GivenWhenThen

	// Arrange or Given (Dado) -> Preparando ambiente para os testes
	Lance primeiroLance(Usuario("Clayton Zambon"), 1000);
	Lance segundoLance(Usuario("Karine Zambon"), 2000);
	Lance terceiroLance(Usuario("Bernadete"), 1500);
	Lance quartoLance(Usuario("Miguel"), 2500);

	Leilao leilao("Fiat 147 0Km");
	leilao.recebeLance(primeiroLance);
	leilao.recebeLance(segundoLance);
	leilao.recebeLance(terceiroLance);
	leilao.recebeLance(quartoLance);

	Avaliador leiloeiro;

	// Act or When (Quando) -> Executando o código a ser testado
	leiloeiro.avalia(leilao);

	// Assert or Then (Então) -> Verificando se tudo deu certo
	std::vector<Lance> maiores3Lances = leiloeiro.recupera3MaioresLances();
	REQUIRE(3 == maiores3Lances.size());
	REQUIRE(2500 == maiores3Lances[0].recuperaValor());
	REQUIRE(2000 == maiores3Lances[1].recuperaValor());
	REQUIRE(1500 == maiores3Lances[2].recuperaValor());
}