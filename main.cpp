#include <iostream>
#include <string>
#include <string_view>
#include "Usuario.hpp"

void* operator new(size_t bytes)
{
	std::cout << "Alocando " << bytes << " bytes" << std::endl;
	return malloc(bytes);
}

void ExibeNome(std::string_view nome)
{
	std::cout << nome << std::endl;
}

int main()
{
	std::cout << "----------------------" << std::endl;
	std::string casal = "Seu Madruga & Bruxa do Setenta e Um";

	std::string_view nomeHomem(casal.c_str(), casal.find('&') - 1);
	std::string_view nomeMulher(casal.c_str() + casal.find('&') + 2);

	ExibeNome(nomeHomem);
	ExibeNome(nomeMulher);
	ExibeNome("Um nome qualquer sem estar na Heap");

	Usuario* usuario = new Usuario("Clayton Zambon");

	std::cout << usuario->recuperaNome() << std::endl;

	delete usuario;
	
	return 0;
}
