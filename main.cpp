#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>
#include <cstring>

class BankAccount{
    private:
    std::unique_ptr<std::string> clientName;
    std::unique_ptr<std::string> clientCPF;
    std::unique_ptr<std::string> clientEmail;
    std::unique_ptr<unsigned int> accountNumber;
    std::unique_ptr<int> balance;
    std::unique_ptr<unsigned int> deposit;
    std::unique_ptr<unsigned int> withdraw;
    
    public:

    //Setters
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
    void setBalance(int bal){
        balance = std::make_unique<int>(bal);
    }
    void setDeposit(unsigned int dep){
        deposit = std::make_unique<unsigned int>(dep);
    }
    void setWithdraw(unsigned int wit){
        withdraw = std::make_unique<unsigned int>(wit);
    }

    //Getters
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
    int getBalance(){
        return *balance;
    }

    //Construtor padrão
    BankAccount(std::string name, std::string cpf, std::string email, unsigned int acc, int bal, unsigned int dep, unsigned int wit){
        clientName = std::make_unique<std::string>(name);
        clientCPF = std::make_unique<std::string>(cpf);
        clientEmail = std::make_unique<std::string>(email);
        accountNumber = std::make_unique<unsigned int>(acc);
        balance = std::make_unique<int>(bal);
        deposit = std::make_unique<unsigned int>(dep);
        withdraw = std::make_unique<unsigned int>(wit);
        
    }
    //Construtor copia
    BankAccount(const BankAccount& other) {
        clientName = std::make_unique<std::string>(*(other.clientName));
        clientCPF = std::make_unique<std::string>(*(other.clientCPF));
        clientEmail = std::make_unique<std::string>(*(other.clientEmail));
        accountNumber = std::make_unique<unsigned int>(*(other.accountNumber));
        balance = std::make_unique<int>(*(other.balance));
        deposit = std::make_unique<unsigned int>(*(other.deposit));
        withdraw = std::make_unique<unsigned int>(*(other.withdraw));    
    }

    //Construtor de movimento
    BankAccount(BankAccount&& other) noexcept {
        clientName = std::move(other.clientName);
        clientCPF = std::move(other.clientCPF);
        clientEmail = std::move(other.clientEmail);
        accountNumber = std::move(other.accountNumber);
        balance = std::move(other.balance);
        deposit = std::move(other.deposit);
        withdraw = std::move(other.withdraw);
    }

    //Operador de atribuição de movimento
    BankAccount& operator=(BankAccount&& other) noexcept {
        if (this != &other) {
            clientName = std::move(other.clientName);
            clientCPF = std::move(other.clientCPF);
            clientEmail = std::move(other.clientEmail);
            accountNumber = std::move(other.accountNumber);
            balance = std::move(other.balance);
            deposit = std::move(other.deposit);
            withdraw = std::move(other.withdraw);
        }
        return *this;
    }

    void deposit_balance(unsigned int deps){
        deps = *deposit;
        *balance += deps;
    }
    void withdraw_balance(unsigned int witd){
        witd = *withdraw;
        *balance -= witd;
    }
};
int main(){
    //Declarando os smart pointers
    std::unique_ptr<std::string> nameClient = std::make_unique<std::string>("");
    std::unique_ptr<std::string> cpfClient = std::make_unique<std::string>("");
    std::unique_ptr<std::string> emailClient = std::make_unique<std::string>("");
    std::unique_ptr<unsigned int> accountNumber = std::make_unique<unsigned int>(0);
    std::unique_ptr<unsigned int> choice = std::make_unique<unsigned int>(0);
    std::unique_ptr<int> balance = std::make_unique<int>(0);
    std::unique_ptr<unsigned int> deposit = std::make_unique<unsigned int>(0);
    std::unique_ptr<unsigned int> withdraw = std::make_unique<unsigned int>(0);

    //Criando objeto client
    BankAccount client(*nameClient, *cpfClient, *emailClient, *accountNumber, *balance, *deposit, *withdraw);

    do{

    //Programa principal
    std::cout << "Ola, seja bem vindo ao seu banco! \n" << "Escolha a opcao desejada \n" << "1 - Cadastrar cliente \n" << "2 - Consultar conta \n" << "3 - Depositar \n" << "4 - Sacar \n" << "5 - Sair \n";
        std::cin >> *choice;
        std::cin.clear();
        if(*choice == 1){

            //Recebendo os dados via teclado
            std::cout << "Digite o nome do cliente: \n";
            std::getline(std::cin >> std::ws, *nameClient);
            std::cin.clear();
            std::cout << "Digite o CPF do cliente: \n";
            std::getline(std::cin >> std::ws, *cpfClient);
            std::cin.clear();
            std::cout << "Digite o email do cliente: \n";
            std::getline(std::cin >> std::ws, *emailClient);
            std::cin.clear();
            std::cout << "Digite o numero da conta: \n";
            std::cin >> *accountNumber;
            std::cin.clear();
            std::cout << "Digite o saldo inicial: \n";
            std::cin >> *balance;
            std::cin.clear();
            
            //Salvando os dados no objeto
            client.setClientName(std::move(*nameClient));
            client.setClientCPF(std::move(*cpfClient));
            client.setClientEmail(std::move(*emailClient));
            client.setAccountNumber(std::move(*accountNumber));
            client.setBalance(std::move(*balance));

            //Mensagem de sucesso
            std::cout << "Cliente cadastrado com sucesso! \n";
        }else if(*choice == 2){
            *nameClient = client.getClientName();
            *cpfClient = client.getClientCPF();
            *emailClient = client.getClientEmail();
            *balance = client.getBalance();
            *accountNumber = client.getAccountNumber();
        
            std::cout << "Dados da conta: \n" << "Saldo: " << *balance << "\n" << "Nome: " << *nameClient << "\n" << "CPF: " << *cpfClient << "\n" << "Email: " << *emailClient << "\n" << "Numero da conta: " << *accountNumber << "\n";
        }else if(*choice == 3){

        std::cout << "Digite o valor a ser depositado: \n";
        std::cin >> std::ws >> *deposit;
        std::cin.clear();

        } 
    }while(*choice != 5);

        return 0;

}