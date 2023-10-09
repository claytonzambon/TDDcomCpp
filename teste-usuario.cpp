#include "catch.hpp"
#include "Usuario.hpp"

TEST_CASE("Usuário deve saber informar o seu primeiro nome")
{
	//Arrange
	Usuario clayton("Clayton Zambon");

	//Act
	std::string primeiroNome = clayton.recuperaPrimeiroNome();

	//Assert
	REQUIRE("Clayton" == primeiroNome);
}