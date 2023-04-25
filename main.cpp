#include <iostream>
#include <memory>
#include <string>

class Bank{
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
    Bank(std::string name, std::string cpf, std::string email, unsigned int acc){
        clientName = std::make_unique<std::string>(name);
        clientCPF = std::make_unique<std::string>(cpf);
        clientEmail = std::make_unique<std::string>(email);
        accountNumber = std::make_unique<unsigned int>(acc);
        
    }
    //Construtor copia
    Bank(const Bank& other) {
        clientName = std::make_unique<std::string>(*(other.clientName));
        clientCPF = std::make_unique<std::string>(*(other.clientCPF));
        clientEmail = std::make_unique<std::string>(*(other.clientEmail));
        accountNumber = std::make_unique<unsigned int>(*(other.accountNumber));    
    }

    //Construtor de movimento
    Bank(Bank&& other) noexcept {
        clientName = std::move(other.clientName);
        clientCPF = std::move(other.clientCPF);
        clientEmail = std::move(other.clientEmail);
        accountNumber = std::move(other.accountNumber);
    }

    //Operador de atribuição de movimento
    Bank& operator=(Bank&& other) noexcept {
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
    
        return 0;
}