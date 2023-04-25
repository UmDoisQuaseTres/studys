/*

Gerador de senhas aleatório sem criptografia
Matheus de Oliveira
04/2023

*/

#include <iostream>
#include <string>
#include <memory>
#include <ctime>


//Criação da classe PasswordGenerator
class PasswordGenerator {

	//Declarando alguns atributos privados
private: 
	//Esse atributo é um ponteiro inteligente que armazena a frase mestra
	std::unique_ptr < std::string > wordMaster;

	//Esse outro atributo armazena o tamanho da senha
	std::unique_ptr <unsigned short int> size;

public:
	//construtor
	PasswordGenerator(std::string word, unsigned short int sz) {
		//Inicializando os ponteiros inteligentes e alocando dinamicamente a memoria
		wordMaster = std::make_unique<std::string>(word);
		size = std::make_unique<unsigned short int>(sz);
	}
	//construtor copia
	PasswordGenerator(const PasswordGenerator& other ) {
		wordMaster = std::make_unique<std::string>(*(other.wordMaster));
		size = std::make_unique<unsigned short int>(*(other.size));
	}
	//construtor de movimento
	PasswordGenerator(PasswordGenerator&& other) noexcept {
		wordMaster = std::move(other.wordMaster);
		size = std::move(other.size);
	}
	//operador de atribuição de movimento
	PasswordGenerator& operator=(PasswordGenerator&& other) noexcept {
		if (this != &other) {
			wordMaster = std::move(other.wordMaster);
			size = std::move(other.size);
		}
		return *this;
	}

	//Função para gerar a senha
	std::string generatePassword() {
		//Declarando a variavel password como o ponteiro *wordMaster
		std::string password = *wordMaster;
		
		//Declarando o range de caracteres que a senha sera gerada
		std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]\\|;:'\"<>,.?/";
		while (password.length() < *size) {
			unsigned short int index = rand() % charset.length();
			password += charset[index];
		}

		return password;
	}
	};
 

int main() {
	while (true) {
		std::srand(std::time(nullptr));
		std::unique_ptr<std::string> insertChar;
		std::unique_ptr<unsigned short int> size;
		std::unique_ptr<unsigned short int> choice;

		insertChar = std::make_unique<std::string>();
		size = std::make_unique<unsigned short int>();
		choice = std::make_unique<unsigned short int>();

		std::cout << "Ola, por favor, escolha a opcao desejada: \n";
		std::cout << "1 - Gerar senha. \n";
		std::cout << "2 - Sair. \n";
		std::cin >> *choice;
		std::cin.clear();
		if (*choice == 1) {
		std::cout << "Insira uma frase mestra: " << "\n";
		std::getline(std::cin, *insertChar);
		std::cin.clear();


		std::cout << "Insira o tamanho da senha: ";
		
		std::cin >> *size;
		std::cin.clear();
		// verificar se o tamanho da senha é válido
		if (*size <= 0 || *size > 100) {
			std::cerr << "Tamanho de senha inválido! Use um valor entre 1 e 100.\n";
			return 1;
		}

		// criar objeto PasswordGenerator e gerar a senha
		PasswordGenerator pg(*insertChar, *size);
		std::string senha = pg.generatePassword();
		std::cout << "Senha gerada: " << senha << "\n";
		
	}
	else if (*choice == 2) {
		return 0;
	}
	}
		return 0;
}