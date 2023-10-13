#include <iostream>
#include <string>
#include <memory>
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

void ExibeNomeUsuario(std::shared_ptr<Usuario> usuario)
{
	std::cout << usuario->recuperaNome() << std::endl;
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

	std::shared_ptr<Usuario> usuario = std::make_shared<Usuario>("Clayton Zambon");
	//Usuario* usuario = new Usuario("Clayton Zambon");

	ExibeNomeUsuario(usuario);
	
	return 0;
}
