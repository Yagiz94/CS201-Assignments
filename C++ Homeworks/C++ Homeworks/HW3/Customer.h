#ifndef Customer_hpp
#define Customer_hpp
#include <stdio.h>
#include <string>
#include "Account.h"
struct node{
    node* next;
    Account * acc;
};
class Customer{
private :
    int id;
    std::string name;
    int getNoOfAccounts();

    std::string lastName;
public:
    int getId();
    Customer(int id,std::string name,std::string lname);
    ~Customer();
    std::string getName();
    std::string getLastName();
    void addAccount(Account*c);
    struct node* accountsHead;
    void printAccounts();
    bool deleteAccount(int id);
    void showCustomer();
};
#endif /* Customer_hpp */
