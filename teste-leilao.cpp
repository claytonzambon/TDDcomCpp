#include "catch.hpp"
#include "Leilao.hpp"
#include "Usuario.hpp"

TEST_CASE("Leil�o n�o deve receber lances consecutivos do mesmo usu�rio")
{
	//Arrange
	Leilao leilao("Fiat 147 0Km");
	Usuario zambon("Clayton Zambon");

	Lance primeiroLance(zambon, 1000);
	Lance segundoLance(zambon, 1500);

	//Act
	//leilao.recebeLance(primeiroLance);
	leilao.recebeLance(Lance(zambon, 1000));
	leilao.recebeLance(segundoLance);

	//Assert
	REQUIRE(1 == leilao.recuperaLances().size());
	REQUIRE(1000 == leilao.recuperaLances()[0].recuperaValor());
}