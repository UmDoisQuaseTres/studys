#include <iostream>
#include <memory>
#include <string>

class BankAccount{
    private:
    std::unique_ptr<std::string> clientName;
    std::unique_ptr<std::string> clientCPF;
    std::unique_ptr<std::string> clientEmail;
    std::unique_ptr<unsigned int> accountNumber;
    
    public:
    void setClientName(std::string name){
        clientName = std::make_unique<std::string>(name);
    }
    void setClientCPF(std::string cpf){
        clientCPF = std::make_unique<std::string>(cpf);
    }
    void setClientEmail(std::string email){
        clientEmail = std::make_unique<std::string>(email);
    }
    void setAccountNumber(unsigned int acc){
        accountNumber = std::make_unique<unsigned int>(acc);
    }
    std::string getClientName(){
        return *clientName;
    }
    std::string getClientCPF(){
        return *clientCPF;
    }
    std::string getClientEmail(){
        return *clientEmail;
    }
    unsigned int getAccountNumber(){
        return *accountNumber;
    }

    //Construtor padrão
    BankAccount(std::string name, std::string cpf, std::string email, unsigned int acc){
        clientName = std::make_unique<std::string>(name);
        clientCPF = std::make_unique<std::string>(cpf);
        clientEmail = std::make_unique<std::string>(email);
        accountNumber = std::make_unique<unsigned int>(acc);
        
    }
    //Construtor copia
    BankAccount(const BankAccount& other) {
        clientName = std::make_unique<std::string>(*(other.clientName));
        clientCPF = std::make_unique<std::string>(*(other.clientCPF));
        clientEmail = std::make_unique<std::string>(*(other.clientEmail));
        accountNumber = std::make_unique<unsigned int>(*(other.accountNumber));    
    }

    //Construtor de movimento
    BankAccount(BankAccount&& other) noexcept {
        clientName = std::move(other.clientName);
        clientCPF = std::move(other.clientCPF);
        clientEmail = std::move(other.clientEmail);
        accountNumber = std::move(other.accountNumber);
    }

    //Operador de atribuição de movimento
    BankAccount& operator=(BankAccount&& other) noexcept {
        if (this != &other) {
            clientName = std::move(other.clientName);
            clientCPF = std::move(other.clientCPF);
            clientEmail = std::move(other.clientEmail);
            accountNumber = std::move(other.accountNumber);
        }
        return *this;
    }
};
int main(){
    //Declarando os smart pointers
    std::unique_ptr<std::string> nameClient;
    std::unique_ptr<std::string> cpfClient;
    std::unique_ptr<std::string> emailClient;
    std::unique_ptr<unsigned int> accountNumber;
    std::unique_ptr<unsigned int> choice;

    //Inicializando os smart pointers
    nameClient = std::make_unique<std::string>();
    cpfClient = std::make_unique<std::string>();
    emailClient = std::make_unique<std::string>();
    accountNumber = std::make_unique<unsigned int>();
    choice = std::make_unique<unsigned int>();

    //Programa principal
    std::cout << "Ola, seja bem vindo ao seu banco! \n" << "Escolha a opcao desejada \n" << "1 - Cadastrar cliente \n" << "2 - Consultar saldo \n" << "3 - Depositar \n" << "4 - Sacar \n" << "5 - Sair \n";
        std::cin >> *choice;
        std::cin.clear();
        if(*choice == 1){
            std::cout << "Digite o nome do cliente: ";
            std::cin >> *nameClient;
            std::cout << "Digite o CPF do cliente: ";
            std::cin >> *cpfClient;
            std::cout << "Digite o email do cliente: ";
            std::cin >> *emailClient;
            std::cout << "Digite o numero da conta: ";
            std::cin >> *accountNumber;
            BankAccount client(std::move(*nameClient), std::move(*cpfClient), std::move(*emailClient), std::move(*accountNumber));
            client.setClientName(std::move(*nameClient));
            client.setClientCPF(std::move(*cpfClient));
            client.setClientEmail(std::move(*emailClient));
            client.setAccountNumber(std::move(*accountNumber));
        }
        



        return 0;

}