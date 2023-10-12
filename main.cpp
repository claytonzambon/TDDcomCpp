#include <iostream>
#include <string>
#include <string_view>

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
	ExibeNome("Um nome qualquer sem estad na Heap");
	
	return 0;
}
