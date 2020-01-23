#ifndef BankingSystem_hpp
#define BankingSystem_hpp
#include <stdio.h>
#include <string>
#include "Customer.h"
struct CustomerNode{
    CustomerNode* next;
    Customer * customer;
};
class BankingSystem {
private:
    CustomerNode* customersHead;
    bool idExist(int id);
    int accountCount;
    int userCount;
    bool checkExist(std::string name,std::string lastname);
    Account* getAccount(int id);

public:
    BankingSystem();
    ~BankingSystem();
    void printAll();

    void addCustomer( const int customerId, const std::string firstName, const std::string lastName );
    void deleteCustomer( const int customerId );
    int addAccount( const int customerId, const double amount );
    void deleteAccount( const int accountId );
    void showAllAccounts();
    void showAllCustomers();
    void showCustomer( const int customerId );
};
#endif /* BankingSystem_hpp */
