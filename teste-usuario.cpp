#include "catch.hpp"
#include "Usuario.hpp"

TEST_CASE("Usu�rio deve saber informar o seu primeiro nome")
{
	//Arrange
	Usuario clayton("Clayton Zambon");

	//Act
	std::string primeiroNome = clayton.recuperaPrimeiroNome();

	//Assert
	REQUIRE("Clayton" == primeiroNome);
}