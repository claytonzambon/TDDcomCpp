#include <iostream>
#include <string>

void* operator new(size_t bytes)
{
	std::cout << "Alocando " << bytes << " bytes" << std::endl;
	return malloc(bytes);
}

int main()
{
	std::cout << "----------------------" << std::endl;
	std::string meuNomeCompleto = "Clayton Zambon";

	std::cout << meuNomeCompleto << std::endl;
	
	return 0;
}
