#include <iostream>
#include <string>
#include <memory>
#include "Usuario.hpp"

/*void* operator new(size_t bytes)
{
	std::cout << "Alocando " << bytes << " bytes" << std::endl;
	return malloc(bytes);
}*/

void ExibeNome(std::string_view nome)
{
	std::cout << nome << std::endl;
}

void ExibeNomeUsuario(std::shared_ptr<Usuario> usuario)
{
	std::cout << usuario->recuperaNome() << std::endl;
}

int main2()
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

class String
{
private:
	char* data;
	size_t size;

public:
	String(const char* string)
	{
		std::cout << "String criada" << std::endl;
		size = strlen(string);
		data = new char[size];
		memcpy(data, string, size);
	}

	String(const String& outraString)
	{
		std::cout << "String copiada" << std::endl;
		size = strlen(outraString.data);
		data = new char[size];
		memcpy(data, outraString.data, size);
	}

	String(String&& outraString)
	{
		std::cout << "String movida" << std::endl;
		size = outraString.size;
		data = outraString.data;

		outraString.size = 0;
		outraString.data = nullptr;
	}

	~String()
	{
		delete data;
	}
};

class User
{
private:
	String nome;
public:
	User(const String& string) : nome(string)
	{
	}

	User(String&& string) : nome((String&&)string)
	{
	}
};

int main() {
	User(String("Zambon"));
	return 0;
}